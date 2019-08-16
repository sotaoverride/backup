/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $
 *
 * $Id:$
 */
/** \page MFD helper for ipIfStatsTable
 *
 * \section intro Introduction
 * Introductory text.
 *
 */
/*
 * standard Net-SNMP includes
 */
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>

/*
 * include our parent header
 */
#include <net-snmp/agent/mib_modules.h>

#include "ipIfStatsTable.h"
#include "ipIfStatsTable_interface.h"

const oid ipIfStatsTable_oid[] = {IPIFSTATSTABLE_OID};
const int ipIfStatsTable_oid_size = OID_LENGTH(ipIfStatsTable_oid);

ipIfStatsTable_registration ipIfStatsTable_user_context;
static ipIfStatsTable_registration* ipIfStatsTable_user_context_p;

void initialize_table_ipIfStatsTable(void);
void shutdown_table_ipIfStatsTable(void);

/**
 * Initializes the ipIfStatsTable module
 */
void init_ipIfStatsTable(void)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:init_ipIfStatsTable", "called\n"));

    /*
     * TODO:300:o: Perform ipIfStatsTable one-time module initialization.
     */

    /*
     * here we initialize all the tables we're planning on supporting
     */
    if (should_init("ipIfStatsTable"))
        initialize_table_ipIfStatsTable();

    /*
     * last changed should be 0 at startup
     */
    ipIfStatsTable_lastChange_set(0);
} /* init_ipIfStatsTable */

/**
 * Shut-down the ipIfStatsTable module (agent is exiting)
 */
void shutdown_ipIfStatsTable(void)
{
    if (should_init("ipIfStatsTable"))
        shutdown_table_ipIfStatsTable();
}

/**
 * Initialize the table ipIfStatsTable
 *    (Define its contents and how it's structured)
 */
void initialize_table_ipIfStatsTable(void)
{
    u_long flags;

    DEBUGMSGTL(
        ("verbose:ipIfStatsTable:initialize_table_ipIfStatsTable", "called\n"));

    /*
     * TODO:301:o: Perform ipIfStatsTable one-time table initialization.
     */

    /*
     * TODO:302:o: |->Initialize ipIfStatsTable user context
     * if you'd like to pass in a pointer to some data for this
     * table, allocate or set it up here.
     */
    /*
     * a netsnmp_data_list is a simple way to store void pointers. A simple
     * string token is used to add, find or remove pointers.
     */
    ipIfStatsTable_user_context_p =
        netsnmp_create_data_list("ipIfStatsTable", NULL, NULL);

    /*
     * No support for any flags yet, but in the future you would
     * set any flags here.
     */
    flags = 0;

    /*
     * call interface initialization code
     */
    _ipIfStatsTable_initialize_interface(ipIfStatsTable_user_context_p, flags);
} /* initialize_table_ipIfStatsTable */

/**
 * Shutdown the table ipIfStatsTable
 */
void shutdown_table_ipIfStatsTable(void)
{
    /*
     * call interface shutdown code
     */
    _ipIfStatsTable_shutdown_interface(ipIfStatsTable_user_context_p);
    netsnmp_free_all_list_data(ipIfStatsTable_user_context_p);
    ipIfStatsTable_user_context_p = NULL;
}

/**
 * extra context initialization (eg default values)
 *
 * @param rowreq_ctx    : row request context
 * @param user_init_ctx : void pointer for user (parameter to
 * rowreq_ctx_allocate)
 *
 * @retval MFD_SUCCESS  : no errors
 * @retval MFD_ERROR    : error (context allocate will fail)
 */
int ipIfStatsTable_rowreq_ctx_init(ipIfStatsTable_rowreq_ctx* rowreq_ctx,
                                   void* user_init_ctx)
{
    DEBUGMSGTL(
        ("verbose:ipIfStatsTable:ipIfStatsTable_rowreq_ctx_init", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:210:o: |-> Perform extra ipIfStatsTable rowreq initialization. (eg
     * DEFVALS)
     */

    return MFD_SUCCESS;
} /* ipIfStatsTable_rowreq_ctx_init */

/**
 * extra context cleanup
 *
 */
void ipIfStatsTable_rowreq_ctx_cleanup(ipIfStatsTable_rowreq_ctx* rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_rowreq_ctx_cleanup",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:211:o: |-> Perform extra ipIfStatsTable rowreq cleanup.
     */
    netsnmp_access_systemstats_entry_free(rowreq_ctx->data);
    rowreq_ctx->data = NULL;
} /* ipIfStatsTable_rowreq_ctx_cleanup */

/**
 * pre-request callback
 *
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_ERROR                : other error
 */
int ipIfStatsTable_pre_request(ipIfStatsTable_registration* user_context)
{
    DEBUGMSGTL(
        ("verbose:ipIfStatsTable:ipIfStatsTable_pre_request", "called\n"));

    /*
     * TODO:510:o: Perform ipIfStatsTable pre-request actions.
     */

    return MFD_SUCCESS;
} /* ipIfStatsTable_pre_request */

/**
 * post-request callback
 *
 * Note:
 *   New rows have been inserted into the container, and
 *   deleted rows have been removed from the container and
 *   released.
 *
 * @param user_context
 * @param rc : MFD_SUCCESS if all requests succeeded
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : other error (ignored)
 */
int ipIfStatsTable_post_request(ipIfStatsTable_registration* user_context,
                                int rc)
{
    DEBUGMSGTL(
        ("verbose:ipIfStatsTable:ipIfStatsTable_post_request", "called\n"));

    /*
     * TODO:511:o: Perform ipIfStatsTable post-request actions.
     */

    return MFD_SUCCESS;
} /* ipIfStatsTable_post_request */

/** @{ */
