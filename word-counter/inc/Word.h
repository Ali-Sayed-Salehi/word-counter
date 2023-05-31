//
// Created by Ali Sayed Salehi on 2023-05-29.
//

#ifndef WORD_COUNTER_WORD_H
#define WORD_COUNTER_WORD_H


#include "NumList.h"

class Word {
private:
    char* pCharArray{};
    int frequency{};
    NumList num_list{};
public:
    Word(const char* pCharArr, int n);
    Word() = delete;
    Word(const Word& source);
    Word(Word&& source) noexcept ;
    Word& operator=(const Word& rhs);
    Word& operator=(Word&& rhs) noexcept;
    virtual ~Word();
    const char* c_str() const;
    void appendNumber(int n);
    size_t size() const;
    void print(std::ostream& os) const;
    const NumList& getNumberList() const;
    int compare(const Word& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Word& aWord);
};


#endif //WORD_COUNTER_WORD_H
