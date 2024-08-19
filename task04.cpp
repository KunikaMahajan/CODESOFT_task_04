#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks; // Vector to store tasks
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the task name: ";
    getline(cin, newTask.name);
    newTask.completed = false; // New tasks are initially pending
    tasks.push_back(newTask);
    cout << "Task added: \"" << newTask.name << "\"" << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "\nTasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].name << " - ";
            if (tasks[i].completed) {
                cout << "Completed" << endl;
            } else {
                cout << "Pending" << endl;
            }
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed: \"" << tasks[taskNumber - 1].name << "\"" << endl;
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
    } else {
        cout << "Task deleted: \"" << tasks[taskNumber - 1].name << "\"" << endl;
        tasks.erase(tasks.begin() + (taskNumber - 1)); // Remove the task
    }
}
