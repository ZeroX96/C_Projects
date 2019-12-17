#include "Lists_ArrBased_APIs.h"

LAB_return_t LAB_create (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        ptr_list->LAB_InitStatus=true;
        ptr_list->LAB_size=0;
        return LAB_NO_ERRORS;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_empty (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            if(ptr_list->LAB_size == 0)
                return LAB_EMPTY;
            return LAB_NOT_EMPTY;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_full (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            if(ptr_list->LAB_size >= MAX_LIST_LENGTH)
                return LAB_FULL;
            return LAB_NOT_FULL;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
uint32_t     LAB_size (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            return ptr_list->LAB_size;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_destroy (List_ArrBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        ptr_list->LAB_InitStatus=false;
        ptr_list->LAB_size=0;
        return LAB_NO_ERRORS;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_insert (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            uint32_t i;
            for(i=ptr_list->LAB_size;i >= position;i--)
            {
                ptr_list->LAB_entry_arr[i]=ptr_list->LAB_entry_arr[i-1];
            }
            ptr_list->LAB_entry_arr[position]=*ptr_entry;
            ptr_list->LAB_size++;
            return LAB_NO_ERRORS;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_delete (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            *ptr_entry=ptr_list->LAB_entry_arr[position];
            uint32_t i;
            for(i=position;i < ptr_list->LAB_size-1;i++)
            {
                ptr_list->LAB_entry_arr[i] = ptr_list->LAB_entry_arr[i+1];
            }
            ptr_list->LAB_size--;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_replace (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            ptr_list->LAB_entry_arr[position]=*ptr_entry;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
LAB_return_t LAB_retrieve (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)||(position > ptr_list->LAB_size-1))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            *ptr_entry=ptr_list->LAB_entry_arr[position];
            return LAB_NO_ERRORS;
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}
//edited to work with the files
LAB_return_t LAB_traverse (List_ArrBased *ptr_list,file_cfg_t* ptr_cfg,f_ret_t(*ptr_func)(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc))
{
    if((ptr_list != NULL)&&(ptr_func != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_list->LAB_InitStatus == true)
        {
            uint32_t i,exec_res=0;
            for(i=0;(i < ptr_list->LAB_size) && (exec_res != F_ER_CANT_READ);i++)
            {
                exec_res=(*ptr_func)(ptr_cfg,&(ptr_list->LAB_entry_arr[i]));
            }
        }
        return LAB_NOT_INITIALIZED;
    }
    return LAB_INVALID_ARG;
}

LAB_return_t LAB_search_by_all(List_ArrBased *ptr_list,LIST_ENTRY*ptr_entry,uint8_t*ptr_search_result,uint16_t*ptr_entry_index)
{
//DEBUGGING	            	    printf("lab search by all\n");
	if((ptr_list != NULL)&&(ptr_entry != NULL)&&(ptr_search_result != NULL)&&(ptr_entry_index != NULL))
	    {
//DEBUGGING	            	    printf("no parameters errors\n");
	        if(ptr_list->LAB_InitStatus == true)
	        {
//DEBUGGING	            	    printf("list initialized\n");
	            uint32_t i;
	            for(i=0;(i <= ptr_list->LAB_size);i++)
	            {
//DEBUGGING	            	    printf("loop=%d\n",i);
	            	if(ptr_list->LAB_entry_arr[i].acc_numb == ptr_entry->acc_numb)
	            	{
//DEBUGGING	            	    printf("correct numb\n");
	            		if(ptr_list->LAB_entry_arr[i].acc_pin == ptr_entry->acc_pin)
		            	{
//DEBUGGING	            	    printf("correct pin\n");
		            		if(!(strcmp(ptr_list->LAB_entry_arr[i].acc_pass,ptr_entry->acc_pass)))
		            		{
//DEBUGGING	            	    printf("correct pass\n");
		            			if(!(strcmp(ptr_list->LAB_entry_arr[i].acc_name,ptr_entry->acc_name)))
		            			{
//DEBUGGING	            	    printf("correct name\n");
		            				*ptr_search_result=true;
		            				*ptr_entry_index=i;
		            				return LAB_NO_ERRORS;
		            			}
		            		}
		            	}
	            	}
	            }
	            *ptr_search_result=false;
	            return LAB_NOT_FOUND;
	        }
	        return LAB_NOT_INITIALIZED;
	    }
	    return LAB_INVALID_ARG;
}


LAB_return_t LAB_search_by_id(List_ArrBased *ptr_list,uint16_t*ptr_entry_id,uint8_t*ptr_search_result,uint16_t*ptr_entry_index)
{
	if((ptr_list != NULL)&&(ptr_entry_id != NULL)&&(ptr_search_result != NULL)&&(ptr_entry_index != NULL))
	    {
	        if(ptr_list->LAB_InitStatus == true)
	        {
	            uint32_t i;
	            for(i=0;(i < ptr_list->LAB_size);i++)
	            {
	            	if(ptr_list->LAB_entry_arr[i].acc_numb == *ptr_entry_id)
	            	{
		            	*ptr_search_result=true;
		            	*ptr_entry_index=i;
		            	return LAB_NO_ERRORS;
	            	}
	            }
	            *ptr_search_result=false;
	            return LAB_NOT_FOUND;
	        }
	        return LAB_NOT_INITIALIZED;
	    }
	    return LAB_INVALID_ARG;
}

