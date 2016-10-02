#include <iostream>
#include <stdio.h>  //includes NULL
#include <stdlib.h> // includes srand and rand
#include <time.h> // time library
#include "IntSequence.h"

using namespace std;

//default constructor
IntSequence::IntSequence(){
  count = 0; //Initialize count variable
  capacity = INITIAL_CAPACITY; //set the capacity = INITIAL_CAPACITY
  seq = new int[capacity]; //allocate a new array with INITIAL_CAPACITY
}

//parameterized constructor
IntSequence::IntSequence(int in_capacity){
  count = 0; //Initialize count variable
  capacity = in_capacity; //set the capacity = in_capacity
  seq = new int[capacity]; //allocate a new array with in_capacity
}

//deconstructor
IntSequence::~IntSequence(){
  delete[] seq; //deallocate the memory
}

//Function that returns the count to the main function
int IntSequence::getCount(){
  return count; //return the count
}

//Function that prints every element in the existing array
void IntSequence::print(){
  for(int i = 0; i < count; i++){ //for loop that loops through every element in the seq array
    cout << seq[i] << " "; //cout the element(s)
  }
}

//Function that inserts a new item into the array given by the user
void IntSequence::insert(int item){ 
  count++; //increase the size
  
  if(count > capacity){ //if the size is greater than the greater than the current capacity
  
  capacity *= 2; //double the current capacity
  
  int* temp = new int[capacity]; //create a new array with the new capacity

  for(int i = 0; i < count; i++){ //for loop that goes through every element in the array
    temp[i] = seq[i]; //transfer all of the data on the old array over
  }
  
  delete[] seq; //deallocate the memory
  
  seq = temp; //set a new sequence equal to the temporary one 
  }

  seq[count - 1] = item; //insert at the end of the current size(count)
}

//Function that sorts the array without all of the extra prompt code (This is for the binary search function)
void IntSequence::sort(){  
  for(int i = 1; i < count; i++){ //first for loop
    for(int j = 0; j < count - 1; j++){ //second for loop
      if(seq[j] > seq[j + 1]){ //if the element before the next element is greater, swap them
        swap(seq[j], seq[j + 1]); //swap the elements
      }
    }
  }
}

//Function that sorts the array via the Insertion sort algorithm
void IntSequence::insertion_sort(){
  int key, position; //Initialize variables
  cout << "===Insertion Sort===========================================" << endl; //spacing
  for(int i = 1; i < count; i++){ //for loop that goes through the entire array
    key = seq[i]; //set the k equal to the ith element
    position = i; //set position = i

    while(position > 0 && seq[position - 1] > key){ //while position is greater than 0 and seq of position - 1 is greater than the key
      seq[position] = seq[position - 1]; //set the position = position - 1
      position -= 1; //decrease position
    }
  
    seq[position] = key; //position = key
    cout << "Insert " << key << ":    "; //spacing/output message

    for(int k = 0; k < count; k++){ //for loop to print
      cout << seq[k] << " "; //print the sequence on the current insertion step
    }
    cout << endl; //spacing
  }
  cout << "Sequence:    "; //output message

  for(int k = 0; k < count; k++){ //for loop to print
    cout << seq[k] << " "; //print the final sorted sequence
  }

  cout << endl; //spacing
}

//Function that sorts the array via the Bubble sort method
void IntSequence::bubble_sort(){
  cout << "===Bubble Sort=============================================" << endl; //spacing
  for(int i = 1; i < count; i++){ //for loop to go through every element in the array
 
    cout << "Iteration " << i << ":   "; //spacing/output message
    for(int j = 0; j < count - 1; j++){ //for loop

      if(seq[j] > seq[j + 1]){ //if the previous is greater than the next
        swap(seq[j], seq[j + 1]); //swap the two
      }   
    }
    for(int j = 0; j < count; j++){ //for loop to print
      cout << seq[j] << " "; //print out the current iteration
    }
    cout << endl; //spacing
  }
  cout << "Sequence:      "; //output message 

  for(int i = 0; i < count; i++){ //for loop to print
    cout << seq[i] << " "; //print out the final iteration
  }
  cout << endl; //spacing
}

//Function that sorts the array via the Selection sort method
void IntSequence::selection_sort(){
  int min; //Initialize variables
  cout << "===Selection Sort=========================================" << endl; //spacing
  for(int i = 0; i < count - 1; i++){ //for loop
    min = i; //set the min variable
    for(int j = i + 1; j < count; j ++){ //for loop to find the min
      if(seq[j] < seq[min]){ //if the current j is less than the min
        min = j; //make it the new min
      }
    }
    if(min != i){ //if the min is not equal to i
      swap(seq[i], seq[min]); //swap them
      cout << "Min " << min << ", swap with " << seq[i] << ":   "; //output message
      for(int k = 0; k < count; k++){ //for loop for printing
        cout << seq[k] << " "; //print the current Iteration
      }
      cout << endl; //spacing
    }
  }
  cout << "Sequence:      "; //output message
  for(int i = 0; i < count; i++){ //for loop for printing
    cout << seq[i] << " "; //print out the final sorted array
  }
  cout << endl; //spacing
}

//Function that shuffles the array in a random order
void IntSequence::shuffle(){
  for(int i = count - 1; i > 0; i--){ //for loop for the algorithm
    srand(time(NULL)); //set a random seed with the system clock
     
    int j = rand() % i; //create a random j that is between 0 and i

    swap(seq[j], seq[i]); //swap seq[j] and seq[i]
  }
}

//Fuction that searches through the array sequentially
int IntSequence::sequential_search(int key){ 
 for(int i = 0; i < count; i++){ //for loop that goes through every element in the array
    if(key == seq[i]){ //if the key is found
      return i; //return the index value (AKA i)
    }
 }
 return -1; //if nothing was returned from the previous loop, return -1 for KEY NOT FOUND
}

//Function that searches through the array binarily
int IntSequence::binary_search(int key, int leftindex, int rightindex, int& comparison_count){
  
  if(leftindex > rightindex){ //if the left is greater than the right
    comparison_count++;
    return -1; //return -1 for KEY NOT FOUND
  }
  else{ //else
    int middle = (leftindex + rightindex) / 2; //Initialize middle
    if(seq[middle] > key){ //if seq[middle] is greater than the key
      comparison_count++;
      return binary_search(key, leftindex, middle - 1, comparison_count); //recursion to look at the left of middle
    }
    else if(seq[middle] < key){ //if seq[middle] is less than the key
      comparison_count++;
      return binary_search(key, middle + 1, rightindex, comparison_count); //recursion to look at the right of middle
    }
    else{ //else
      comparison_count++;
      return middle; //return middle
    }
  }
}	
