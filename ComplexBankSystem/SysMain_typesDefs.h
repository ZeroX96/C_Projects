#ifndef __SYSMAIN_TYPESDEFS_H__
#define __SYSMAIN_TYPESDEFS_H__


#include <stdint-gcc.h>
#include <stdbool.h>


//SYSTEM OPTIONS
#define SIGN_IN 	'I'
#define SIGN_UP 	'U'
#define SYS_MANAGE 	'M'
#define SYS_EXIT	'E'
//ACCOUNT OPTIONS
#define SIGNOUT		'S'
#define MANAGE		'M'
#define HISTORY		'H'
#define TRANSFER	'T'
#define WITHDRAW	'W'
#define DEPOSITE	'D'
#define CHANGE_DATA 'C'
#define BACK	 	'B'
#define DELETE		'D'
#define REPEATE		'R'
#define LIST		'L'
//ACCOUNT MANAGEMENT OPTIONS
#define TYPE_CH 	'T'
#define NAME_CH 	'N'
#define NUMB_CH 	'U'
#define PASS_CH 	'P'
#define PIN__CH 	'I'
#define ADDR_CH 	'A'
#define CURR_CH 	'C'

#define MAX_LIST_LENGTH 20

#define NAME_MAX_LENGTH 20

#define MAX_PASS_LENGTH 20


//perform data backup per operation or per minute by commenting the next line
#define BACKUP_PER_OPERATION_EN

#ifndef BACKUP_PER_OPERATION_EN
#define BACKUP_PER_MINUTE_EN
#endif // BACKUP_PER_OPERATION_EN



typedef struct date
{
    int year;
    char month;
    char day;
}date_t;

typedef enum systemOps
{
    deposite,
    withdrow,
    transfer,
    sys_exit,
}systemOps_t;


typedef struct history
{
    date_t date;
    systemOps_t operation;
    int         balanceBefore;
    int         balanceAfter;
}history_t;
typedef enum currency
{
	US_Dollar_cur,
	UK_POUND_cur,
	TU_LIRA_cur,
	KS_REIAL_cur,
	EG_POUND_cur,
	JA_YEN_cur,
}currency_t;
typedef enum acc_type
{
	CHECKING_ACCOUNT,
	SAVINGS_ACCOUNT,
	BROKERAGE_ACCOUNT,
	MONEY_MARKET_ACCOUNT,
	CERTIFICATE_OF_DEPOSITE_ACCOUNT,
	INDIVIDUAL_RETIREMENT_ARRANGEMENT_ACCOUNT,
}acc_type_t;

typedef struct account
{
    char        acc_name[NAME_MAX_LENGTH+1];   //plus one for the NULL char
    char        acc_add [NAME_MAX_LENGTH+1];   //plus one for the NULL char
    char        acc_pass[NAME_MAX_LENGTH+1];   //plus one for the NULL char
    acc_type_t  acc_type;
    int         acc_numb;
    int         acc_pin;
    //date_t      acc_open_date;  //got by c system
    double      acc_balance;
    currency_t  acc_currency;
}account_t;

typedef account_t LIST_ENTRY;

typedef enum
{
	SYS_ER_NO,
	SYS_ER_LIST_INIT_FAILED,
}sys_ret_t;

#endif //__SYSMAIN_TYPESDEFS_H__
