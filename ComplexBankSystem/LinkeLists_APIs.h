#ifndef __LINKEDLISTS_APIS_H__
#define __LINKEDLISTS_APIS_H__

#include "Includes.h"


#include "LinkeLists_typesDefs.h"
#include "SysMain_typesDefs.h"

//GeneralListsApis
list_ret_t ListCreate(list_t *ptr_list);
list_ret_t ListFull(list_t *ptr_list);
list_ret_t ListDestroy(list_t *ptr_list);
list_ret_t ListEmpty(list_t *ptr_list);
uint32_t   ListSize(list_t *ptr_list);
list_ret_t ListDelete(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
list_ret_t ListRetrieve(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
list_ret_t ListInsert(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
list_ret_t ListReplace(list_t *ptr_list,LIST_ENTRY *ptr_entry,uint32_t position);
list_ret_t ListTravers(List_ArrBased *ptr_list,file_cfg_t* ptr_cfg,f_ret_t(*ptr_func)(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc));
list_ret_t ListSearchByIDOnly(List_ArrBased *ptr_list,uint16_t*entry_id,uint8_t*search_result,uint16_t*entry_index);
list_ret_t ListSearchByALL(List_ArrBased *ptr_list,LIST_ENTRY*ptr_entry,uint8_t*search_result,uint16_t*entry_index);

#endif //__LINKEDLISTS_APIS_H__
