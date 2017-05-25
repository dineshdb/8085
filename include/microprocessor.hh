#ifndef MICROPROCESSOR_HH
#define MICROPROCESSOR_HH

#define NOF_REG 12

#include <functional>
#include "memory.hh"
#include "typedef.hh"

enum REGISTER {
	A, PSW, B, C, D, E, H, L
};

enum FLAG_BITS {
	CARRY = 	0b00000001,
	PARITY =	0b00000100,
	AUX_CARRY=	0b00010000,
	ZERO =		0b01000000,
	SIGN=		0b10000000,
};

enum MNEMONIC {
// Arithmetic
	ADD,
	ADC,
	ADI,
	ACI,
	LXI,
	DAD,
	SUB,
	SBB,
	SUI,
	SBI,
	INR,
	INX,
	DCR,
	DCX,
	DAA,
// Branching
	JMP,
	JC,
	JNC,
	JP,
	JM,
	JZ,
	JNZ,
	JPE,
	JPO,

	CC,
	CNC,
	CP,
	CM,
	CZ,
	CNZ,
	CPE,
	CPO,
	RET,
	RC,
	RNC,
	RP,
	RM,
	RZ,
	RNZ,
	RPE,
	RPO,
	PCHL,
	RST,

// Control Instructions
	NOP,
	HLT,
	DI,
	EI,
	RIM,
	SIM,

// DATA TRANSFER
	MOV,
	MVI,
	LDA,
	LDAX,
	LHLD,
	STA,
	STAX,
	SHLD,
	XCHG,
	SPHL,
	XTHL,
	PUSH,
	POP,
	OUT,
	IN,

// lOGITCAL
	CMP,
	CPI,
	ANA,
	ANI,
	XRA,
	XRI,
	ORA,
	ORI,
	RLC,
	RRC,
	RAL,
	RAR,
	CMA,
	CMC,
	STC
};
class Microprocessor {
    Memory *m;

    i8 registers[NOF_REG];
    int sp;	// Stack Pointer
    int pc;	// Program Counter
    int mp;	// Memory Pointer
    int ic;	// Instruction Counter
    int cc;	// Clock Cycle Counter

public:
	void setMemory(Memory *mem){
		m = mem;
	}
	void clearRegisters();
	void setRegister(REGISTER r, i8 value);
	i8 getRegister(REGISTER r);
	void setProgramCounter(int location);
	int step();
	bool getFlag(FLAG_BITS f);
	void setFlag(FLAG_BITS f);
	void clearFlag(FLAG_BITS f);
	void clearFlags();

	void add(REGISTER r);
	void add(i16 memory);

	void adc(REGISTER r);
	void adc(i16 memory);

	void adi(i8 data);
	void aci(i8 data);
	void dad(REGISTER pair);

	void sub(REGISTER r);
	void sub(i16 memory);

	void sbb(REGISTER r);
	void sbb(i16 memory);

	void sui(i8 data);
	void sbi(i8 data);

	void inr(REGISTER r);
	void inr(i16 address);

	void jmp(i16 );

	void mov(REGISTER d, REGISTER s);
	void mov(REGISTER d, i16 mem);
	void mov(i16 mem, REGISTER s);

	void mvi(REGISTER d, i16 data);
	void lda(i16 address);
	void ldax(REGISTER pair);
	void lxi(REGISTER pair, i16 data);
	void ldhd(i16 address);
	void sta(i16 address);
	void stax(REGISTER pair);
	void shld(i16 address);
	void xchg();
	void sphl();
	void xthl();
	void push(REGISTER pair);
	void pop(REGISTER pair);
	void out(i8 address);
	void in(i8 address);
};

#endif
