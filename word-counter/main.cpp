
#include <iostream>
#include <cassert>
#include <string>
//#include "inc/NumList.h"
#include "inc/Word.h"
//#include "inc/WordList.h"
//#include "Dictionary.h"


using std::cout;
using std::endl;

/*
void testNumListClass() {
    std::cout << "Testing NumList!\n";
    NumList list{};
    cout << "list-1 -> " << list << endl;
    assert(list.getCapacity() == 1);

    list.append(19);
    cout << "list-2 -> " << list << endl;
    assert(list.getCapacity() == 1);
    assert(list.getSize() == 1);

    list.append(32);
    cout << "list-3 -> " << list << endl;
    assert(list.getCapacity() == 2);
    assert(list.getSize() == 2);

    list.append(21);
    cout << "list-4 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.getSize() == 3);

    list.append(7);
    cout << "list-5 -> " << list << endl;
    assert(list.getCapacity() == 4);
    assert(list.getSize() == 4);

    list.append(18);
    cout << "list-6 -> " << list << endl;
    assert(list.getCapacity() == 8);
    assert(list.getSize() == 5);

    int value = -1;
    for (int k = 0; k < list.getSize(); ++k) {
        assert(list.get(k, value));
        assert(value == list.get(k));
    }

    assert(! list.get(list.getSize(), value));
    cout << "NumList Test Successful" << endl;
}
*/

Word makeWord(string word, size_t lineNumber)
{
    Word w1{ word, lineNumber };
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
/*
void testWordList() {
    WordList bucket;
    Word t1("Hello", 1); bucket.addSorted(t1);
    Word t2("Hello", 11); bucket.addSorted(t2);
    Word t3("Hello", 111); bucket.addSorted(t3);
    Word tArray[]{ Word("How", 1), Word("are", 11), Word("you", 2),
                   Word("today?", 22), Word("#tag", 3),
                   Word("bye", 3) };
    for (const Word& t : tArray)
    {
        bucket.addSorted(t);
    }
    bucket.print(cout);
    cout << endl;
}
*/
/*
void testDictionaryClass() {
        cout << "Enter the name of input text file: " ;
        string filename;
        std::cin >> filename;
        Dictionary dictionary(filename);
        dictionary.print(cout);
};
*/

int main() {
    //testNumListClass();
    testWordClass();
    //testWordList();
    //testDictionaryClass();
    return 0;
}

// /Users/ali/repos/word-counter/word-counter/Seuss.txt