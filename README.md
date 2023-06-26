# word-counter
A program that indexes the words in an input text file, 
keeping track of (1) the line numbers of the lines in 
which the words appear, and (2) the frequency (number of occurrences) 
of the words in the input file, and (3) sorting words based on text, length, or frequency depending on
user input.

The program displays the resulting index, 
formatting it similar to an index at the end of a typical textbook.

In the latest version, a refactor has been done in order to use standard C++ containers
and classes instead of local implementations.

## How to run
In the main.cpp, uncomment the function you want to 
run and test. The functions are:
```c++
//testWordClass();
//makeDictionary();
runProgram();
```
to only test the final results, only run
`runProgram();`

*Note:*
When prompted to input the file name, 
give the absolute address of your test file.

The user then enters his preferred delimiters and the dictionary gets created.
In the next step, menu options will be shown as follows:

Choose one of the following options
1 - Print input lines
2 - Print original unsorted words
3 - Print words sorted by text
4 - Print words sorted by frequency
5 - Print words sorted by length
0 - Exit

After selected any of the option, the use will be prompted to select the buckets(characters)
or the lines that he wants to be displayed. if nothing is entered, all the lines or buckets will be 
displayed.


## Sample Output
delimiters: . ;?()="-,13579

1st column: word

2ns column: frequency in the whole document

3rd column: number of the lines in which the word appears 

```txt
Choose one of the following options
1 - Print input lines
2 - Print original unsorted tokens
3 - Print tokens sorted by text
4 - Print tokens sorted by frequency
5 - Print tokens sorted by length
0 - Exit
Enter your choice:
5
which buckets? (enter characters)
t
buckets sorted on word length
===========================
<T>     to       (5)    8 28 29 38 47 

        The      (3)    11 19 

        Top      (1)    1 

        Two      (1)    12 

        the      (5)    11 19 20 27 31 

        than     (3)    16 17 45 

        that     (3)    16 19 20 

        them     (1)    33 

        this     (1)    27 

        true     (1)    16 

        tuzz     (1)    28 

        There    (1)    16 

        These    (1)    25 

        Today    (2)    16 35 

        there    (2)    29 45 

        those    (2)    40 41 

        three    (1)    23 

        truer    (1)    16 

        things   (2)    19 25 

        Theodor  (1)    3 

        troubles         (3)    45 47 

        trisyllabic      (1)    5
```

