/**
 * @file ctrl.c
 * @brief config getter/setter function
 * @author simpart
 */
/*** include ***/
#include "tetraring.h"
#include "ncf/com.h"
#include "ncf/lb.h"

/*** global ***/
extern int g_ncflb_grpchn;

/*** function ***/
int ncflb_add (ncflb_group_t *grp) {
    
    /* param check */
    __ttrchk_nullprm(grp);
    
    /* init group chain */
    if (TTRCHN_ID_INIT == g_ncflb_grpchn) {
        g_ncflb_grpchn = ttrchn_create();
        __ttrchk_retng(g_ncflb_grpchn);
    }
    
    /* add groupt chain element */
    int ret = ttrchn_add(g_ncflb_grpchn, grp);
    __ttrchk_retng(ret);
    
    return NCF_OK;
}

int ncflb_get (int idx, ncflb_group_t *out) {
    
    /* param check */
    __ttrchk_signprm(idx);
    __ttrchk_nullprm(out);
    
    /* get target element */
    out = (ncflb_group_t *) ttrchn_get(g_ncflb_grpchn, idx);
    __ttrchk_nullval(out, "failed get config");
    
    return NCF_OK;
}

int ncflb_chainid (void) {
    return g_ncflb_grpchn;
}
/* end of file */
