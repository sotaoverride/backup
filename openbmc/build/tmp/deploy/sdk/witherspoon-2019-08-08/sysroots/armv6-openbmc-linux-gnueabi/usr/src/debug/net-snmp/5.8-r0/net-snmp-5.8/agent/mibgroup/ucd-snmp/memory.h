/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.9 2005/01/07 09:37:18 dts12 Exp $
 */
#ifndef MEMORY_H
#define MEMORY_H

config_require(hardware / memory)

    /*
     * function declarations
     */
    void init_memory(void);
void memory_parse_config(const char* token, char* cptr);
void memory_free_config(void);
Netsnmp_Node_Handler handle_memory;

#define MEMORY_INDEX 1
#define MEMORY_ERRNAME 2
#define MEMORY_SWAP_TOTAL 3
#define MEMORY_SWAP_AVAIL 4
#define MEMORY_REAL_TOTAL 5
#define MEMORY_REAL_AVAIL 6
#define MEMORY_STXT_TOTAL 7
#define MEMORY_STXT_AVAIL 8 /* Deprecated */
#define MEMORY_RTXT_TOTAL 9
#define MEMORY_RTXT_AVAIL 10 /* Deprecated */
#define MEMORY_FREE 11
#define MEMORY_SWAP_MIN 12
#define MEMORY_SHARED 13
#define MEMORY_BUFFER 14
#define MEMORY_CACHED 15
#define MEMORY_STXT_USED 16
#define MEMORY_RTXT_USED 17
#define MEMORY_SWAP_TOTAL_X 18
#define MEMORY_SWAP_AVAIL_X 19
#define MEMORY_REAL_TOTAL_X 20
#define MEMORY_REAL_AVAIL_X 21
#define MEMORY_FREE_X 22
#define MEMORY_SWAP_MIN_X 23
#define MEMORY_SHARED_X 24
#define MEMORY_BUFFER_X 25
#define MEMORY_CACHED_X 26
#define MEMORY_SWAP_ERROR 100
#define MEMORY_SWAP_ERRMSG 101
#endif /* MEMORY_H */
