/*
 ============================================================================
 Name        : queue_task.c
 Author      : ZeroX86
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "common.h"
#include <string.h>

int main(void) {
	queue m3tz;
	queue_errors creation_res = queue_create(&m3tz,20);

	printf("creation_res = %d \n",creation_res);
	//
	node_data abdo;
	printf("abdo's data is %d \n",abdo.data);
	queue_errors pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);

	//
	abdo.data=30;
	printf("abdo's data is %d \n",abdo.data);
	//

	queue_errors push_res = queue_push(&m3tz,&abdo);
	printf("push_res = %d \n",push_res);
	printf("abdo's data is %d \n",abdo.data);
	pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
	pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
	//

	//
	pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
	//
	push_res = queue_push(&m3tz,&abdo);
	printf("push_res = %d \n",push_res);

	printf("abdo's data is %d \n",abdo.data);
	abdo.data=50;
	printf("abdo's data is %d \n",abdo.data);
	pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
    pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
	pop_res = queue_pop(&m3tz,&abdo);
	printf("pop_res = %d \n",pop_res);
	printf("abdo's data is %d \n",abdo.data);
    /*
    int check=0;
    printf("if wanna add press 0  else take press 1\n");
    scanf("%d",&check);
    if(check == 0)
    {

    }

	puts("\n!!!Hello World!!!");*/ /* prints !!!Hello World!!! */
    int check=0;
	scanf("%d",&check);
	return EXIT_SUCCESS;
}
