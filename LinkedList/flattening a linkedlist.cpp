Node* mergesort(Node* l1,Node* l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    if(l1->data>l2->data)swap(l1,l2);
    Node* ans=l1;
    while(l1 && l2){
        Node* temp=NULL;
        while(l1!=NULL && l1->data<=l2->data){
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return ans;
}
/*struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* merge(Node* a,Node* b){
    Node* temp=new Node(0);
    Node* res=temp;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a==NULL){
        temp->bottom=b;
    }
    else{
        temp->bottom=a;
    }
    return res->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL){
       return root;
   }
   root->next=flatten(root->next);
   root=merge(root,root->next);
   return root;
}
