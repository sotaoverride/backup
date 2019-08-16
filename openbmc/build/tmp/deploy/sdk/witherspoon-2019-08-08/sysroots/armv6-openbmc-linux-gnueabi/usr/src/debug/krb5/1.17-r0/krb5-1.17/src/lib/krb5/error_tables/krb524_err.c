/*
 * et-c-krb524_err.c:
 * This file is automatically generated; please do not edit it.
 */

#include <stdlib.h>

#define N_(a) a

static const char* const text[] = {N_("Cannot convert V5 keyblock"),
                                   N_("Cannot convert V5 address information"),
                                   N_("Cannot convert V5 principal"),
                                   N_("V5 realm name longer than V4 maximum"),
                                   N_("Kerberos V4 error"),
                                   N_("Encoding too large"),
                                   N_("Decoding out of data"),
                                   N_("Service not responding"),
                                   N_("Kerberos version 4 support is disabled"),
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

const struct error_table et_k524_error_table = {text, -1750206208L, 9};

static struct et_list link = {0, 0};

void initialize_k524_error_table_r(struct et_list** list);
void initialize_k524_error_table(void);

void initialize_k524_error_table(void)
{
    initialize_k524_error_table_r(&_et_list);
}

/* For Heimdal compatibility */
void initialize_k524_error_table_r(struct et_list** list)
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
    et->table = &et_k524_error_table;
    et->next = 0;
    *end = et;
}
