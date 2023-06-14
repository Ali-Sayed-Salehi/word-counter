/*
//
// Created by Ali Sayed Salehi on 2023-05-30.
//

#ifndef WORD_COUNTER_WORDLIST_H
#define WORD_COUNTER_WORDLIST_H


#include "Word.h"

class WordList {

private:
    struct WordNode {
        Word theWord;
        WordNode *next; // Pointer to the next node or nullptr

        explicit WordNode(const Word &aWord, WordNode *next = nullptr) : theWord(aWord), next(next) {}
        WordNode() = delete;
        WordNode(const WordNode &source) = delete;
        WordNode(WordNode &&source) = delete;
        WordNode& operator=(const WordNode& source) = delete;
        WordNode& operator=(WordNode&& source) = delete;
        virtual ~WordNode() = default;
    };

    WordNode* head{ nullptr };
    WordNode* tail{ nullptr };
    size_t theSize{ 0 }; // number of nodes in the list

    void addBack(const Word& aWord);
    void addFront(const Word& aWord);
    bool remove(WordNode* nodePtr);
    void clear();

    WordNode* lookUp(const Word& aWord) const;
    void addAfter(WordNode* nodePtr, const Word& aWord);

public:
    WordList() = default;
    WordList(const WordList& source);
    WordList(WordList&& source) noexcept;
    bool operator==(const WordList& other) const;
    WordList& operator=(const WordList& rhs);
    WordList& operator=(WordList&& rhs) noexcept ;
    bool removeFront();
    bool removeBack();
    virtual ~WordList();
    bool empty() const;
    size_t size() const;
    void print(std::ostream& os) const;
    Word& front() const;
    Word& back() const;
    void addSorted(const Word& aWord);
    void addSorted(const std::string& str, int lineNum);
    bool search(const Word& aWord) const;
};


#endif //WORD_COUNTER_WORDLIST_H
*/
