/*
 * Holds the hardware addresses and registers mapped to natural language names.
 * addresses.h
 *
 */

#ifndef INCLUDES_ADDRESSES_H_
#define INCLUDES_ADDRESSES_H_

#define USER_REG    *(unsigned int*) 0x90080000

#define CTL1        *(unsigned int*) 0x01980000
#define HLD         7

#define PRD1        *(unsigned int*) 0x01980004

#define EXT_INT4_EXT_INT7 *(unsigned int*) 0x019C0008 //Ref. TMS320C6713B FLOATING-POINT DIGITAL SIGNAL PROCESSOR, p.19 of 154 , table 6, PDF

#define GPEN        *(unsigned int*) 0x01B00000
#define GPDIR       *(unsigned int*) 0x01B00004
#define GPPOL       *(unsigned int*) 0x01B00024

#define MUXH        *(unsigned int*) 0x019C0000
#define MUXL        *(unsigned int*) 0x019C0004

#define CE3         *(unsigned int*) 0xB0000000
#define TLC1550     *(unsigned int*) 0xB0000400

#endif /* INCLUDES_ADDRESSES_H_ */
