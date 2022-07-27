#include<bits/stdc++.h>
class node{
    public:
    int key,val;
    node* prev,*next;
    node(int k,int v){
        key=k;
        val=v;
    }
};
class LFUCache
{
public:
    int cap;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> map;
    unordered_map<int,int> freq;
    
    LFUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        node* temp=head->next;
        head->next=newnode;
        temp->prev=newnode;
        newnode->next=temp;
        newnode->prev=head;
    }
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key_)
    {
        //if(cap==0)return -1;
        if(map.find(key_)!=map.end()){
            node* existingnode=map[key_];
            int ans=existingnode->val;
            map.erase(key_);
            deletenode(existingnode);
            addnode(existingnode);
            map[key_]=head->next;
            freq[key_]++;
            return ans;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if(map.find(key_)!=map.end()){
            node* temp=map[key_];
            deletenode(temp);
            map.erase(key_);
            freq[key_]++;
        }
        if(map.size()==cap){
            int mini=1000;
            node* delnode;
            for(auto it:freq)mini=min(mini,it.second);
            int cnt=0;
            for(auto it:freq){
                if(it.second==mini)cnt++;
            }
            
            if(cnt==1){
                int keyvalue=0;
                for(auto it:freq){
                    if(it.second==mini){
                        delnode=map[it.first];
                        keyvalue=it.first;
                        break;
                    }
                }
                map.erase(keyvalue);
                freq.erase(keyvalue);
                deletenode(delnode);
            }
            else{
                map.erase(tail->prev->key);
                deletenode(tail->prev);
                freq.erase(tail->prev->key);
            }
        }
        addnode( new node(key_,value));
        map[key_]=head->next;
        freq[key_]++;
    }
};
