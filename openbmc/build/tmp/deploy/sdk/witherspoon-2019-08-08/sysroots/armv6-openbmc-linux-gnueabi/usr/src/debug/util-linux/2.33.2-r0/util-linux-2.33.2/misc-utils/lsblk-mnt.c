#include <libmount.h>

#include "c.h"
#include "lsblk.h"
#include "nls.h"
#include "pathnames.h"
#include "xalloc.h"

static struct libmnt_table *mtab, *swaps;
static struct libmnt_cache* mntcache;

static int table_parser_errcb(struct libmnt_table* tb
                              __attribute__((__unused__)),
                              const char* filename, int line)
{
    if (filename)
        warnx(_("%s: parse error at line %d -- ignored"), filename, line);
    return 1;
}

static int is_active_swap(const char* filename)
{
    if (!swaps)
    {
        swaps = mnt_new_table();
        if (!swaps)
            return 0;
        if (!mntcache)
            mntcache = mnt_new_cache();

        mnt_table_set_parser_errcb(swaps, table_parser_errcb);
        mnt_table_set_cache(swaps, mntcache);

        if (!lsblk->sysroot)
            mnt_table_parse_swaps(swaps, NULL);
        else
        {
            char buf[PATH_MAX];
            snprintf(buf, sizeof(buf), "%s" _PATH_PROC_SWAPS, lsblk->sysroot);
            mnt_table_parse_swaps(swaps, buf);
        }
    }

    return mnt_table_find_srcpath(swaps, filename, MNT_ITER_BACKWARD) != NULL;
}

char* lsblk_device_get_mountpoint(struct blkdev_cxt* cxt)
{
    struct libmnt_fs* fs;
    const char* fsroot;

    assert(cxt);
    assert(cxt->filename);

    if (cxt->is_mounted || cxt->is_swap)
        return cxt->mountpoint;

    if (!mtab)
    {
        mtab = mnt_new_table();
        if (!mtab)
            return NULL;
        if (!mntcache)
            mntcache = mnt_new_cache();

        mnt_table_set_parser_errcb(mtab, table_parser_errcb);
        mnt_table_set_cache(mtab, mntcache);

        if (!lsblk->sysroot)
            mnt_table_parse_mtab(mtab, NULL);
        else
        {
            char buf[PATH_MAX];
            snprintf(buf, sizeof(buf), "%s" _PATH_PROC_MOUNTINFO,
                     lsblk->sysroot);
            mnt_table_parse_mtab(mtab, buf);
        }
    }

    /* Note that maj:min in /proc/self/mountinfo does not have to match with
     * devno as returned by stat(), so we have to try devname too
     */
    fs = mnt_table_find_devno(mtab, makedev(cxt->maj, cxt->min),
                              MNT_ITER_BACKWARD);
    if (!fs)
        fs = mnt_table_find_srcpath(mtab, cxt->filename, MNT_ITER_BACKWARD);
    if (!fs)
    {
        if (is_active_swap(cxt->filename))
        {
            cxt->mountpoint = xstrdup("[SWAP]");
            cxt->is_swap = 1;
        }
        else
            cxt->mountpoint = NULL;

        return cxt->mountpoint;
    }

    /* found */
    fsroot = mnt_fs_get_root(fs);
    if (fsroot && strcmp(fsroot, "/") != 0)
    {
        /* hmm.. we found bind mount or btrfs subvolume, let's try to
         * get real FS root mountpoint */
        struct libmnt_fs* rfs;
        struct libmnt_iter* itr = mnt_new_iter(MNT_ITER_BACKWARD);

        mnt_table_set_iter(mtab, itr, fs);
        while (mnt_table_next_fs(mtab, itr, &rfs) == 0)
        {
            fsroot = mnt_fs_get_root(rfs);
            if ((!fsroot || strcmp(fsroot, "/") == 0) &&
                mnt_fs_match_source(rfs, cxt->filename, mntcache))
            {
                fs = rfs;
                break;
            }
        }
        mnt_free_iter(itr);
    }

    DBG(DEV, ul_debugobj(cxt, "mountpoint: %s", mnt_fs_get_target(fs)));
    cxt->mountpoint = xstrdup(mnt_fs_get_target(fs));
    cxt->is_mounted = 1;
    return cxt->mountpoint;
}

void lsblk_mnt_init(void)
{
    mnt_init_debug(0);
}

void lsblk_mnt_deinit(void)
{
    mnt_unref_table(mtab);
    mnt_unref_table(swaps);
    mnt_unref_cache(mntcache);
}
