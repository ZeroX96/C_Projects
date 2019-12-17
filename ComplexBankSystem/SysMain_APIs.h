#ifndef __SYSMAIN_APIS_H__
#define __SYSMAIN_APIS_H__

#include "Includes.h"

//SystemApis
sys_ret_t SysInit(file_cfg_t* ptr_file_input,file_cfg_t* ptr_file_output,list_t* ptr_sys_list,char input_file_name[],char output_file_name[],uint8_t enc_key);
sys_ret_t SysDeInit(file_cfg_t* ptr_file_input,file_cfg_t* ptr_file_output,list_t* ptr_sys_list,char input_file_name[],char output_file_name[],uint8_t enc_key);
sys_ret_t SysBegin();
sys_ret_t SysEnd();
sys_ret_t SysRestore(file_cfg_t* ptr_file_input,list_t* ptr_sys_list,uint8_t enc_key);
sys_ret_t SysBackUp(file_cfg_t* ptr_file_input,list_t* ptr_sys_list,uint8_t enc_key);
sys_ret_t SysSignIn(list_t* list);
sys_ret_t SysSignUp(list_t* list);
sys_ret_t SysManage(list_t* list);
sys_ret_t SysCurrencyExchange(int from,int to,double* value);
void      SysDelay();
#endif // __SYSMAIN_APIS_H__

