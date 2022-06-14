//m1
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newhead,*l1,*l2;
        if(head==NULL)return head;
        l1=head;
        while(l1){
            l2=new Node(l1->val);
            l2->next=l1->next;
            l1->next=l2;
            l1=l1->next->next;
        }
        newhead=head->next;
        l1=head;
        while(l1){
            if(l1->random)l1->next->random=l1->random->next;
            l1=l1->next->next;
        }
        l1=head;
        while(l1){
            l2=l1->next;
            l1->next=l2->next;
            if(l2->next)l2->next=l2->next->next;
            l1=l1->next;
        }
        return newhead;
    }
};
//m2
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr=head;
        Node* front=head;
        //creating copy
        while(itr!=NULL){
            front=itr->next;
            Node* copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            itr=front;
        }
        //creating random
        itr=head;
        while(itr!=NULL){
            if(itr->random!=NULL){
                itr->next->random=itr->random->next;
            }
            itr=itr->next->next;
        }
        //extracting copy
        itr=head;
        Node* newhead=new Node(0);
        Node* copy=newhead;
        while(itr!=NULL){
            front=itr->next->next;
            copy->next=itr->next;
            itr->next=front;
            itr=front;
            copy=copy->next;
        }
        return newhead->next;
    }
};










