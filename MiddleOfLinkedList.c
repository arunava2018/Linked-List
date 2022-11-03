/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    //brute force approach
    //time complexity will be--> O(n)+O(n/2)
    //space complexity will be-->O(1)
    
    int count=0,main_count=0;
    struct ListNode *p,*q;
    p=head;
    q=head;
    while(q!=NULL){
        count++;
        q=q->next;
    }
    if(count%2!=0){
        main_count=(count+1)/2;
    }
    else{
        main_count=(count/2)+1;
    }
    while(main_count!=1){
        p=p->next;
        main_count--;
    }
    head=p;
    return head;

}