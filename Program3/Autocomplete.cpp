#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "Autocomplete.h"

using namespace std;

//Insert function that will take a Term object and insert it into the terms vector of the Autocomplete object
void Autocomplete::insert(Term newterm){
   terms.push_back(newterm); //push the term back in the vector
}

//The allMatches function that will create a vector of Terms, find all the terms that have the same given prefix
//and add those terms into the newly created vector. This vector is then returned.        
vector<Term> Autocomplete::allMatches(string prefix){
   vector<Term> my_vector; //create the vector of terms

   for(int k = 0; k < terms.size(); k++){ //loop through all the terms
      for(int i = 0; i < terms.size() - 1; i++){
         if(terms[i].compareTo(terms[i + 1]) == -1){ //sort them in lexicographical by calling the compareTo function
            swap(terms[i], terms[i + 1]); //if its = -1 then they need to be swapped
         }
      }
   }

   //THIS CODE IS TO REMOVE POSSIBLE SEGMENTATION FAULTS (THE VERY NEXT FOR LOOP)
   int counter = 0; 

   for(int i = 0; i < terms.size(); i++){
      if(terms[i].query.substr(0, prefix.length()) == prefix){ 
         counter++;
      }      
   }
   if(counter != 0){

      //get the middlemost index by calling binary search
      int index = binary_search(prefix, 0, terms.size() - 1);
    

      //set counters for the right and left side
      int right = 0;
      int left = 0;

      //loop through the right half
      for(int i = index; i < terms.size(); i++){
         if(terms[i].query.substr(0, prefix.length()) != prefix){ //if the prefix doesnt match
            break; //break the loop
         }
         else{
            right++; //if they do then increment the right side
         }
      }

   //loop through the left half
      for(int i = index; i >= 0; i--){
         if(terms[i].query.substr(0, prefix.length()) != prefix){ //if the prefix doesn't match
            break; //break the loop
         }
         else{
            left++; //if they do then increment the left side
         }
      }

   //If the index isnt't negative 1
      if(index != -1){   
         for(int i = (index - left) + 1; i < index + right; i++){ //loop through the chunk that matches
            my_vector.push_back(terms[i]); //insert it
         }
      }

      if(my_vector.size() != 0){ 
         for(int k = 0; k < my_vector.size(); k++){
            for(int i = 0; i < my_vector.size() - 1; i++){
               if(my_vector[i].byReverseWeightOrder(my_vector[i + 1]) == -1){
                  swap(my_vector[i], my_vector[i + 1]);
               }
            }
         }
      }
   }
   return my_vector; //return the vector
}

//Print function for any time the list of terms needs to be checked
void Autocomplete::print(){
   for(int i = 0; i < terms.size(); i++){ //loop thorugh every term
      terms[i].print(); //call the print function of the Term object
   }
}

int Autocomplete::binary_search(string key, int leftindex, int rightindex){
  if(terms[leftindex].query > terms[rightindex].query){ //if the left is greater than the right
    return -1; //return -1 for KEY NOT FOUND
  }
  else{ //else
    int middle = (leftindex + rightindex) / 2; //Initialize middle
    if(terms[middle].query.substr(0, key.length()) > key){ //if terms[middle] is greater than the key
      return binary_search(key, leftindex, middle - 1); //recursion to look at the left of middle
    }
    else if(terms[middle].query.substr(0, key.length()) < key){ //if terms[middle] is less than the key
      return binary_search(key, middle + 1, rightindex); //recursion to look at the right of middle
    }
    else{ //else
      return middle; //return middle
    }
  }
}

