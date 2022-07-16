// Stack class.
class Stack {
    
public:
    vector<int> st;
    int size;
    Stack(int capacity) {
        // Write your code here.
        size=capacity;
    }

    void push(int num) {
        st.push_back(num);
    }

    int pop() {
        int n=st.size();
        if(n==0)return -1;
        int x=st[st.size()-1];
        st.erase(st.begin()+st.size()-1);
        return x;
    }
    
    int top() {
        int n=st.size();
        if(n==0)return -1;
        int x=st[st.size()-1];
        return x;
    }
    
    int isEmpty() {
        if(st.size()==0)return 1;
        return 0;
    }
    
    int isFull() {
        if(st.size()==size)return 1;
        return 0;
    }
    
};

//m2
#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
