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

void print(struct node* head){
    struct node* ptr;
    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node* reverse(struct node* head){
    struct node* ptr1=head;
    struct node* ptr2=ptr1->next;
    
    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}
int main(){
    struct node* head=NULL;
    struct node* ptr;
    head=addtoEmpty(head,40);
    head=insertAtEnd(head,45);
    head=insertAtEnd(head,23);
    head=insertAtEnd(head,24);
    head=insertAtEnd(head,25);
    printf("Before reverse \n");
    print(head);
    printf("After reverse \n");
    head=reverse(head);
    print(head);
}