#ifndef MEMORY_HH
#define MEMORY_HH

#define K64 1024*1024*64

class Memory{
	char m[K64];
public:
	void setMemory(char data,int location);
	void setMemory(char *data, int location, int size);
	char getMemory(int location);
	void clearMemory();
};
#endif
