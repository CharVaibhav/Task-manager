# Task-manager
This is a simple command-line-based Task Manager program written in C. It allows users to add, edit, display, sort, and delete tasks. It also provides functionality to set task reminders and trigger alarms for overdue tasks.

Features
Add Task: Add a new task with details such as task name, priority, due date, due time, and notes.
Display Tasks: View all added tasks in a formatted list.
Sort Tasks: Sort tasks by priority (highest to lowest).
Search Task: Search for tasks by name.
Reminders: Check if any tasks are overdue and trigger an alarm for overdue tasks.
Edit Task: Modify task details like name, priority, due date, due time, and notes.
Delete Task: Remove a task from the task list.
Program Structure
struct Task: Structure used to store task details, including name, priority, due date, due time, notes, and the time the task was added.
Global Variables:
taskList: Stores an array of tasks.
taskCount: Tracks the number of tasks added.
Usage
Menu Options
Once the program starts, you will be presented with the following menu options:

Add Task: Prompts you to enter task details and stores the task in the task list.
Display Tasks: Shows all tasks with their respective details (name, priority, due date, notes).
Sort Tasks: Sorts the tasks in descending order of priority and displays them.
Search Task: Enter a task name to search for and display matching tasks.
Check Reminders: Compares the current time with task due dates and times to check for overdue tasks.
Edit Task: Allows you to select and modify task details.
Delete Task: Removes a task from the task list based on the provided index.
Exit: Exits the program.
Adding a Task
To add a task, you will be prompted to provide:

Task name: Description of the task.
Priority: A value from 1-10 where 10 is the highest priority.
Due date: The deadline in DD/MM/YYYY format.
Due time: The specific time in HH
format.
Notes: Any additional details regarding the task.
Editing a Task
To edit a task, select the option from the menu and provide the index of the task you want to edit. You can choose to modify the task name, priority, due date, due time, or notes.

Deleting a Task
To delete a task, provide the index of the task to be removed from the list.

Checking Reminders
This feature compares the current system date and time with the due dates of all tasks. If any tasks are overdue, an alarm sound will be triggered, and the overdue tasks will be displayed.

Limitations
The maximum number of tasks is set to 100.
Task names are limited to 50 characters, due dates to 12 characters (DD/MM/YYYY), and notes to 200 characters.
The program uses a simple priority-based sorting method.
Compilation and Execution
To compile and run the program:

Open a terminal or command prompt.
Navigate to the directory containing the source code.
Compile the program using a C compiler (e.g., gcc):
Copy code
gcc task_manager.c -o task_manager
Run the compiled program:
bash
Copy code
./task_manager
Future Enhancements
Implement task categorization (e.g., work, personal, urgent).
Add task completion status tracking.
Integrate persistent storage (save/load tasks from a file).
License
This project is open-source and free to use.


