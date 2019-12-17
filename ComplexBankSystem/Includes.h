#ifndef __INCLUDES_H__
#define __INCLUDES_H__
//library includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
//project includes
#include "Encryption_typesDefs.h"
#include "files_typesDefs.h"
#include "LinkeLists_typesDefs.h"
#include "Lists_ArrBased_typesDefs.h"
#include "SysMain_typesDefs.h"

#include "files_apis.h"
#include "LinkeLists_APIs.h"
#include "Lists_ArrBased_APIs.h"
#include "SysMain_APIs.h"

/*#include "HashDefines.h"
#include "LinkedLists.h"
#include "encryption.h"
#include "files.h"
#include "Zgraphics.h"
#include "Lists_ArrBased.h"
#include "Mouse.h"
#include "SysMain.h"*/

#ifndef EOF
#define EOF (-1)
#endif // EOF

#ifndef EOL
#define EOL '\n'
#endif // EOL

#ifndef NUL
#define NUL '\0'
#endif // NUL

#ifndef NULL
#define NULL ((void*)0)
#endif // NULL

#define ON  1
#define OFF 0


#endif // __INCLUDES_H__

