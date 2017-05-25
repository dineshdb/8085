#ifndef MICROPROCESSOR_HH
#define MICROPROCESSOR_HH

#define NOF_REG 16

enum REGISTER {
	A, B, C, D, E, H, L, SP, PC
};

enum INSTRUCTION {

}
class Microprocessor {

    char registers[NOF_REG];

public:
	void clearRegisters();
	void setRegister(char name, char value);
	int execute(int address);
};

#endif
