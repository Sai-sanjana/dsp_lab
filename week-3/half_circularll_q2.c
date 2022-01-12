/* Program to split a circular linked list into two halves */
#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void split(struct Node *head,struct Node **head1_ref,struct Node **head2_ref);
void insert(struct Node **head_ref, int data);
void display(struct Node *head);


void main()
{
  int i,n,val;

  struct Node *head = NULL;
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;

  printf("\n Enter number of nodes to be inserted in circular linked list: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    printf("\n Enter %d node value ",i);
    scanf("%d",&val);
    insert(&head,val);
  }

  printf("\n\n Original Circular Linked List");
  display(head);

  /* Split the list */
  split(head, &head1, &head2);

  printf("\n\nFirst Circular Linked List");
  display(head1);

  printf("\n\nSecond Circular Linked List");
  display(head2);

}


void split(struct Node *head,struct Node **head1_ref,struct Node **head2_ref)
{
  struct Node *ptr2 = head;
  struct Node *ptr1 = head;

  if(head == NULL)
    return;

  while(ptr1->next != head && ptr1->next->next != head)
  {
     ptr1 = ptr1->next->next;
     ptr2 = ptr2->next;
  }

  if(ptr1->next->next == head)
    ptr1 = ptr1->next;

  *head1_ref = head;

  if(head->next != head)
    *head2_ref = ptr2->next;

  /* Make second half circular */
  ptr1->next = ptr2->next;

  /* Make first half circular */
  ptr2->next = head;
}


void insert(struct Node **head_ref, int data)
{
  struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref;
  ptr1->data = data;
  ptr1->next = *head_ref;


  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;
    temp->next = ptr1;
  }
  else
     ptr1->next = ptr1; /*For the first node */

  *head_ref = ptr1;
}


void display(struct Node *head)
{
  struct Node *temp = head;
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d->", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}
















