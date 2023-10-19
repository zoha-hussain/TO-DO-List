#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100; 

class ToDoList {
private:
    string tasks[MAX_TASKS];
    int taskCount;

public:
    ToDoList() : taskCount(0) {}

    void addTask(const string& description) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount] = description;
            ++taskCount;
            cout << "Task \"" << description << "\" ADDED." << endl;
        }
        else {
            cout << "Cannot add more tasks. Task list is full." << endl;
        }
    }

    void viewTasks() const {
        if (taskCount == 0) {
            cout << "No tasks found." << endl;
        }
        else {
            cout << "Tasks:\n";
            for (int i = 0; i < taskCount; ++i) {
                cout << "- " << tasks[i] << endl;
            }
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= taskCount) {
            cout << "Task \"" << tasks[index - 1] << "\" REMOVED." << endl;
            for (int i = index - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            --taskCount;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    int taskIndex;

    do {
        cout << "\n***** TO-DO LIST MANAGER *****\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore();
            cout << "Enter task description: ";
            getline(cin, taskDescription);
            todoList.addTask(taskDescription);
            break;
        case 2:
            todoList.viewTasks();
            break;
        case 3:
            cout << "Enter task number to remove: ";
            cin >> taskIndex;
            todoList.removeTask(taskIndex);
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
