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
struct node* delFirst(struct node* head){
    struct node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
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

int main(){
    struct node* head=NULL;
    struct node* ptr;
    head=addtoEmpty(head,40);
    head=insertAtEnd(head,45);
    head=insertAtEnd(head,23);
    printf("Before ddeleteion \n");
    print(head);
    printf("After delete the first node \n");
    head=delFirst(head);
    print(head);
    return 0;
}