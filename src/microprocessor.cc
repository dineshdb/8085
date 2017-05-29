#include "microprocessor.hh"

int Microprocessor::step(){
	int opcode = m->getMemory(pc);
	return 0;
}

void Microprocessor::clearFlags(){
	psw = 0;
}

void Microprocessor::setProgramCounter(int location){
	pc = location;
}
