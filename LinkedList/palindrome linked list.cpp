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
    bool isPalindrome(ListNode* head) {
        deque<int> q;
        while(head){
            q.push_back(head->val);
            head=head->next;
        }
        while(q.size()>1){
            int x=q.back(),y=q.front();
            q.pop_back();q.pop_front();
            if(x!=y)return false;
        }
        return true;
    }
};
//try O(1) space and O(n) time=> reverse first half terms and then start matching
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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int mid=cnt/2;
        ListNode* prev=NULL,*curr=head,*nextptr;
        int i=0;
        while(i<mid){
            nextptr=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nextptr;
            i++;
        }
        if(cnt&1)curr=curr->next;
        while(curr && prev){
            if(curr->val!=prev->val)return false;
            curr=curr->next;
            prev=prev->next;
        }
        return true;
    }
};
