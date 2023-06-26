//
// Created by Ali Sayed Salehi on 2023-05-29.
//

#include "../inc/Word.h"

Word::Word(string text, size_t line_number) : text(text), frequency(1) {
    line_number_vec.push_back(line_number);
}


void Word::print(ostream &os) const {

    os << "\t" << text << "\t (" << frequency << ")" << "\t";
    for (const auto& element : line_number_vec) {
        os << element << " ";
    }
    os << std::endl;
}

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
        if (w1 < w2) return true;
    }
    return false;
}

bool isLessFrequent(const Word& w1, const Word& w2) {
    if (w1.get_frequency() < w2.get_frequency()) return true;
    if (w1.get_frequency() == w2.get_frequency()) {
        if (w1 < w2) return true;
    }
    return false;
}

bool operator<(const Word &w1, const Word &w2) {return w1.get_word_text() < w2.get_word_text();}


