/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL,*curr=head,*nextptr;
        int cnt=0;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        curr=head;
        if(cnt<k)return head;
        int count=0;
        while(count<k){
            nextptr=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nextptr;
            count++;
        }
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k);
        }
        return prev;
    }
};
//try recursively
//code studio is more tricky
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node *dummy = new Node(1);
   dummy->next = head;
   
   Node *prev = dummy,*curr=dummy,*nextptr=dummy;
   
   int count = 0;    
   while(curr->next != NULL){
       curr = curr->next;
       count++;
   }
   
   int j = 0;
   while(count>0 && j<n){
       curr = prev->next;
       nextptr = curr->next;
       int x = (b[j]<=count) ? b[j] : count;
       if(x==0){
           j++;
           continue;
       }
       for(int i=1;i<x;i++){
           curr->next = nextptr->next;
           nextptr->next = prev->next;
           prev->next = nextptr;
           nextptr = curr->next;
       }
       prev = curr;
       count -= b[j];
       j++;
   }
   return dummy->next;
}
