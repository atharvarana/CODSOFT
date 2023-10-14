//CodeSoft Internship Task-4

// Intern name: Atharva Rana
// Batch: A4

// TO-DO LIST:Build a simple console-based to-do list manager that allows users to add, view, and delete tasks

// Task Input: Allow users to input tasks they want to add to the list.
// Add Task: Implement a function to add tasks to the list.
// View Tasks: Display the list of tasks with their status (completed or pending).
// Mark Task as Completed: Allow users to mark tasks as completed.
// Remove Task: Provide an option to remove tasks from the list.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int ID;

struct todo {
    int id;
    string task;
    bool completed;
};

void addtodo(vector<todo>& todos) {
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl
         << endl
         << endl
         << endl;
    todo newTodo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, newTodo.task);
    newTodo.completed = false; // By default, the task is not completed
    ID++;

    newTodo.id = ID;

    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << newTodo.id;
    write << "\n" << newTodo.task;
    write << "\n" << newTodo.completed;
    write.close();

    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "\n\tDo you want to add more tasks? (y/n): ";
    cin >> ch;

    if (ch == 'y') {
        addtodo(todos);
    } else {
        todos.push_back(newTodo); // Add the new task to the vector
        cout << "\n\tTask has been added successfully";
        return;
    }
}

void print(const todo& s) {
    cout << "\n\tID is: " << s.id;
    cout << "\n\tTask is: " << s.task;
    if (s.completed) {
        cout << "\n\tStatus: Completed";
    } else {
        cout << "\n\tStatus: Incomplete";
    }
}

void readData(const vector<todo>& todos) {
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl
         << endl
         << endl
         << endl;

    cout << "\n\t------------------Your current Incomplete Tasks in the list--------------------";

    for (const todo& task : todos) {
        if (!task.completed) {
            print(task);
        }
    }
}

int searchData(const vector<todo>& todos) {
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl
         << endl
         << endl
         << endl;

    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;

    for (const todo& task : todos) {
        if (task.id == id) {
            print(task);
            return id;
        }
    }

    cout << "\n\tTask not found.";
    return -1;
}

void updateData(vector<todo>& todos) {
    system("cls");
    cout << "\t*******************************************************************" << endl;
    cout << "\t*                      To Do List Application                     *" << endl;
    cout << "\t*******************************************************************" << endl
         << endl
         << endl
         << endl;

    int id = searchData(todos);
    cout << "\n\n\tYou want to update this task (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tEnter todo task: ";
        cin.get();
        getline(cin, newData.task);

        for (todo& task : todos) {
            if (task.id == id) {
                // Update the task
                task.task = newData.task;
                cout << "\n\tTask updated successfully.";
                return;
            }
        }
    } else {
        cout << "\n\tRecord not updated.";
    }
}

// Function to mark a task as complete
void markAsComplete(vector<todo>& todos, int id) {
    for (todo& task : todos) {
        if (task.id == id) {
            task.completed = true;
            cout << "\n\tTask marked as complete.";
            return;
        }
    }
    cout << "\n\tTask not found.";
}

int main() {
    vector<todo> todos;

    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    } else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << endl;
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Display Task";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Update Task";
        cout << "\n\t5. Mark Task as Complete";

        int choice;
        cout << "\n\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                addtodo(todos);
                break;
            case 2:
                readData(todos);
                break;
            case 3:
                searchData(todos);
                break;
            case 4:
                updateData(todos);
                break;
            case 5:
                int taskId;
                cout << "\n\tEnter the ID of the task to mark as complete: ";
                cin >> taskId;
                markAsComplete(todos, taskId);
                break;
        }
    }

    return 0;
}
