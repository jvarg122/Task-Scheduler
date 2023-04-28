#ifndef __TASK_HPP__
#define __TASK_HPP__
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class task{

  public:
    task(); 
    task(string); //checked off
    task(string, string);
    task(string, string,int , int); //checked off
    task(string, string, string, int, int, string, string, int);
    void input_name(string); //checked off
    string output_name();
    void input_date(string); //checked off
    void input_note(string); //checked off
    void input_time(int, int); //checked off
    void input_location(string); //checked off
    bool isComplete(string); //checked off
    void input_subtasks(string); //checked off
    void input_priority(int); //checked off
    void input_label(string); //checked off
    void edit_task(task* taskName); //checked off
    void display(); //checked off

    string name;
    string note;
    string date;
    int hours;
    int minutes;
    string location;
    string label;
    int priority; //greater integer implies greater priority (priority is 0 for no priority)
    bool complete;
    //vector <Task* > subtasks; //need to implement vector<Task*> subtasks in task.cpp
    vector <string> subtasks;
};

#endif
