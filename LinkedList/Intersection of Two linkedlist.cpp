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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> map;
        int cnt=0;
        while(headA && headB){
            map.insert(headA);
            cnt++;
            headA=headA->next;
        }
        while(headB){
            map.insert(headB);
            cnt++;
            if(map.size()!=cnt){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
};
//m2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA,*curr2=headB;
        while(curr1!=curr2){
            curr1=curr1?curr1->next:headB;
            curr2=curr2?curr2->next:headA;
        }
        return curr1;
    }
};
//m3
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0,b=0;
        ListNode* temp1=headA,*temp2=headB;
        while(headA){
            a++;headA=headA->next;
        }
        while(headB){
            b++;headB=headB->next;
        }
        int t=abs(a-b);
        headA=temp1,headB=temp2;
        if(a>b){
            while(t--){
                headA=headA->next;
            }
        }
        else if(b>a){
            while(t--){
                headB=headB->next;
            }
        }
        while(headA && headB){
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};



