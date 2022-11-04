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
//case 1
struct node* delFirst(struct node* head){
    struct node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
}
//case 2
struct node* delLast(struct node* head){
    struct node* temp=head;
    struct node* temp2;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
}
//case 3
struct node* delInter(struct node* head,int pos){
  struct node* temp=head;
  struct node* temp2=NULL;
  if(pos==1){
    head=delFirst(head);
    return head;
  }
  while(pos>1){
    temp=temp->next;
    pos--;
  }
  if(temp->next==NULL){
    head=delLast(head);
  }
  else{
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
  }
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
    head=insertAtEnd(head,24);
    head=insertAtEnd(head,25);
    printf("Before ddeleteion \n");
    print(head);
    printf("After delete the  node \n");
  //  head=delFirst(head);
  //  head=delLast(head);
    head=delInter(head,3);
    print(head);
    return 0;
}
