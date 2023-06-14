//
// Created by Ali Sayed Salehi on 2023-05-29.
//

#include "../inc/Word.h"

//Word::Word(const char* pCharArr, int n) :
//    pCharArray(new char[std::strlen(pCharArr) + 1]),  frequency(0){
//    strcpy(pCharArray, pCharArr);
//    num_list.append(n);
//    frequency = num_list.getSize();
//}

Word::Word(string text, size_t line_number) : text(text), frequency(1) {
    line_number_vec.push_back(line_number);
}

//Word::Word(const Word &source) : frequency(source.frequency), num_list(source.num_list){
//    std::size_t sourceStringLength = std::strlen(source.pCharArray);
//    pCharArray = new char[sourceStringLength + 1];
//    strcpy(pCharArray, source.pCharArray);
//}

//Word::Word(Word&& source) noexcept :
//    pCharArray(source.pCharArray), frequency(source.frequency), num_list(std::move(source.num_list)){
//    source.pCharArray = nullptr;
//}
/*

Word &Word::operator=(const Word &rhs) {
    if (this == &rhs) return *this;
    delete[] pCharArray;

    std::size_t rhsStringLength = std::strlen(rhs.pCharArray);
    pCharArray = new char[rhsStringLength + 1];
    strcpy(pCharArray, rhs.pCharArray);

    frequency = rhs.frequency;
    num_list = rhs.num_list;
    return *this;
}
*/
/*

Word &Word::operator=(Word &&rhs)  noexcept {
    if (this == &rhs) return *this;
    delete[] pCharArray;
    pCharArray = rhs.pCharArray;
    rhs.pCharArray = nullptr;

    frequency = rhs.frequency;
    num_list = std::move(rhs.num_list);
    return *this;
}
*/

//Word::~Word() {
//    delete[] pCharArray;
//}
/*

const char *Word::c_str() const {
    return pCharArray;
}
*/
/*

void Word::appendNumber(int n) {
    num_list.append(n);
}
*/
/*

size_t Word::size() const {
    return std::strlen(pCharArray);
}
*/

//void Word::print(std::ostream &os) const {
//    os << "\t" << pCharArray << "\t (" << num_list.getSize() << ")";
//    num_list.print(os);
//    os << std::endl;
//}

void Word::print(ostream &os) const {
    os << "\t" << text << "\t (" << frequency << ")";
    for (const auto& element : line_number_vec) {
        os << element << " ";
    }
    os << std::endl;
}
/*

const NumList &Word::getNumberList() const {
    return num_list;
}
*/

int Word::compare(const Word &other) const {
    //TODO: Is std::string::compare correct?
    auto result = this -> text.compare(other.text);

    if (result < 0) {
        //this is less than other
        return -1;
    } else if (result > 0) {
        //this is greater than other
        return 1;
    } else {
        //this is equal to other
        return 0;
    }
}



//std::ostream &operator<<(std::ostream &os, const Word &aWord) {
//    os << "\t" << aWord.pCharArray << "\t (" << aWord.num_list.getSize() << ")";
//    aWord.num_list.print(os);
//    os << std::endl;
//
//    return os;
//}

std::ostream &operator<<(ostream &os, const Word &aWord) {
    aWord.print(os);
    return os;
}

void Word::push_back_line_number(size_t lineNum) {
    auto it = std::find(line_number_vec.begin(), line_number_vec.end(), lineNum);

    if (it != line_number_vec.end()) {
        return;
    } else {
        line_number_vec.push_back(lineNum);
    }
}

string Word::get_word_text() const {return text;}

size_t Word::get_frequency() const { return frequency;}

vector<size_t> Word::get_number_list() const { return line_number_vec;}

size_t Word::length() const { return text.length(); }

void Word::increment_frequency() {++frequency;}


bool isShorter(const Word& w1, const Word& w2) {
    auto w1Length = w1.length();
    auto w2Length = w2.length();

    if (w1Length < w2Length) return true;
    if (w1Length == w2Length) {
        if (w1.get_word_text() < w2.get_word_text()) return true;
    }
    return false;
}

bool isLessFrequent(const Word& w1, const Word& w2) {
    if (w1.get_frequency() < w2.get_frequency()) return true;
    if (w1.get_frequency() == w2.get_frequency()) {
        if (w1.get_word_text() < w2.get_word_text()) return true;
    }
    return false;
}

bool operator<(const Word &w1, const Word &w2) {return w1.get_word_text() < w2.get_word_text();}


