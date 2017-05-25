#ifndef SIMULATOR_HH
#define SIMULATOR_HH

#include "microprocessor.hh"
#include "memory.hh"

class Simulator{
    Microprocessor p;
    Memory m;

public:
	void clearMemory();
	void clearRegisters();
	void go();
	void pause();
	void resume();
	void step();
};
#endif
