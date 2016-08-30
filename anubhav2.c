#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node* SortedMergeExp(struct node* a, struct node* b);
struct node* SortedMergeGoal(struct node* a, struct node* b);
void MergeSort(struct node** headRef,int h);
void FrontBackSplit(struct node* source,struct node** frontRef, struct node** backRef);


typedef struct node{
	char name[20];
	int goals;
	char club[20];
	char country[20];
	int age;
	int exp;
	struct node *next;
}node; 

int main(){
	int ch;
	node *head=NULL,*temp=NULL,*current=NULL;
	node *delete1=NULL,*delete2=NULL;
	char name[20];
	int goalcount;

	printf("1. Insert a Player Info\n");
	printf("2. Sort the list of players on the basis of their Experience\n");
	printf("3. Sort the list of players on the basis of their Goal Count\n");
	printf("4. Delete a player from the list\n");
	printf("5. Display the whole list\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	
	while(ch!=6){
		switch(ch){
			case 1: 
				
				temp = (node*)malloc(sizeof(node));
				printf("Enter Name\n");

				scanf("%s",temp->name);
				printf("Enter Goal Scored\n");
				scanf("%d",&goalcount);
				temp->goals = goalcount;
				printf("Enter Club name\n");
				scanf("%s",temp->club);
				printf("Enter Country name\n");
				scanf("%s",temp->country);
				printf("Enter Age\n");
				scanf("%d",&temp->age);
				printf("Enter Experience\n");
				scanf("%d",&temp->exp);
				if(head==NULL){
					head = temp;
					current = temp;
					temp->next = NULL;

				}
				else{
					current->next = temp;
					temp->next = NULL;
					current = temp;
				}


			break;

			case 2:
				MergeSort(&head,3);
				printf("List Sorted.\n);");
			break;

			case 3:
				MergeSort(&head,2);
				printf("List Sorted.\n);");

			break;
			
			case 4:
				printf("Enter the player name to be deleted\n");
				scanf("%s",name);
				
				delete1 = head;
				
				if(strcmp(delete1->name,name) == 0){
					head = delete1->next;
					free(delete1);
					delete1 = head;
					delete2 = head;
					printf("\tFirst Node deleted\n");
				}
				else{
					delete2 = head;
					delete1 = delete1->next;
					while(delete1!=NULL){
						if(strcmp(delete1->name,name) == 0){
							delete2->next = delete1->next;
							free(delete1);
							printf("Player Info Deleted");
						}
						delete2 = delete2->next;
						delete1 = delete2->next;
					}
				}
				

			break;
			
			case 5:
				temp = head;
				while(temp!=NULL){
					printf("\t%s\t%d\t%s\t%s\t%d\t%d\n",temp->name,temp->goals,temp->club,temp->country,temp->age,temp->exp);
					temp=temp->next;
				}

			break;
			
		}
		printf("What next\n");
		scanf("%d",&ch);

	}
	


	
	return 0;
}




void MergeSort(struct node** headRef,int h)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
 
  /* Base case -- length 0 or 1 */
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }
 
  /* Split head into 'a' and 'b' sublists */
  FrontBackSplit(head, &a, &b); 
 
  /* Recursively sort the sublists */
  MergeSort(&a,h);
  MergeSort(&b,h);
 
  /* answer = merge the two sorted lists together */
  
  if(h==2)
  	*headRef = SortedMergeExp(a, b);
  else
  	*headRef = SortedMergeGoal(a, b);
}



struct node* SortedMergeExp(struct node* a, struct node* b)
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->exp <= b->exp)
  {
     result = a;
     result->next = SortedMergeExp(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMergeExp(a, b->next);
  }
  return(result);
}


struct node* SortedMergeGoal(struct node* a, struct node* b)
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->goals <= b->goals)
  {
     result = a;
     result->next = SortedMergeGoal(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMergeGoal(a, b->next);
  }
  return(result);
}


void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    /* length < 2 cases */
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}
 
