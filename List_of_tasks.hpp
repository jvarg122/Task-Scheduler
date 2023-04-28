#ifndef __LIST_of_TASKS_HPP__
#define __LIST_of_TASKS_HPP__

#include "task.hpp"
#include <ctime> //for getting current date and time
#include <unistd.h> //use <Windows.h> for windows machine //for getCurrentDateTime()
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class List_of_tasks
{

public:
  vector<task* > list;
 
public:
  void add_task(); 
  void delete_task(const string& );
  void markTaskComplete(task* task);
  void time_left(task* ); 
  void sort_by_priority(); //if two priorities are same, then compare time for 
  void sort_by_time(); //if two times are same, then compare priority
  void output_all();
  void output_highestPriority(); //output the one with top priority
  void output_userTask(const string& );
  void display_by_label(const string& );
  void add_task(task* );

};
#endif