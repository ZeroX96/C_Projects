/*
 ============================================================================
 Name        : testing.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Includes.h"
/*
#define SIGN_IN 	'I'
#define SIGN_UP 	'U'
#define SYS_MANAGE 	'M'
#define SYS_EXIT	'E'
msa aaa mmm 0 123 321 543.954 0
asd aas sad 1 321 312 231.456 1
sss saa dcz 2 111 123 421.736 2
aaa sas asd 3 222 132 412.264 3
dsa ssa xzs 4 333 333 324.214 4

*/
int main()
{
	uint8_t choice=0;

file_cfg_t file_input;
file_input.file_init_state=false;	//globals are automatically zeroed
file_cfg_t file_output;
file_output.file_init_state=false; //globals are automatically zeroed
list_t list_system;

	SysInit(&file_input,&file_output,&list_system,"GrBaSy_in.txt","GrBaSy_ou.txt",56);
	while(1)
	{
	    SysBegin();
	    fflush(stdin);
		scanf("%c",&choice);
		if(choice == SIGN_IN)
		{
			SysSignIn(&list_system);
		}
		else if(choice == SIGN_UP)
		{
			SysSignUp(&list_system);
		}
		else if(choice == SYS_MANAGE)
		{
			SysManage(&list_system);
		}
		else if(choice == SYS_EXIT)
		{
			break;
		}
		else
		{
			printf("**->WRONG CHOICE :(\n");
			SysDelay();
		    system("CLS");
		}
	}
	SysEnd();
	SysDeInit(&file_input,&file_output,&list_system,"GrBaSy_in.txt","GrBaSy_ou.txt",56);
	//c close the cmd
	return 0;
}
#if 0       //testing..............
int main(void) {

	list_t list_test_1;
	char m=ListCreate(&list_test_1);
    printf("=list created %d \n",m==LAB_NO_ERRORS);

	file_cfg_t file_test_out;
	file_test_out.file_init_state=false;
	file_cfg_t file_test_in;
	file_test_in.file_init_state=false;
	//char file_name_test[MAX_FILE_NAME]="GrBaSy2.txt";
	//strcpy(file_test_out.file_name_obj,file_name_test);
/*
//Hash Defines FOR FILE OPENING MODES   to be used as opening modes
		#define R       "r"      //Open an existing file for reading.
		#define W       "w"      //Create a file for writing. If the file already exists, discard the current contents.
		#define A       "a"      //Append: open or create a file for writing at the end of the file.
		#define R_PLUS  "r+"     //Open an existing file for update (reading and writing).
		#define W_PLUS  "w+"     //Create a file for update. If the file already exists, discard the current contents.
		#define A_PLUS  "a+"     //Append: open or create a file for update; writing is done at the end of the file.
		#define RB      "rb"     //Open an existing file for reading in binary mode.
		#define WB      "wb"     //Create a file for writing in binary mode. If the file already exists, discard the current contents.
		#define AB      "ab"     //Append: open or create a file for writing at the end of the file in binary mode.
		#define RB_PLUS "rb+"    //Open an existing file for update (reading and writing) in binary mode.
		#define WB_PLUS "wb+"    //Create a file for update in binary mode. If the file already exists, discard the current contents.
		#define AB_PLUS "ab+"    //Append: open or create a file for update in binary mode; writing is done at the end of the file.

 * */
	//R_PLUS is good
	m=FilesInit(&file_test_out,"GrBaSy2.txt",R_PLUS);	//redesign the init to enter the file name with it and the mode!!!!!!!!!!!!!
    printf("=files 1 init %d \n",m==F_ER_NO);
	//strcpy(file_test_in.file_name_obj,file_name_test);

	m=FilesInit(&file_test_in,"GrBaSy2.txt",R);	//redesign the init to enter the file name with it and the mode!!!!!!!!!!!!!
	printf("=files 2 init %d \n",m==F_ER_NO);
	LIST_ENTRY entry_test0={"MSA","@GMAIL","passcode021",US_Dollar_acc,6746,676,21242.335,US_Dollar_cur};
	m=ListInsert(&list_test_1,&entry_test0,1);
	printf("=list insert %d \n",m==LAB_NO_ERRORS);
//errror if writen once and tried to read twice
/*	m=FilesWriteRecord(&file_test_out,&entry_test0);
	printf("=files write 1 record %d \n",m==F_ER_NO);
	m=FilesWriteRecord(&file_test_out,&entry_test0);
	printf("=files write 2 record %d \n",m==F_ER_NO);
	m=FilesWriteRecord(&file_test_out,&entry_test0);
	printf("=files write 3 record %d \n",m==F_ER_NO);
	m=FilesWriteRecord(&file_test_out,&entry_test0);
	printf("=files write 4 record %d \n",m==F_ER_NO);
*/
	//LIST_ENTRY entry_test1={"MSA","@GMAIL","passcode021",US_Dollar_acc,75752,562124,542412,US_Dollar_cur};
	//m=FilesWriteRecord(&file_test_out,&entry_test1);
	//printf("=files write 2 record %d \n",m);
	//LIST_ENTRY entry_test2={"MSA","@GMAIL","passcode021",US_Dollar_acc,45792,54214,7574,US_Dollar_cur};
	//FilesWriteRecord(&file_test_out,&entry_test2);
	//LIST_ENTRY entry_test3={"MSA","@GMAIL","passcode021",US_Dollar_acc,210124,868686,75274,US_Dollar_cur};
	//FilesWriteRecord(&file_test_out,&entry_test3);
	//LIST_ENTRY entry_test4={"MSA","@GMAIL","passcode021",US_Dollar_acc,57575,868686,2124,US_Dollar_cur};
	//FilesWriteRecord(&file_test_out,&entry_test4);
	//create two instances one for input and another for output
	LIST_ENTRY entry_input;

    printf("before reading %s %s %s %d %d %d %lf %d\n"\
    		,entry_input.acc_name,entry_input.acc_add,entry_input.acc_pass,\
			entry_input.acc_type,entry_input.acc_numb,entry_input.acc_pin,\
			entry_input.acc_balance,entry_input.acc_currency);
	printf("about to read\n");
	//////////////////////////
    m=FilesReadRecord(&file_test_in,&entry_input);
    printf("=files read 1 record %d \n",m==F_ER_NO);
	/*m=FilesReadRecord(&file_test_in,&entry_input);
    printf("=files read 2 record %d \n",m==F_ER_NO);
	m=FilesReadRecord(&file_test_in,&entry_input);
    printf("=files read 3 record %d \n",m==F_ER_NO);
	m=FilesReadRecord(&file_test_in,&entry_input);
    printf("=files read 4 record %d \n",m==F_ER_NO);*/
	////////////////////////////

    m=ListInsert(&list_test_1,&entry_test0,ListSize(&list_test_1)+1);
    printf("=ListInsert %d \n",m==LAB_NO_ERRORS);


    printf("after reading %s %s %s %d %d %d %lf %d\n"\
    		,entry_input.acc_name,entry_input.acc_add,entry_input.acc_pass,\
			entry_input.acc_type,entry_input.acc_numb,entry_input.acc_pin,\
			entry_input.acc_balance,entry_input.acc_currency);
	if(!strcmp(entry_input.acc_name,entry_test0.acc_name))
	{
		printf("the name got is the same\n");
		if(!strcmp(entry_input.acc_pass,entry_test0.acc_pass))
			{
				printf("the pasword got is the same\n");
				if(entry_input.acc_pin == entry_test0.acc_pin)
					{
						printf("the pin got is the same\n");
					}
			}
	}
	/////////////////////////////////////////////////////////////2
	/*FilesReadRecord(&file_test_in,&entry_input);

    printf("%s %s %s %d %d %d %lf %d\n"\
    		,entry_input.acc_name,entry_input.acc_add,entry_input.acc_pass,\
			entry_input.acc_type,entry_input.acc_numb,entry_input.acc_pin,\
			entry_input.acc_balance,entry_input.acc_currency);
	if(!strcmp(entry_input.acc_name,entry_test1.acc_name))
	{
		printf("the name got is the same\n");
		if(!strcmp(entry_input.acc_pass,entry_test1.acc_pass))
			{
				printf("the pasword got is the same\n");
				if(entry_input.acc_pin == entry_test1.acc_pin)
					{
						printf("the pin got is the same\n");
					}
			}
	}*/


	//ListInsert(&list_test_1,)
	puts("!!!Hello World!!!\n"); /* prints !!!Hello World!!! */
	printf("the current list size = %d \n",ListSize(&list_test_1)); /* prints !!!Hello World!!! */

	m=FilesDeInit(&file_test_out);
	printf("=fileDeinit 1 %d \n",m==F_ER_NO);
	m=FilesDeInit(&file_test_in);
	printf("=fileDeinit 2 %d \n",m==F_ER_NO);
	return EXIT_SUCCESS;
}
#endif
