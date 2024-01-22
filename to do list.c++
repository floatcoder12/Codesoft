//make a to-do-list:
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> toDoList;

void addTask() {
    string description;
    cout << "Enter task description: ";
    getline(cin, description);
    toDoList.push_back({description, false}); 
    
}

void viewTasks() {
    cout << "To-Do List:\n";
    for (int i = 0; i < toDoList.size(); i++) {
        cout << i + 1 << ". " << toDoList[i].description;
        if (toDoList[i].completed) {
            cout << " (Completed)\n";
        } else {
            cout << " (Pending)\n";
        }
    }
}

void markTaskAsCompleted() {
    int taskIndex;
    cout << "Enter task number to mark as completed: ";
    cin >> taskIndex;
    cin.ignore(); 

    if (taskIndex > 0 && taskIndex <= toDoList.size()) {
        toDoList[taskIndex - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void removeTask() {
    int taskIndex;
    cout << "Enter task number to remove: ";
    cin >> taskIndex;
    cin.ignore(); 

    if (taskIndex > 0 && taskIndex <= toDoList.size()) {
        toDoList.erase(toDoList.begin() + taskIndex - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List:\n";
        cout << "\nRise and grind! Today's victories are built on small, determined steps.\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask();
                cout <<" Task added successfully!\n";
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                cout << "Applause!! you completed one new task\n";
                break;
            case 4:
                removeTask();
                cout <<"Task removed...\n";
                break;
            case 5:
                cout<<"Exiting...\n";
                cout<<"Finished tasks, but the journey continues. What excites you tomorrow?\n";
                break;

            default:
            cout<<"Invalid choice!\n";
        }
    } while(choice!=5);
    
    return 0;
}          