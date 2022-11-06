#include <stdio.h>
#include <stdlib.h>

// node creation
struct node {
  int data;
  struct node* link;
};

struct node* addtoEmpty(int data){
  struct node* temp=malloc(sizeof(struct node*));
  temp->data=data;
  temp->link=NULL;
  return temp;
}
struct node* insertAtEnd(struct node *head, int data){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link=NULL;
    struct node* p = head;

    while(p->link!=NULL){
        p = p->link;
    }
    p->link = ptr;
    return head;
}

struct node* insert(struct node *head, int data){
    struct node* temp;
    struct node * ptr = malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    int key=data;
    if(head==NULL || key<head->data){
        ptr->link=head;
        head=ptr;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->data<key){
            temp=temp->link;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
    return head;
}
void linkedListTraversal(struct node *head)
{
    struct node* ptr=head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
int main(){
    struct node* head=NULL;
    head=addtoEmpty(24);
    insertAtEnd(head,45);
    insertAtEnd(head,56);
    insertAtEnd(head,100);
    head=insert(head,75);
    linkedListTraversal(head);
    return 0;
}


