#include "MyForwardList.h"

MyForwardList::Block::Block(int value) {
    this->value = value;
    next = nullptr;
    ++size;
}

MyForwardList::Block::~Block() {
    --size;
}

MyForwardList::Block *MyForwardList::Get_At(int index) {
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    Block *block = first;

    for (int count = 0; count < index; ++count) {
        block = block->next;
    }

    return block;
}

MyForwardList::Block *MyForwardList::Get_At_Before(int index) {
    if (index < 1 || index >= size()) {
        return nullptr;
    }
    Block *block = first;
    for (int count = 0; count < index - 1; ++count) {
        block = block->next;
    }
    return block;
}

MyForwardList::MyForwardList() {
    first = nullptr;
    last = nullptr;
}

MyForwardList::~MyForwardList() {
    while (first != nullptr) {
        pop_front();
    }
}

int MyForwardList::size() {
    return Block::size;
}

void MyForwardList::print() {
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

void MyForwardList::pop_back() {
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

void MyForwardList::pop_front() {
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

void MyForwardList::push_back(int data) {
    Block *block = new Block(data);
    if (first == nullptr) {
        first = last = block;
        return;
    }
    last->next = block;
    last = block;
}

void MyForwardList::push_front(int data) {
    Block *block = new Block(data);
    if (first == nullptr) {
        first = last = block;
        return;
    }
    block->next = first;
    first = block;
}

void MyForwardList::insert(int index, int data) {
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

void MyForwardList::erase(int index) {
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
    Block *left = Get_At_Before(index);
    Block *block = left->next;
    Block *right = block->next;
    left->next = right;
    delete block;
}

int MyForwardList::Block::size = 0;