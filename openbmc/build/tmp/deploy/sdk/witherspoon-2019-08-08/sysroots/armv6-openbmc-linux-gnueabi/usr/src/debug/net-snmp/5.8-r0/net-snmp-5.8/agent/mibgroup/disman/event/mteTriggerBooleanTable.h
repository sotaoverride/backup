/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.table_data.conf,v 1.8 2005/07/19 14:52:03 dts12 Exp $
 */
#ifndef MTETRIGGERBOOLEANTABLE_H
#define MTETRIGGERBOOLEANTABLE_H

/*
 * function declarations
 */
void init_mteTriggerBooleanTable(void);
void shutdown_mteTriggerBooleanTable(void);
Netsnmp_Node_Handler mteTriggerBooleanTable_handler;

/*
 * column number definitions for table mteTriggerBooleanTable
 */
#define COLUMN_MTETRIGGERBOOLEANCOMPARISON 1
#define COLUMN_MTETRIGGERBOOLEANVALUE 2
#define COLUMN_MTETRIGGERBOOLEANSTARTUP 3
#define COLUMN_MTETRIGGERBOOLEANOBJECTSOWNER 4
#define COLUMN_MTETRIGGERBOOLEANOBJECTS 5
#define COLUMN_MTETRIGGERBOOLEANEVENTOWNER 6
#define COLUMN_MTETRIGGERBOOLEANEVENT 7
#endif /* MTETRIGGERBOOLEANTABLE_H */
