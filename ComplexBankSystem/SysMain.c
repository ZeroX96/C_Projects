#include "SysMain_APIs.h"

static char management_name[16]="Mahmoud_Saad_96";
static char management_pass[12]="ZeroX86.Msa";

sys_ret_t SysBegin()
{
	//todo:clear screen
	printf("***************************************************************************\n");
	printf("***************************************************************************\n");
	printf("   /$$$$$$$$                                /$$   /$$  /$$$$$$   /$$$$$$ \n");
	printf("  |_____ $$                                | $$  / $$ /$$__  $$ /$$__  $$\n");
	printf("       /$$/   /$$$$$$   /$$$$$$   /$$$$$$  |  $$/ $$/ |$$   \\$$| $$  \\__/ \n");
	printf("      /$$/   /$$__  $$ /$$__  $$ /$$ __ $$  \\ $$$$/   | $$$$$$/| $$$$$$$ \n");
	printf("     /$$/   | $$$$$$$$| $$  \\__/|$$     \\$$   >$$ $$  >$$ __ $$| $$__  $$\n");
	printf("    /$$/    | $$_____/| $$      | $$    |$$ / $$/\\ $$| $$   \\$$| $$   \\$$\n");
	printf("   /$$$$$$$$|  $$$$$$$| $$      |  $$$$$$/ |$$    \\ $$| $$$$$$/|  $$$$$$/\n");
	printf("  |________/\\_______/ |__/       \\______/  |__/  |__/ \\______/ \\______/ \n");
	printf("***************************************************************************\n");
	printf("***************************************************************************\n");
	//SysRestore();	//TODO:ret check and so open the sys or show an error message to restart and kill the developer
	printf("***********************  Welcome to ZEROX86 Bank  *************************\n");
	printf("**~~~~~~~~~~~~~~~~~~~~~~~~~~~   MAIN MENU   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~***\n");
	printf("***************************************************************************\n");
	printf("**->01.SIGN IN.........(I).\n");
	printf("**->02.SIGN UP.........(U).\n");
	printf("**->03.MANAGE SYSTEM...(M).\n");
	printf("**->04.EXIT SYSTEM.....(E).\n");
	printf("***************************************************************************\n");
	printf("**->Make Your Choice!\n");
	printf("**-<");
return SYS_ER_NO;
}

sys_ret_t SysEnd()
{
	printf("***************************************************************************\n");
	printf("************************************MSA************************************\n");
	printf("*********************************Thank YOU*********************************\n");
	printf("***********************I'LL SHUT DOWN AUTOMATICALLY************************\n");
	printf("***************************************************************************\n");
	printf("***************************************************************************\n");
	//SysBackUp();
    SysDelay();
    SysDelay();
    system("CLS");
	return SYS_ER_NO;
}

sys_ret_t SysInit(file_cfg_t* ptr_file_input,file_cfg_t* ptr_file_output,list_t* ptr_sys_list,char input_file_name[],char output_file_name[],uint8_t enc_key)
{
	//TODO:params Check
	//TODO: notice that the file will need to be created offline "R" & "R_PLUS"
	char res=ListCreate(ptr_sys_list);								//TODO:error detect
//Debugging	printf("ListCreate res=%d\n",res);
	res=FilesInit(ptr_file_output,output_file_name,R_PLUS);			//TODO:error detect		//TODO: revise the opening mode or the files must be already existing
//Debugging	printf("FilesInit-1 res=%d\n",res);
	res=FilesInit(ptr_file_input,input_file_name,R);					//TODO:error detect
//Debugging	printf("FilesInit-2 res=%d\n",res);
	res=SysRestore(ptr_file_input,ptr_sys_list,enc_key);				//TODO:error detect
//Debugging	printf("SysRestore res=%d\n",res);
	return SYS_ER_NO;
}

