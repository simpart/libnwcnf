/**
 * @file lb.h
 * @brief defined load balancer
 * @author simpart
 */
#ifndef __LB_H__
#define __LB_H__

/*** include ***/
#include "protopia.h"


/*** define ***/
#define NCFLB_NAMESIZ 32

/*** struct ***/
typedef struct ncflb_serv {
    uint8_t  addr[PIAIP_IPSIZ];
    uint16_t port;
    char     *url;
    void     *resv;
} ncflb_serv_t;

typedef struct ncflb_group {
    char         name[NCFLB_NAMESIZ];
    ncflb_serv_t vip;
    int          rsrv;
    int          algo;
    int          health;
    void         *resv;
} ncflb_group_t;

#endif
/* end of file */
