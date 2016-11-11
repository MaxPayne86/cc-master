#ifndef CC_ASSIGNMENT_H
#define CC_ASSIGNMENT_H


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

#define CC_MODE_TOGGLE  0x01
#define CC_MODE_TRIGGER 0x02


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

typedef struct cc_assignment_t {
    int device_id, actuator_id;
    float value, min, max, def;
    uint32_t mode;
} cc_assignment_t;

typedef struct cc_unassignment_t {
    int device_id, assignment_id;
} cc_unassignment_t;


/*
****************************************************************************************************
*       FUNCTION PROTOTYPES
****************************************************************************************************
*/

int cc_assignment_add(cc_assignment_t *assignment);
void cc_assignment_remove(cc_unassignment_t *unassignment);


/*
****************************************************************************************************
*       CONFIGURATION ERRORS
****************************************************************************************************
*/


#endif
