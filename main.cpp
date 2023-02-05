#include <iostream>
#include "MyForwardList.h"


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

    auto x = *(list.first);

    for (auto i = list.first; i != list.last; i = i->next) {
        std::cout << list.first->value << " ";
    }

    return 0;
}
