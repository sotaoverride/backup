/*
 * et-c-adb_err.c:
 * This file is automatically generated; please do not edit it.
 */

#include <stdlib.h>

#define N_(a) a

static const char* const text[] = {
    N_("No Error"),
    N_("Principal or policy already exists"),
    N_("Principal or policy does not exist"),
    N_("Database not initialized"),
    N_("Invalid policy name"),
    N_("Invalid principal name"),
    N_("Database inconsistency detected"),
    N_("XDR encoding error"),
    N_("Failure!"),
    N_("Bad lock mode"),
    N_("Cannot lock database"),
    N_("Database not locked"),
    N_("KADM5 administration database lock file missing"),
    N_("Insufficient permission to lock file"),
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

const struct error_table et_adb_error_table = {text, 28810240L, 14};

static struct et_list link = {0, 0};

void initialize_adb_error_table_r(struct et_list** list);
void initialize_adb_error_table(void);

void initialize_adb_error_table(void)
{
    initialize_adb_error_table_r(&_et_list);
}

/* For Heimdal compatibility */
void initialize_adb_error_table_r(struct et_list** list)
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
    et->table = &et_adb_error_table;
    et->next = 0;
    *end = et;
}
