/**
 * @file lb.h
 * @brief defined load balancer
 * @author simpart
 */
#ifndef __NCFLB_H__
#define __NCFLB_H__

/*** include ***/
#include "protopia.h"


/*** define ***/
#define NCFLB_NAMESIZ 32

/*** struct ***/
typedef struct ncflb_listen {
    uint8_t  addr[PIAIP_IPSIZ];
    uint16_t port;
    char     *url;
    void     *resv;
} ncflb_listen_t;

typedef struct ncflb_group {
    char           name[NCFLB_NAMESIZ];
    ncflb_listen_t listen;
    int            rsrv;
    int            algo;
    int            health;
    void           *resv;
} ncflb_group_t;


/*** prototype ***/
/* startend.c */
int ncflb_init  (ncflb_group_t *);
int ncflb_close (void);

/* ctrl.c */
int ncflb_add   (ncflb_group_t *);
int ncflb_get   (int, ncflb_group_t *);
int ncflb_chainid (void);

#endif
/* end of file */
