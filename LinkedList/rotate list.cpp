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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        k%=cnt;
        if(k==0)return head;
        int n=cnt-k;
        temp=head;
        while(n!=1){
            temp=temp->next;
            n--;
        }
        ListNode* tail=temp->next,*newhead=temp->next;
        while(tail->next)tail=tail->next;
        tail->next=head;
        temp->next=NULL;
        return newhead;
        
    }
};
