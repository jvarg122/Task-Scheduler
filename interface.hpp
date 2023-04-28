#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include "task.hpp"
#include "List_of_tasks.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

class Interface : public List_of_tasks {
  private:

  public:
    void display_options(); //displays the tasks the user has chosen

    void input_tasks(); //user task is taken and stored

    void output_tasks(); //This class contains all the outputs by priority in addition to the option to select and display particular details.

    void display_task_status();

    void edit_tasks(const string& );
};


#endif