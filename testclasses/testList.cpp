#include "List_of_tasks.hpp"
#include "task.hpp"
#include <iostream>

int main() {
  List_of_tasks list1;
  int choice;
  cout << "Choose test cases (1-8)\n";
  cin >> choice;

  if (choice == 1) // add_task()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task1", "Sample Note", "01/01/2022", 11, 59,"Loc: UCR Campus", "-", 0);
      list1.add_task(task1);
      list1.output_all();
      delete task1;
    }
    cout << "------created a task and successfully added it to list-----\n";
  }

  else if (choice == 2) // output_all()
  {
    {
      List_of_tasks list1;
      task* task1= new task("Task1", "Sample Note", "01/01/2022", 11, 59,"Loc: UCR Campus", "-", 0);
      list1.add_task(task1);
      list1.output_all();
      delete task1;
    }
    cout << "\n----successfully implemented output_all()----\n";
  }

  else if (choice == 3) // delete_task()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task1", "Sample Note", "01/01/2022", 11, 59,"Loc: UCR Campus", "-", 0);
      list1.add_task(task1);
      list1.output_all();
      cout << "\n\nDeleting Task1\n";
      list1.delete_task("Task1");
      list1.output_all();
      delete task1;
    }
    cout << "\n----------Successfully deleted a task---------\n";
  } else if (choice == 3) // delete_task(), add_task()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task1", "Sample Note", "01/01/2022", 11, 59,"Loc: UCR Campus", "-", 0);
      list1.add_task(task1);
      list1.output_all();
      cout << "\n\nDeleting Task1\n";
      list1.delete_task("Task1");
      list1.output_all();
      task* task2 = new task("Task2", "Sample Note", "01/01/2022", 02, 00,
                  "Loc: UCR Campus", "-", 0);
      list1.add_task(task2);
      task* task3= new task("Task3", "Sample Note", "01/01/2022", 02, 00,
                  "Loc: UCR Campus", "-", 0);
      list1.add_task(task3);
      list1.output_all();
      delete task1;
      delete task2;
      delete task3;
    }
    cout << "\n---------Successfully deleted and added a task---------\n";
  }

  else if (choice == 4) //time_left()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task1", "Sample Note", "03/11/2022", 11, 59,"Loc: UCR Campus", "-", 0);
      list1.add_task(task1);
      list1.output_all();

      list1.time_left(task1);
      delete task1;
    }
    cout << "\n-------Successfully outputted the time_left() function--------\n";
  }

  else if (choice == 5) // sort_by_time(), sort_by_priority()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task 1", "Sample Note", "01/01/2022", 11, 59,
                  "Loc: UCR Campus", "-", 3);
      task* task2 = new task("Task 2", "Sample Note", "01/01/2022", 02, 20,
                  "Loc: UCR Campus", "-", 2);
      task* task3 = new task("Task 3", "Sample Note", "03/03/2022", 03, 30,
                  "Loc: UCR Campus", "-", 1);
      list1.add_task(task1);
      list1.add_task(task2);
      list1.add_task(task3);
      list1.output_all();
      cout << "\n:::::::::Sorting by time:\n\n";
      list1.sort_by_time();
      list1.output_all();
      cout << "\n:::::::::Sorted by priority:\n\n";
      list1.sort_by_priority();
      list1.output_all();
      delete task1;
      delete task2;
      delete task3;
    }
    cout << "\n-----------Successfully implemented sort_by_time() and sort_by_priority()---------\n";
  }

  else if (choice == 6) // outputHighestPrioirity()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task 1", "Sample Note", "01/01/2022", 11, 59,
                  "Loc: UCR Campus", "-", 3);
      task* task2 = new task("Task 2", "Sample Note", "02/02/2022", 02, 20,
                  "Loc: UCR Campus", "-", 2);
      task* task3 = new task("Task 3", "Sample Note", "03/03/2022", 03, 30,
                  "Loc: UCR Campus", "-", 1);
      list1.add_task(task1);
      list1.add_task(task2);
      list1.add_task(task3);
      list1.output_highestPriority();
      delete task1;
      delete task2;
      delete task3;
    }
    cout << "\n----------Successfully implemented output_highestPriority()----------\n\n";
  }

  else if (choice == 7) // output_userTask()
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task 1", "Sample Note", "01/01/2022", 11, 59,
                  "Loc: UCR Campus", "-", 3);
      task* task2 = new task("Task 2", "Sample Note", "02/02/2022", 02, 20,
                  "Loc: UCR Campus", "-", 2);
      task* task3 = new task("Task 3", "Sample Note", "03/03/2022", 03, 30,
                  "Loc: UCR Campus", "-", 1);
      list1.add_task(task1);
      list1.add_task(task2);
      list1.add_task(task3);
      cout << "Outputting Task2\n";
      list1.output_userTask("Task 2");
      cout << "Outputting Task1\n";
      list1.output_userTask("Task 1");
      delete task1;
      delete task2;
      delete task3;
    }
    cout << "\n---------Successfully implemented output_userTask()------------\n\n";
  }
  else if (choice == 8)// display_by_label(const string& labelName)
  {
    {
      List_of_tasks list1;
      task* task1 = new task("Task 1", "Sample Note", "01/01/2022", 11, 59,"Loc: UCR Campus", "-", 3);
      task* task2 = new task("Task 2", "Sample Note", "02/02/2022", 02, 20,"Loc: UCR Campus", "//", 2);
      task* task3 = new task("Task 3", "Sample Note", "03/03/2022", 03, 30,"Loc: UCR Campus", "-", 1);
      list1.add_task(task1);
      list1.add_task(task2);
      list1.add_task(task3);
      list1.output_all();
      cout << ":::::::::::Printing tasks with label \'-\'\n";
      list1.display_by_label("-");
      delete task1;
      delete task2;
      delete task3;
    }
    cout << "\n----------Successfully implemented display_by_label()----------\n\n";
  }
}