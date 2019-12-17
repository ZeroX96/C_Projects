
#ifndef __LISTS_ARRBASED_APIS_H__
#define __LISTS_ARRBASED_APIS_H__

#include "Includes.h"



//StaticListsApiS
LAB_return_t LAB_create     (List_ArrBased *ptr_list);
LAB_return_t LAB_empty      (List_ArrBased *ptr_list);
LAB_return_t LAB_full       (List_ArrBased *ptr_list);
uint32_t     LAB_size       (List_ArrBased *ptr_list);
LAB_return_t LAB_destroy    (List_ArrBased *ptr_list);
LAB_return_t LAB_insert     (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_delete     (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_replace    (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_retrieve   (List_ArrBased *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
LAB_return_t LAB_traverse (List_ArrBased *ptr_list,file_cfg_t* ptr_cfg,f_ret_t(*ptr_func)(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc));
LAB_return_t LAB_search_by_id(List_ArrBased *ptr_list,uint16_t* ptr_entry_id,uint8_t*ptr_search_result,uint16_t*ptr_entry_index);
LAB_return_t LAB_search_by_all(List_ArrBased *ptr_list,LIST_ENTRY* ptr_entry,uint8_t*ptr_search_result,uint16_t*ptr_entry_index);

#endif //__LISTS_ARRBASED_APIS_H__

