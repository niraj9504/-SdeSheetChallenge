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
//M1 iterative 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr;
        
        while(curr){
            nextptr=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
};
//m2 recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
};
//m3 recursive type like 1st one
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy=NULL;
        while(head){
            ListNode* nextptr=head->next;
            head->next=dummy;
            dummy=head;
            head=nextptr;
        }
        return dummy;
    }
};
