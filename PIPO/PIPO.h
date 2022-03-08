#ifndef _PIPO_H_
#define _PIPO_H_

#include "type.h"
#include "PIPO_SBOX.h"

void Keyadd(byte* state, byte* Rk);
void convert(byte* state);
void SLayer_TLU(byte* state);
void SLayer_BS(byte* state);
void RLayer(byte* state);
void KeySchedule(byte* Masterkey, byte Rk[14][8]);
void Encryption(byte* Plain, byte* Cipher, byte* MasterKey);
void Inv_SLayer_TLU(byte* state);
void Inv_SLayer_BS(byte* state);
void Inv_RLayer(byte* state);
void Decryption(byte* Cipher, byte* Plain, byte* MasterKey);

#endif