#ifndef __FILES_APIS_H__
#define __FILES_APIS_H__
//#include "files_typesDefs.h"
//#include "SysMain_typesDefs.h"

#include "Includes.h"

//FilesApiS
f_ret_t FilesInit(file_cfg_t* ptr_cfg,char file_name[],char open_mode[]);
f_ret_t FilesDeInit(file_cfg_t* ptr_cfg);
f_ret_t FilesWriteRecord(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc);
f_ret_t FilesReadRecord(file_cfg_t* ptr_cfg,LIST_ENTRY *ptr_acc);
f_ret_t FilesRefresh(file_cfg_t *ptr_cfg_file);
f_ret_t FilesSysBackup(file_cfg_t* ptr_cfg,list_t *ptr_list);
f_ret_t FilesSysRestore(file_cfg_t* ptr_cfg,list_t *ptr_list);
f_ret_t FileEncrypt(file_cfg_t *file_ptr_in,file_cfg_t *file_ptr_out,uint8_t key);
f_ret_t FileDecrypt(file_cfg_t *file_ptr_in,file_cfg_t *file_ptr_out,uint8_t key);

#endif // __FILES_APIS_H__
