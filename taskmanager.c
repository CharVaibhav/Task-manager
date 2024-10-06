#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 9 
#define MAX_NOTES_LENGTH 200

struct Task {
    char name[MAX_TASK_NAME];
    int priority;
    char dueDate[12]; // Assuming DD/MM/YYYY format for simplicity
    char dueTime[MAX_TIME_LENGTH];
	char notes[MAX_NOTES_LENGTH];
	char addedTime[MAX_TIME_LENGTH];
     
};

struct Task taskList[MAX_TASKS];
int taskCount = 0;
char dueDate[MAX_DATE_LENGTH];

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task name: ");
        scanf(" %[^\n]", taskList[taskCount].name);
        printf("Enter task priority (1-10): ");
        scanf("%d", &taskList[taskCount].priority);
        printf("Enter due date (DD/MM/YYYY): ");
        scanf("%s", taskList[taskCount].dueDate);
        printf("Enter due time (HH:MM): ");
        scanf("%s", taskList[taskCount].dueTime);
        
    time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        strftime(taskList[taskCount].addedTime, sizeof(taskList[taskCount].addedTime), "%H:%M:%S", localTime);
        
        printf("Enter notes for the task: ");
        scanf(" %[^\n]", taskList[taskCount].notes);
        taskCount++;
        printf("Task added successfully.\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}



void displayTasks() {
    if (taskCount > 0) {
        printf("\nTask List:\n");
        printf("--------------------------------------------------\n");
        printf("| %-20s | %-10s | %-12s | %-20s |\n", "Task Name", "Priority", "Due Date", "Notes");
        printf("--------------------------------------------------\n");
        int i;
        for (i = 0; i < taskCount; i++) {
            printf("| %-20s | %-10d | %-12s | %-20s |\n", taskList[i].name, taskList[i].priority, taskList[i].dueDate, taskList[i].notes);
        }
        printf("--------------------------------------------------\n");
    } else {
        printf("Task list is empty.\n");
    }
}



void sortTasks(struct Task *tasks, int taskCount) {
    // Sorting logic remains the same
    int i, j;
    for (i = 0; i < taskCount - 1; i++) {
        for (j = 0; j < taskCount - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted by priority.\n");
    displayTasks(); // Removed unnecessary arguments
}


void searchTaskByName(const char *searchTerm) {
    int i, found = 0;
    printf("\nSearch Results:\n");
    printf("---------------------------------\n");
    for (i = 0; i < taskCount; i++) {
        if (strstr(taskList[i].name, searchTerm) != NULL) {
            printf("Task: %s (Priority: %d, Due Date: %s)\n", taskList[i].name, taskList[i].priority, taskList[i].dueDate);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks found matching '%s'.\n", searchTerm);
    }
    printf("---------------------------------\n");
}

void triggerAlarm() {
    int i;
    for (i = 0; i < 5; i++) { // Print the alert message 5 times to simulate an alarm
        printf("\a"); // Output a system bell (alert sound)
        printf("ALERT: Overdue task(s) detected!\n");
        printf("Please check your tasks.\n");
        // Add a delay to make the message noticeable
        // You can use a system-specific sleep function or a loop to create a delay
        // Example using a loop for delay (this might not be accurate):
        int j;
        for (j = 0; j < 10000000; j++) {
            // Adding delay using an empty loop
        }
    }
}

void checkReminders() {
    time_t now;
    struct tm *local;
    time(&now);
    local = localtime(&now);
    
    
    char currentDateTime[20]; // Store current date as DD/MM/YYYY string
    strftime(currentDateTime, 20, "%d/%m/%Y %H:%M", local);

    printf("\nREMINDERS:\n");
    printf("------------------------------\n");
    int i;
    int overdueCount = 0; // Counter to track overdue tasks
    for (i = 0; i < taskCount; i++) {
        char taskDateTime[20]; // Combine task's date and time as string
        snprintf(taskDateTime, sizeof(taskDateTime), "%s %s", taskList[i].dueDate, taskList[i].dueTime);
        
        printf("Task '%s' - Due time: %s\n", taskList[i].name, taskList[i].dueTime);

        // Compare current time with task's due time
        if (strcmp(taskDateTime, currentDateTime) < 0) {
            printf("Overdue: Task '%s'!\n", taskList[i].name);
            overdueCount++;
        }
    }
    printf("------------------------------\n");

    if (overdueCount > 0) {
        // Trigger alarm/notification for overdue tasks
        // Add your alarm/notification logic here
        printf("Alarm: Overdue tasks detected!\a");
        printf("\a");
        printf("\a");
        printf("\a");
        printf("\a");
        printf("\a");
        printf("\a");
        printf("\a");
    }
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
    
void editTaskName(int index) {
    printf("Enter new task name: ");
    scanf(" %[^\n]", taskList[index].name);
}

void editTaskPriority(int index) {
    printf("Enter new task priority (1-10): ");
    scanf("%d", &taskList[index].priority);
}
void editDueDate(int index) {
    printf("Enter new due date (DD/MM/YYYY): ");
    scanf("%s", taskList[index].dueDate);
}

void editDueTime(int index) {
    printf("Enter new due time (HH:MM): ");
    scanf("%s", taskList[index].dueTime);
}
void editNotes(int index) {
    printf("Enter new notes for the task: ");
    scanf(" %[^\n]", taskList[index].notes);
}

void editTask(int index) {
    if (index >= 0 && index < taskCount) {
        printf("Editing Task at Index %d\n", index);
        printf("1. Edit Task Name\n");
        printf("2. Edit Task Priority\n");
        printf("3. Edit due date (DD/MM/YYYY): \n");
        printf("4. Edit due time\n");
        printf("5. Edit notes for the task\n");
        printf("Enter your choice (1-4): ");
        
        int choice;
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                editTaskName(index);
                printf("Task name updated successfully.\n");
                break;
            case 2:
                editTaskPriority(index);
                printf("Task priority updated successfully.\n");
                break;
            case 3:
                editDueDate(index);
                printf("Due date updated successfully.\n");
                break;
            case 4:
                editDueTime(index);
                printf("Due time updated successfully.\n");
                break;
            case 5:
            	editNotes(index);
                printf("Notes updated successfully.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } else {
        printf("Invalid index for editing task.\n");
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < taskCount) {
        printf("Task at Index %d will be deleted:\n", index);
        printf("Task Name: %s\n", taskList[index].name);
        printf("Task Priority: %d\n", taskList[index].priority);
        printf("Due Date: %s\n", taskList[index].dueDate);
        printf("Due Time: %s\n", taskList[index].dueTime);
        printf("Notes: %s\n", taskList[index].notes);
        
        printf("Are you sure you want to delete this task? (1 - Yes, 0 - No): ");
        int choice;
        scanf("%d", &choice);
        clearBuffer();
        
        if (choice == 1) {
        	int i;
            for (i = index; i < taskCount - 1; i++) {
                taskList[i] = taskList[i + 1];
            }
            taskCount--;
            printf("Task deleted successfully.\n");
        } else {
            printf("Task deletion canceled.\n");
        }
    } else {
        printf("Invalid index for deleting task.\n");
    }
}


int main() {
    int choice;
    char searchTerm[MAX_TASK_NAME];

    do {
        printf("\nTask Manager Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Sort tasks\n");
        printf("4. Search Task\n");
        printf("5. Check Reminders\n");
        printf("6. Edit task\n");
        printf("7. Delete task\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                sortTasks(taskList, taskCount);
                break;
            case 4:
                printf("Enter the task name to search: ");
                scanf("%s", searchTerm);
                searchTaskByName(searchTerm);
                break;
            case 5:
                checkReminders();
                break;
            case 6:
                printf("Enter the index of the task to edit: ");
                int editIndex;
                scanf("%d", &editIndex);
                int result;
                if (result == 0) {
                    editTask(editIndex);
                }
                break;
            case 7:
    			printf("Enter the index of the task to delete: ");
    			int deleteIndex;
    			scanf("%d", &deleteIndex);
    			deleteTask(deleteIndex);
    			break;

            case 8:
                printf("Exiting task manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}
