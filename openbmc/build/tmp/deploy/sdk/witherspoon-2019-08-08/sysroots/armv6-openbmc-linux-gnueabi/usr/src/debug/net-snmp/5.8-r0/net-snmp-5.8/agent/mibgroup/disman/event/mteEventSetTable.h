/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.table_data.conf,v 1.8 2005/07/19 14:52:03 dts12 Exp $
 */
#ifndef MTEEVENTSETTABLE_H
#define MTEEVENTSETTABLE_H

/*
 * function declarations
 */
void init_mteEventSetTable(void);
void shutdown_mteEventSetTable(void);
Netsnmp_Node_Handler mteEventSetTable_handler;

/*
 * column number definitions for table mteEventSetTable
 */
#define COLUMN_MTEEVENTSETOBJECT 1
#define COLUMN_MTEEVENTSETOBJECTWILDCARD 2
#define COLUMN_MTEEVENTSETVALUE 3
#define COLUMN_MTEEVENTSETTARGETTAG 4
#define COLUMN_MTEEVENTSETCONTEXTNAME 5
#define COLUMN_MTEEVENTSETCONTEXTNAMEWILDCARD 6
#endif /* MTEEVENTSETTABLE_H */