sys_ret_t SysDeInit(file_cfg_t* ptr_file_input,file_cfg_t* ptr_file_output,list_t* ptr_sys_list,char input_file_name[],char output_file_name[],uint8_t enc_key)
{
	//TODO:params Check
	char res=SysBackUp(ptr_file_input,ptr_sys_list,enc_key);			//TODO:error detect
//Debugging	printf("SysBackUp res=%d\n",res);
	res=ListDestroy(ptr_sys_list);								//TODO:error detect
//Debugging	printf("ListDestroy res=%d\n",res);
	res=FilesDeInit(ptr_file_output);			//TODO:error detect
//Debugging	printf("FilesDeInit res=%d\n",res);
	res=FilesDeInit(ptr_file_input);					//TODO:error detect
//Debugging	printf("FilesDeInit res=%d\n",res);
	return SYS_ER_NO;
}

sys_ret_t SysRestore(file_cfg_t* ptr_file_input,list_t* ptr_sys_list,uint8_t enc_key)
{
	//todo params check
	FileDecrypt(ptr_file_input,ptr_file_input,enc_key);		//TODO:may point to a temp file and write back to the same file after end//TODO:error detect
	FilesSysRestore(ptr_file_input,ptr_sys_list);			//TODO:may point to a temp file and write back to the same file after end//TODO:error detect
	//todo ret vals
	return SYS_ER_NO;
}

sys_ret_t SysBackUp(file_cfg_t* ptr_file_input,list_t* ptr_sys_list,uint8_t enc_key)
{
	//todo params check
//Debugging	printf("BACK UP OPERATION...\n");
	char res=FilesSysBackup(ptr_file_input,ptr_sys_list);
//Debugging	printf("backup res=%d\n",res);
	res=FileEncrypt(ptr_file_input,ptr_file_input,enc_key);		//TODO:may point to a temp file and write back to the same file after end//TODO:error detect
//Debugging	printf("Encrypt res=%d\n",res);
//Debugging	printf("BACK UP OPERATION...\n");//todo ret vals
	return SYS_ER_NO;
}

