#include "List_of_tasks.hpp"

void List_of_tasks::add_task()
{
  task* task_ = new task();
  list.push_back(task_);
}


void List_of_tasks::add_task(task* t) {list.push_back(t);}

void List_of_tasks::delete_task(const string& taskName)
{
  for(unsigned int i=0; i<list.size(); i++)
    {
      if(list.at(i)->name == taskName)
      {
        task* temp = list.at(i);
        list.at(i) = list.at(list.size()-1);
        list.pop_back();
        break; //delete only one task at a time
      }
    }
}

void List_of_tasks::markTaskComplete(task* task)
{
  task->complete = true;
}

void List_of_tasks::time_left(task* task)
{//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
  int years=0;  
  int month=0;
  int days=0; 
  int hours=0;
  int min=0;
  time_t now = time(0);
  tm *ltm = localtime(&now);
  cout << "Current hour: " << (-8+ltm->tm_hour) << endl;
  cout << "Current min: " << (ltm->tm_min) << endl;
  if(stoi((task->date).substr(6,4)) >= (1900+ ltm->tm_year))
  {
    years = stoi((task->date).substr(6,4)) - (1900+ ltm->tm_year);
    if(stoi((task->date).substr(0,2)) >= (1+ltm->tm_mon))
    {
      month = stoi((task->date).substr(0,2)) - (1+ltm->tm_mon);
      if(stoi((task->date).substr(3,2)) >= ltm->tm_mday)
      {
        days = stoi((task->date).substr(3,2)) - ltm->tm_mday;
        if(task->hours >= ltm->tm_hour)
        {
          hours = task->hours - (-8+ltm->tm_hour);
          if(task->minutes >= ltm->tm_min)
          {
            min = task->minutes - (ltm->tm_min);
            cout << "Time left: \n";
            cout << years << " years, " << month << " months, " << days << " days, " << hours << " hours,and " << min << "minutes.\n";
          }
          else
          {
            cout << "Task overdue\n";
          }
        }
        else
        {
          cout << "Task overdue\n";
        }
      }
      else
      {
        cout << "Task overdue\n";
      }
    }
    else
    {
      cout << "Task overdue\n";
    }
  }
  else
  {
    cout << "Task overdue\n";
  }
}


void List_of_tasks::sort_by_time()
{
  string currSorted="";
  int curr= 0;
  
  
  for(unsigned int i=0; i<list.size(); i++)//sorting year
    {
      currSorted = list.at(i)->date.substr(6,4);
      for(unsigned int j=0; j<list.size()-1; j++)
        {
          string currTask = list.at(j)->date.substr(6,4);
          if(currSorted > currTask)
          {
            task* temp = list.at(i); string str_temp = currSorted;
            list.at(i) = list.at(j); currSorted = currTask;
            list.at(j) = temp; currTask = str_temp;
          }
        }
    }
  
  for(unsigned int i=0; i<list.size(); i++)//sorting month
    {
      currSorted = list.at(i)->date.substr(3,2);
      for(unsigned int j=0; j<list.size()-1; j++)
        {
          string currTask = list.at(j)->date.substr(3,2);
          if(currSorted > currTask)
          {
            task* temp = list.at(i); string str_temp = currSorted;
            list.at(i) = list.at(j); currSorted = currTask;
            list.at(j) = temp; currTask = str_temp;
          }
        }
    }
  
  for(unsigned int i=0; i<list.size(); i++)//sorting dates
    {
      currSorted = list.at(i)->date.substr(0,2);
      for(unsigned int j=0; j<list.size()-1; j++)
        {
          string currTask = list.at(j)->date.substr(0,2);
          if(currSorted > currTask)
          {
            task* temp = list.at(i); string str_temp = currSorted;
            list.at(i) = list.at(j); currSorted = currTask;
            list.at(j) = temp; currTask = str_temp;
          }
        }
    }
  
  
  for(unsigned int i=0; i<list.size(); i++)//sorting hours
    {
      curr = list.at(i)->hours;
      for(unsigned int j=0; j<list.size()-1; j++)
        {
          int currTask = list.at(j)->hours;
          if(curr > currTask)
          {
            int l_temp=0;
            task* temp = list.at(i); l_temp = curr;
            list.at(i) = list.at(j); curr = currTask;
            list.at(j) = temp; currTask = l_temp;
          }
        }
    }
  
  
  for(unsigned int i=0; i<list.size(); i++)//sorting min
    {
      curr = list.at(i)->minutes;
      for(unsigned int j=0; j<list.size()-1; j++)
        {
          int currTask = list.at(j)->minutes;
          if(curr > currTask)
          {
            int l_temp=0;
            task* temp = list.at(i); l_temp = curr;
            list.at(i) = list.at(j); curr = currTask;
            list.at(j) = temp; currTask = l_temp;
          }
        }
    }
}

void List_of_tasks::sort_by_priority()
{
  int curr=0;
  for(unsigned int i=0; i<list.size(); i++)
    {
     curr = list.at(i)->priority;
      for(unsigned int j=0; j<list.size()-1; j++)
      {
        int currTask = list.at(j)->priority;
        if(curr > currTask)
        {
              task* temp = list.at(i); 
              list.at(i) = list.at(j); 
              list.at(j) = temp; 
        }
      }
  }
}

void List_of_tasks::output_all()
{
  for(unsigned i=0; i<list.size();i++)
    {
      list.at(i)->display();
    }
}

void List_of_tasks::output_highestPriority()
{
  int highestPriorityIndex =0;
  for(unsigned i=0; i<list.size();i++)
    {
      if(list.at(i)->priority > list.at(highestPriorityIndex)->priority)
      {
        highestPriorityIndex = i;
      }
    }
  cout << "Task with highest Prioirity (" << list.at(highestPriorityIndex)->priority << ")\n";
  list.at(highestPriorityIndex)->display();
}

void List_of_tasks::output_userTask(const string& taskName)
{
  for(unsigned i=0; i<list.size(); i++)
    {
      if(list.at(i)->name == taskName)
      {
        list.at(i)->display();
        break;
      }
    }
}

void List_of_tasks::display_by_label(const string& labelName)
{
  for(unsigned int i=0; i<list.size();i++)
    {
      if(list.at(i)->label == labelName)
      {
        list.at(i)->display();
      }
    }
}