/*
 * et-c-k5e1_err.c:
 * This file is automatically generated; please do not edit it.
 */

#include <stdlib.h>

#define N_(a) a

static const char* const text[] = {
    N_("Plugin does not support interface version"),
    N_("Invalid module specifier"),
    N_("Plugin module name not found"),
    N_("The KDC should discard this request"),
    N_("Can't create new subsidiary cache"),
    N_("Invalid keyring anchor name"),
    N_("Unknown keyring collection version"),
    N_("Invalid UID in persistent keyring name"),
    N_("Malformed reply from KCM daemon"),
    N_("Mach RPC error communicating with KCM daemon"),
    N_("KCM daemon reply too big"),
    N_("No KCM server found"),
    0};

struct error_table
{
    char const* const* msgs;
    long base;
    int n_msgs;
};
struct et_list
{
    struct et_list* next;
    const struct error_table* table;
};
extern struct et_list* _et_list;

const struct error_table et_k5e1_error_table = {text, -1750600192L, 12};

static struct et_list link = {0, 0};

void initialize_k5e1_error_table_r(struct et_list** list);
void initialize_k5e1_error_table(void);

void initialize_k5e1_error_table(void)
{
    initialize_k5e1_error_table_r(&_et_list);
}

/* For Heimdal compatibility */
void initialize_k5e1_error_table_r(struct et_list** list)
{
    struct et_list *et, **end;

    for (end = list, et = *list; et; end = &et->next, et = et->next)
        if (et->table->msgs == text)
            return;
    et = malloc(sizeof(struct et_list));
    if (et == 0)
    {
        if (!link.table)
            et = &link;
        else
            return;
    }
    et->table = &et_k5e1_error_table;
    et->next = 0;
    *end = et;
}