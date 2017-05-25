#include "microprocessor.hh"

void Microprocessor::clearRegisters(){
	for(int i= 0 ; i< NOF_REG; i++){
		registers[i] = 0;
	}
}

int Microprocessor::step(){
	int opcode = m->getMemory(pc);

	return 0;
}

char Microprocessor::getRegister(REGISTER r){
	return registers[r];
}

bool Microprocessor::getFlag(FLAG_BITS f){
	return registers[PSW] ^ f;
}

void Microprocessor::setFlag(FLAG_BITS f){
	registers[PSW] |= f;
}

void Microprocessor::clearFlag(FLAG_BITS f){
	registers[PSW] &= ~f;
}

void Microprocessor::clearFlags(){
	registers[PSW] = 0;
}

void Microprocessor::setProgramCounter(int location){
	pc = location;
}
