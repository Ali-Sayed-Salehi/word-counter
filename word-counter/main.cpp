
#include <iostream>
#include <cassert>
#include "inc/NumList.hpp"

using std::cout;
using std::endl;

void testNumList();

int main() {
    testNumList();
    return 0;
}


void testNumList() {
    std::cout << "Testing NumList!\n";
    NumList list{};
    cout << "list-1 -> " << list << endl;
    assert(list.getCapacity() == 1);

    list.append(19);
    cout << "list-2 -> " << list << endl;
    assert(list.getCapacity() == 1);
    assert(list.getSize() == 1);

    list.append(32);
    cout << "list-3 -> " << list << endl;
    assert(list.getCapacity() == 2);
    assert(list.getSize() == 2);

    list.append(21);
    cout << "list-4 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.getSize() == 3);

    list.append(7);
    cout << "list-5 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.getSize() == 4);

    list.append(18);
    cout << "list-6 -> " << list << endl;
    assert(list.getCapacity() == 8);
    assert(list.getSize() == 5);

    int value = -1;
    for (int k = 0; k < list.getSize(); ++k) {
        assert(list.get(k, value));
        assert(value == list.get(k));
    }

    assert(! list.get(list.getSize(), value));
    cout << "NumList Test Successful" << endl;
}