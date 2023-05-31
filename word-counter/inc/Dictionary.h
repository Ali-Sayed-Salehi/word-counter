//
// Created by Ali Sayed Salehi on 2023-05-31.
//

#ifndef WORD_COUNTER_DICTIONARY_H
#define WORD_COUNTER_DICTIONARY_H

#include<string>
using std::string;
#include "../inc/WordList.h"

class Dictionary {
private:
    string filename;
    WordList wordListBuckets[27];  // 26  alpha buckets + 1 none-alpha bucket
    size_t bucketIndex(const string& word) ;
public:
    explicit Dictionary(const string& filename);
    void processWord(const string& word, int lineNum) ;
    void print(std::ostream& out) const;
    Dictionary()  = delete;
    ~Dictionary() = default;
    Dictionary(const Dictionary& source) = default;
    Dictionary(Dictionary&& source) = default;
    Dictionary& operator=(const Dictionary& rhs) = default;
    Dictionary& operator=(Dictionary&& rhs) = default;
};


#endif //WORD_COUNTER_DICTIONARY_H
