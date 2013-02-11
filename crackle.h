#ifndef __CRACKLE_H__
#define __CRACKLE_H__

#include <stdint.h>

typedef struct _crackle_state_t {
    int connect_found;
    int preq_found;
    int pres_found;
    int confirm_found;
    int random_found;
    int enc_req_found;
    int enc_rsp_found;

    // field from connect packet
    uint8_t ia[6], ra[6];
    int iat, rat;

    uint8_t preq[7];
    uint8_t pres[7];

    uint8_t mconfirm[16], sconfirm[16];
    uint8_t mrand[16], srand[16];

    // encryption request fields
    uint8_t rand[8];
    uint8_t ediv[2];
    uint8_t skdm[8];
    uint8_t ivm[4];

    // encryption response fields
    uint8_t skds[8];
    uint8_t ivs[4];

    uint8_t tk[16];
    uint8_t stk[16];
    uint8_t session_key[16];
} crackle_state_t;

void calc_stk(crackle_state_t *state, uint32_t numeric_key);
void calc_session_key(crackle_state_t *state);

#endif /* __CRACKLE_H__ */
