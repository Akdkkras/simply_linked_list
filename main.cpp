#include <iostream>
#include <forward_list>

class Block {
public:
    int value;
    Block *next;
    static int size;

    Block(int value) {
        this->value = value;
        next = nullptr;
        ++size;
    }

    ~Block() {
        --size;
    }

};

int Block::size = 0;

class MyForwardList {
public:
    Block *first;
    Block *last;

    MyForwardList() {
        first = nullptr;
        last = nullptr;
    }

    ~MyForwardList() {
        while (first != nullptr) {
            pop_front();
        }
    }

    int size() {
        return Block::size;
    }

    void print() {
        if (size() == 0) {
            std::cout << "empty";
            return;
        }
        Block *block = first;
        while (block->next) {
            std::cout << block->value << " ";
            block = block->next;
        }
        std::cout << block->value;
    }

    void pop_front() {
        if (first == nullptr) {
            return;
        }
        if (first == last) {
            delete last;
            first = last = nullptr;
            return;
        }
        Block *block = first;
        first = first->next;
        delete block;
    }

    void push_back(int data) {
        Block *block = new Block(data);
        if (first == nullptr) {
            first = last = block;
            return;
        }
        last->next = block;
        last = block;
    }

    void push_front(int data) {
        Block *block = new Block(data);
        if (first == nullptr) {
            first = last = block;
            return;
        }
        block->next = first;
        first = block;
    }

    void pop_back() {
        if (first == nullptr) {
            return;
        }
        if (first == last) {
            delete last;
            first = last = nullptr;
            return;
        }
        Block *block = first;
        while (block->next != last) {
            block = block->next;
        }
        delete last;
        block->next = nullptr;
        last = block;
    }

    Block *Get_At(int index) {
        if (index < 0 || index >= size()) {
            return nullptr;
        }

        Block *block = first;

        for (int count = 0; count < index; ++count) {
            block = block->next;
        }

        return block;
    }

    Block *Get_At_Before(int index) {
        if (index < 1 || index >= size()) {
            return nullptr;
        }
        Block *block = first;
        for (int count = 0; count < index - 1; ++count) {
            block = block->next;
        }
        return block;
    }

    void insert(int index, int data) {
        if (index == 0) {
            push_front(data);
            return;
        }
        if (index < 0 || index > size()) {
            return; /// попытка вставить элемент по несуществующему индексу
        }
        if (index == size()) {
            push_back(data);
            return;
        }
        Block *block = new Block(data);
        Block *left = Get_At_Before(index);
        Block *right = left->next;
        left->next = block;
        block->next = right;
    }

    void erase(int index) {
        if (index < 0 || index >= size()) {
            return; /// попытка удалить элемент по несуществующему индексу
        }
        if (index == 0) {
            pop_front();
            return;
        }
        if (index == size() - 1) {
            pop_back();
            return;
        }
        Block* left = Get_At_Before(index);
        Block* block = left->next;
        Block* right = block->next;
        left->next = right;
        delete block;
    }
};

int main() {
    MyForwardList list;
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.push_front(5);
    list.push_back(7);
    list.push_front(3);
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.pop_front();
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.pop_back();
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.pop_front();
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    for (int i = 0; i < 6; ++i) {
        list.push_back(rand() % 100);
    }
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.insert(2, 54);
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    list.erase(0);
    std::cout << "list: ";
    list.print();
    std::cout << "\n";
    std::cout << "size: " << list.size() << "\n\n";

    return 0;
}
