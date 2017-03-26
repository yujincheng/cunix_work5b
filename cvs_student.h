#include <stdint.h>
#include <iostream>

class cvs_student{
public:	
	uint64_t ID;
	char Name[128];
	char Department[32];
	uint8_t Age;
	void set_student(uint64_t,char*,char*,uint8_t);
	int get_student_from_stdin();
	void show_student_to_stout();
};

void le2be(void* input,void* output,int size);
