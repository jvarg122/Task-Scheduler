#include "interface.hpp"
#include "task.hpp"
#include "List_of_tasks.hpp"
#include <iostream>
using namespace std;

void Interface::display_options() {
  char userChoice;
  List_of_tasks::output_all();

  do{
    cout << "--------Display Options Menu--------: " << endl;
    cout << "1 - Display all tasks" << endl;
    cout << "2 - Display tasks by priority" << endl;
    cout << "3 - Display tasks by time due" << endl;
    cout << "4 - Display specific task" << endl;
    cout << "5 - Display the date and time a task is due" << endl;
    cout << "q - quit." << endl;
  
    cin >> userChoice;
    
    //task changes:
    if(userChoice == '1'){
      List_of_tasks::output_all();
    }
    else if(userChoice == '2'){
      List_of_tasks::sort_by_priority();
      List_of_tasks::output_all();
    }
    else if(userChoice == '3'){
      List_of_tasks::sort_by_time();
      List_of_tasks::output_all();
    }
    else if(userChoice == '4'){
      string taskName;
      cout << "What task would you like to see: ";
      cin.ignore();
      getline(cin, taskName);
      List_of_tasks::output_userTask(taskName);
    }
    else if (userChoice == '5'){
      string taskName;
      cout << "Which task's due date would you want to see? ";
      cin.ignore();
      getline(cin, taskName);
      for (unsigned int i=0; i < list.size(); ++i) {
        if(taskName == list.at(i)->name)
        {
          cout << taskName << " is due on " << list.at(i)->date << " at " << list.at(i)->hours << ":" << list.at(i)->minutes << ".\n";
          break;
        }
      } 
    }
    {
      cout << "Invalid choice\n";
    }
  } while (userChoice != 'q');
  
}

void Interface::input_tasks() {
  string str;
  cout << "What task would you like to add?" << endl;

  task* temp = new task();
  
  cout << "Enter task name\n";
  cin.ignore();
  getline(cin, str);
  temp->input_name(str);
  
  cout << "Enter date the task is due:(must be in mm/dd/yyyy format)\n";
  cin >> str;
  temp->input_date(str);

  cout << "Enter time the task is due:(must be in hh:mm 24-hour format)\n";
  cin >> str;
  temp->input_time( stoi(str.substr(0,2)), stoi(str.substr(3,2)) );

  char choice;
  cout << "Would you like to add a note(y/n)?" << endl;
  cin >> choice;
  if(choice == 'y') {
    cout << "Enter a note for your task\n";
    cin.ignore();
    getline(cin, str);
    temp->input_note(str);
  }
  cout << "Would you like to add a label(y/n)?" << endl;
  cin >> choice;
  if(choice == 'y') {
    cout << "Enter a label for your task\n";
    cin.ignore();
    getline(cin, str);
    temp->input_label(str);
  }
  cout << "Would you like to add a priority(y/n)?" << endl;
  cin >> choice;
  if(choice == 'y') {
    int p;
    cout << "What would be the priority of this task?\n";
    cin >> p;
    temp->input_priority(p);
  }
  cout << "Would you like to add a location(y/n)?" << endl;
  cin >> choice;
  if(choice == 'y') {
    cout << "Enter a location for your task\n";
    cin.ignore();
    getline(cin, str);
    temp->input_location(str);
  }
  cout << "Would you like to add a subtask(y/n)?\n";
  cin >> choice;
  if (choice == 'y') {
    do {
      cout << "Enter subtask\n";
      cin.ignore();
      getline(cin, str);
      temp->input_subtasks(str);
      cout << "Would you like to add another subtask?(y/n)\n";
      cin >> choice;
    }while(choice =='y');
      
  }
  cout << "\n\n";
  List_of_tasks::add_task(temp);
}

void Interface::output_tasks() {
  List_of_tasks::output_all();
}

void Interface::display_task_status() {
  for(unsigned int i=0; i<list.size(); i++)
    {
      if(list.at(i)->complete == false)
        {
          cout << "not complete" <<endl;
        }
      else
        {
          cout << "complete" <<endl;
        }
    }
}

void Interface::edit_tasks(const string& str)
{
  for(unsigned int i=0; i<list.size(); i++)
    {
      if(str == list.at(i)->name)
      {
        list.at(i)->task::edit_task(list.at(i));
      }
    }
}