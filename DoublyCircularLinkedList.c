#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* addtoEmpty(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* addtobeg(struct node* tail,int data){
    struct node* new=addtoEmpty(data);
    if(tail==NULL){
        return new;
    }
    else{
        struct node* temp=tail->next;
        new->prev=tail;
        new->next=temp;
        temp->prev=new;
        tail->next=new;
        return tail;
    }
}

struct node* addatEnd(struct node* tail,int data){
     struct node* new=addtoEmpty(data);
     if(tail==NULL){
        return new;
     }
     else{
         struct node* temp=tail->next;
         new->next=temp;
         new->prev=tail;
         tail->next=new;
         temp->prev=new;
         tail=new;
         return tail;
     }
}

struct node* addatIndex(struct node* tail,int data,int pos){
     struct node* new=addtoEmpty(data);
     if(tail==NULL){
        return new;
     }
         struct node* temp=tail->next;
         while(pos>1){
            temp=temp->next;
            pos--;
         }
         new->prev=temp;
         new->next=temp->next;
         temp->next->prev=new;
         temp->next=new;
         if(temp==tail){
            tail=tail->next;
         }
         return tail;
}

struct node* delFirst(struct node* tail){
    if(tail==NULL){
        return tail;
     }
    struct node* temp=tail->next;
     if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
     }
     tail->next=temp->next;
     temp->next->prev=tail;
     free(temp);
     return tail;

}


void print(struct node* tail){
    struct node* temp=tail->next;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}

int main(){
    struct node* tail=NULL;
    tail=addtoEmpty(45);
    tail=addtobeg(tail,34);
    tail=addtobeg(tail,3);
    tail=addatEnd(tail,69);
    tail=addatIndex(tail,34,2);
    tail=delFirst(tail);
    print(tail);
    return 0;
}


 