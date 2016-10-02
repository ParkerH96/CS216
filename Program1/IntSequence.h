#ifndef INTSEQUENCE_H
#define INTSEQUENCE_H

const int INITIAL_CAPACITY = 5;

class IntSequence
{
  public:
    // create an integer array with capacity = INITIAL_CAPACITY
    IntSequence(); //default constructor
    // create an integer array with capacity = in_capacity
    IntSequence(int in_capacity);

    // insert item into the end of the array; count increased by 1
    void insert(int item);

    //display all the items in the array
    void print();

    // sort the sequence into non-decreasing order
    // using Selection Sorting algorithm
    void selection_sort();

    // sort the sequence into non-decreasing order
    // using Insertion sorting algorithm
    void insertion_sort();

    // sort the sequence into non-decreasing order
    // using Bubble Sorting algorithm
    void bubble_sort();

    // shuffle the items in the sequence
    // generates a random permutation of array elements
    void shuffle();

    // search a target key in the array:
    // if found return the index number; if not found return -1;
    int sequential_search(int key);

    // sort the array into non-decreasing order first, then
    // search a target key in the array:
    // if found return the index number; if not found return -1
    int binary_search(int key, int leftindex, int rightindex, int& comparison_count);

    // destructor
    ~IntSequence();

    // more member functions here ...
    //return the count
    int getCount();

    //sort without output messages for the binary_search
    void sort();

  private:
    int capacity; // the capacity of the array
    int count; // actual num of items in the array
    int* seq; // the pointer points at the first item in the array
};

#endif
