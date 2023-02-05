#pragma once
#include <iostream>

class MyForwardList {
private:
    class Block {
    public:
        int value;
        Block *next;
        static int size;

        Block(int value);

        ~Block();
    };

    Block *Get_At(int index);

    Block *Get_At_Before(int index);
public:
    Block *first;
    Block *last;

    MyForwardList();

    ~MyForwardList();

    int size();

    void print();

    void pop_back();

    void pop_front();

    void push_back(int data);

    void push_front(int data);

    void insert(int index, int data);

    void erase(int index);
};

//int MyForwardList::Block::size = 0;