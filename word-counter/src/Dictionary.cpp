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
