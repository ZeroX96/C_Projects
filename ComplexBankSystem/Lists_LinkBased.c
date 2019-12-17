#ifdef DYNAMIC_ALLOCATION_EN
#include "Lists_LinkBased.h"


LLB_return_t LLB_create (List_LinkBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        ptr_list->LLB_InitStatus=true;
        ptr_list->LLB_head=NULL;
        ptr_list->LLB_size=0;
        return LLB_NO_ERRORS;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_empty (List_LinkBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            if(ptr_list->LLB_size == 0)
                return LLB_EMPTY;
            return LLB_NOT_EMPTY;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_full (List_LinkBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            return LLB_NOT_FULL;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
uint32_t     LLB_size (List_LinkBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            return ptr_list->LLB_size;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_destroy (List_LinkBased *ptr_list)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp;
            while(ptr_temp != NULL)
            {
                ptr_temp=ptr_list->LLB_head;
                ptr_list->LLB_head=ptr_temp->node_next;
                free(ptr_temp);
            }
            ptr_list->LLB_InitStatus=false;
            ptr_list->LLB_size=0;
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_insert (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp_1=(LLB_node*)malloc(sizeof(LLB_node));
            LLB_node* ptr_temp_2;
            ptr_temp_1->node_entry=*ptr_entry;
            ptr_temp_1->node_next=NULL;
            if(position == 0)
            {
                ptr_temp_1->node_next=ptr_list->LLB_head;
                ptr_list->LLB_head=ptr_temp_1;
            }
            else
            {
                uint32_t i;   //revise
                for(ptr_temp_2=ptr_list->LLB_head,i=0;i<position-1;i++)
                    ptr_temp_2=ptr_temp_2->node_next;
                ptr_temp_1->node_next=ptr_temp_2->node_next;
                ptr_temp_2->node_next=ptr_temp_1;
            }
            ptr_list->LLB_size++;
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_delete(List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if(ptr_list != NULL)
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp_1;
            LLB_node* ptr_temp_2;
            if(position == 0)
            {
                *ptr_entry=ptr_list->LLB_head->node_entry;
                ptr_temp_1=ptr_list->LLB_head;
                ptr_list->LLB_head=ptr_temp_1->node_next;
                free(ptr_temp_1);
            }
            else
            {
                uint32_t i=0;   //revise
                for(ptr_temp_2=ptr_list->LLB_head;i<position-1;i++)
                    ptr_temp_2=ptr_temp_2->node_next;
                ptr_temp_1=ptr_temp_2->node_next;
                ptr_temp_2->node_next=ptr_temp_1->node_next;
                *ptr_entry=ptr_temp_1->node_entry;
                free(ptr_temp_1);
            }
            ptr_list->LLB_size--;
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_replace    (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)&&(ptr_entry    != NULL))
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp=ptr_list->LLB_head;
            uint32_t i=0;
            while(i< position)
            {
                ptr_temp=ptr_temp->node_next;
                i++;
            }
            ptr_temp->node_entry=*ptr_entry;
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
LLB_return_t LLB_retrieve   (List_LinkBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    if((ptr_list != NULL)&&(ptr_entry != NULL))
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp=ptr_list->LLB_head;
            uint32_t i=0;
            while(i< position)
            {
                ptr_temp=ptr_temp->node_next;
                i++;
            }
            *ptr_entry=ptr_temp->node_entry;
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
//edited to work with the files
LLB_return_t LLB_traverse   (List_LinkBased *ptr_list,file_cfg_t* ptr_cfg,void(*ptr_func)(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc))
{
    if((ptr_list != NULL)&&(ptr_func != NULL)&&(ptr_cfg != NULL))
    {
        if(ptr_list->LLB_InitStatus == true)
        {
            LLB_node* ptr_temp=ptr_list->LLB_head;
            while(ptr_temp != NULL)
            {
                (*ptr_func)(ptr_cfg,&(ptr_temp->node_entry));
                ptr_temp=ptr_temp->node_next;
            }
            return LLB_NO_ERRORS;
        }
        return LLB_NOT_INITIALIZED;
    }
    return LLB_INVALID_ARG;
}
#endif //DYNAMIC_ALLOCATION_EN
