#include <iostream>
#include <string>
#include "Term.h"
#include "Autocomplete.h"

using namespace std;

//Default constructor
Term::Term(){
    query = ""; //set query equal to an empty string
    weight = 0; //set weight equal to 0
}

//Paramterized constructor
Term::Term(string query, long weight){
    this->query = query; //set query = query
    this->weight = weight; //set weight = weight
}

//Function to help sort Terms in order of reverse weight
int Term::byReverseWeightOrder(Term that){
    if(weight == that.weight){ //if the first weight equals the next
       return 0; //return 0
    }
    else if(weight > that.weight){ //if the first weight is greater
       return 1; //return 1
    }   
    else{ //else if the second weight is greater
       return -1; //return -1
    }
}

//Function to help sort Terms in lexicographical order with their queries
int Term::compareTo(Term that){
    if(query == that.query){ //if the first query equals the second
       return 0; //return 0
    }
    else if(query > that.query){ //if the first query is greater
       return -1; //return -1
    }
    else{ 
       return 1; //return 0
    }
}

//Function that sorts by Prefix order
int Term::byPrefixOrder(Term that, int r){
    string str1 = query.substr(0, r);
    string str2 = that.query.substr(0, r);

    if(str1 == str2){
       return 0;
    }
    else if(str1 > str2){
       return -1;
    }
    else{
       return 1;
    }
    
}

//Print function
void Term::print(){
    cout << weight << " " << query << endl; //cout the weight followed by a space and then the query
}
