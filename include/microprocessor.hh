#ifndef MICROPROCESSOR_HH
#define MICROPROCESSOR_HH

#define NOF_REG 16

enum REGISTER {
	A, B, C, D, E, H, L
};

enum INSTRUCTION {

};
class Microprocessor {

    char registers[NOF_REG];
    int sp;
    int pc;

public:
	void clearRegisters();
	void setRegister(REGISTER r, char value);
	char getRegister(REGISTER r);
	int step(int address);

	void add(REGISTER r);
	void add(int memory);

	void adc(REGISTER r);
	void adc(int memory);

	void adi(char data);
	void aci(char data);
	void dad(REGISTER pair);

	void sub(REGISTER r);
	void sub(int memory);

	void sbb(REGISTER r);
	void sbb(int memory);

	void sui(char data);
	void sbi(char data);

	void inr(REGISTER r);
	void inr(int address);

	void jmp(int );

	void mov(REGISTER d, REGISTER s);
	void mov(REGISTER d, int mem);
	void mov(int mem, REGISTER s);

	void mvi(REGISTER d, int data);
	void lda(int address);
	void ldax(REGISTER pair);
	void lxi(REGISTER pair, int data);
	void ldhd(int address);
	void sta(int address);
	void stax(REGISTER pair);
	void shld(int address);
	void xchg();
	void sphl();
	void xthl();
	void push(REGISTER pair);
	void pop(REGISTER pair);
	void out(char address);
	void in(char address);
};

#endif
