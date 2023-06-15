/*
//
// Created by Ali Sayed Salehi on 2023-05-31.
//

#include <fstream>
#include <sstream>
#include "Dictionary.h"

size_t Dictionary::bucketIndex(const string &word) {
    size_t index = 26; // bucket index for words not beginning with a letter
    if (isalpha(word[0]))
    {
        if(isupper(word[0])) index = word[0] - 'A';
        else                  index = word[0] - 'a';
    }
    return index;
}

Dictionary::Dictionary(const string &filename) : filename(filename)
{
    for (auto & wordListBucket : wordListBuckets) {
        auto* wordListPtr = new WordList();
        wordListBucket = *wordListPtr;
    }


    std::ifstream fin(filename);  // create an input file stream
    if (!fin)
    {
        std::cout << "could not open input file: " << filename << std::endl;
        exit(1);
    }

    int lineNum = 0;
    string line;
    getline(fin, line); // very important first attempt to read;
    // this first attemot will get the i/o flags initialized
    while (fin) {
        //cout << line << endl;
        ++lineNum;                // count the line
        std::istringstream sin(line);  // turn the line into an input string stream
        string wordStr;
        while (sin >> wordStr)     // extract word strings
        {
            processWord(wordStr, lineNum);
        }
        getline(fin, line);      // attempt to read the next line, if any
    }
    fin.close();


}

void Dictionary::processWord(const string &word, int lineNum) {
    size_t wordIndex = bucketIndex(word);
    wordListBuckets[wordIndex].addSorted(word, lineNum);
}



void Dictionary::print(std::ostream &out) const {
    char character {'A'};
    char capital{};
    for (auto & wordListBucket : wordListBuckets) {
        if (character == '[') character = ' ';
        out << "<" << character << ">";
        wordListBucket.print(out);
        character++;
    }

}


*/

#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include<array>
#include<vector>
#include<set>
#include <forward_list>
#include "../inc/word.h"
#include "Dictionary.h"

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

size_t Dictionary::bucket_index(const string &wordText) const {
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
    auto listBucketAtIndex = (*word_list_buckets)[newWordBucketIndex];
    listBucketAtIndex.push_back(newWord);
}

void Dictionary::extract_and_push(const string &line, size_t line_number) {
    auto wordsFromLine = extract_words_from_line(line);
    for (const auto& word : wordsFromLine) {
        push_back_into_bucket(word, line_number);
    }
}


void Dictionary::print_original_buckets(const set<char> &charSet) const {
    char character {'A'};
    char capital{};
    for (auto & wordListBucket : *word_list_buckets) {
        // TODO: check the charset for needed chars
        if (character == '[') character = ' ';
        std::cout << "<" << character << ">";
        for (const auto& word : wordListBucket) {
            std::cout << word << std::endl;
        }
        character++;
    }

}