sys_ret_t SysSignUp(list_t* list)
{
	if(ListFull(list) == LAB_NOT_FULL)
	{
		LIST_ENTRY temp_entry;
		printf("***************************************************************************\n");
		printf("**************************\n");
		printf("**  _SIGNUP_OPERATION_  **\n");
		printf("**************************\n");
		printf("**->ENTER YOUR ACCOUNT NAME.\n**-<");
		scanf("%s",&temp_entry.acc_name);	//TODO:revise scanf or gets is better not to lose any spaces
		printf("**->ENTER YOUR ACCOUNT PASSWORD.\n**-<");
		scanf("%s",&temp_entry.acc_pass);
		printf("**->ENTER YOUR ACCOUNT HOLDER ADDRESS.\n**-<");
		scanf("%s",&temp_entry.acc_add);
		printf("**->ENTER YOUR ACCOUNT TYPE.\n");
		printf("**->CHECKING_ACCOUNT.................(0),\n");
		printf("**->SAVINGS_ACCOUNT..................(1),\n");
		printf("**->BROKERAGE_ACCOUNT................(2),\n");
		printf("**->MONEY_MARKET_ACCOUNT.............(3),\n");
		printf("**->CERTIFICATE_OF_DEPOSITE_ACCOUNT..(4).\n**-<");
		scanf("%d",&temp_entry.acc_type);
		printf("**->ENTER YOUR ACCOUNT NUMBER.\n**-<");
		scanf("%d",&temp_entry.acc_numb);
		printf("**->ENTER YOUR ACCOUNT PIN.\n**-<");
		scanf("%d",&temp_entry.acc_pin);
		printf("**->ENTER YOUR ACCOUNT INITIAL BALANCE.\n**-<");
		scanf("%lf",&temp_entry.acc_balance);
		printf("**->ENTER YOUR ACCOUNT CURRENCY.\n");
		printf("**->US_DOLLAR..(0),\n");
		printf("**->UK_POUND...(1),\n");
		printf("**->TU_LIRA....(2),\n");
		printf("**->SA_RIAL....(3),\n");
		printf("**->EG_POUND...(4),\n");
		printf("**->JA_YEN.....(5),\n**-<");
		scanf("%d",&temp_entry.acc_currency);
		ListInsert(list,&temp_entry,ListSize(list)+1);	//TODO:error detect
		printf("**->YOUR ACCOUNT WAS CREATED SUCCESSFULLY,THNAK YOU.\n");
        SysDelay();
        SysDelay();
        system("CLS");
		//TODO:save record per operation or when opening and closing????? systembackup
		return SYS_ER_NO;
	}
	//TODO:return vals, printf here or send te ret_val to the caller/sys handler and it decides
	//printf(sorry the system is full, we cant accept any more)

	return SYS_ER_NO;
}
void SysDelay()
{
    uint32_t delay_1=0,delay_2=0;
    for(delay_1=0;delay_1 <= 0xffffff;delay_1++)
    {
       for(delay_2=0;delay_2 <= 0xf;delay_2++)
      {

      }
    }
    delay_1=delay_2=0;
}
sys_ret_t SysSignIn(list_t* list)
{

	LIST_ENTRY temp_entry_signIn,temp_entry_transfer;	//temp_entry_signIn used for accessing the signed in account data while temp_entry_transfer is used for destinations accounts
	uint8_t search_result=false,choice=0;
	uint16_t entry_index_signIn=0,entry_index_transfer=0;
	double temp_dbl32_operation_value=0;
	uint8_t temp_uint8_operation_currency=0;
	uint16_t temp_uint16_transfer_dist_id=0;
    printf("***************************************************************************\n");
    printf("**************************\n");
    printf("**  _SIGNIN_OPERATION_  **\n");
    printf("**************************\n");
	printf("**->ENTER YOUR ACCOUNT NAME.\n**-<");
	scanf("%s",&temp_entry_signIn.acc_name);	//TODO:revise scanf or gets is better not to lose any spaces
	printf("**->ENTER YOUR ACCOUNT PASSWORD.\n**-<");
	scanf("%s",&temp_entry_signIn.acc_pass);
	printf("**->ENTER YOUR ACCOUNT NUMBER.\n**-<");
	scanf("%d",&temp_entry_signIn.acc_numb);
	printf("**->ENTER YOUR ACCOUNT PIN.\n**-<");
	scanf("%d",&temp_entry_signIn.acc_pin);
	ListSearchByALL(list,&temp_entry_signIn,&search_result,&entry_index_signIn);//todo:check return valsListSearchById(list,&search_result,&entry_index,&temp_uint16_transfer_dist_id);
//DEBUGGING	printf("**->DEBUG,SEARCH RES=%d\n",search_result);
	if(search_result == true)
	{
		search_result=false;
		ListRetrieve(list,&temp_entry_signIn,entry_index_signIn);	//todo:check return vals
        printf("***************************************************************************\n");
		printf("**->ACCOUNT FOUND.\n");
		while(choice != SIGNOUT)
		{
			printf("**->WELCOME %s\n",temp_entry_signIn.acc_name);
			//TODO://show current data
			printf("**->01.Deposite..(D)\n");
			printf("**->02.WithDraw..(W)\n");
			printf("**->03.Transfer..(T)\n");
			printf("**->04.History...(H)\n");
			printf("**->05.Manage....(M)\n");
			printf("**->06.SignOut...(S)\n");
			printf("**->Make Your Choice!\n**-<");
			fflush(stdin);
			choice=getchar();
			if(choice == DEPOSITE)
			{
				//TODO:while not back
				//TODO:{
//DEBUGGING	                fflush(stdin);
//DEBUGGING	                choice=getchar();
				while(choice != BACK)
				{
					printf("**************************\n");
					printf("** _DEPOSITE_OPERATION_ **\n");
					printf("**************************\n");
					printf("**->ENTER YOUR INPUT VALUE.\n**-<");
					scanf("%lf",&temp_dbl32_operation_value);
					printf("**->ENTER THE OPERATION CURRENCY.(0-Dollar,1-LE,2-UK_POUND,3-REIAL,4-YEN,5-LIRA).\n**-<");
					scanf("%d",&temp_uint8_operation_currency);
					//TODO:currency Exchange	//DONE
					SysCurrencyExchange(temp_entry_signIn.acc_currency,temp_uint8_operation_currency,&temp_dbl32_operation_value);
					temp_entry_signIn.acc_balance +=temp_dbl32_operation_value;
					ListReplace(list,&temp_entry_signIn,entry_index_signIn);
					//TODO:if update with every op is enabled,WORK HERE
					printf("**->REPEATE OR GO BACK?(R/B).\n**-<");
                    fflush(stdin);
                    choice=getchar();
				}//TODO:BACK??//TODO:get decision//TODO:}
			}
			else if(choice == WITHDRAW)
			{
				//TODO:while not back
				//TODO:{
//DEBUGGING	                fflush(stdin);
//DEBUGGING	                choice=getchar();
				while(choice != BACK)
				{
					printf("**************************\n");
					printf("** _WITHDRAW_OPERATION_ **\n");
					printf("**************************\n");
					printf("**->ENTER YOUR REQUIRED VALUE!\n**-<");
					scanf("%lf",&temp_dbl32_operation_value);
					printf("**->ENTER THE OPERATION CURRENCY.(0-Dollar,1-LE,2-UK_POUND,3-REIAL,4-YEN,5-LIRA)\n**-<");
					scanf("%d",&temp_uint8_operation_currency);
					//TODO:currency Exchange	//DONE
					SysCurrencyExchange(temp_entry_signIn.acc_currency,temp_uint8_operation_currency,&temp_dbl32_operation_value);
					//TODO:check if the value is available>> wanted > or < the actual?
					if(temp_entry_signIn.acc_balance >= temp_dbl32_operation_value)
					{
						printf("**->HERE YOU ARE, YOUR REQUESTED VALUE.\n");
						temp_entry_signIn.acc_balance -=temp_dbl32_operation_value;
						ListReplace(list,&temp_entry_signIn,entry_index_signIn);
					}
					else
					{
						printf("**->SORRY,YOUR BALANCE CANT AFFORD THIS OPERATION,");
						printf("**->YOUR CURRENT BALANCE =%lf.\n",temp_entry_signIn.acc_balance);
					}
					printf("**->REPEATE OR GO BACK?(R/B).\n**-<");
                    fflush(stdin);
                    choice=getchar();
				}	//TODO:BACK//TODO:get decesion//TODO:}
			}
			else if(choice == TRANSFER)
			{
				//TODO:while not back
				//TODO:{
//DEBUGGING	                fflush(stdin);
//DEBUGGING	                choice = getchar();
				while(choice != BACK)
				{
					printf("**************************\n");
					printf("** _TRANSFER_OPERATION_ **\n");
					printf("**************************\n");
					printf("**->ENTER YOUR TRANSFER VALUE.\n**-<");
					scanf("%lf",&temp_dbl32_operation_value);
					printf("**->ENTER THE OPERATION CURRENCY.(0-Dollar,1-LE,2-UK_POUND,3-REIAL,4-YEN,5-LIRA).\n**-<");
					scanf("%d",&temp_uint8_operation_currency);
					printf("**->ENTER THE RECEIVER ACCOUNT NUMBER.\n**-<");
					scanf("%d",&temp_uint16_transfer_dist_id);	//temp_3 is used to search for an account to transfer money to it so i dont need to search by name/pass/pin
					//now search
					ListSearchByIDOnly(list,&entry_index_transfer,&search_result,&temp_uint16_transfer_dist_id);	//todo:check return vals
					if(search_result == true)
					{
						search_result=false;
						//TODO:check if the value is available>> wanted > or < the actual?
						if(temp_entry_signIn.acc_balance >= temp_dbl32_operation_value)
						{
							printf("**->TRANSFERING THE MONEY AS NEEDED.\n");
							SysCurrencyExchange(temp_entry_signIn.acc_currency,temp_uint8_operation_currency,&temp_dbl32_operation_value);
							//getting the money from the account and performing currency exchange
							temp_entry_signIn.acc_balance -=temp_dbl32_operation_value;
							ListReplace(list,&temp_entry_signIn,entry_index_signIn);
							//Now sending the money to the designated account
							ListRetrieve(list,&temp_entry_transfer,entry_index_transfer);
							//TODO:revise the currency exchange
							SysCurrencyExchange(temp_uint8_operation_currency,temp_entry_transfer.acc_currency,&temp_dbl32_operation_value);
							temp_entry_transfer.acc_balance += temp_dbl32_operation_value;
							ListReplace(list,&temp_entry_transfer,entry_index_transfer);
						}
						else
						{
							printf("**->SORRY,YOUR BALANCE CANT AFFORD THIS OPERATION,");
							printf("**->YOUR CURRENT BALANCE =%lf.\n",temp_entry_signIn.acc_balance);
						}
					}
					else
					{
						printf("**->SORRY,THE REQUIRED ACCOUNT DOESN'T EXIST!\n");
					}
					printf("**->REPEATE OR GO BACK?(R/B).\n**-<");
					fflush(stdin);
                    choice = getchar();
				}//TODO:print enter the right account or back//TODO:get decision//TODO:}
			}
			else if(choice == MANAGE)
			{
				char temp_arr[MAX_PASS_LENGTH];
//DEBUGGING                fflush(stdin);
//DEBUGGING               choice = getchar();
				while( choice != BACK)
				{
					printf("****************************\n");
					printf("** _MANAGEMENT_OPERATION_ **\n");
					printf("****************************\n");
					printf("**->WELCOME TO THE MANAGEMENT SECTION %s\n",temp_entry_signIn.acc_name);
					printf("**->01.DELETE............(D).\n");
					printf("**->02.CHANGE YOUR DATA..(C).\n");
					printf("**->03.BACK..............(B).\n");
					if(choice == DELETE)
					{
                        //fflush(stdin);
                        //choice = getchar();
						while(choice != BACK)
						{
							printf("**->PLEASE ENTER YOUR PASSWORD\n**-<");
							scanf("%s",&temp_arr);	//TODO:revise which is better,for not losing any spaces or sth.
							choice =strcmp(temp_arr,temp_entry_signIn.acc_pass);
							if(choice == 0)	//the password is correct>>delete the account
							{
								ListDelete(list,&temp_entry_signIn,entry_index_signIn);
								printf("**->YOUR DATA WERE\n");
								printf("**->NAME=%s,ADD=%s,BALANCE=%lf\n",temp_entry_signIn.acc_name,temp_entry_signIn.acc_add,temp_entry_signIn.acc_balance);
								printf("**->CURRENCY=%d,NUMBER=%d,PASSWORD=%s\n",temp_entry_signIn.acc_currency,temp_entry_signIn.acc_numb,temp_entry_signIn.acc_pass);
								printf("**->PIN=%d,TYPE=%d.\n",temp_entry_signIn.acc_pin,temp_entry_signIn.acc_type);
								printf("**->NOW THAT,YOUR ACCOUNT WAS DELETED THANKS FOR VISITING US.\n");
							}
							else
							{
								printf("**->INVALID PASSWORD,PLEASE ENTER THE CORRECT PASSWORD\n");
							}
							printf("**->REPEATE OR GO BACK?(R/B).\n**-<");
                            fflush(stdin);
                            choice = getchar();
						}
					}
					else if(choice == CHANGE_DATA)
					{
						while(choice != BACK)
						{
							//TODO:change data
							printf("**->WELCOME TO YOUR ACCOUNT MANAGEMENT SECTION.\n");
							printf("**->01.CHANGE YOUR ACCOUNT TYPE?......(T).\n");
							printf("**->02.CHANGE YOUR ACCOUNT NAME?......(N).\n");
							printf("**->03.CHANGE YOUR ACCOUNT NUMBER?....(U).\n");
							printf("**->04.CHANGE YOUR ACCOUNT PASSWORD?..(P).\n");
							printf("**->05.CHANGE YOUR ACCOUNT PIN?.......(I).\n");
							printf("**->06.CHANGE YOUR ACCOUNT ADDRESS?...(A).\n");
							printf("**->07.CHANGE YOUR ACCOUNT CURRENCY?..(C).\n**-<");
                            fflush(stdin);
							choice = getchar();
							if(choice == TYPE_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW TYPE.\n");
								printf("**->CHECKING_ACCOUNT.................(0),\n");
								printf("**->SAVINGS_ACCOUNT..................(1),\n");
								printf("**->BROKERAGE_ACCOUNT................(2),\n");
								printf("**->MONEY_MARKET_ACCOUNT.............(3),\n");
								printf("**->CERTIFICATE_OF_DEPOSITE_ACCOUNT..(4).\n**-<");
								scanf("%d",&temp_entry_signIn.acc_type);

							}
							else if(choice == NAME_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW NAME.\n**-<");
								scanf("%s",&temp_entry_signIn.acc_name);
								//TODO:revise scanf or gets is better not to lose any spaces

							}
							else if(choice == NUMB_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW NUMBER.\n**-<");
								scanf("%d",&temp_entry_signIn.acc_numb);

							}
							else if(choice == PASS_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW PASSWORD.\n**-<");
								scanf("%s",&temp_entry_signIn.acc_pass);

							}
							else if(choice == PIN__CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW PIN.\n**-<");
								scanf("%d",&temp_entry_signIn.acc_pin);

							}
							else if(choice == ADDR_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW ADDRESS.\n**-<");
								scanf("%s",&temp_entry_signIn.acc_add);

							}
							else if(choice == CURR_CH)
							{
								printf("**->ENTER YOUR ACCOUNT NEW CURRENCY.\n");
								printf("**->US_DOLLAR..(0),\n");
								printf("**->UK_POUND...(1),\n");
								printf("**->TU_LIRA....(2),\n");
								printf("**->SA_RIAL....(3),\n");
								printf("**->EG_POUND...(4),\n");
								printf("**->JA_YEN.....(5),\n**-<");
								scanf("%d",&temp_entry_signIn.acc_currency);
								//TODO:perform account currency exchange
							}
							else
							{
								printf("**->INVALID CHOICE,PLEASE SELECT A CORRECT ONE\n");
							}
							printf("**->REPEATE OR GO BACK?(R/B).\n**-<");
                            fflush(stdin);
							choice = getchar();
						}
						ListReplace(list,&temp_entry_signIn,entry_index_signIn);
					}
					else
					{
						printf("**->INVALID CHOICE,PLEASE SELECT A CORRECT ONE\n");
					}
					printf("**->REPEATE OR GO BACK?(R/B).\n**-<");//TODO:print enter the right account or back//TODO:get decision//TODO:}
                    fflush(stdin);
                    choice = getchar();
				}
			}	//https://zoom.us/j/7921603641
			else if(choice == SIGNOUT)
			{
				//do any thing but dont let the system goes to the invalid error and the system will signout of the while one loop!
				printf("**->SIGNING OUT...\n");
			}
			else
			{
				printf("**->INVALID CHOICE,PLEASE SELECT A CORRECT ONE\n");
			}
		}
		//todo:do i need to do a backup here??
	}
	else
	{
		printf("**->THE REQUIRED ACCOUNT DOESN'T EXIST!\n");
		printf("**->YOU NEED TO JOIN THE SYSTEM FIRST :D .\n");
	}
	return SYS_ER_NO;
}

