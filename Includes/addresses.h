/*
 * Holds the hardware addresses and registers mapped to natural language names.
 * addresses.h
 *
 */

#ifndef INCLUDES_ADDRESSES_H_
#define INCLUDES_ADDRESSES_H_

#define USER_REG    *(unsigned int*) 0x90080000

// Timer config registers
#define CTL0        *(unsigned int*) 0x01940000
#define CTL1        *(unsigned int*) 0x01980000
#define HLD         7
// Timer period registers
#define PRD0        *(unsigned int*) 0x01940004
#define PRD1        *(unsigned int*) 0x01980004



#define EXT_INT4_EXT_INT7 *(unsigned int*) 0x019C0008 //Ref. TMS320C6713B FLOATING-POINT DIGITAL SIGNAL PROCESSOR, p.19 of 154 , table 6, PDF

#define GPEN        *(unsigned int*) 0x01B00000
#define GPDIR       *(unsigned int*) 0x01B00004
#define GPPOL       *(unsigned int*) 0x01B00024

#define MUXH        *(unsigned int*) 0x019C0000
#define MUXL        *(unsigned int*) 0x019C0004

// SDRAM memory address corresponding to 0x80000000 to 0x8FFFFFFF (which is entirely the EMIF CE0 (according to DSK datasheet Ref. p. 13 of 52 PDF)
#define SDRAM_BEGIN        *(unsigned short*) 0x80000000
#define SDRAM_END        *(unsigned short*) 0x8FFFFFFF

// EMIF registers for ADC
#define CECTL3      *(unsigned int*) 0x01800014
#define WRSETUP     28
#define WRSTRB      22
#define WRHLD       20
#define RDSETUP     16
#define RDSTRB      8
#define MTYPE       4
#define RDHLD       0
#define CE3         *(unsigned int*) 0xB0000000
// The first 3584 KB of CE3 are reserved for future growth
// 3584 * 1024 = 3 670 016 = 0x380000
#define FAULT_ADDR  *(unsigned int*) 0xB0300000
#define TLC1550     *(unsigned int*) 0xB0380000

#endif /* INCLUDES_ADDRESSES_H_ */
