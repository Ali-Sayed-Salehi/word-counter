
#ifndef NumList_hpp
#define NumList_hpp

#include <cstdio>
#include <iostream>

class NumList {
private:
    int* pArray{};
    int capacity{};
    int size{};

    void expand();



public:
    NumList();
    NumList(const NumList& source);
    NumList(NumList&& source) noexcept;
    NumList& operator=(const NumList& rhs);
    NumList& operator=(NumList&& rhs) noexcept;
    virtual ~NumList();
    bool empty() const;
    bool full() const;
    int getSize() const;
    int getCapacity() const;
    bool contains(int x) const;
    void append(int x);
    void print(std::ostream& os) const;
    int get(int index) const;
    bool get(int index, int& value) const;

    friend std::ostream& operator<<(std::ostream& os, const NumList& numList);

};



#endif /* NumList_hpp */
