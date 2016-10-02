#include <iostream>
#include "scheduler.h"

using namespace std;

//default constructor
Scheduler::Scheduler(){
  teams = 0; //set teams = 0
  Arrange = 0; //set Arrange to 0
}

//Parameterized constructor
Scheduler::Scheduler(int ini_teams){
  teams = ini_teams; //set teams equal to the parameter
  Arrange = new int*[teams]; //allocate new memory
  
  for(int i = 0; i < teams; i++){ //for loop to allocate the 2D memory
    Arrange[i] = new int[teams]; //allocate 2D part of the array
  } 
 
}

//destructor
Scheduler::~Scheduler(){
  for(int i = 0; i < teams; i++){ //deallocate 2D part of memory
    delete[] Arrange[i]; 
  }
  delete[] Arrange; //deallocate the array
  Arrange = 0; //set it equal to 0
}

//print function
void Scheduler::print(){
  for(int i = 0; i < teams; i++){ //for loop to loop through every row
    for(int j = teams - 1; j >= 0; j--){ //for loop to loop through every column
      cout << Arrange[i][j] << " "; //output the element in the array
    }
    cout << endl; //spacing
  }

  //THIS IS THE FIX TO MY MEMORY ERROR
  for(int i = 0; i < teams; i++){ //outside for loop
    for(int j = 0; j < teams; j++){ //inner loop
      Arrange[i][j] = 0; //set every element equal to 0 to remove possible memory leaks
    }
  }
}


//recursive generate schedule function
void Scheduler::generateSchedule(int r, int c){  
  bool insertion = false; //bool value for if an insertion has occured

  for(int i = 1; i < teams + 1; i++){ //for loop to loop through all the teams
    if(!C_Row(r, i) && !C_Column(c, i)){ //if the number is not in the current column or row, insert it
      Arrange[r][c] = i; //insert it
      insertion == true; //set insertion equal to true
    }
   
    if(insertion) { //if there was an insertion already
      break; //break the loop so that the next number can be inserted
    }
  }

  if(r == teams - 1 && c == teams - 1){ //if we are in the last row and column
    return; //return because Arrange is full
  }
  else{
    if(c == teams - 1){ //if we are in the last column
      generateSchedule(r + 1, 0); //increment the row
    }
    else{ //otherwise we are in the last row
      generateSchedule(r, c + 1); //increment the column
    }
  }
}

//function for checking the row
bool Scheduler::C_Row(int r, int item){
  bool found = false; //found bool value
  for(int i = 0; i < teams; i++){ //for loop that loops through all the teams
    if(Arrange[r][i] == item){ //if any of the elements = the item
      found = true; //then it is found
    }
  }
  return found; //return found
}

//function for checking the column
bool Scheduler::C_Column(int c, int item){
  bool found = false; //found bool value
  for(int i = 0; i < teams; i++){ //for loop that loops through all the items
    if(Arrange[i][c] == item){ //if any of the elements = the item
      found = true; //then it is found
    }
  }
  return found; //return found

}
