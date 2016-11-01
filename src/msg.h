#ifndef CC_MSG_H
#define CC_MSG_H


/*
****************************************************************************************************
*       INCLUDE FILES
****************************************************************************************************
*/

#include <stdint.h>


/*
****************************************************************************************************
*       MACROS
****************************************************************************************************
*/

#define CC_MSG_HEADER_SIZE  4


/*
****************************************************************************************************
*       CONFIGURATION
****************************************************************************************************
*/


/*
****************************************************************************************************
*       DATA TYPES
****************************************************************************************************
*/

// commands definition
enum cc_cmd_t {CC_CMD_CHAIN_SYNC, CC_CMD_HANDSHAKE, CC_CMD_DEV_DESCRIPTOR, CC_CMD_ASSIGNMENT,
               CC_CMD_DATA_UPDATE, CC_CMD_UNASSIGNMENT};

// fields names and sizes in bytes
// DEV_ADDRESS (1), COMMAND (1), DATA_SIZE (2), DATA (N), CHECKSUM (1)

typedef struct cc_msg_t {
    uint8_t dev_address;
    uint8_t command;
    uint16_t data_size;
    uint8_t *header, *data;
} cc_msg_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

cc_msg_t *cc_msg_new(void);
void cc_msg_delete(cc_msg_t *msg);
void* cc_msg_parser(const cc_msg_t *msg);
void cc_msg_builder(int command, const void *data_struct, cc_msg_t *msg);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
