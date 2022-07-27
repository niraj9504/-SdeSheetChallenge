class LRUCache {
public:
    //defining doubly linked list
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
            
            node(int k,int v){
                key=k;
                val=v;
            }     
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> map;
    
    
    //*LRU cache starts
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    //add newnode just after head
    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    //delete node
    void deletenode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    //*
    int get(int key_) {
        if(map.find(key_)!=map.end()){
            node* resnode=map[key_];
            int ans=resnode->val;
            map.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            map[key_]=head->next;
            return ans;
        }
        return -1;
    }
    //*
    void put(int key_, int value) {
        if(map.find(key_)!=map.end()){
            node* existingnode=map[key_];
            map.erase(key_);
            deletenode(existingnode);
        }
        if(map.size()==cap){
            map.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key_,value));
        map[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
