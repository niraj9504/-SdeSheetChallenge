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
        if(cap==0)return -1;
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

//m2 is correct
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    
    
    
};
class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->removeNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addFront(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};
