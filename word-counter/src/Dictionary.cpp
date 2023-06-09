
//
// Created by Ali Sayed Salehi on 2023-05-31.
//

#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include<array>
#include<vector>
#include<set>
#include <algorithm>
#include <forward_list>
#include "../inc/Word.h"
#include "../inc/Dictionary.h"

using std::forward_list;
using std::set;
using std::vector;
using std::string;
using std::ostream;
using std::array;
using std::list;

Dictionary::Dictionary(const string &input_text_file, const string &delimiters) : filename(input_text_file),
            theDelimiters(delimiters), word_list_buckets(new std::array<list<Word>, 27>){

    std::ifstream file(input_text_file);
    if (!file)
    {
        std::cout << "could not open input file: " << input_text_file << std::endl;
        exit(1);
    }

    std::string line;
    size_t lineNumber = 0;
    while (std::getline(file, line)) {
        ++lineNumber;
        input_lines.push_back(line);
        extract_and_push(line, lineNumber);
    }
    file.close();
}

size_t Dictionary::bucket_index(const string &wordText) {
    size_t index = 26; // bucket index for words not beginning with a letter
    if (isalpha(wordText[0]))
    {
        if(isupper(wordText[0])) index = wordText[0] - 'A';
        else                  index = wordText[0] - 'a';
    }
    return index;
}

vector<string> Dictionary::extract_words_from_line(const string &line) const {
    vector<string> lineTokens {};

    size_t tokenStartIndex { line.find_first_not_of(theDelimiters) };
    while (tokenStartIndex != std::string::npos) {
        size_t tokenEndIndex = line.find_first_of(theDelimiters, tokenStartIndex + 1);
        if (tokenEndIndex == std::string::npos) tokenEndIndex = line.length();

        std::string token {line.substr(tokenStartIndex, tokenEndIndex - tokenStartIndex)};
        tokenStartIndex = line.find_first_not_of(theDelimiters, tokenEndIndex + 1);

        lineTokens.push_back(token);
    }
    return lineTokens;
}

Dictionary::~Dictionary() {
    delete word_list_buckets;
}

void Dictionary::push_back_into_bucket(const string &wordText, size_t line_number) {
    Word newWord (wordText, line_number);
    auto newWordBucketIndex = bucket_index(wordText);
    auto& listBucketAtIndex = (*word_list_buckets)[newWordBucketIndex];
    if (exists(listBucketAtIndex, newWord)) {
        Word& oldWord = find(listBucketAtIndex, newWord);
        oldWord.increment_frequency();
        oldWord.push_back_line_number(line_number);
    } else {
        listBucketAtIndex.push_back(newWord);
    }
}

void Dictionary::extract_and_push(const string &line, size_t line_number) {
    auto wordsFromLine = extract_words_from_line(line);
    for (const auto& word : wordsFromLine) {
        push_back_into_bucket(word, line_number);
    }
}


void Dictionary::print_original_buckets(const set<char> &charSet) const {
    char character {'A'};
    std::cout << "unsorted buckets" << std::endl;
    std::cout << "===========================" << std::endl;
    for (auto & wordListBucket : *word_list_buckets) {
        if (!charSet.empty()) {
            if (charSet.count(character) > 0 || charSet.count(tolower(character)) > 0) {
                if (character == '[') character = ' ';
                std::cout << "<" << character << ">";
                if (wordListBucket.empty()) {
                    std::cout << "\t" << "list is empty" << std::endl;
                }
                for (const auto& word : wordListBucket) {
                    std::cout << word << std::endl;
                }
            }
        } else {
            if (character == '[') character = ' ';
            std::cout << "<" << character << ">";
            if (wordListBucket.empty()) {
                std::cout << "\t" << "list is empty" << std::endl;
            }
            for (const auto& word : wordListBucket) {
                std::cout << word << std::endl;
            }
        }
        character++;
    }

}