sys_ret_t SysManage(list_t* list)
{
	char temp_name_arr[MAX_PASS_LENGTH];
	char temp_pass_arr[MAX_PASS_LENGTH];
    printf("***************************************************************************\n");
    printf("**************************\n");
    printf("**_SYS_MANAGE_OPERATION_**\n");
    printf("**************************\n");
	printf("**->ENTER THE MANAGEMENT ACCOUNT NAME\n**-<");
	scanf("%s",&temp_name_arr);	//TODO:revise scanf or gets is better not to lose any spaces
	printf("**->ENTER THE MANAGEMENT ACCOUNT PASSCODE\n**-<");
	scanf("%s",&temp_pass_arr);	//TODO:revise scanf or gets is better not to lose any spaces
	uint8_t comp_res=strcmp(management_name,temp_name_arr);
	if(comp_res == 0)
	{
		comp_res=strcmp(management_pass,temp_pass_arr);
		if(comp_res == 0)
		{
			uint8_t choice=0,temp_search_res=false;
			uint16_t temp_uint16_id=0,temp_uint16_index=0;
			LIST_ENTRY temp_list_entry;
			while(choice != BACK)
			{
				printf("**->WELCOME SIR, TO THE MANAGEMENT SECTION.\n");
				printf("**->01.LIST_ALL_ACCOUNTS..(L)\n");
				printf("**->02.DELETE_AN_ACCOUNT..(D)\n");
                fflush(stdin);
				if((choice=getchar()) == LIST )
				{
					for(temp_uint16_id=0;temp_uint16_id < ListSize(list);temp_uint16_id++)
					{
						ListRetrieve(list,&temp_list_entry,temp_uint16_id);
						if(temp_list_entry.acc_numb != 0)
						{
							printf("**->%2d-WITH NUMBER=%2d WE HAVE %s. \n",temp_uint16_id,temp_list_entry.acc_numb,temp_list_entry.acc_name);

						}
					}

				}
				else if(choice == DELETE)
				{
					printf("**->WRITE THE ACCOUNT ID NUMBER\n**-<");
					scanf("%d",&temp_uint16_id);
					ListSearchByIDOnly(list,&temp_uint16_id,&temp_search_res,&temp_uint16_index);
					if(temp_search_res == true)
					{
						temp_search_res=false;
						ListDelete(list,&temp_list_entry,temp_uint16_index);
						printf("**->ACCOUNT DELETED SUCCESSFULLY :D.\n");
					}
					else
					{
						printf("**->SORRY THE ACCOUNT COULD NOT BE FOUND AND HENCE NOT DELETED.\n");
					}
				}
				else
				{
					printf("**->>SORRY WRONG CHOICE!!\n");
				}
				printf("**->AGAIN OR GO BACK(A-B)?\n**-<");
                fflush(stdin);
				choice=getchar();
			}
		}
		else
		{
			printf("**->SORRY :( WRONG PASSWORD!!\n");
		}
	}
	else
	{
		printf("**->SORRY :( WRONG NAME!\n");
        SysDelay();
        system("CLS");
	}
	return SYS_ER_NO;
}

