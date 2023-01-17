#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t* create(uint32_t u32L_size_of_element, uint16_t u16L_stack_size)
{
  stack_t* objL_stack = (stack_t*)malloc(sizeof(stack_t));
	objL_stack->u16_stack_size = u16L_stack_size;
	objL_stack->u16_top = 0;
  objL_stack->u32_item_size = u32L_size_of_element;
	objL_stack->P_arr = malloc(objL_stack->u16_stack_size * objL_stack->u32_item_size);
	return objL_stack;
}

bool is_full(stack_t* objPL_stack)
{
  if (objPL_stack == NULL)
    return 0;

	return objPL_stack->u16_top == objPL_stack->u16_stack_size;
}

bool is_empty(stack_t* objPL_stack)
{
  if (objPL_stack == NULL)
    return 0;

	return objPL_stack->u16_top == 0;
}

e_stack_err_t push(stack_t* objPL_stack, void* PL_item)
{
  if (objPL_stack == NULL)
    return eStackErrInvalidArgument;

	if(is_full(objPL_stack))
		return eStackErrIsFull;

	memcpy((objPL_stack->P_arr + (objPL_stack->u32_item_size * objPL_stack->u16_top)), PL_item, objPL_stack->u32_item_size);
  objPL_stack->u16_top++;
  return eStackErrOk;
}

e_stack_err_t pop(stack_t* objPL_stack, void* PL_item)
{
  if (objPL_stack == NULL)
    return eStackErrInvalidArgument;

	if(is_empty(objPL_stack))
		return eStackErrIsEmpty;

  objPL_stack->u16_top--;
  memcpy(PL_item, (objPL_stack->P_arr + (objPL_stack->u16_top * objPL_stack->u32_item_size)), objPL_stack->u32_item_size);
	return eStackErrOk;
}

e_stack_err_t peak(stack_t* objPL_stack, void* PL_item)
{
  if (objPL_stack == NULL)
    return eStackErrInvalidArgument;

	if(is_empty(objPL_stack))
		return eStackErrIsEmpty;
  
  memcpy(PL_item, (objPL_stack->P_arr + (objPL_stack->u16_top * objPL_stack->u32_item_size)), objPL_stack->u32_item_size);
	return eStackErrOk;
}

e_stack_err_t delete_stack(stack_t* objPL_stack)
{
  if (objPL_stack == NULL)
   return eStackErrInvalidArgument;
 
	free(objPL_stack);
	printf("successfully delete\n");
	return eStackErrOk;
}

void stack_demo(void)
{
  stack_t* objPL_stack = create(sizeof(uint32_t), 3);
  uint32_t u32L_element = 10;

  push(objPL_stack, &u32L_element);
  u32L_element = 20;
  push(objPL_stack, &u32L_element);
  u32L_element = 30;
  push(objPL_stack, &u32L_element);

  pop(objPL_stack, &u32L_element);
  printf("%d popped \n", u32L_element);
  pop(objPL_stack, &u32L_element);
  printf("%d popped \n", u32L_element);

  delete_stack(objPL_stack);
}
