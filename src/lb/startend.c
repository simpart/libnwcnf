/**
 * @file startend.c
 * @brief start, end process for lb function
 * @author simpart
 */
/*** include ***/
#include <string.h>
#include "tetraring.h"
#include "ncf/com.h"
#include "ncf/lb.h"

/*** global ***/
int g_ncflb_grpchn = TTRCHN_ID_INIT;

/*** function ***/
int ncflb_init (ncflb_group_t *grp) {
    
    /* param check */
    __ttrchk_nullprm(grp);
    
    memset(grp, 0x00, sizeof(ncflb_group_t));
    
    /* init group chain */
    if (TTRCHN_ID_INIT == g_ncflb_grpchn) {
        g_ncflb_grpchn = ttrchn_create();
        __ttrchk_retng(g_ncflb_grpchn);
    }
    
    /* init real server chain */
    grp->rsrv = ttrchn_create();
    __ttrchk_retng(grp->rsrv);
    
    return NCF_OK;
}

int ncflb_close (void) {
    ncflb_group_t *grp = NULL;
    
    if (TTRCHN_ID_INIT != g_ncflb_grpchn) {
        
        __ttrchn_loop_chain (g_ncflb_grpchn) {
            
            /* get chain contents */
            grp = (ncflb_group_t *) chain->conts;
            __ttrchk_nullval(grp, "chian contents is null");
            
            /* close real server chain */
            if (TTRCHN_ID_INIT != grp->rsrv) {
                ttrchn_free(grp->rsrv);
            }
            
        }
        
        /* close group chain */
        ttrchn_free(g_ncflb_grpchn);
    }
    
    return NCF_OK;
}
/* end of file */
