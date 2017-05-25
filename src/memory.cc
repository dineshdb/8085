#include "memory.hh"

void Memory::clearMemory(){
	for(int i = 0 ; i < K64; i++){
		m[i] = 0;
	}
}

void Memory::setMemory(char data, int location){
	m[location] = data;
}

void Memory::setMemory(char *data, int location, int size){
	for(int i=0; i < size; i++){
		m[location+i] = data[i];
	}
}
char Memory::getMemory(int location){
	return m[location];
}
