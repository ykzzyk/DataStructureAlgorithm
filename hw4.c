#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

void print(struct Node *head){
    while (head != NULL)
    {
        printf("%d —> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// push the new element to the linked list
void add_element(Node *head, int val) {
    while (head->next != NULL) {
      head = head->next;
    }
    // add the element to the end of the list
    head->next = (Node *) malloc(sizeof(Node));
    head->next->data = val;
    head->next->next = NULL;
}

Node *merge_lsts(Node *lst1 , Node *lst2 , Node *merging){
	Node *head3;
	
	if(lst1 == NULL) return lst2;
	if(lst2 == NULL) return lst1;

  lst1 = lst1->next; // remove the header 0
  lst2 = lst2->next; // remove the header 0
	
  /*
  Initilize the merging list
  */
  if(lst1->data <= lst2->data)
  {
    merging = lst1;
    lst1 = merging->next;
  }
  else
  {
    merging = lst2;
    lst2 = merging->next;
  }
	head3 = merging;
	
	while(lst1 && lst2) // when lst 1 != NULL and lst2 != NULL
	{
		if(lst1->data <= lst2->data)
		{
			merging->next = lst1;
			merging = lst1;
			lst1 = merging->next;
		}
		else
		{
			merging->next = lst2;
			merging = lst2;
			lst2 = merging->next;
		}
	}
	
	if(lst1==NULL) merging->next = lst2;
	if(lst2==NULL) merging->next = lst1;
	
	return head3;	
}



int main()
{

  Node *head1 = NULL, *head2, *merged_lst = NULL;
  int i, a, num1, num2;
  char stop;

  head1 = (struct Node*)malloc(sizeof(struct Node));
  head2 = (struct Node*)malloc(sizeof(struct Node));

  printf("please type the numbers in List 1: ");
  scanf("%d", &num1);
  printf("List 1 is: ");
  for (i = 0; i < num1; i++){
    scanf("%d", &a);
    add_element(head1, a);
  }

  printf("please type the numbers in List 2: ");
  scanf("%d", &num2);
  printf("List 2 is: ");
  for (i = 0; i < num2; i++){
    scanf("%d", &a);
    add_element(head2, a);
  }

  printf("The linked list 1 is: ");
  print(head1);
  printf("The linked list 2 is: ");
  print(head2);
  
  merged_lst = merge_lsts(head1, head2, merged_lst);
  printf("The merged list is: ");
  print(merged_lst);

  return 0;
}