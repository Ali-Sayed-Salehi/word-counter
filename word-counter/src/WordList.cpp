//
// Created by Ali Sayed Salehi on 2023-05-30.
//

#include "../inc/WordList.h"

void WordList::addBack(const Word &aWord) {
    auto* newNode = new WordNode(aWord);
    if (tail == nullptr)
    {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    theSize++;
}

void WordList::addFront(const Word &aWord) {
    auto *newNode = new WordNode(aWord);
    newNode->next = head;
    head = newNode;
    theSize++;
    if (tail == nullptr){ tail = head; }
}

bool WordList::remove(WordNode *nodePtr) {
    if (nodePtr == nullptr || head == nullptr) {
        return false;
    }

    if (head == tail && nodePtr == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --theSize;
        return true;
    }

    if (nodePtr == head) {
        if (removeFront()) return true;
        return false;
    }

    if (nodePtr == tail) {
        if (removeBack()) return true;
        return false;
    }

    WordNode* current = head;
    while (current->next != nullptr) {
        if (current->next == nodePtr) {
            current->next = current->next->next;
            delete nodePtr;
            --theSize;
            return true;
        }
        current = current->next;
    }
    return false;
}

WordList::WordNode *WordList::lookUp(const Word &aWord) const {
    WordNode* current = head;
    while (current != nullptr) {
        if ((current->theWord).compare(aWord) == 0) {
            return current;
        }
        current = current->next;
    }

    if (size() == 1) {
        if ((head->theWord).compare(aWord) > 0) return nullptr;
        else return head;
    }

    current = head;
    if ((head->theWord).compare(aWord) > 0) return nullptr;
    while (current->next != nullptr) {
        if ((current->next->theWord).compare(aWord) > 0) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void WordList::addAfter(WordList::WordNode *nodePtr, const Word &aWord) {
    if (nodePtr == nullptr) {
        addFront(aWord);
        return;
    }

    if (head == tail && nodePtr == head) {
        addBack(aWord);
        return;
    }

    auto *newNode = new WordNode(aWord);
    newNode->next = nodePtr->next;
    nodePtr->next = newNode;
    theSize++;
}


WordList::WordList(const WordList &source) {
    WordNode* current = source.head;
    while (current != nullptr) {
        addBack(current->theWord);
        current = current->next;
    }
    tail = current;
}

WordList::WordList(WordList &&source)  noexcept :
    head(source.head), tail(source.tail), theSize(source.theSize){
    source.head = nullptr;
    source.tail = nullptr;
}

WordList &WordList::operator=(const WordList &rhs) {
    if (this == &rhs) return *this;

    clear();

    WordNode* current = rhs.head;
    while (current != nullptr) {
        addFront(current->theWord);
        current = current->next;
    }
    return *this;
}

bool WordList::removeFront() {
    if (head == nullptr) {
        return false;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --theSize;
        return true;
    }

    head = head->next;
    delete head;
    --theSize;
    return true;
}

bool WordList::removeBack() {
    if (head == nullptr) {
        return false;
    }

    if (size() == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        --theSize;
        return true;
    }

    // get second-to-lest node
    WordNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    tail = current;
    --theSize;
    return true;
}

bool WordList::operator==(const WordList &other) const {
    if (theSize != other.theSize) {
        return false;
    }
    if (head == nullptr && other.head == nullptr) return true;

    WordNode* current = head;
    WordNode* otherCurrent = other.head;

    while (current != nullptr) {
        if ((current->theWord).compare(otherCurrent->theWord) != 0) {
            return false;
        }
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return true;
}

WordList &WordList::operator=(WordList &&rhs)  noexcept {
    if (this == &rhs) return *this;
    clear();

    head = rhs.head;
    tail = rhs.tail;
    theSize = rhs.theSize;

    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.theSize = 0;

    return *this;
}

void WordList::clear() {
    while (head != nullptr) {
        WordNode* temp = head;
        head = head->next;
        delete temp;
    }
    theSize = 0;
    tail = nullptr;
}

WordList::~WordList() {
    clear();
}

bool WordList::empty() const {
    return (theSize == 0);
}

size_t WordList::size() const {
    return theSize;
}

void WordList::print(std::ostream &os) const {
    if (empty()) {
        os << "list is empty" << std::endl;
    }

    WordNode* current = head;
    while (current != nullptr) {
        os << current->theWord << " ";
        current = current->next;
    }
    os << std::endl;
}

Word &WordList::front() const {
    return head->theWord;
}

Word &WordList::back() const {
    return tail->theWord;
}

void WordList::addSorted(const Word &aWord) {
    if (empty()) {
        addFront(aWord);
        return;
    }

    if (search(aWord)) {
        lookUp(aWord)->theWord.appendNumber(aWord.getNumberList().get(aWord.getNumberList().getSize() - 1));
        return;
    }

    if (size() == 1) {
        if ((head->theWord).compare(aWord) > 0) addFront(aWord);
        else addBack(aWord);
        return;
    }

    WordNode* current = head;
    if ((head->theWord).compare(aWord) > 0) {
        addFront(aWord);
        return;
    }
    while (current->next != nullptr) {
        if ((current->next->theWord).compare(aWord) > 0) {
            addAfter(current, aWord);
            return;
        }
        current = current->next;
    }
    addBack(aWord);
}

void WordList::addSorted(const std::string &str, int lineNum) {

    Word* newWord = new Word(str.c_str(), lineNum);
    Word aWord = *newWord;

    if (empty()) {
        addFront(aWord);
        return;
    }

    if (search(aWord)) {
        lookUp(aWord)->theWord.appendNumber(lineNum);
        return;
    }

    if (size() == 1) {
        if ((head->theWord).compare(aWord) > 0) addFront(aWord);
        else addBack(aWord);
        return;
    }

    WordNode* current = head;
    if ((head->theWord).compare(aWord) > 0) {
        addFront(aWord);
        return;
    }
    while (current->next != nullptr) {
        if ((current->next->theWord).compare(aWord) > 0) {
            addAfter(current, aWord);
            return;
        }
        current = current->next;
    }
    addBack(aWord);
}

bool WordList::search(const Word &aWord) const {
    WordNode* current = head;
    while (current != nullptr) {
        if ((current->theWord).compare(aWord) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}



