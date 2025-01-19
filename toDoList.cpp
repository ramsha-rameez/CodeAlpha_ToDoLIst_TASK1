#include <iostream>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

int main() {
    Task* tasks = nullptr;  // Pointer to dynamically allocate tasks
    int taskCount = 0;      // Number of current tasks
    int capacity = 0;       // Current capacity of the task list
    int choice;

    do {
        cout << "\n--- To-Do List ---\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == 1) {
            // Expand capacity if needed
            if (taskCount == capacity) {
                capacity = (capacity == 0) ? 1 : capacity * 2;
                Task* newTasks = new Task[capacity];
                for (int i = 0; i < taskCount; ++i) {
                    newTasks[i] = tasks[i];
                }
                delete[] tasks;
                tasks = newTasks;
            }

            // Add the new task
            cout << "Enter task description: ";
            getline(cin, tasks[taskCount].description);
            tasks[taskCount].completed = false;
            taskCount++;
            cout << "Task added.\n";
        } else if (choice == 2) {
            cout << "Enter task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;
            if (taskNumber > 0 && taskNumber <= taskCount) {
                tasks[taskNumber - 1].completed = true;
                cout << "Task marked as completed.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        } else if (choice == 3) {
            if (taskCount == 0) {
                cout << "No tasks available.\n";
            } else {
                cout << "\nTasks:\n";
                for (int i = 0; i < taskCount; ++i) {
                    cout << i + 1 << ". " << tasks[i].description
                         << (tasks[i].completed ? " [Completed]" : " [Pending]") << "\n";
                }
            }
        } else if (choice != 4) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    cout << "Goodbye!\n";

    // Free the dynamically allocated memory
    delete[] tasks;

    return 0;
}
