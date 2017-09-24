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

// SDRAM memory address corresponding to 0x80000000 to 0x8FFFFFFF (which is entirely the EMIF CE0 (according to DSK datasheet Ref. p. 13 of 52 PDF)
#define SDRAM_BEGIN        *(unsigned int*) 0x80000000
#define SDRAM_END        *(unsigned int*) 0x8FFFFFFF

#endif /* INCLUDES_ADDRESSES_H_ */
