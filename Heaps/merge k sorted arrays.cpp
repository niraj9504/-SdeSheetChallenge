#include<bits/stdc++.h>
//codestudio (slower)
vector<int> mergeTwoSortedLists(vector<int> a,vector<int> b){
    if(a.size()==0)return b;
    if(b.size()==0)return a;
    int n=a.size();
    int m=b.size();
    int i=0,j=0;
    vector<int> temp;
    while(i<n && j<m){
        if(a[i]>=b[j]){
            temp.push_back(b[j]);
            j++;
        }
        else{
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i<n){
        temp.push_back(a[i++]);
    }
    while(j<m)temp.push_back(b[j++]);
    return temp;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    int n=kArrays.size();
    for(int i=0;i<n;i++){
        ans=mergeTwoSortedLists(ans,kArrays[i]);
    }
    return ans;
}
//leetcode -> 23 no. prob
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
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val>=l2->val){
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        else{
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode* dummy=new ListNode(-1e6);
        ListNode* temp=dummy;
        for(int i=0;i<n;i++){
            temp=mergeTwoLists(temp,lists[i]);
        }
        return dummy->next;
    }
};

