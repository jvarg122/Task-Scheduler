## Task Scheduler
 
 > Authors: [Aakash Nellutla](https://github.com/aakashn14), [Harsh Vardhan Shama](https://github.com/harshvardhan-sharma1), [Hin Kit Eric Wong](https://github.com/erichkw528), [Josue Vargas](https://github.com/jvarg122), [Yuantong Yang](https://github.com/yyang18)
  

## Project Description:
As working individuals, it is important to manage your time effectively. A task scheduler would efficiently solve the problem, allowing one to set tasks, timers, and reminders as and how desired.


Technologies used: 
> C++ (https://cplusplus.com) - An OOP language used globally. 
> Git (https://git-scm.com/) -  Git allows users to track code changes and manage their project using simple commands
> GitHub(https://github.com/) -  A code hosting platform for version control and collaboration


Input from user: Due date, time, location, priority, label/tag, name of task, and a small note. (everything but name can be optional)*

Output to user: List of tasks at hand, reminders of tasks due at current time.

Features: scheduling tasks, adding tasks, editing tasks, task deletion, add subtasks, reminders for task due

 > ## Phase II

## Class Diagram
 <h3>UML Diagram:</h3> 
 <img src= "https://i.imgur.com/EmTjZRd.png">
 <h3>UML Diagram Description</h3>
 
<b>Task Class</b>: This class contains all the variables needed to run the program and its features.<br><br>
<b>List_of_Tasks Class</b>: This class contains the “vector<Task*>list” which is a vector of Task pointers pointing to each of the task-objects. Additionally, there are public functions which allow the user to modify their tasks, reminders, etc. There are also two private helper functions which help the public function, sort_task(), to first sort by time, then by priority.<br><br>
<b>Interface Class</b>: This class interacts with the user. It can prompt the user for input and display the tasks.<br><br>
<b>Input class</b>: This class contains the user input required for tasks to be added to the scheduler. The input class stores name, date, notes, time, location, subtasks, priority of tasks, notification preferences, and label(s). The gist of our Task Scheduler is built in this class.<br><br>
<b>Output class</b>: This class contains all the outputs by priority in addition to the option to select and display particular details.<br><br>
 
 > ## Phase III
 <h3>Design Pattern:</h3> 

The design pattern we are implementing into our Task scheduling software is the Composite pattern.

Using the composite design pattern allows us to define a clear hierarchy of tasks, subtasks and their subcategories. Additionally, we have the flexibility to add components to our classes. Also, it allows us, as a group, to divide development workload within ourselves efficiently.  

In our Task scheduling software, we wish to represent both tasks (simple) and subtasks(complexities) uniformly.The client treats the primitives and composites the same, as we want our user to treat tasks and subtasks as the same. Additionally, it allows us to expand on our already existing code, to add features as and when requested by the user/client. Hence, using the composite design pattern makes code handling much more efficient. 

The following are the structure implemented in our software:

Leaf class → Task

Composite class → List_of_Tasks

Component class → interface

 > ## Final deliverable
 
 ## Screenshots
 
 * 1. You will be greeted by the following screen:
 <img src= "https://i.imgur.com/iUG2yK6.png">
 
 * 2. Next is the first option, Add task:
 <img src= "https://i.imgur.com/U4ZAJ3G.png">
 
 * 3. Next will be option 2, Edit Task:
 <img src= "https://i.imgur.com/6PwXUN0.png">
 
 * 4. Then comes the Edit Task Menu:
 <img src= "https://i.imgur.com/cJyOdqV.png">
 
 * 5. Here we use unique features like change priority and delete subtask:
 <img src= "https://i.imgur.com/J27OtFN.png">
 
 * 6. This is the quit option which leads you back to the main menu:
 <img src= "https://i.imgur.com/LqrIMPY.png">
 
 * 7. This is the output tasks option, which leads you to the display options menu:
 <img src= "https://i.imgur.com/FjLqdSy.png">
 
 * 8. Here are options 1, 4, and 5 in action:
 <img src= "https://i.imgur.com/XiPFnBX.png">
 
 * 9. Here we add a task again (after quitting display options menu), then sort by priority:
 <img src= "https://i.imgur.com/nb0ypWZ.png">
 
 * 10. Display by priority:
 <img src= "https://i.imgur.com/0xTeaYl.png">
 
 * 11. And lastly here is the option to remove a task in action:
 <img src= "https://i.imgur.com/uKfHinO.png">
 
 ## Installation/Usage
 
 To begin to use the task scheduler, the user must first recursively clone the following repository:
 
`https://github.com/cs100/final-project-anell002-hwong051-jvarg122-hshar021-yyang437.git`
 
 After this is cloned, one must enter the directory and the following command must be run first to compile our application:
 
 `g++ -std=c++11 task.cpp List_of_tasks.cpp interface.cpp main.cpp -o output`
 
 Next run this command:
 
 `./output`
 
 ## Testing
 For our task scheduler:
 * We tested our constructors and code for Interface Class, List_of_tasks class, and Tasks Class
 * We tested functions such as edit_tasks() which allow users to manipulate their tasks
 * We created unit tests for our patterns and classes, ran it in valgrind to check for memory leaks, and fixed the bugs that were found
 
