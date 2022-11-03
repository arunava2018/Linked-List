#include <stdio.h>
#include <stdlib.h>

// node creation
struct node {
  int data;
  struct node* next;
  struct node* prev;
};
struct node* addtoEmpty(struct node* head,int data){
  struct node* temp=malloc(sizeof(struct node*));
  temp->prev=NULL;
  temp->data=data;
  temp->next=NULL;
  head=temp;
  return head;
}
//case 1
struct node* insertAtBeginning(struct node* head,int data){
  struct node* temp=malloc(sizeof(struct node*));
  temp->prev=NULL;
  temp->data=data;
  temp->next=NULL;
  temp->next=head;
  head->prev=temp;
  head=temp;
  return head;
}
//case 2
struct node* insertAtEnd(struct node* head,int data){
   struct node* temp,*tp;
   temp=malloc(sizeof(struct node*));
   temp->prev=NULL;
   temp->data=data;
   temp->next=NULL;
   tp=head;
   while(tp->next!=NULL){
    tp=tp->next;
   }
   tp->next=temp;
   temp->prev=tp;
   return head;
}


int main(){
struct node* head=NULL;
struct node* ptr;
head=addtoEmpty(head,40);
head=insertAtBeginning(head,42);
head=insertAtBeginning(head,4);
head=insertAtEnd(head,2);
ptr=head;
while(ptr!=NULL){
  printf("%d ",ptr->data);
  ptr=ptr->next;
}
return 0;
/* Save address of first node in head */
}

