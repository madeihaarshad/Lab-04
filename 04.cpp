#include <iostream>
#include <list>
#include <string>

using namespace std;

class ToDoList {
private:
    string task;
    list<ToDoList> subtasks;
    bool completed;

public:
    ToDoList(const string &task) : task(task), completed(false) {}

    void addSubtask(const string &subtask) {
        subtasks.push_back(ToDoList(subtask));
    }

    void display(int depth = 0) const {
        string status = completed ? "[Completed]" : "[Pending]";
        cout << string(depth, '-') << " " << status << " " << task << endl;
        
        for (const auto &subtask : subtasks) {
            subtask.display(depth + 2);
        }
    }

    void markCompleted(bool status) {
        completed = status;
    }

    bool isCompleted() const {
        return completed;
    }

    list<ToDoList>& getSubtasks() {
        return subtasks;
    }

    string getTask() const {
        return task;
    }
};

int main() {
    cout << "Enter the name of the main task: ";
    string taskName;
    getline(cin, taskName);

    ToDoList todoMain(taskName);

    char choice;
    do {
        string subtaskName;
        cout << "Enter the name of the subtask: ";
        getline(cin, subtaskName);

        todoMain.addSubtask(subtaskName);

        cout << "Add another subtask? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y');

    cout << "\n\nYour To-Do List:" << endl;
    todoMain.display();
    char markChoice;
    cout << "Do you want to mark the main task as completed? (y/n): ";
    cin >> markChoice;
    cin.ignore(); 
    if (markChoice == 'y') {
        todoMain.markCompleted(true);
    }

    for (auto &subtask : todoMain.getSubtasks()) {
        cout << "Do you want to mark subtask '" << subtask.getTask() << "' as completed? (y/n): ";
        cin >> markChoice;
        cin.ignore(); 
        if (markChoice == 'y') {
            subtask.markCompleted(true);
        }
    }

    cout << "\n\nAfter marking tasks as completed or pending:" << endl;
    todoMain.display();

    return 0;
}

