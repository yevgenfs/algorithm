#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>

typedef struct Stack
{
	uint32_t u32_item_size;
	uint16_t u16_stack_size;
	uint16_t u16_top;
	void*    P_arr; 
}stack_t;

typedef enum StackErr
{
  eStackErrOk,
  eStackErrIsFull,
  eStackErrIsEmpty,
  eStackErrInvalidArgument,
  eStackErrAllocationError,
  eStackErrIsNotEmpty
}e_stack_err_t;


stack_t* create(uint32_t u32L_size_of_element, uint16_t u16L_stack_size);
bool is_full(stack_t* objPL_stack);
bool is_empty(stack_t* objPL_stack);
e_stack_err_t push(stack_t* objPL_stack, void* PL_item);
e_stack_err_t pop(stack_t* objPL_stack, void* PL_item);
e_stack_err_t peak(stack_t* objPL_stack, void* PL_item);
e_stack_err_t delete_stack(stack_t* objPL_stack);
void stack_demo(void);

#endif