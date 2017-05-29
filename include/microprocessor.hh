#ifndef MICROPROCESSOR_HH
#define MICROPROCESSOR_HH

#define NOF_REG 12

#include <functional>
#include "memory.hh"
#include "typedef.hh"

enum REGISTER {};

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

    i8 A;
    union {
	struct {
		bool carry:1;
		bool parity:1;
		bool aux_carry:1;
		bool zero:1;
		bool sign:1;
	};
	i8 psw;
    };
    union {
    	struct {
    	    i8 B;
    	    i8 C;
    	};
	i16 BC;
    };
    union {
    	struct {
    	    i8 D;
    	    i8 E;
    	};
	i16 DE;
    };
    union {
    	struct {
    	    i8 H;
    	    i8 L;
    	};
	i16 HL;
    };
    i16 sp;	// Stack Pointer
    i16 pc;	// Program Counter
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
