#include "task.hpp"
#include "List_of_tasks.hpp"
#include "interface.hpp"
#include <iostream>


int main() {
  Interface I;
  int userChoice;
  cout << "Select test cases (1- )\n";
  cin >> userChoice;

  if (userChoice == 1) { //test input_tasks()
    {
      I.input_tasks();
      I.output_tasks();
    }
  }
  else if (userChoice == 2) {  //test display_options()
    {
      I.input_tasks();
      cout << endl;
      I.display_options(); 
    }
  }
  else if (userChoice == 3) { //test output_tasks()
    {
      I.input_tasks();
      I.output_tasks();
    }
  }
  else if (userChoice == 4) { //test display_task_status()
    {
      I.input_tasks();
      cout << endl;
      I.display_task_status();
    }
  }
  
  return 0;
}