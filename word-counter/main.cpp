
#include <iostream>
#include <utility>
#include <string>
#include <filesystem>
#include "inc/Word.h"
#include "inc/Dictionary.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

Word makeWord(string word, size_t lineNumber)
{
    Word w1{ std::move(word), lineNumber };
    return w1; // return a temporary
}
void testWordClass(){
    std::cout << "Testing Objects of Class Word\n";

    Word w1{ makeWord("Hello", 11)};
    cout << "A) w1: "; w1.print(cout); cout << endl;

    w1 = makeWord("Goodbye", 22); // move assignment
    cout << "B) w1: "; w1.print(cout); cout << endl;
/*
    w1.appendNumber(33);
    w1.appendNumber(44);
    w1.appendNumber(55);
    w1.appendNumber(66);
    */
    w1.push_back_line_number(33);
    w1.push_back_line_number(44);
    w1.push_back_line_number(55);
    w1.push_back_line_number(66);

    cout << "C) w1: "; w1.print(cout); cout << endl;

    Word w2 = w1; // copy constructor (not copy assignment)
//    w1.appendNumber(77);
    w1.push_back_line_number(77);

    cout << "D) w1: "; w1.print(cout); cout << endl;
    cout << "E) w2: "; w2.print(cout); cout << endl;

    w2 = w1; // copy assignment
    cout << "F) w1: "; w1.print(cout); cout << endl;
    cout << "G) w2: "; w2.print(cout); cout << endl;


    Word w3 = std::move(w2); // move constructor
    cout << "H) w3: "; w3.print(cout); cout << endl;
//    cout << "I) w2: "; w2.print(cout); cout << endl; // warning C26800: Use of a moved from object

    w1 = std::move(w3); // move assignment
 //   cout << "J) w3: "; w3.print(cout); cout << endl; // warning C26800: Use of a moved from object
    cout << "K) w1: "; w1.print(cout); cout << endl;

    auto ia = w1.get_number_list();
    cout << "L) ia: ";
    for (auto& element : ia) {
        cout << element << " ";
    }
    cout << endl;

    cout << "M) length of w1: " << w1.get_word_text() << " = " << w1.length();
    cout << endl;
}
Dictionary* makeDictionary() {
    //auto currentDir = std::__fs::filesystem::current_path();
    //string filename{currentDir.parent_path().string() + "/Seuss.txt"};
    string filename{"/Users/ali/repos/word-counter/word-counter/Seuss.txt"};
    string userInput{};
    string separators{" \r.\t;?()=\n\"-,13579"};

    cout << "Enter the name of input text file: " ;
    std::getline(std::cin, userInput);
    if(!userInput.empty()) filename = userInput;

    userInput.clear();
    cout << "Enter the separator characters:" << endl;
    std::getline(std::cin, userInput);
    if(!userInput.empty()) separators = userInput;
    separators = separators + "\r\r\n";

    auto* dictionary = new Dictionary(filename, separators);
    return dictionary;
};
set<size_t> lineNumberTokenizer(const string& line, const string& delimiters = " \t\n\r") {
    set<size_t> lineTokens {};
    if (line.empty()) return lineTokens;

    size_t tokenStartIndex { line.find_first_not_of(delimiters) };
    while (tokenStartIndex != std::string::npos) {
        size_t tokenEndIndex = line.find_first_of(delimiters, tokenStartIndex + 1);
        if (tokenEndIndex == std::string::npos) tokenEndIndex = line.length();

        std::string token {line.substr(tokenStartIndex, tokenEndIndex - tokenStartIndex)};
        tokenStartIndex = line.find_first_not_of(delimiters, tokenEndIndex + 1);

        lineTokens.insert(std::stoul(token));
    }
    return lineTokens;
}
void runProgram() {
    auto dictionary = makeDictionary();
    string userInput{};
    int menuOption{};
    string selectedChars{};
    set<size_t> selectedLines{};
    set<char> selectedBuckets{};
    string nonAlphaSymbols{"\\\"\\\\;.,?!=’:|{}[]()&+-*%$#!~>^</\"1234567890"};
    size_t found{};
    bool exit{false};
    while (!exit) {
        selectedChars.clear();
        selectedBuckets.clear();
        selectedLines.clear();

        cout<< "\n\n";
        cout << "Choose one of the following options" << endl;
        cout << "1 - Print input lines" << endl;
        cout << "2 - Print original unsorted tokens" << endl;
        cout << "3 - Print tokens sorted by text" << endl;
        cout << "4 - Print tokens sorted by frequency" << endl;
        cout << "5 - Print tokens sorted by length" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice:" << endl;

        getline(cin,userInput);
        if (!userInput.empty()) menuOption = std::stoi(userInput);
        userInput.clear();

        switch (menuOption)  {
            case 0:
                cout << "GoodBye!" << endl;
                exit = true;
                break;

            case 1:
                cout << "which lines? (enter numbers separated by space)" << endl;
                getline(cin,userInput);
                if (!userInput.empty()) selectedLines = lineNumberTokenizer(userInput);
                userInput.clear();
                dictionary->print_input_lines(selectedLines);
                break;

            case 2:
                cout << "which buckets? (enter characters)" << endl;

                getline(cin,userInput);

                found = userInput.find_first_of(nonAlphaSymbols);
                if (found != std::string::npos) selectedBuckets.insert('[');

                selectedChars = userInput;
                userInput.clear();
                for (char c : selectedChars) {
                    if (c == ' ' || c == '\n' || c == '\t' || c == '\r') continue;
                    selectedBuckets.insert(c);
                }
                dictionary->print_original_buckets(selectedBuckets);
                break;

            case 3:
                cout << "which buckets? (enter characters)" << endl;
                getline(cin,userInput);
                found = userInput.find_first_of(nonAlphaSymbols);
                if (found != std::string::npos) selectedBuckets.insert('[');
                selectedChars = userInput;
                userInput.clear();
                for (char c : selectedChars) {
                    if (c == ' ' || c == '\n' || c == '\t' || c == '\r') continue;
                    selectedBuckets.insert(c);
                }
                dictionary->print_buckets_sorted_on_word_text(selectedBuckets);
                break;

            case 4:
                cout << "which buckets? (enter characters)" << endl;
                getline(cin,userInput);
                found = userInput.find_first_of(nonAlphaSymbols);
                if (found != std::string::npos) selectedBuckets.insert('[');
                selectedChars = userInput;
                userInput.clear();
                for (char c : selectedChars) {
                    if (c == ' ' || c == '\n' || c == '\t' || c == '\r') continue;
                    selectedBuckets.insert(c);
                }
                dictionary->print_buckets_sorted_on_word_frequency(selectedBuckets);
                break;

            case 5:
                cout << "which buckets? (enter characters)" << endl;
                getline(cin,userInput);
                found = userInput.find_first_of(nonAlphaSymbols);
                if (found != std::string::npos) selectedBuckets.insert('[');
                selectedChars = userInput;
                userInput.clear();
                for (char c : selectedChars) {
                    if (c == ' ' || c == '\n' || c == '\t' || c == '\r') continue;
                    selectedBuckets.insert(c);
                }
                dictionary->print_buckets_sorted_on_word_length(selectedBuckets);
                break;

            default:
                dictionary->print_original_buckets();
                dictionary->print_input_lines();
        }
    }
    delete dictionary;
}

int main() {
    //testWordClass();
    //makeDictionary();
    runProgram();

    return 0;
}

// /Users/ali/repos/word-counter/word-counter/Seuss.txt

// . ;?()= "-,13579