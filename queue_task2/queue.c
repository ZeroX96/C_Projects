/*
 * queue.c
 *
 *  Created on: 5 Jul 2018
 *      Author: Mahmoud
 */
#include "queue.h"
#include <stdlib.h>

bool_t memcopy(ecore_u8 * dst,ecore_u8 * src,ecore_u16 size)
{
	bool_t b_ret_val=E_TRUE;
	if((dst != NULL) && (src != NULL) && (size !=0))
	{
		while(size)
	{
		*dst=*src;
		dst++;
		src++;
		size--;
	}
	}
	else
	{
		b_ret_val=E_FALSE;
	}
	return b_ret_val;

}


queue_errors queue_create(queue *p_q,ecore_u16 size)
{
	queue_errors b_ret_val= _no_errors;
	if((p_q != NULL) && (size != 0))
	{
		p_q->queue_current_size=0;
		p_q->queue_max_size=size;
		p_q->q_first = NULL;
		p_q->q_last  = NULL;
	}
	else
	{
		b_ret_val=_invalid_parameters;
	}

	return b_ret_val;
}


queue_errors queue_push(queue *p_q,node_data*p_data)
{
	queue_errors b_ret_val=_no_errors;
	if((p_q != NULL) && (p_data != NULL))
	{
		if(p_q-> queue_current_size < p_q->queue_max_size)
		{
			queue_node *pn= (queue_node* )malloc(sizeof(queue_node));
			if(pn != NULL)
			{

				bool_t copying_res=memcopy((ecore_u8 *)& pn->data ,(ecore_u8 *) p_data,sizeof(node_data));

				if(copying_res == E_TRUE)
				{
				    p_q->queue_current_size++;
				//printf("p_q->queue_current_size= %d\n",p_q->queue_current_size);
                    if(p_q->q_last == NULL)
                    {
                        p_q->q_last=pn;
                        //printf("no i'm not a null\n");
                        p_q->q_last->p_next=NULL;
                    }
                    else
                    {
                        p_q->q_last=pn;
                        p_q->q_last->p_next=(queue_node*)pn;  //test
                    }
				}
				else
				{
					b_ret_val=_copying_error;
				}

				if(p_q->q_first == NULL)
				{
					p_q->q_first=(void *)pn;  //test
				}

			}
			else
			{
				b_ret_val=_internal_mem_error;
			}
		}
		else
		{
			b_ret_val=_queue_full;
		}
	}
	else
	{
		b_ret_val = _invalid_parameters;
	}
	return b_ret_val;
}

queue_errors queue_pop(queue * p_q,node_data * p_data)
{
	queue_errors b_ret_val=_no_errors;
	if((p_q != NULL) && (p_data != NULL))
	{

        //printf("p_q->queue_current_size= %d before testing\n",p_q->queue_current_size);
		if(p_q->queue_current_size > 0 )
		{
        //printf("p_q->queue_current_size= %d after testing\n",p_q->queue_current_size);
			bool_t copying_res=memcopy((ecore_u8 *)p_data,(ecore_u8 *)&(((queue_node*)p_q->q_last)->data),sizeof(node_data));
			if(copying_res == E_TRUE)
			{
				queue_node *pn =(queue_node *) p_q->q_first;
				p_q->q_first= (queue_node *)p_q ->q_first->p_next;
				free( (void*)pn);
				p_q->queue_current_size--;
				//printf("p_q->queue_current_size= %d\n",p_q->queue_current_size);
			}
			else
			{
				b_ret_val=_copying_error;
			}
		}
		else
		{
		   // printf("it says the queue is empty\n");
			b_ret_val=_queue_empty;
		}
	}
	else
	{
		b_ret_val = _invalid_parameters;
	}
	return b_ret_val;
}



