// O(logn) time, O(1) space
class MedianFinder {
public:
    priority_queue<int> small;//smaller half
    priority_queue<int,vector<int>,greater<int>> large;//larger half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(small.size()<large.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size()?small.top() :(small.top()+large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//codestudio
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{    
    if(n==0)return;
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    small.push(arr[0]);
    cout<<small.top()<<" ";
    for(int i=1;i<n;i++){
        int x=arr[i];
        if(small.size()>large.size()){
            if(small.top()>x){
                small.push(x);
                large.push(small.top());
                small.pop();
            }
            else{
                large.push(x);
            }
            cout<<(large.top()+small.top())/2<<" ";
        }
        else {
            if(small.top()<x){
                large.push(x);
                small.push(large.top());
                large.pop();
            }
            else{
                small.push(x);
            }
            cout<<small.top()<<" ";
        }
    }
}
