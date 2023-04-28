#include <iostream>
#include "task.hpp"
#include "List_of_tasks.hpp"
#include "interface.hpp"

int main() 
{
  Interface I;
  char c;
  string str;
  cout << "\'\'\'\'\'\'\'\'\'\'Welcome to Task Scheduler\'\'\'\'\'\'\'\'\'\'\n\n\n\n ";
  
  do
  {
    cout << "\n__________MAIN MENU___________\n";
    cout << "1)Add a task(s)\n2)Edit a task(s)\n3)Remove a task(s)\n4)Output task(s)\n";
    cout << "Enter (1-4) to proceed.\nEnter \'q\' to quit\n\n";
    cin >> c;
    if(c=='1')
    {
      I.input_tasks();
    }
    else if(c=='2')
    {
      I.output_tasks();
      cout << "Enter name of task that you wish to edit.\n";
      cin.ignore();
      getline(cin, str);
      I.edit_tasks(str);
    }
    else if(c=='3')
    {
      I.output_tasks();
      cout << "Enter name of task you wish to remove\n";
      cin.ignore();
      getline(cin, str);
      I.delete_task(str);
    }
    else if(c=='4')
    {
      I.display_options();
    }
    else if(c=='q')
    {
      break;
    }
    else
    {
      cout << "Invalid input. Try again!!\n";
    }      
  }while(c!='q');

  return 0;
}

