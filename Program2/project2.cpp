#include <iostream>
#include <string>
#include <sstream>
#include "scheduler.h"

using namespace std;

int main(){

  string str; //Initialize variables
  int teams, power;

  cout << "Please input the number of teams to be scheduled (type q or Q to quit): "; //output message
  cin >> str; //get the string from the user
  
  while(str != "q" && str != "Q"){ //while loop for when user input is != q or Q
    string check = str; //make a new string equal to the old string
    istringstream ss(check); //make a string stream for str->int conversion
    ss >> teams; //convert the str to an int
    
    if(teams > 512){ //make sure the max number of teams is 512
      cout << "The maximum number of teams is 512" << endl; //output message
    }   
    else if(teams == 1){ //special case for 1 team
      cout << "The schedule for 1 teams: " << endl << 1 << endl; //output schedule for 1 team
    }
    else{
      power = teams; //set power equal to the amount of teams

      while(power % 2 == 0 && power > 1){ //while loop to check if power of two
        power /= 2; //divide power by 2
      }
    
      if(power == 1){ //if power == 1 then it was a power of two
        Scheduler my_schedule = Scheduler(teams); //creat a class variable with the user input
      
        cout << "The schedule for " << teams << " teams:" << endl; //output message
          
        my_schedule.generateSchedule(0, 0); //call the recursive function for the schedule
        my_schedule.print(); //call the print function
      }
      else{
        cout << "The number of teams is not a power of two!" << endl; //output error message
      }
    }
    cout << "Please input the number of teams to be scheduled (type q or Q to quit): "; //output message
    cin >> str; //gather new input
  }

  cout << "Thanks for using the scheduling program." << endl; //ending message

}