sys_ret_t SysCurrencyExchange(int from,int to,double* value)
{
	if(from == US_Dollar_cur)
	{
		switch(to)
		{
		case UK_POUND_cur:*value*=0.79;
			break;
		case KS_REIAL_cur:*value*=3.75;
			break;
		case EG_POUND_cur:*value*=16.29;
			break;
		case JA_YEN_cur:*value*=108.38;
			break;
		case TU_LIRA_cur:*value*=5.89;
			break;
		}
	}
	else if(from == UK_POUND_cur)
	{
		switch(to)
		{
		case US_Dollar_cur:*value*=1.27;
			break;
		case KS_REIAL_cur:*value*=4.75;
			break;
		case TU_LIRA_cur:*value*=7.44;
			break;
		case EG_POUND_cur:*value*=20.61;
			break;
		case JA_YEN_cur:*value*=137.10;
			break;
		}

	}
	else if(from == KS_REIAL_cur)
	{
		switch(to)
		{
		case US_Dollar_cur:*value*=0.27;
			break;
		case UK_POUND_cur:*value*=0.21;
			break;
		case EG_POUND_cur:*value*=4.34;
			break;
		case JA_YEN_cur:*value*=28.87;
			break;
		case TU_LIRA_cur:*value*=1.57;
			break;
		}

	}
	else if(from == EG_POUND_cur)
	{
		switch(to)
		{
		case US_Dollar_cur:*value*=0.06;
			break;
		case UK_POUND_cur:*value*=0.05;
			break;
		case KS_REIAL_cur:*value*=0.23;
			break;
		case JA_YEN_cur:*value*=6.65;
			break;
		case TU_LIRA_cur:*value*=0.36;
			break;
		}

	}
	else if(from == JA_YEN_cur)
	{
		switch(to)
		{
		case US_Dollar_cur:*value*=0.0092;
			break;
		case UK_POUND_cur:*value*=0.01;
			break;
		case KS_REIAL_cur:*value*=0.04;
			break;
		case EG_POUND_cur:*value*=0.15;
			break;
		case TU_LIRA_cur:*value*=0.05;
			break;
		}

	}
	else if(from == TU_LIRA_cur)
	{
		switch(to)
		{
		case US_Dollar_cur:*value*=0.17;
			break;
		case UK_POUND_cur:*value*=0.13;
			break;
		case KS_REIAL_cur:*value*=0.64;
			break;
		case EG_POUND_cur:*value*=2.77;
			break;
		case JA_YEN_cur:*value*=18.42;
			break;
		}

	}
	return SYS_ER_NO;
}
//Alfred Aho
