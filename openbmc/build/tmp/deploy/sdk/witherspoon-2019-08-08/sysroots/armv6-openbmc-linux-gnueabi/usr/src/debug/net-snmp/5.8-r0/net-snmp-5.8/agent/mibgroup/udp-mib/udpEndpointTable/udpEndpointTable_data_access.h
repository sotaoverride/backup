/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $
 *
 * $Id$
 */
#ifndef UDPENDPOINTTABLE_DATA_ACCESS_H
#define UDPENDPOINTTABLE_DATA_ACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 *********************************************************************
 * function declarations
 */

/*
 *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table udpEndpointTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * UDP-MIB::udpEndpointTable is subid 7 of udp.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.7.7, length: 8
 */

int udpEndpointTable_init_data(
    udpEndpointTable_registration* udpEndpointTable_reg);

/*
 * TODO:180:o: Review udpEndpointTable cache timeout.
 * The number of seconds before the cache times out
 */
#define UDPENDPOINTTABLE_CACHE_TIMEOUT 60

void udpEndpointTable_container_init(netsnmp_container** container_ptr_ptr,
                                     netsnmp_cache* cache);
void udpEndpointTable_container_shutdown(netsnmp_container* container_ptr);

int udpEndpointTable_container_load(netsnmp_container* container);
void udpEndpointTable_container_free(netsnmp_container* container);

int udpEndpointTable_cache_load(netsnmp_container* container);
void udpEndpointTable_cache_free(netsnmp_container* container);

int udpEndpointTable_row_prep(udpEndpointTable_rowreq_ctx* rowreq_ctx);

#ifdef __cplusplus
}
#endif
#endif /* UDPENDPOINTTABLE_DATA_ACCESS_H */
