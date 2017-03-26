#include "cvs_student.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argn, char* argv[]){
	int num = 2;
	// 初始化数组
	cvs_student* student_list;
	student_list = new cvs_student[num];
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].get_student_from_stdin();		
	}
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].show_student_to_stout();	
		std::cout << "this is new" << std::endl;
	}
	
	// 转化成大端
	cvs_student* student_list_out;
	student_list_out = new cvs_student[num];
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].convert_le_be(student_list_out[stu_i]);	
	}
	
	// 写入文件
	int outf = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC, 0600);
	write(outf, student_list_out, sizeof(cvs_student)*num );
    close(outf);
	
	// 读取文件
	int inf = open(argv[1], O_RDONLY, 0),i;
    i = read(inf, student_list, sizeof(cvs_student)*num);
    close(inf);
	
	// 转化成小端并输出
	for(int stu_i = 0; stu_i <  num; stu_i ++){
		student_list[stu_i].convert_le_be(student_list_out[stu_i]);	
		student_list_out[stu_i].show_student_to_stout();	
		
		std::cout << "this is new" << std::endl;
	}
	
	return 0;
}