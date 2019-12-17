#include "LinkeLists_APIs.h"


list_ret_t ListCreate(list_t *ptr_list)
{
    return LAB_create     (ptr_list);
}

list_ret_t ListFull(list_t *ptr_list)
{
    return LAB_full     (ptr_list);

}

list_ret_t ListDestroy(list_t *ptr_list)
{
    return LAB_destroy     (ptr_list);

}

list_ret_t ListEmpty(list_t *ptr_list)
{
    return LAB_empty     (ptr_list);

}

uint32_t ListSize(list_t *ptr_list)
{
    return LAB_size     (ptr_list);

}

list_ret_t ListDelete(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    return LAB_delete     (ptr_list,ptr_entry,position);

}

list_ret_t ListRetrieve(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    return LAB_retrieve     (ptr_list,ptr_entry,position);

}

list_ret_t ListInsert(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    return LAB_insert     (ptr_list,ptr_entry,position);

}

list_ret_t ListReplace(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position)
{
    return LAB_replace     (ptr_list,ptr_entry,position);

}

list_ret_t ListTravers(List_ArrBased *ptr_list,file_cfg_t* ptr_cfg,f_ret_t(*ptr_func)(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc))
{
    return LAB_traverse     (ptr_list,ptr_cfg,ptr_func);

}

list_ret_t ListSearchByALL(List_ArrBased *ptr_list,LIST_ENTRY*ptr_entry,uint8_t*search_result,uint16_t*entry_index)
{
    return LAB_search_by_all(ptr_list,ptr_entry,search_result,entry_index);

}
list_ret_t ListSearchByIDOnly(List_ArrBased *ptr_list,uint16_t*entry_id,uint8_t*search_result,uint16_t*entry_index)
{
    return LAB_search_by_id(ptr_list,entry_id,search_result,entry_index);

}
