/*
//
// Created by Ali Sayed Salehi on 2023-05-28.
//

#include "../inc/NumList.h"

NumList::NumList() : capacity(1), pArray(new int[1]), size(0) {
}

NumList::~NumList() {
    delete[] pArray;
}

NumList::NumList(const NumList& source) :
    capacity(source.capacity), pArray(new int[source.capacity]), size(source.size) {

    for (int i = 0; i < source.size; ++i) {
        pArray[i] = source.pArray[i];
    }

}

NumList::NumList(NumList &&source)  noexcept :
        capacity(source.capacity), pArray(source.pArray), size(source.size) {
    source.pArray = nullptr;
}

bool NumList::empty() const {
    return size == 0;
}

bool NumList::full() const {
    return size == capacity;
}

int NumList::getSize() const {
    return size;
}

void NumList::expand() {
    int* expandedPArray = new int[capacity * 2];
    for (int i = 0; i < size; ++i) {
        expandedPArray[i] = pArray[i];
    }
    delete[] pArray;
    pArray = expandedPArray;
    capacity *= 2;
}

int NumList::getCapacity() const {
    return capacity;
}

bool NumList::contains(int x) const {
    for (int i =0; i < size; ++i){
        if (pArray[i] == x) return true;
    }
    return false;
}

void NumList::append(int x) {
    if (full()) expand();
    pArray[size] = x;
    ++size;
}

NumList& NumList::operator=(const NumList& rhs) {
    if (this == &rhs) return *this;
    delete[] pArray;
    pArray = new int[rhs.capacity];

    for (int i = 0; i < rhs.size; ++i) {
        pArray[i] = rhs.pArray[i];
    }

    capacity = rhs.capacity;
    size = rhs.size;
    return *this;
}

NumList &NumList::operator=(NumList &&rhs) noexcept {
    if (this == &rhs) return *this;

    delete[] pArray;
    pArray = rhs.pArray;
    rhs.pArray = nullptr;

    capacity = rhs.capacity;
    size = rhs.size;
    return *this;
}

void NumList::print(std::ostream &os) const {
    for (int i = 0; i < size; ++i) {
        os << " " << pArray[i] << ",";
    }
}

int NumList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index");
    }
    return pArray[index];
}

bool NumList::get(int index, int &value) const {
    if (index < 0 || index >= size) {
        return false;
    }

    value = pArray[index];
    return true;
}


std::ostream& operator<<(std::ostream& os, const NumList& numList) {
    for (int i = 0; i < numList.size; ++i) {
        os << " " << numList.pArray[i] << ",";
    }
    return os;
}
*/
