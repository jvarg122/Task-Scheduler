#include <iostream>
#include "task.hpp"

int main()
{
  int c;
  cout << "Enter choice (1-11)\n";
  cin >> c;
  cout << "\n";

  if (c == 1) // empty task
  {
    task* t= new task();
    t->display();
    delete t;
    cout << "--------Successfully implemented default constructor--------\n\n";
  }

  else if(c == 2) //parameterized constructor (name)
  {
    task* t= new task("Task Name");
    t->display();
    delete t;
    cout << "--------Successfully implemented (name) constructor--------\n\n";
  }

  else if(c == 3) //name, date, hr, mins
  {
    {
      task* t= new task("Task Name", "01/01/2001", 11,59);
      t->display();
      delete t;
    }
    cout << "--------Successfully implemented (name,date,hrs,mins) constructor--------\n\n";
  }

  else if(c==4) //parameterized consturctor
  {
    {
      task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
      t->display();
      delete t;
    }
    cout << "--------Successfully implemented parameterized constructor--------\n\n";
  }

  else if(c==5) //input_name(), input_date(), input_time()
  {
    {
      task* t = new task("zero", "00/00/0000", 00,00);
      t->input_name("ABCD");
      t->input_date("11/11/1111");
      t->input_time(11,59);
      t->display();
      delete t;
    }
    cout << "--------Successfully implemented input_name(), date(), time()--------\n\n";
  }

  else if(c==6) //edit_task()
  {
    {
      task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
      t->display();
      t->edit_task(t);
      t->display();
      delete t;
    }
    cout << "--------Successfully implemented edit_task()--------\n\n";
  }

  else if(c==7){ //input_label() input_priority(int) input_note(string) input_location(string)
    {
      task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
      t->display();
      
      cout << endl << "Outputting again:" << endl;
      t->input_label("Red thongs ftw");
      t->input_priority(69);
      t->input_note("the size is S");
      t->input_location("Victoria's Secret");
      t->display();
      delete t;
    }
    cout << "--------Successfully implemented input_label(string)--------\n\n";
  }
  else if(c==8){ //input_subtasks(string) isComplete(string)
    task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
    t->display();
    t->input_subtasks("Finish UML");
    t->isComplete("task one");
    t->display();
    delete t;

    cout << "--------Successfully implemented the input_subtasks(string)--------\n\n";
  }
  else if(c==9){ //more cases for subtasks
    task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
    t->input_subtasks("Eat apple");
    t->input_subtasks("Eat bananas");
    t->input_subtasks("Eat fish");
    t->input_subtasks("Eat steak");
    t->input_subtasks("Eat grapes");
    t->input_subtasks("Eat peaches");
    t->display();
    delete t;

    cout << "--------Successfully implemented the input_subtasks(string)--------\n\n";
  }
    else if(c==10){ //more cases for subtasks
    task* t=new task("Task Name", "Notes for task", "01/01/2022", 11,59, "UCR Campus", "label-red", 0 );
    t->input_subtasks("");
    t->display();
    delete t;

    cout << "--------Successfully implemented the input_subtasks(string)--------\n\n";
  }
  
  return 0;
}