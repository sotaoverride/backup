/*
 * et-h-kdc5_err.h:
 * This file is automatically generated; please do not edit it.
 */

#include <et/com_err.h>

#define KDC5_RCSID (-1779992064L)
#define KDC5_NOPORT (-1779992063L)
#define KDC5_NONET (-1779992062L)
#define KDC5_IO_RESPONSE (-1779992061L)
extern const struct error_table et_kdc5_error_table;
extern void initialize_kdc5_error_table(void);

/* For compatibility with Heimdal */
extern void initialize_kdc5_error_table_r(struct et_list** list);

#define ERROR_TABLE_BASE_kdc5 (-1779992064L)

/* for compatibility with older versions... */
#define init_kdc5_err_tbl initialize_kdc5_error_table
#define kdc5_err_base ERROR_TABLE_BASE_kdc5