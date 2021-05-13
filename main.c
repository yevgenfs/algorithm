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

void post_order(struct node* node)
{
	if(node == NULL)
		return;
	post_order(node->left);
	post_order(node->right);
	printf("%d \n",node->data);
}

void in_order(struct node* node)
{
	if(node == NULL)
		return;
	in_order(node->left);
	printf("%d \n",node->data);
	in_order(node->right);
}

void pre_order(struct node* node)
{
	if(node == NULL)
		return;
	printf("%d \n",node->data);
	pre_order(node->left);
	pre_order(node->right);
}

int main(void) 
{
	struct node* root = create(1);
	root->left = create(2);
	root->right = create(3);
	root->left->left = create(4);
	
	printf("post_order \n");
	post_order(root);
	printf("in_order\n");
	in_order(root);
	printf("pre_order\n");
	pre_order(root);
	
	free(root->left->left);
	free(root->left);
	free(root->right);
	free(root);
	
	return 0;
}
