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
    __ttrchk_nullprm2(str, addr);
    __ttrchk_strnlen(str, NCFCNV_V4IP_STRSIZ);
    
    /* init param */
    __ttrmem_ninit(addr, sizeof(ncf_ipv4_t));
    
    char buf[NCFCNV_V4IP_STRSIZ] = {0};
    int  num = 0;
    __ttr_loop_i(NCF_IPV4_ELMCNT) {
        
        __ttrmem_strinit(buf);
        ttrstr_split(str, '.', i, buf);
        
        __ttrstr_atoi(num, buf);
        __ttrchk_lange(num, 0, 255);
        
        addr->addr[i] = num;
    }
    
    return NCF_OK;
}
/* end of file */
