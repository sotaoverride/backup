/*
 * et-h-import_err.h:
 * This file is automatically generated; please do not edit it.
 */

#include <et/com_err.h>

#define IMPORT_BAD_FILE (37349888L)
#define IMPORT_BAD_TOKEN (37349889L)
#define IMPORT_BAD_VERSION (37349890L)
#define IMPORT_BAD_RECORD (37349891L)
#define IMPORT_BAD_FOOTER (37349892L)
#define IMPORT_FAILED (37349893L)
#define IMPORT_MISMATCH_COUNT (37349894L)
#define IMPORT_UNK_OPTION (37349895L)
#define IMPORT_WARN_DB (37349896L)
#define IMPORT_RENAME_FAILED (37349897L)
#define IMPORT_EXTRA_DATA (37349898L)
#define IMPORT_CONFIRM (37349899L)
#define IMPORT_OPEN_DUMP (37349900L)
#define IMPORT_IMPORT (37349901L)
#define IMPORT_TTY (37349902L)
#define IMPORT_RENAME_OPEN (37349903L)
#define IMPORT_RENAME_LOCK (37349904L)
#define IMPORT_RENAME_UNLOCK (37349905L)
#define IMPORT_RENAME_CLOSE (37349906L)
#define IMPORT_GET_PARAMS (37349907L)
extern const struct error_table et_imp_error_table;
extern void initialize_imp_error_table(void);

/* For compatibility with Heimdal */
extern void initialize_imp_error_table_r(struct et_list** list);

#define ERROR_TABLE_BASE_imp (37349888L)

/* for compatibility with older versions... */
#define init_imp_err_tbl initialize_imp_error_table
#define imp_err_base ERROR_TABLE_BASE_imp
