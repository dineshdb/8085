#include "memory.hh"

void Memory::clearMemory(){
	for(int i = 0 ; i < K64; i++){
		m[i] = 0;
	}
}
