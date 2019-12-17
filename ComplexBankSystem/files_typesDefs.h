#ifndef __FILES_TYPESDEFS_H__
#define __FILES_TYPESDEFS_H__

#include <stdint-gcc.h>
#include <stdbool.h>



#define MAX_FILE_NAME 25


//Hash Defines FOR FILE OPENING MODES   /**< to be used as opening modes */
#define R       "r"      //Open an existing file for reading.
#define W       "w"      //Create a file for writing. If the file already exists, discard the current contents.
#define A       "a"      //Append: open or create a file for writing at the end of the file.
#define R_PLUS  "r+"     //Open an existing file for update (reading and writing).
#define W_PLUS  "w+"     //Create a file for update. If the file already exists, discard the current contents.
#define A_PLUS  "a+"     //Append: open or create a file for update; writing is done at the end of the file.
#define RB      "rb"     //Open an existing file for reading in binary mode.
#define WB      "wb"     //Create a file for writing in binary mode. If the file already exists, discard the current contents.
#define AB      "ab"     //Append: open or create a file for writing at the end of the file in binary mode.
#define RB_PLUS "rb+"    //Open an existing file for update (reading and writing) in binary mode.
#define WB_PLUS "wb+"    //Create a file for update in binary mode. If the file already exists, discard the current contents.
#define AB_PLUS "ab+"    //Append: open or create a file for update in binary mode; writing is done at the end of the file.

#ifndef NULL
#define NULL ((void*)0)
#endif //NULL


typedef enum ret_val
{
    F_ER_NO,
    F_ER_INV_PARAM,
    F_ER_ALREADEY_INITIATED,
    F_ER_ALREADEY_UNINITIATED,
    F_ER_NOT_INITIALIZED,
	F_ER_CANT_READ,
	F_ER_CANT_WRITE,
}f_ret_t;

typedef struct
{
    FILE*       ptr_file;
    char        file_name_obj[MAX_FILE_NAME];
    bool        file_init_state;
}file_cfg_t;

#endif // __FILES_TYPESDEFS_H__
