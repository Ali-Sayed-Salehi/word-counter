# word-counter
A program that indexes the words in an input text file, 
keeping track of (1) the line numbers of the lines in 
which the words appear, and (2) the frequency (number of occurrences) 
of the words in the input file.

The program displays the resulting index, 
formatting it similar to an index at the end of a typical textbook.

The counter uses a singly-linked list to store
the words and their frequencies.

## How to run
In the main.cpp, uncomment the class you want to 
run and test. The classes are:
```c++
testNumListClass();
testWordClass();
testWordList();
testDictionaryClass();
```
to only test the final results, only run
`testDictionaryClass();`

*Note:*
When prompted to input the file name, 
give the absolute address of your test file.

## Sample Output
1st column: word

2ns column: frequency in the whole document

3rd column: number of the lines in which the word appears 

```txt
<A>     a        (2) 37, 46,
        advertising      (1) 9,
        ahead    (1) 46,
        alive    (1) 16,
        all      (1) 47,
        alphabet         (1) 27,
        also     (1) 8,
        am."     (1) 33,
        and      (13) 4, 7, 8, 9, 11, 12, 22, 25, 29, 33, 40, 41, 46,
        are      (7) 11, 14, 16, 25, 40, 45, 47,
        around!"         (1) 29,
        awful    (1) 37,
 
<B>     Blue     (1) 12,
        But      (1) 46,
        bat.     (1) 46,
        be       (2) 28, 29,
        because  (3) 40, 43, 43,
        began    (1) 7,
        behind.  (1) 46,
        below    (1) 14,
        better.  (1) 38,
        beyond   (1) 29,
        big      (1) 46,
        books    (3) 4, 7, 8,
        born     (1) 7,
        bought   (1) 46,
        brain    (1) 31,
 
<C>     Cat      (1) 11,
        called   (1) 27,
        cares    (1) 37,
        cells."  (1) 31,
        characters,      (1) 4,
        children's       (2) 4, 7,
        come     (2) 45, 46,
        companies.       (1) 9,
        cry      (1) 43,
 
<D>     Dr.      (3) 1, 3, 14,
        day!     (1) 35,
        did      (1) 25,
        do       (2) 33, 33,
        don't    (2) 41, 41,
 
<E>     Eggs     (1) 11,
        eggs     (1) 33,
 
<F>     Fish     (3) 12, 12, 12,
        Fish.    (1) 12,
        famous   (2) 3, 11,
        feel     (1) 40,
        filled   (1) 4,
        for      (2) 3, 8,
        found    (1) 29,
        from     (2) 46, 46,
        fun      (2) 25, 25,
        funny    (1) 4,
 
<G>     Geisel,  (1) 3,
        Green    (1) 11,
        get      (2) 35, 38,
        go       (1) 29,
        go."     (1) 20,
        going    (2) 37, 47,
        good"    (1) 25,
        green    (1) 33,
        guaranteed!"     (1) 23,
 

```

