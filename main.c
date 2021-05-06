#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Stack
{
	int32_t top;
	uint8_t size;
	int32_t* arr; 
};

struct Stack* create(uint8_t size)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top =  -1;
	stack->arr = (int32_t*)malloc(stack->size * sizeof(int32_t));
	return stack;
}

uint8_t is_full(struct Stack* stack)
{
	return stack->top == stack->size - 1;
}

uint8_t is_empty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int32_t item)
{
	if(is_full(stack))
		return;
	stack->arr[++stack->top] = item;
}

int32_t pop(struct Stack* stack)
{
	if(is_empty(stack))
		return -1;
	return stack->arr[stack->top--];
}

int32_t peak(struct Stack* stack)
{
	if(is_empty(stack))
		return 0;
	return stack->arr[stack->top];
}

int main(void) 
{
	struct Stack* stack = create(100);
	
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	
	printf("%d popped \n",pop(stack));
	printf("%d popped \n",pop(stack));
	
	return 0;
}
