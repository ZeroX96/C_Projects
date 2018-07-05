/*
 * queue.h
 *
 *  Created on: 5 Jul 2018
 *      Author: Mahmoud
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "common.h"

typedef enum
{
	_no_errors=0,			//0
	_invalid_parameters,	//1
	_internal_mem_error,	//2
	_copying_error,			//3
	_queue_full,			//4
	_queue_empty,			//5

}queue_errors;


typedef struct
{
	ecore_u16 data;
}node_data;

typedef struct queue_Node
{
	node_data data;
	struct queue_Node *p_next;
}queue_node;

typedef struct
{
	ecore_u16 queue_current_size;
	ecore_u16 queue_max_size;
	queue_node *q_first;
	queue_node *q_last;
}queue;


queue_errors queue_create(queue *p_q,ecore_u16 size);

queue_errors queue_push(queue *p_q,node_data*p_data);

queue_errors queue_pop(queue * p_q,node_data * p_data);





#endif /* QUEUE_H_ */
