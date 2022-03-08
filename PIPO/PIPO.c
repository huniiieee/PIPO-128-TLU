#include "PIPO.h"

void Keyadd(byte* state, byte* Rk)
{
	state[0] ^= Rk[0];
	state[1] ^= Rk[1];
	state[2] ^= Rk[2];
	state[3] ^= Rk[3];
	state[4] ^= Rk[4];
	state[5] ^= Rk[5];
	state[6] ^= Rk[6];
	state[7] ^= Rk[7];
}
void convert(byte* state)
{
	int i, j;
	byte T[8] = { 0, };
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			T[i] |= (((state[j] & (1 << (7-i))) >> (7-i)) << (7-j));

	for (i = 0; i < 8; i++)
		state[i] = T[i];
}
void SLayer_TLU(byte* state)
{
	convert(state);
	state[0] = Sbox[state[0]];
	state[1] = Sbox[state[1]];
	state[2] = Sbox[state[2]];
	state[3] = Sbox[state[3]];
	state[4] = Sbox[state[4]];
	state[5] = Sbox[state[5]];
	state[6] = Sbox[state[6]];
	state[7] = Sbox[state[7]];
	convert(state);
}

void Inv_SLayer_TLU(byte* state)
{
	convert(state);
	state[0] = Sbox_inv[state[0]];
	state[1] = Sbox_inv[state[1]];
	state[2] = Sbox_inv[state[2]];
	state[3] = Sbox_inv[state[3]];
	state[4] = Sbox_inv[state[4]];
	state[5] = Sbox_inv[state[5]];
	state[6] = Sbox_inv[state[6]];
	state[7] = Sbox_inv[state[7]];
	convert(state);
}

void SLayer_BS(byte* state)
{
	byte T[3] = { 0, };
	state[2] ^= (state[0] & state[1]);
	state[3] ^= (state[4] & state[2]);
	state[0] ^= state[3];
	state[1] ^= state[4];
	state[4] ^= (state[3] | state[2]);
	state[2] ^= state[0];
	state[3] ^= (state[2] & state[1]);

	state[5] ^= state[6] & state[7];
	state[7] ^= state[5] | state[6];
	state[6] ^= state[5] | state[7];
	state[5] = ~state[5];

	// Extend XOR
	 state[0] ^= state[6]; state[4] ^= state[5]; state[3] ^= state[7];
	
	 //S5_2
	T[0] = state[0]; T[1] = state[4]; T[2] = state[3];
	state[1] ^= (T[0] & state[2]);
	T[0] ^= state[1];
	state[1] ^= (T[2] | T[1]);
	T[1] ^= state[2];
	state[2] ^= (state[1] | T[2]);
	T[2] ^= (T[1] & T[0]);
	// truncate XOR and swap
	state[5] ^= T[0]; T[0] = state[6] ^ T[2]; state[6] = state[7] ^ T[1];
	state[7] = state[0]; state[0] = T[0];
	T[1] = state[4]; state[4] = state[1]; state[1] = T[1];
	T[2] = state[3]; state[3] = state[2]; state[2] = T[2];

}
void Inv_SLayer_BS(byte* state)
{
	byte T[3] = { 0, };

	T[0] = state[0]; state[0] = state[7]; state[7] = state[6]; state[6] = T[0];
	T[0] = state[0]; T[1] = state[1]; T[2] = state[2];

	state[3] ^= (state[4] | T[2]);
	state[4] ^= (T[2] | T[1]);
	T[1] ^= state[3];
	T[0] ^= state[4];
	T[2] ^= (T[1] & T[0]);
	state[4] ^= (state[3] & state[0]);


	 state[7] ^= T[1]; state[6] ^= T[2]; state[5] ^= T[0];
	T[0] = state[4]; state[4] = state[1]; state[1] = T[0];
	T[0] = state[2]; state[2] = state[3]; state[3] = T[0];

	
	 state[0] ^= state[6]; state[4] ^= state[5]; state[3] ^= state[7];

	
	state[3] ^= (state[2] & state[1]);
	state[2] ^= state[0];
	state[4] ^= (state[3] | state[2]);
	state[1] ^= state[4];
	state[0] ^= state[3];
	state[3] ^= (state[4] & state[2]);
	state[2] ^= (state[0] & state[1]);

	state[5] = ~state[5];
	state[6] ^= state[5] | state[7];
	state[7] ^= state[5] | state[6];
	state[5] ^= state[6] & state[7];
}
void RLayer(byte* state)
{
	state[6] = (state[6] << 7) | (state[6] >> 1);
	state[5] = (state[5] << 4) | (state[5] >> 4);
	state[4] = (state[4] << 3) | (state[4] >> 5);
	state[3] = (state[3] << 6) | (state[3] >> 2);
	state[2] = (state[2] << 5) | (state[2] >> 3);
	state[1] = (state[1] << 1) | (state[1] >> 7);
	state[0] = (state[0] << 2) | (state[0] >> 6);
}

void Inv_RLayer(byte* state)
{
	state[6] = (state[6] << 1) | (state[6] >> 7);
	state[5] = (state[5] << 4) | (state[5] >> 4);
	state[4] = (state[4] << 5) | (state[4] >> 3);
	state[3] = (state[3] << 2) | (state[3] >> 6);
	state[2] = (state[2] << 3) | (state[2] >> 5);
	state[1] = (state[1] << 7) | (state[1] >> 1);
	state[0] = (state[0] << 6) | (state[0] >> 2);
}

void KeySchedule(byte* Masterkey, byte Rk[14][8])
{
	for (int i = 0; i <=ROUND; i++)
	{
		for (int j = 0; j < 8; j++)
			Rk[i][j] = Masterkey[8 * (1 - (i % 2)) + j];
		
		Rk[i][7] ^= i;
	}

}

void Encryption(byte* Plain, byte* Cipher,byte*MasterKey)
{
	byte Rk[14][8] = { 0, };
	KeySchedule(MasterKey, Rk);
	for (int i = 0; i < ROUND; i++)
	{
		Keyadd(Plain, Rk[i]);
		SLayer_BS(Plain);
		RLayer(Plain);
	}

	Keyadd(Plain, Rk[ROUND]);
	memcpy(Cipher, Plain, 8);
}

void Decryption(byte* Cipher, byte* Plain, byte* MasterKey)
{
	byte Rk[14][8] = { 0, };
	KeySchedule(MasterKey, Rk);
	for (int i = ROUND; i >0; i--)
	{
		Keyadd(Cipher, Rk[i]);
		Inv_RLayer(Cipher);
		Inv_SLayer_BS(Cipher);
	}
	Keyadd(Cipher, Rk[0]);
	memcpy(Plain, Cipher, 8);
}