class Queue {
public:
    vector<int> q;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(q.size()==0)return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(q.size()==0)return -1;
        int x=q[0];
        q.erase(q.begin());
        return x;
    }

    int front() {
        // Implement the front() function
        if(q.size()==0)return -1;
        int x=q[0];
        return x;
    }
};
