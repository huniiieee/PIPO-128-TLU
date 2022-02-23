#include "PIPO_TLU.h"
#include "type.h"
#include "PIPO_SBOX.h"

int main(void) {

	byte Plain[8] = { 0x09,0x85,0x52,0xF6,0x1E,0x27,0x00,0x26 };
	byte Cipher[8] = { 0, };
	byte MasterKey[16] = { 0x6D,0xC4,0x16,0xDD,0x77,0x94,0x28,0xD2,0x7E,0x1D,0x20,0xAD,0x2E,0x15,0x22,0x97 };
	byte Rk[14][8] = { 0, };
	printf("Ciphertext=====");
	Encryption(Plain, Cipher,MasterKey ,Rk);
	for (int i = 0; i < 8; i++)
		printf("%02x ", Cipher[i]);
	printf("\n");
	printf("Plaintext======");
	Decryption(Cipher, Plain, MasterKey, Rk);
	
	for (int i = 0; i < 8; i++)
		printf("%02x ", Plain[i]);
	return 0;
}
