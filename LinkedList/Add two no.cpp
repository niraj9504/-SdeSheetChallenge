//make this short
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        auto temp=ans;
        int p=0;
        while(l1!=NULL && l2!=NULL){
            int k=p+l1->val+l2->val;
            p=k/10;
            ListNode* tempar=new ListNode(k%10);
            temp->next=tempar;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int k=p+l1->val;
            p=k/10;
            ListNode* tempar=new ListNode(k%10);
            temp->next=tempar;
            temp=temp->next;
            l1=l1->next;
            //l2=l2->next;
        }
        while(l2!=NULL){
            int k=p+l2->val;
            p=k/10;
            ListNode* tempar=new ListNode(k%10);
            temp->next=tempar;
            temp=temp->next;
            //l1=l1->next;
            l2=l2->next;
        }
        if(p==1){
            ListNode* tempar=new ListNode(1);
            temp->next=tempar;
        }
        return ans->next;
    }
};

//short
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

Node *addTwoNumbers(Node *a, Node *b)
{
        int carry=0;
        Node* ans=new Node(0);
        Node* temp=ans;
        while(a || b || carry){
            int sum=0;
            if(a){
                sum+=a->data;
                a=a->next;
            }
            if(b){
                sum+=b->data;
                b=b->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
    return ans->next;
}
