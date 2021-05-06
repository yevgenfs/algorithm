#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node
{
	int32_t data;
	struct node* next;
};

void display (struct node* n)
{
	while(n != NULL)
	{
		printf("%d \n",n->data);
		n = n->next;
	}
}

int main(void) 
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	head->data = 11;
	second->data = 32;
	third->data = 61;
	
	head->next = second;
	second->next = third;
	third->next = NULL;
	
	display(head);
	
	return 0;
}
