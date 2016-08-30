#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct node
{
	int data;
	struct node* next;	
}node;

node* removenode(node **head, int x);

int main(){
	node *head = NULL;
	node *temp = NULL;
	node *current = NULL;
	int k = 100;

	temp = (node*)malloc(sizeof(node));
	temp->data = k++;
	temp->next = NULL;
	head = temp;
	current = temp;

	for(int i = 0; i < 4 ; i++){
		temp = (node*)malloc(sizeof(node));
		temp->data = k++;
		temp->next = NULL;
		current->next = temp;
		current = temp;

	}



	temp = head;
	
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp=temp->next;

	}
	printf("\n");


	temp = head;

	node **splptr = &head;

	current = removenode(splptr, 3);	

	temp = current;
	
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp=temp->next;

	}
	printf("\n");



	return 0;
}



node* removenode(node **head,int x){
node *ptr = NULL;
node *temp = NULL;
node *temp1 = NULL;
temp = *head;
//printf("%d",temp->data);
if(x==1){
	*head = (*head)->next;
	free(temp);
	return *head;
}
for(int i =0;i<x-2;i++){
	temp = temp->next;

}

temp1 = temp->next;
ptr = temp->next->next;
temp->next = ptr;
free(temp1);
return *head;

}




