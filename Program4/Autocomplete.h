#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>
#include "Term.h"

using namespace std;

class Autocomplete
{
    public:

      // inserts the newterm to the sequence
       void insert(Term newterm);

      // returns all terms that start with the given prefix,
      // in descending order of weight
      vector<Term> allMatches(string prefix);
      
      int binary_search(string key, int leftindex, int rightindex);

      //Prints all the items in the vector
      void print();
      // other member functions you need…

    private:
      // choose your own data structure to represent the sequence of Term objects
      vector<Term> terms;
}; 

#endif /* AUTOCOMPLETE_H */
