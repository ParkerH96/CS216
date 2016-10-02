#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
 public:
      // default constructor
      Term();
      // initialize with the given query string and weight
      Term(string query, long weight);
      // compares two terms in descending order by weight
      int byReverseWeightOrder(Term that);
      // compares two terms in lexicographic order by query
      int compareTo(Term that);
      // compares two terms in lexicographic order but using only
      // the first r characters of each query
      int byPrefixOrder(Term that, int r);
      // displays the term in the following format:
      // the weight, followed by a tab key, followed by the query
      void print();
     // other member functions you need…
     friend class Autocomplete;
 private:
     string query;
     long weight;
};


#endif