void Dictionary::print_input_lines(const set<size_t> &line_number_set) const {
    int lineNumber {0};
    for (const auto& line : input_lines) {
        ++lineNumber;
        if (!line_number_set.empty()) {
            if (line_number_set.count(lineNumber) > 0) {
                std::cout << std::endl;
                std::cout << lineNumber << " : " << line << std::endl;
            }
        }
    }
}

void Dictionary::print_buckets_sorted_on_word_text(const set<char> &charSet) const {
    char character {'A'};
    std::cout << "buckets sorted on word text" << std::endl;
    std::cout << "===========================" << std::endl;
    for (auto & wordListBucket : *word_list_buckets) {
        if (!charSet.empty()) {
            if (charSet.count(character) > 0 || charSet.count(tolower(character)) > 0) {
                if (character == '[') character = ' ';
                std::cout << "<" << character << ">";
                std::forward_list<Word> forwardWordListBucket(wordListBucket.begin(), wordListBucket.end());
                forwardWordListBucket.sort();
                for (const auto& word : forwardWordListBucket) {
                    std::cout << word << std::endl;
                }
            }
        } else {
            if (character == '[') character = ' ';
            std::cout << "<" << character << ">";
            if (wordListBucket.empty()) {
                std::cout << "\t" << "list is empty" << std::endl;
            }
            for (const auto& word : wordListBucket) {
                std::cout << word << std::endl;
            }
        }
        character++;
    }
}

void Dictionary::print_buckets_sorted_on_word_frequency(const set<char> &charSet) const {
    char character {'A'};
    std::cout << "buckets sorted on word frequency" << std::endl;
    std::cout << "===========================" << std::endl;
    for (auto & wordListBucket : *word_list_buckets) {
        if (!charSet.empty()) {
            if (charSet.count(character) > 0 || charSet.count(tolower(character)) > 0) {
                if (character == '[') character = ' ';
                std::cout << "<" << character << ">";
                std::forward_list<Word> forwardWordListBucket(wordListBucket.begin(), wordListBucket.end());
                forwardWordListBucket.sort(isLessFrequent);
                for (const auto& word : forwardWordListBucket) {
                    std::cout << word << std::endl;
                }
            }
        } else {
            if (character == '[') character = ' ';
            std::cout << "<" << character << ">";
            if (wordListBucket.empty()) {
                std::cout << "\t" << "list is empty" << std::endl;
            }
            for (const auto& word : wordListBucket) {
                std::cout << word << std::endl;
            }
        }
        character++;
    }
}

void Dictionary::print_buckets_sorted_on_word_length(const set<char> &charSet) const {
    char character {'A'};
    std::cout << "buckets sorted on word length" << std::endl;
    std::cout << "===========================" << std::endl;
    for (auto & wordListBucket : *word_list_buckets) {
        if (!charSet.empty()) {
            if (charSet.count(character) > 0 || charSet.count(tolower(character)) > 0) {
                if (character == '[') character = ' ';
                std::cout << "<" << character << ">";
                std::forward_list<Word> forwardWordListBucket(wordListBucket.begin(), wordListBucket.end());
                forwardWordListBucket.sort(isShorter);
                for (const auto& word : forwardWordListBucket) {
                    std::cout << word << std::endl;
                }
            }
        } else {
            if (character == '[') character = ' ';
            std::cout << "<" << character << ">";
            if (wordListBucket.empty()) {
                std::cout << "\t" << "list is empty" << std::endl;
            }
            for (const auto& word : wordListBucket) {
                std::cout << word << std::endl;
            }
        }
        character++;
    }
}

bool Dictionary::exists(const list<Word>& list, const Word &word) {
    bool found = std::any_of(list.begin(), list.end(), [&](const Word &element) {
        return element.get_word_text() == word.get_word_text();
    });
    return found;
}

Word &Dictionary::find(list<Word> &list, const Word &word) {
    for (auto& element : list) {
        if (element.get_word_text() == word.get_word_text()) {
            return element;
        }
    }
    return list.back();
}

