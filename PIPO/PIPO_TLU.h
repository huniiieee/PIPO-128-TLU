#ifndef _PIPO_TLU_H_
#define _PIPO_TLU_H_

#include "type.h"
#include "PIPO_SBOX.h"

void Keyadd(byte* state, byte* Rk);
void convert(byte* state);
void SLayer(byte* state);
void RLayer(byte* state);
void KeySchedule(byte* Masterkey, byte Rk[14][8]);
void Encryption(byte* Plain, byte* Cipher, byte* MasterKey, byte Rk[14][8]);
void Inv_SLayer(byte* state);
void Inv_RLayer(byte* state);
void Decryption(byte* Cipher, byte* Plain, byte* MasterKey, byte Rk[14][8]);

#endif