#include <iostream>
#include <string>
#include "stdlib.h"
#include "stdio.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Autocomplete.h"
#include "Term.h"


using namespace std;

int main(int argc, char** argv){
   //create an ifstream
   ifstream in_file;

   //if statement in regards to incorrect number of command line arguments
   if (argc != 3){ //if its not equal to 3
      cout << "Invalid Usage: ./Program3 <input filename> <k-value>" << endl; //error message
      return 1; //return 1
   }
  
   //Attempt to open the 2nd command line argument (which should be a file)
   in_file.open(argv[1]);
   if(!in_file.good()){ //if it does not open
      cout << "Failure in opening file: " << argv[1] << endl; //error message
      return 2; //return 2
   }

   //Initialize a string and an Autocomplete object
   string line;
   Autocomplete whole_list;

   //while you can get a line from the file store that line into the string line
   while(getline(in_file, line)){
      //Initialize variables
      string query;
      string weight_str;
      long weight;
      
      //query is equal to everything after the tab mark
      query = line.substr(line.find("\t") + 1, -1);
      //the weight string is equal to everything before the tab mark
      weight_str = line.substr(0, line.find("\t"));

      //convert weight string into a long called weight
      weight = atol(weight_str.c_str());
      
      if(query != ""){
         //Create a Term object with query and weight
         Term my_term(query, weight);

         //Insert that object into the Autocomplete object
         whole_list.insert(my_term);
      }
   }
   
   cout << endl; //spacing
   

   string pre = ""; //create a prefix string
   //while the user doesn't type exit
   while(pre != "exit"){
      //create a vector of Terms
      vector<Term> matches;   

      //output message to prompt the user for a search query
      cout << "Please input the search query(type 'exit' to quit): ";
      cin >> pre;

      //if statement to catch if the user types exit at the very beginning
      if(pre == "exit"){
         cout << endl;
         return 0;
      }
 
      //call the allmatches function for the list of all terms and set that equal to the matches vector
      matches = whole_list.allMatches(pre);

      //create an int k that is equal to the 3rd command line argument
      int k = *argv[2] - '0';
      
      //if statement for when there are more matches than the k value
      if(matches.size() > k){ 
         for(int i = 0; i < k; i++){ //for loop that will only loop through the first k terms
            matches[i].print(); //print each match
         }
      }
      else{ //else the amount of matches is less than k
         for(int i = 0; i < matches.size(); i++){ //just loop through all the matches
            matches[i].print(); //print each match
         }
      }   
      //reset the vector
      for(int i = 0; i < matches.size(); i++){
         matches.pop_back();
      }

  }
   
}
