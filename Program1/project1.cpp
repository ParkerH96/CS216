#include <iostream>
#include <sstream>
#include <string>
#include "IntSequence.h"

using namespace std;

int main(){
  int option; //Initialize a option variable 
  cout << "1. Read" << endl << "2. Print" << endl << "3. Sort" << endl << "4. Shuffle" << endl << "5. Search" << endl << "6. Quit" << endl << "Option: "; //Display the main menu
  cin >> option; //Gather an input from the user for a option
 
  while(option > 6 || option < 1){ //while loop that ensures the user's option is between 1 and 6
    cout << "Invalid option!" << endl; //display error message
    cout << "======================================================================" << endl; //spacing
    cout << "1. Read" << endl << "2. Print" << endl << "3. Sort" << endl << "4. Shuffle" << endl << "5. Search" << endl << "6. Quit" << endl << "Option: "; //Re-display the main menu
    cin >> option; //gather a new option from the user
  }
  
  IntSequence my_sequence; //Initialize a class object to use for this program

  while(option != 6){ //main while loop that runs until they choose the quit option or option == 6
    if(option == 1){ //if statement for the read option (option == 1)
      int element; //Initialize variables
      string str = "";

      while(str != "q"){ //while loop that tracks whether or not the user types "q" to quit
        cout << "Enter the next element (Enter 'q' to stop): "; //output message
        cin >> str; //gather a string element from the user
   
        if(str != "q"){ //if statement to insert items so long as "q" was not typed
          string check = str; //make a new string equal to the old string
          istringstream ss(check); //make a string stream for str->int conversion
          ss >> element; //convert the str to an int
          my_sequence.insert(element); //insert that int
        }
      }   
      cout << "===================================================================" << endl; //spacing
    }
   
    if(option == 2){ //if statement for the print option (option == 2)
      cout << "Sequence:      "; //output message
      my_sequence.print(); //call the print function
      cout << endl; //spacing
      cout << "===================================================================" << endl; //spacing
    }
   
    if(option == 3){ //if statement for the sort option (option == 3)
      int sort_option; //Initialize a sort option variable
      cout << "===================================================================" << endl; //spacing
      cout << "1. Insertion sort" << endl << "2. Selection sort" << endl << "3. Bubble sort" << endl << "4. Quit" << endl << "Option: "; //display the sub menu for sorting
      cin >> sort_option; //gather a sort option from the user
      
      while(sort_option > 4 || sort_option < 1){ //while loop that ensures the sort option is between 1 and 4
        cout << "Invalid option!" << endl; //output error message
        cout << "===================================================================" << endl; //spacing 
        cout << "1. Insertion sort" << endl << "2. Selection sort" << endl << "3. Bubble sort" << endl << "4. Quit" << endl << "Option: "; //re-display the sub menu
        cin >> sort_option; //gather a new option from the user
      }
    
      if(sort_option == 1){ //if statement for insertion sort option (option == 1)
        my_sequence.insertion_sort(); //call the insetion sort function
        cout << "===================================================================" << endl; //spacing
      }
      else if(sort_option == 2){ //if statement for selection sort option (sort_option == 2)
        my_sequence.selection_sort(); //call the selection sort function
        cout << "===================================================================" << endl; //spacing
      }
      else if(sort_option == 3){ //if statement for bubble sort option (sort_option == 3)
        my_sequence.bubble_sort(); //call the bubble sort function
        cout << "===================================================================" << endl; //spacing
      }
      else{
        cout << "===================================================================" << endl; //spacing
      }
    }

    if(option == 4){ //if statement for the shuffle option (option == 4)
      my_sequence.shuffle(); //call the shuffle function
      cout << "====================================================================" << endl; //spacing
    }
 
    if(option == 5){ //if statement for the search option (option == 5)
      int search_option; //Initialize a variable for the search option
      cout << "====================================================================" << endl; //spacing
      cout << "1. Sequential search" << endl << "2. Binary search" << endl << "3. Quit" << endl << "Option: "; //display the search sub menu
      cin >> search_option; //Gather a search option from the user

      while(search_option > 3 || search_option < 1){ //while loop that ensures the search option to be between 1 and 3
        cout << "Invalid option!" << endl; //output error message
        cout << "====================================================================" << endl; //spacing
        cout << "1. Sequential search" << endl << "2. Binary search" << endl << "3. Quit" << endl << "Option: "; //re-display the search sub menu
        cin >> search_option; //Gather a new search option from the user
      }
      
      if(search_option == 1){ //if statement for sequential search (search_option == 1)
        int key, index; //Initialize variables
        cout << "Enter the key to find: "; //display output message
        cin >> key; //Gather a search key from the user

        cout << "Sequence:      "; //display output message
        my_sequence.print(); //call the print function
        index = my_sequence.sequential_search(key); //call the sequential seach function

        if(index == -1){ //if statement for when the key is not found (index == -1)
          cout << endl << "Key not found." << endl << "Search with " << my_sequence.getCount() << " comparison(s)." << endl; //display output message / call count function
          cout << "=================================================================" << endl; //spacing
        }
        else{ //else the key is found
          cout << endl << "Key found at index " << index << endl << "Search with " << index + 1 << " comparison(s)." << endl; //display the amount of comparison(s)
          cout << "=================================================================" << endl; //spacing
        }
      }

      if(search_option == 2){ //if statement for binary search (search_option == 2)
        int key, index, comparison_count; //Initialize variables
        cout << "Enter the key to find: "; //display an output message
        cin >> key; //Gather a search key from the user
            
        cout << "Unsorted sequence:      "; //output message
        my_sequence.print(); //call the print function

        cout << endl; //spacing

        cout << "Sorted sequence:      "; //output message

        my_sequence.sort(); //call the sort function
        my_sequence.print(); //call the print function

        comparison_count = 0; //Set this back to 0

        index = my_sequence.binary_search(key, 0, my_sequence.getCount() - 1, comparison_count); //call the binary search function

        if(index == -1){ //key not found
          cout << endl << "Key not found." << endl << "Search with " << comparison_count << " comparison(s)." << endl; //display amount of comparison(s) / call count function
          cout << "=================================================================" << endl; //spacing
        }
        else{ //key found
          cout << endl << "Key found at index " << index << endl << "Search with " << comparison_count << "  comparison(s)." << endl; //display amount of comparisons
          cout << "================================================================" << endl; //spacing
        }
      }

      if(search_option == 3){ //Quit option
        cout << "================================================================" << endl; //spacing
      }
    }
    cout << "1. Read" << endl << "2. Print" << endl << "3. Sort" << endl << "4. Shuffle" << endl << "5. Search" << endl << "6. Quit" << endl << "Option: "; //main prompt
    cin >> option; //Gather a new input

    while(option > 6 || option < 1){ //same while loop as before to check the input to be between 1 and 6
      cout << "Invalid option!" << endl;
      cout << "======================================================================" << endl;
      cout << "1. Read" << endl << "2. Print" << endl << "3. Sort" << endl << "4. Shuffle" << endl << "5. Search" << endl << "6. Quit" << endl << "Option: ";
      cin >> option;
    }

  }
  cout << "Thank you for using the program." << endl << "====================================================================" << endl; //Final output message
}
