//
// Created by Ali Sayed Salehi on 2023-05-29.
//

#ifndef WORD_COUNTER_WORD_H
#define WORD_COUNTER_WORD_H


// #include "NumList.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

class Word {
private:
//    char* pchararray{};
//    int frequency{};
//    numlist num_list{};

    string text;
    vector<size_t> line_number_vec;
    size_t frequency{1};


public:
    Word(string text, size_t line_number);

//    Word(const char* pCharArr, int n);
    Word() = delete;
//    Word(const Word& source);
//    Word(Word&& source) noexcept ;
    Word(const Word& source) = default;
    Word(Word&& source) = default;
    Word& operator=(const Word& rhs) = default;
    Word& operator=(Word&& rhs) noexcept = default;
//    virtual ~Word();
    ~Word() = default;
    int compare(const Word& other) const;
    void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Word& aWord);

    string get_word_text() const;
    size_t get_frequency()const;
    vector<size_t> get_number_list() const;
    size_t length() const;
    void increment_frequency();
    void push_back_line_number(size_t lineNum);

/*
    const char* c_str() const;
    void appendNumber(int n);
    size_t size() const;
    const NumList& getNumberList() const;
*/

};

bool operator<(const  Word& w1, const  Word& w2);
bool isShorter(const Word& w1, const Word& w2);
bool isLessFrequent(const Word& w1, const Word& w2);

#endif //WORD_COUNTER_WORD_H
