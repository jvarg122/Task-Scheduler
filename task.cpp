#include "task.hpp"
using namespace std;
#include <cstdlib>
#include <string>

task::task() {
  this->name = "";
  this->note = "";
  this->date = "";
  this->hours = 0;
  this->minutes = 0;
  this->location = "";
  this->label = "";
  this->priority = 0;
  this->complete = false;
}

task::task(string newName, string newNote, string newDate, int newHour,
           int newMinute, string newLocation, string newLabel,
           int newPriority) {
  this->name = newName;
  this->note = newNote;
  this->date = newDate;
  this->hours = newHour;
  this->minutes = newMinute;
  this->location = newLocation;
  this->label = newLabel;
  this->priority = newPriority;
  this->complete = false;
}

task::task(string newName, string newDate, int hours, int minutes)
    : name(newName), date(newDate), hours(hours), minutes(minutes) {
  this->note = "";
  this->location = "";
  this->label = "";
  this->priority = 0;
  this->complete = false;
}

task::task(string newName) : name(newName) {
  this->note = "";
  this->date = "";
  this->hours = 0;
  this->minutes = 0;
  this->location = "";
  this->label = "";
  this->priority = 0;
  this->complete = false;
}

task::task(string newName, string newDate) : name(newName), date(newDate) {
  this->note = "";
  this->hours = 0;
  this->minutes = 0;
  this->location = "";
  this->label = "";
  this->priority = 0;
  this->complete = false;
}

void task::input_name(string newName) { this->name = newName; }

string task::output_name() { return this->name; }

void task::input_date(string newDate) { this->date = newDate; }

void task::input_note(string newNote) { this->note = newNote; }

void task::input_time(int hours, int minutes) {
  this->hours = hours;
  this->minutes = minutes;
}

void task::input_location(string newLocation) { this->location = newLocation; }

void task::input_label(string newLabel) { this->label = newLabel; }

void task::input_priority(int newPriority) { this->priority = newPriority; }

bool task::isComplete(string completedTaskName) {
  if (this->name == completedTaskName) {
    this->complete = true; 
    return true;
  }
  return false;
}

void task::input_subtasks(string subtask_name) { 
  subtasks.push_back(subtask_name);
}

void task::edit_task(task *taskName) {
  char choice;

  do {
    cout << "\n-----EDIT TASK MENU--------\n";
    cout << "1 - Change name." << endl;
    cout << "2 - Change note." << endl;
    cout << "3 - Change date." << endl;
    cout << "4 - Change time." << endl;
    cout << "5 - Change location." << endl;
    cout << "6 - Change label." << endl;
    cout << "7 - Change priority." << endl;
    cout << "8 - add subtask." << endl;
    cout << "9 - delete subtask." << endl;
    cout << "q - quit." << endl;

    cin >> choice;

    if (choice == '1') {
      string newName;
      cout << "Enter new name:\n";
      cin.ignore();
      getline(cin, newName);
      taskName->input_name(newName);
    } else if (choice == '2') {
      string newNote;
      cout << "Enter new note: " << endl;
      cin.ignore();
      getline(cin, newNote);
      taskName->input_note(newNote);
    } else if (choice == '3') {
      string newDate;
      cout << "Enter new date (must be in mm/dd/yyyy format):\n";
      cin.ignore();
      getline(cin, newDate);
      taskName->input_date(newDate);
    } else if (choice == '4') { // input_time(int , int)
      int hours, minutes;
      cout << "Enter new hour: " << endl;
      cin >> hours;
      cout << "Enter new minutes: " << endl;
      cin >> minutes;
      taskName->input_time(hours, minutes);
    } else if (choice == '5') { // input_location(string)
      string newLocation;
      cout << "Enter new location: " << endl;
      cin.ignore();
      getline(cin, newLocation);
      taskName->input_location(newLocation);
    } else if (choice == '6') { // change label
      string newLabel;
      cout << "Enter new label: " << endl;
      cin.ignore();
      getline(cin, newLabel);
      taskName->input_label(newLabel);
    } else if (choice == '7') { // change priority
      int newPriority;
      cout << "Enter new priority: " << endl;
      cin >> newPriority;
      taskName->input_priority(newPriority);
    } else if (choice == '8') { // add subtask, input_subtasks(string);
      string newSubtaskName;
      cout << "Enter the new subtask name: " << endl;
      cin.ignore();
      getline(cin, newSubtaskName);
      taskName->input_subtasks(newSubtaskName);
    } else if (choice == '9') { // output all subtask first and then delete?
      for (int i = 1; i <= subtasks.size(); i++) {
        cout << "Subtask #" << i
             << " is: " << subtasks.at(i - 1); // outputs names for each subtasktas
        cout << endl;
      }
      cout << endl;
      cout << "Enter the # of the subtask that you want to delete:" << endl;
      int deleteNum;
      cin >> deleteNum;
      subtasks.erase(subtasks.begin() + deleteNum - 1);
    } else {
      break;
      cout << "Invalid input -- press \'q\' to quit\n";
    }
  } while (choice != 'q');
}

void task::display() { // display the task details, bascially output all the private variables w good-looking format, including all subtasks.
  cout << "Name:\t\t " << this->name << endl;
  cout << "Note:\t\t " << this->note << endl;
  cout << "Date:\t\t " << this->date << endl;
  cout << "Time:\t\t " << this->hours << ":" << this->minutes << endl;
  cout << "Location:\t " << this->location << endl;
  cout << "Label:\t\t " << this->label << endl;
  cout << "Priority:\t " << this->priority << endl;
  cout << "Subtasks for task " << this->name << ": \n";
  for (int i = 1; i <= subtasks.size(); i++) {
    cout << "Subtask #" << i << " is:\t" << subtasks.at(i - 1);
    cout << endl << endl;
  }
}
