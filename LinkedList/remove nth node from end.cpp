//m1 (slow)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* temp=head;
        while(temp){
            s++;
            temp=temp->next;
        }
        if(s==1)return NULL;
        int k=s-n+1;
        if(k==1)return head->next;
        temp=head;
        while(k!=2){
            temp=temp->next; 
            k--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
//m2
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead=new ListNode();
        newHead->next=head;
        ListNode* slow=newHead,*fast=newHead;
        for(int i=1;i<=n;i++)fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return newHead->next;
    }
};
//missing step
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int n)
{
        LinkedListNode<int> *newHead=new LinkedListNode<int>(1);
        LinkedListNode<int> *slow=newHead,*fast=newHead;
        newHead->next=head;
        if(head==NULL || n==0)return head;//imp. step
        for(int i=1;i<=n;i++)fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return newHead->next;
}
