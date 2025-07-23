 #include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Structure to store task information
struct Task {
    string description;
    bool isCompleted;
};

// Function to add a task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task: ";
    cin.ignore(); // Clear input buffer
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n\n";
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!\n\n";
        return;
    }
    
    cout << "\n--- TO-DO LIST ---\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";
        if (tasks[i].isCompleted) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
    cout << "------------------\n\n";
}

// Function to mark task as completed
void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    
    int taskNumber;
    cout << "Enter task number to mark complete: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n\n";
    } else {
        cout << "Invalid task number!\n\n";
    }
}

// Function to delete a task
void deleteTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully!\n\n";
    } else {
        cout << "Invalid task number!\n\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    
    cout << "SIMPLE TO-DO LIST MANAGER\n";
    
    while (true) {
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Goodbye!";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n\n";
                // Clear input buffer if invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
