#include "files_apis.h"

f_ret_t FilesInit(file_cfg_t* ptr_cfg,char file_name[],char open_mode[])
{
    if(ptr_cfg != NULL)
    {
        if(ptr_cfg->file_init_state == true)
        {
        	//printf("SSSSSSSSSSSSSSSSSSSSS\n");
            return F_ER_ALREADEY_INITIATED;
        }
        strcpy(ptr_cfg->file_name_obj,file_name);
        ptr_cfg->ptr_file = fopen(ptr_cfg->file_name_obj,open_mode);	//decide the file opening mode
        ptr_cfg->file_init_state=true;
        return F_ER_NO;
    }
    return F_ER_INV_PARAM;
}

f_ret_t FilesWriteRecord(file_cfg_t* ptr_cfg,account_t *ptr_acc)
{
    if((ptr_acc != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_cfg->file_init_state == true)
        {
            //fwrite(ptr_acc,sizeof(account_t),1,ptr_cfg->ptr_file);	//error unknown plus it's not good for the arr length
            int exec_res=0;
            char res=fprintf(ptr_cfg->ptr_file,"%s %s %s %d %d %d %lf %d\n"\
            		,ptr_acc->acc_name,ptr_acc->acc_add,ptr_acc->acc_pass,\
					ptr_acc->acc_type,ptr_acc->acc_numb,ptr_acc->acc_pin,\
					ptr_acc->acc_balance,ptr_acc->acc_currency);
            printf("fprintf res =%d\n",res);
            if(EOF == exec_res){return F_ER_CANT_READ;}	//checking if could read or not :D
            return F_ER_NO;
        }
        return F_ER_NOT_INITIALIZED;
    }
    else
    {
        return F_ER_INV_PARAM;
    }
    return F_ER_NO;
}

f_ret_t FilesSysBackup(file_cfg_t* ptr_cfg,list_t *ptr_list)
{
    if((ptr_list != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_cfg->file_init_state == true)
        {
            //build on traverse list :D:D:D:D:D:D:D:D:D:D:D:D:D:D
            ListTravers(ptr_list,ptr_cfg,FilesWriteRecord);
        	return F_ER_NO;
        }
        return F_ER_NOT_INITIALIZED;
    }
    else
    {
        return F_ER_INV_PARAM;
    }
    return F_ER_NO;
}

f_ret_t FilesReadRecord(file_cfg_t* ptr_cfg,account_t *ptr_acc)
{
    if((ptr_acc != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_cfg->file_init_state == true)
        {
            //fread(ptr_acc,sizeof(account_t),1,ptr_cfg->ptr_file);
            int exec_res=0;
            //printf("exec_res 1=%d\n",exec_res);
            // On success, this function returns the number of values read and
            // on error or end of the file it returns EOF or -1.
            exec_res = fscanf(ptr_cfg->ptr_file,"%s %s %s %d %d %d %lf %d"\
            		,ptr_acc->acc_name,ptr_acc->acc_add,ptr_acc->acc_pass, \
					&ptr_acc->acc_type,&ptr_acc->acc_numb,&ptr_acc->acc_pin,\
					&ptr_acc->acc_balance,&ptr_acc->acc_currency);
            printf("fscanf res =%d\n",exec_res);
            if(EOF == exec_res){return F_ER_CANT_READ;}	//checking if could read or not :D
            return F_ER_NO;
        }
        return F_ER_NOT_INITIALIZED;
    }
    else
    {
        return F_ER_INV_PARAM;
    }
    return F_ER_NO;
}


f_ret_t FilesSysRestore(file_cfg_t* ptr_cfg,list_t *ptr_list)
{
    if((ptr_list != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_cfg->file_init_state == true)
        {
            //build on traverse list :D:D:D:D:D:D:D:D:D:D:D:D:D:D
            ListTravers(ptr_list,ptr_cfg,FilesReadRecord);
        	return F_ER_NO;
        }
        return F_ER_NOT_INITIALIZED;
    }
    else
    {
        return F_ER_INV_PARAM;
    }
    return F_ER_NO;
}

f_ret_t FilesRefresh(file_cfg_t *ptr_cfg_file)
{
	if(ptr_cfg_file != NULL)//TODO:params check
	{
		fclose(ptr_cfg_file->ptr_file);	//TODO:error detection
		ptr_cfg_file->ptr_file = fopen(ptr_cfg_file->file_name_obj,R_PLUS); //TODO:error detection
		ptr_cfg_file->file_init_state=true;
		return F_ER_NO;
	}
	return F_ER_INV_PARAM;//TODO:return vals
}

f_ret_t FilesDeInit(file_cfg_t* ptr_cfg)
{
    if(ptr_cfg != NULL)
    {
        if(ptr_cfg->file_init_state == false)
        {
            return F_ER_ALREADEY_UNINITIATED;
        }
        fclose( ptr_cfg->ptr_file ); // fclose closes the file
        ptr_cfg->file_init_state=false;
        return F_ER_NO;
    }
    return F_ER_INV_PARAM;
}

