/************************************************************************************************************
 *  fifo.h
 *  First_Term_project C
 *  Created on: ٠٣‏/٠٩‏/٢٠٢٢
 *  Author: Abdullah Kortam
 ***********************************************************************************************************/
#ifndef FIFO_H_
#define FIFO_H_
//DataBase of each student
struct  sinfo
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int NoCourse ;
	int cid[5];
};
//queue implementation
struct  fifo
{
	struct sinfo* p ;
	struct fifo* next ;
};

typedef enum
{
	student_successfully,
	student_failed
}status;
//APOI
void add_student_file();
void add_student_manually();			//DONE
void find_rl();							//DONE
void find_fn();							//DONE
void find_c();							//DONE
void tot_S();							//DONE
void del_s();							//DONE
void up_s();							//DONE
void show_s();							//DONE
//PERIPHERALS
status rollcheck(int x);				//DONE
status fillstr();						//DONE
struct fifo* file_handle();				//DONE
status duplicate(int x);				//DONE
#endif /* FIFO_H_ */
