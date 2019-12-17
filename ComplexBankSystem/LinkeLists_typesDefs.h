#ifndef __LINKEDLISTS_TYPESDEFS_H__
#define __LINKEDLISTS_TYPESDEFS_H__

#include "SysMain_typesDefs.h"
//system cfg
#define MAX_LIST_LENGTH 20

typedef enum
{
    LAB_NO_ERRORS,
    LAB_ERROR_FOUND,
    LAB_INVALID_ARG,
    LAB_EMPTY,
    LAB_NOT_EMPTY,
    LAB_FULL,
    LAB_NOT_FULL,
    LAB_NOT_INITIALIZED,
	LAB_NOT_FOUND,
}LAB_return_t;

typedef struct {
    LIST_ENTRY  LAB_entry_arr[MAX_LIST_LENGTH];
    uint32_t    LAB_size;
    bool        LAB_InitStatus;//may add an extra variable to define whither initialized or not
}List_ArrBased;

typedef LAB_return_t list_ret_t;

//if static
typedef List_ArrBased list_t;
#endif //__LINKEDLISTS_TYPESDEFS_H__
