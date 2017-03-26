#include "cvs_student.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int num = 2;
	cvs_student* student_list;
	student_list = new cvs_student[num];
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].get_student_from_stdin();		
	}
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].show_student_to_stout();	
		std::cout << "this is new" << std::endl;
	}
	return 0;
}