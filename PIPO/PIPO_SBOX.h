#ifndef _PIPO_SBOX_H_
#define _PIPO_SBOX_H_

#include "type.h"
static byte Sbox[256] = { 0x5E, 0xF9, 0xFC, 0x00, 0x3F, 0x85, 0xBA, 0x5B, 0x18, 0x37, 0xB2, 0xC6, 0x71, 0xC3, 0x74, 0x9D, 
					0xA7, 0x94, 0x0D, 0xE1, 0xCA, 0x68, 0x53, 0x2E, 0x49, 0x62, 0xEB, 0x97, 0xA4, 0x0E, 0x2D, 0xD0, 
					0x16, 0x25, 0xAC, 0x48, 0x63, 0xD1, 0xEA, 0x8F, 0xF7, 0x40, 0x45, 0xB1, 0x9E, 0x34, 0x1B, 0xF2, 
					0xB9, 0x86, 0x03, 0x7F, 0xD8, 0x7A, 0xDD, 0x3C, 0xE0, 0xCB, 0x52, 0x26, 0x15, 0xAF, 0x8C, 0x69, 
					0xC2, 0x75, 0x70, 0x1C, 0x33, 0x99, 0xB6, 0xC7, 0x04, 0x3B, 0xBE, 0x5A, 0xFD, 0x5F, 0xF8, 0x81, 
					0x93, 0xA0, 0x29, 0x4D, 0x66, 0xD4, 0xEF, 0x0A,0xE5, 0xCE, 0x57, 0xA3, 0x90, 0x2A, 0x09, 0x6C,		
					0x22, 0x11, 0x88, 0xE4, 0xCF, 0x6D, 0x56, 0xAB, 0x7B, 0xDC, 0xD9, 0xBD, 0x82, 0x38, 0x07, 0x7E, 
					0xB5, 0x9A, 0x1F, 0xF3, 0x44, 0xF6, 0x41, 0x30,	0x4C, 0x67, 0xEE, 0x12, 0x21, 0x8B, 0xA8, 0xD5, 
					0x55, 0x6E, 0xE7, 0x0B, 0x28, 0x92, 0xA1, 0xCC, 0x2B, 0x08, 0x91, 0xED, 0xD6, 0x64, 0x4F, 0xA2,
					0xBC, 0x83, 0x06, 0xFA, 0x5D, 0xFF, 0x58, 0x39, 0x72, 0xC5, 0xC0, 0xB4, 0x9B, 0x31, 0x1E, 0x77, 
					0x01, 0x3E, 0xBB, 0xDF, 0x78, 0xDA, 0x7D, 0x84, 0x50, 0x6B, 0xE2, 0x8E, 0xAD, 0x17, 0x24, 0xC9, 
					0xAE, 0x8D, 0x14, 0xE8, 0xD3, 0x61, 0x4A, 0x27, 0x47, 0xF0, 0xF5, 0x19, 0x36, 0x9C, 0xB3, 0x42,
					0x1D, 0x32, 0xB7, 0x43, 0xF4, 0x46, 0xF1, 0x98, 0xEC, 0xD7, 0x4E, 0xAA, 0x89, 0x23, 0x10, 0x65, 
					0x8A, 0xA9, 0x20, 0x54, 0x6F, 0xCD, 0xE6, 0x13, 0xDB, 0x7C, 0x79, 0x05, 0x3A, 0x80, 0xBF, 0xDE, 
					0xE9, 0xD2, 0x4B, 0x2F, 0x0C, 0xA6, 0x95, 0x60, 0x0F, 0x2C, 0xA5, 0x51, 0x6A, 0xC8, 0xE3, 0x96, 
					0xB0, 0x9F, 0x1A, 0x76, 0xC1, 0x73, 0xC4, 0x35, 0xFE, 0x59, 0x5C, 0xB8, 0x87, 0x3D, 0x02, 0xFB };

static byte Sbox_inv[256] = { 0x03, 0xA0, 0xFE, 0x32, 0x48, 0xDB, 0x92, 0x6E, 0x89, 0x5E, 0x57, 0x83, 0xE4, 0x12, 0x1D, 0xE8, 
					0xCE, 0x61, 0x7B, 0xD7, 0xB2, 0x3C, 0x20, 0xAD, 0x08, 0xBB, 0xF2, 0x2E, 0x43, 0xC0, 0x9E, 0x72, 
					0xD2, 0x7C, 0x60, 0xCD, 0xAE, 0x21, 0x3B, 0xB7, 0x84, 0x52, 0x5D, 0x88, 0xE9, 0x1E, 0x17, 0xE3, 
					0x77, 0x9D, 0xC1, 0x44, 0x2D, 0xF7, 0xBC, 0x09, 0x6D, 0x97, 0xDC, 0x49, 0x37, 0xFD, 0xA1, 0x04, 
					0x29, 0x76, 0xBF, 0xC3, 0x74, 0x2A, 0xC5, 0xB8, 0x23, 0x18, 0xB6, 0xE2, 0x78, 0x53, 0xCA, 0x8E, 
					0xA8, 0xEB, 0x3A, 0x16, 0xD3, 0x80, 0x66, 0x5A, 0x96, 0xF9, 0x4B, 0x07, 0xFA, 0x94, 0x00, 0x4D, 
					0xE7, 0xB5, 0x19, 0x24, 0x8D, 0xCF, 0x54, 0x79, 0x15, 0x3F, 0xEC, 0xA9, 0x5F, 0x65, 0x81, 0xD4, 
					0x42, 0x0C, 0x98, 0xF5, 0x0E, 0x41, 0xF3, 0x9F, 0xA4, 0xDA, 0x35, 0x68, 0xD9, 0xA6, 0x6F, 0x33, 
					0xDD, 0x4F, 0x6C, 0x91, 0xA7, 0x05, 0x31, 0xFC, 0x62, 0xCC, 0xD0, 0x7D, 0x3E, 0xB1, 0xAB, 0x27, 
					0x5C, 0x8A, 0x85, 0x50, 0x11, 0xE6, 0xEF, 0x1B, 0xC7, 0x45, 0x71, 0x9C, 0xBD, 0x0F, 0x2C, 0xF1, 
					0x51, 0x86, 0x8F, 0x5B, 0x1C, 0xEA, 0xE5, 0x10, 0x7E, 0xD1, 0xCB, 0x67, 0x22, 0xAC, 0xB0, 0x3D, 
					0xF0, 0x2B, 0x0A, 0xBE, 0x9B, 0x70, 0x46, 0xC2, 0xFB, 0x30, 0x06, 0xA2, 0x90, 0x6B, 0x4A, 0xDE,
					0x9A, 0xF4, 0x40, 0x0D, 0xF6, 0x99, 0x0B, 0x47, 0xED, 0xAF, 0x14, 0x39, 0x87, 0xD5, 0x59, 0x64, 
					0x1F, 0x25, 0xE1, 0xB4, 0x55, 0x7F, 0x8C, 0xC9, 0x34, 0x6A, 0xA5, 0xD8, 0x69, 0x36, 0xDF, 0xA3,		
					0x38, 0x13, 0xAA, 0xEE, 0x63, 0x58, 0xD6, 0x82, 0xB3, 0xE0, 0x26, 0x1A, 0xC8, 0x8B, 0x7A, 0x56, 
					0xB9, 0xC6, 0x2F, 0x73, 0xC4, 0xBA, 0x75, 0x28, 0x4E, 0x01, 0x93, 0xFF, 0x02, 0x4C, 0xF8, 0x95 };

#endif