f_ret_t FileEncrypt(file_cfg_t *file_ptr_in,file_cfg_t *file_ptr_out,uint8_t key)
{
	//TODO:paams check
		char ch_got=0;
	if(file_ptr_in == file_ptr_out)
	{
		FILE*temp_file_ptr;
		temp_file_ptr = fopen("temp_file.txt",W);		//TODO:error detect
														//TODO: if error occured re-init the ptr_cfg_file ptr
		while((ch_got=fgetc(file_ptr_in->ptr_file)) != EOF)
		{
			ch_got+=key;
			fprintf(temp_file_ptr,"%c",ch_got);			//TODO:error detect
		}
		fclose(temp_file_ptr);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open to copy the output
		file_ptr_in->ptr_file = fopen(file_ptr_in->file_name_obj,W);		//TODO:error detect
		temp_file_ptr = fopen("temp_file.txt",R);		//TODO:error detect
		while((ch_got=fgetc(temp_file_ptr)) != EOF)
		{
			fprintf(file_ptr_in->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(temp_file_ptr);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open the file
		file_ptr_in->ptr_file = fopen(file_ptr_in->file_name_obj,R);		//TODO:error detect
	}
	else
	{

		while((ch_got=fgetc(file_ptr_in->ptr_file)) != EOF)
		{
			ch_got+=key;
			fprintf(file_ptr_out->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(file_ptr_out->ptr_file);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open to copy the output
		file_ptr_in->ptr_file  = fopen(file_ptr_in->file_name_obj ,W);		//TODO:error detect
		file_ptr_out->ptr_file = fopen(file_ptr_out->file_name_obj,R);		//TODO:error detect
		while((ch_got=fgetc(file_ptr_out->ptr_file)) != EOF)
		{
			fprintf(file_ptr_in->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(file_ptr_out->ptr_file);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open the file
		/*As you can see, + requests a stream that can do both input and output. When using such a stream, you must
		 call fflush or a file positioning function such as fseek when switching from reading to writing or vice versa.
		 Otherwise, internal buffers might not be emptied properly. */
		file_ptr_in->ptr_file  = fopen(file_ptr_in->file_name_obj ,R);		//TODO:error detect
		file_ptr_out->ptr_file = fopen(file_ptr_out->file_name_obj,R_PLUS);		//TODO:error detect

	}

	return F_ER_NO;
}

f_ret_t FileDecrypt(file_cfg_t *file_ptr_in,file_cfg_t *file_ptr_out,uint8_t key)
{
	//TODO:REVISE THE DECRYPTION IS REVERSED BY THE ENCRYPTION OR NOT    SRC->ENC->TEMP->SRC   DERYPTED->
	//TODO:paams check
		char ch_got=0;
	if(file_ptr_in == file_ptr_out)
	{
		FILE*temp_file_ptr;
		temp_file_ptr = fopen("temp_file.txt",W);		//TODO:error detect
														//TODO: if error occured re-init the ptr_cfg_file ptr
		while((ch_got=fgetc(file_ptr_in->ptr_file)) != EOF)
		{
			ch_got-=key;
			fprintf(temp_file_ptr,"%c",ch_got);			//TODO:error detect
		}
		fclose(temp_file_ptr);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open to copy the output
		file_ptr_in->ptr_file = fopen(file_ptr_in->file_name_obj,W);		//TODO:error detect
		temp_file_ptr = fopen("temp_file.txt",R);		//TODO:error detect
		while((ch_got=fgetc(temp_file_ptr)) != EOF)
		{
			fprintf(file_ptr_in->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(temp_file_ptr);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open the file
		file_ptr_in->ptr_file = fopen(file_ptr_in->file_name_obj,R);		//TODO:error detect
	}
	else
	{
																		//https://youtu.be/tc4ROCJYbm0 >>the Unix OS
		while((ch_got=fgetc(file_ptr_in->ptr_file)) != EOF)
		{
			ch_got-=key;
			fprintf(file_ptr_out->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(file_ptr_out->ptr_file);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open to copy the output
		file_ptr_in->ptr_file  = fopen(file_ptr_in->file_name_obj ,W);		//TODO:error detect
		file_ptr_out->ptr_file = fopen(file_ptr_out->file_name_obj,R);		//TODO:error detect
		while((ch_got=fgetc(file_ptr_out->ptr_file)) != EOF)
		{
			fprintf(file_ptr_in->ptr_file,"%c",ch_got);			//TODO:error detect
		}
		fclose(file_ptr_out->ptr_file);							//TODO:error detect
		fclose(file_ptr_in->ptr_file);
		//re-open the file
		/*As you can see, + requests a stream that can do both input and output. When using such a stream, you must
		 call fflush or a file positioning function such as fseek when switching from reading to writing or vice versa.
		 Otherwise, internal buffers might not be emptied properly. */
		file_ptr_in->ptr_file  = fopen(file_ptr_in->file_name_obj ,R);		//TODO:error detect
		file_ptr_out->ptr_file = fopen(file_ptr_out->file_name_obj,R_PLUS);		//TODO:error detect

	}

	return F_ER_NO;
}

