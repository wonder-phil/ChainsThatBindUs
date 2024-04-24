#include <vector>
#include <iostream>

class Queue {
private:
    std::vector<int> queue;

public:
    void insert(int value) {
        queue.push_back(value);
    }

    int dequeue() {
        if (queue.empty()) {
            return -1; 
        }
        int first_elt = queue.front();
        queue.erase(queue.begin()); 
        return first_elt;
    }

    bool empty() const {
        return queue.empty();
    }
};