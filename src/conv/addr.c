/**
 * @file addr.c
 * @brief address config function
 * @author simpart
 */

/*** include ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tetraring.h"
#include "protopia.h"
#include "ncf/com.h"
#include "ncf/conv.h"


int ncfcnv_str2addrv4 (const char *str, ncf_ipv4_t *addr) {
    
    /* check parameter */
    TTRCHK_NULLPRM2(str, addr);
    TTRCHK_STRNLEN(str, NCFCNV_V4IP_STRSIZ);
    
    /* init param */
    TTRMEM_NINIT(addr, sizeof(ncf_ipv4_t));
    
    char buf[NCFCNV_V4IP_STRSIZ] = {0};
    int  num = 0;
    TTR_LOOP_i(NCF_IPV4_ELMCNT) {
        
        TTRMEM_STRINIT(buf);
        ttrstr_split(str, '.', i, buf);
        
        TTRSTR_ATOI(num, buf);
        TTRCHK_LANGE(num, 0, 255);
        
        addr->addr[i] = num;
    }
    
    return NCF_OK;
}
/* end of file */
