/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        if(head==NULL || head->next==NULL)return NULL;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL || fast->next==NULL)return NULL;
            if(slow==fast){
                break;
            }
        }
        //if(cycle==false)return NULL;
        if(slow!=fast)return NULL;
        slow=head;
        if(slow==fast)return fast;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        return fast->next;
    }
};
