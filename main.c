#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node
{
	int32_t data;
	struct node* left;
	struct node* right;
};

struct node* create(int32_t data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return(node);
}

void in_order(struct node* node)
{
	if(node == NULL)
		return;
	in_order(node->left);
	printf("%d \n",node->data);
	in_order(node->right);
}

struct node* insert(struct node* node, int32_t data)
{
	if(node == NULL)
		return create(data);;
	if(data < node->data)
	{
		node->left = insert(node->left, data);
	}
	else if(data > node->data)
	{
		node->right = insert(node->right, data);
	}
	return (node);
}

int main(void) 
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	in_order(root);
	
	return 0;
}
