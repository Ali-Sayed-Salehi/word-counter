//
// Created by Ali Sayed Salehi on 2023-05-31.
//

#ifndef WORD_COUNTER_DICTIONARY_H
#define WORD_COUNTER_DICTIONARY_H
/*

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
using std::forward_list;
using std::set;
using std::vector;
using std::string;
using std::ostream;
using std::array;
using std::list;

class Dictionary {
private:

    string filename; // input file name
    string theDelimiters;
    vector<string> input_lines {}; // the lines in the input file
    array<list<Word>, 27>* word_list_buckets; // array of 27 word list buckets

    // returns the index of the bucket corresponding to wordText[0]
    size_t bucket_index(const string& wordText) const;

    // extracts and returns the words separated by theDelimiters in a specified line
    vector<string> extract_words_from_line(const string& line) const;

    // creates a Word object using the specified wordText and line_number and then
// inserts the object at the end of the bucket list corresponding to wordText[0].
    void push_back_into_bucket(const string& wordText, size_t line_number);

    // extract_words_from_line and push_back_into_bucket,
    void extract_and_push(const string& line, size_t line_number);


public:
    explicit Dictionary(const string& input_text_file, const string& delimiters = " \t\n");
    Dictionary() = delete;
    ~Dictionary();
    Dictionary(const Dictionary& ) = default;  // copy ctor
    Dictionary(      Dictionary&&) = default;  // move ctor
    Dictionary& operator=(const Dictionary& ) = default;  // copy assignment
    Dictionary& operator=(      Dictionary&&) = default;

    // prints all input lines, each preceded by line number (menu option 1)
//    If line_number_set is empty, then this member functions prints every line of the input text file;
//    Otherwise, it prints only the input lines whose line numbers correspond to those stored in line_number_set.
    void print_input_lines(const set<size_t>& line_number_set) const;

    // prints the original unsorted buckets represented by charSet (menu option 2)
    void print_original_buckets(const set<char>& charSet) const;

//  prints the buckets represented by charSet sorted on word text (menu option 3)
    void print_buckets_sorted_on_word_text(const set<char>& charSet)const;

//  prints the buckets represented by charSet sorted on word frequecy (menu option 4)
    void print_buckets_sorted_on_word_frequecy(const set<char>& charSet)const;

// prints the buckets represented by charSet sorted on word length (menu option 5)
    void print_buckets_sorted_on_word_length(const set<char>& charSet)const;

};


#endif //WORD_COUNTER_DICTIONARY_H
