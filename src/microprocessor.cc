#include "microprocessor.hh"

void Microprocessor::clearRegisters(){
	for(int i= 0 ; i< NOF_REG; i++){
		registers[i] = 0;
	}
}

int Microprocessor::step(int address){

	return 0;
}

char Microprocessor::getRegister(REGISTER r){
	return registers[r];
}
