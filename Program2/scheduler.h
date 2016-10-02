#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
 public:
  Scheduler(); // default constructor
  Scheduler(int ini_teams); // constructor
  // generate the schedule for the number of team = teams 
  void generateSchedule(int r, int c);

  // display the table content of the schedule for each team
  void print();
  // destructor
  ~Scheduler();
  // more member functions here ...

  //Function that returns true or false as to whether an item passed in was in the row passed in
  bool C_Row(int r, int item);

  //Function that returns true or false as to whether an item passed in was in the column passed in
  bool C_Column(int c, int item);

 private:
  int teams; // the number of teams to be scheduled
  int** Arrange;
  // the pointer points at a dynamic two-dimensional
  // array to represent the scheduling table for each team
};

#endif
