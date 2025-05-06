#include <iostream>
#include <vector>
#include <string>


template <typename T>
class Queue {
private:
    std::vector<T> items;
    size_t frontIndex = 0;

public:
    void push(const T& item) {
        items.push_back(item);
        std::cout << "Added: " << item << " to queue.\n";
    }

    T pop() {
        T removedItem = items[frontIndex];
        frontIndex++;

        if (frontIndex > items.size() / 2) {
            items.erase(items.begin(), items.begin() + frontIndex);
            frontIndex = 0;
        }
        return removedItem;
    }

    T front() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty! No front element.");
        }
        return items[frontIndex];
    }

    bool empty() const {
        return frontIndex >= items.size();
    }
};


int main() {
    Queue<std::string> stringQueue;
    stringQueue.push("Sword");
    stringQueue.push("Shield");
    stringQueue.push("Potion");
    stringQueue.display();

    stringQueue.pop();
    stringQueue.display();

    Queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    intQueue.display();

    intQueue.pop();
    intQueue.display();

    return 0;
}
