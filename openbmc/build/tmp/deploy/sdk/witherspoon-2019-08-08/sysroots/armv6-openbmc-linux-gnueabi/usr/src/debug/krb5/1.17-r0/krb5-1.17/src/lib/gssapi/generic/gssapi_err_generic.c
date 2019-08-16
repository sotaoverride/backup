/*
 * et-c-gssapi_err_generic.c:
 * This file is automatically generated; please do not edit it.
 */

#include <stdlib.h>

#define N_(a) a

static const char* const text[] = {
    N_("No @ in SERVICE-NAME name string"),
    N_("STRING-UID-NAME contains nondigits"),
    N_("UID does not resolve to username"),
    N_("Validation error"),
    N_("Couldn't allocate gss_buffer_t data"),
    N_("Message context invalid"),
    N_("Buffer is the wrong size"),
    N_("Credential usage type is unknown"),
    N_("Unknown quality of protection specified"),
    N_("Local host name could not be determined"),
    N_("Hostname in SERVICE-NAME string could not be canonicalized"),
    N_("Mechanism is incorrect"),
    N_("Token header is malformed or corrupt"),
    N_("Packet was replayed in wrong direction"),
    N_("Token is missing data"),
    N_("Token was reflected"),
    N_("Received token ID does not match expected token ID"),
    N_("The given credential's usage does not match the requested usage"),
    N_("Storing of acceptor credentials is not supported by the mechanism"),
    N_("Storing of non-default credentials is not supported by the mechanism"),
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

const struct error_table et_ggss_error_table = {text, -2045022976L, 20};

static struct et_list link = {0, 0};

void initialize_ggss_error_table_r(struct et_list** list);
void initialize_ggss_error_table(void);

void initialize_ggss_error_table(void)
{
    initialize_ggss_error_table_r(&_et_list);
}

/* For Heimdal compatibility */
void initialize_ggss_error_table_r(struct et_list** list)
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
    et->table = &et_ggss_error_table;
    et->next = 0;
    *end = et;
}
