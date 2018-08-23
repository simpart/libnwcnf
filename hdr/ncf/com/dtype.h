/**
 * @file dtype.h
 * @brief defined common data type
 * @author simpart
 */
#ifndef __TYPE_H__
#define __TYPE_H__

/*** include ***/
#include "tetraring.h"

/*** define ***/
#define NCF_IPV4_ELMCNT 4

/*** struct ***/
typedef struct ncfdtp_ipv4 {
    uchar addr[NCF_IPV4_ELMCNT];
} ncf_ipv4_t;


/*** prototype ***/


#endif
/* end of file */
