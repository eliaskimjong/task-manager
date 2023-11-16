#include <iostream>
#include <ctime>   
#include <fstream>
#include <string>
using namespace std;

class manager {
private:
    string title; // All these are user inputs that will be saved in a txt file
    string task = "no task";
    int priority;
    int due;
    string due_date;
    string status = "none";
    string prio = "none";
    string input;
public:
    void sche_UI() { //The task manager big title
        cout << "-----------------------------------------\n";
        cout << "      Simple Task Manager Application     \n";
        cout << "-----------------------------------------\n";
    }
    void tasks() { //this is for printing out the text within the file
        ifstream myfile("dataa.txt"); // Open the file for reading

        if (!myfile.is_open()) { //if file cant open then we get this message
            cerr << "Unable to open dataa.txt for reading.\n";
            return;
        }

        while (getline(myfile, task)) {
            cout << task << endl; // Print the task title

            if (getline(myfile, prio)) {
                cout << prio << endl; // Print priority
            }

            if (getline(myfile, status)) {
                cout << status << endl; // Print status
            }
            cout << "-------------------------" << endl;
        }

        myfile.close();
    }
    void add_task() { //this adds task 
        ofstream file("dataa.txt", ios::app); // Open file in append mode

        if (file.is_open()) {
            cin.ignore(); // Clear the newline character left in the buffer

            // Input task title
            cout << "Enter task title: ";
            getline(cin, task);
            file << "Task Title: " << task << "\n";

            // Input priority
            cout << "What is the priority? (low, medium, high): ";
            getline(cin, prio);
            file << "Priority: " << prio << "\n";

            // Input status
            cout << "What is the status? (not working on it, working on it, done): ";
            getline(cin, status);
            file << "Status: " << status << "\n";

            // Input due date
            cout << "In how many days is it due? ";
            cin >> due;
            file << "Due In: " << due << " days\n";

            file << "-------------------------\n";
            file.close();
        }
        else {
            cerr << "Unable to open dataa.txt for writing.\n";
        }
    }
    void printSomething() { //this will be printed out in scheduele
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Year: " << 1900 + ltm.tm_year << endl;
        cout << "Month: " << 1 + ltm.tm_mon << endl;
        cout << "Day: " << ltm.tm_mday << endl;
        cout << "Time: " << 5 + ltm.tm_hour << ":" << 30 + ltm.tm_min << ":" << ltm.tm_sec << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    void data() { //this saves the title we get from user input
        cout << "Enter your schedule Title: ";
        getline(cin, title);
        ofstream myfile;//this is for getting input
        myfile.open("dataa.txt");
        if (myfile.is_open()) {
            myfile << title << "\n";
            myfile.close();
            cout << "Text written to dataa.txt successfully.\n";
        }
        else {
            cerr << "Unable to open dataa.txt for writing.\n";
        }
    }
};

int main() {
    manager Manager;
    Manager.printSomething();
    string input, input1, input2;
    bool task;
    cout << "Welcome to the Task Manager!\n";
    cout << "This simple program helps you manage your tasks efficiently.\n";
    cout << "You can add tasks, mark them as done, and more.\n";
    cout << "Let's get started!\n";
    cout << "would you like to reload last scheduele or start a new one?(reload or new): ";
    cin >> input;
    if (input == "new" || input == "New") {
        cin.ignore(); // consume the newline character left in the input buffer
        Manager.data(); //this writes down input in a txt document
        system("CLS");//this clears the console
        Manager.sche_UI();//Titel of task manager
        Manager.printSomething();//Time and date
        Manager.tasks();//asks if you want to add task
    }
    if (input == "reload" || input == "Reload") {
        cin.ignore();
        system("CLS");
        //Manager.readInput();
        Manager.sche_UI();
        Manager.printSomething();
        Manager.tasks();
    }
    cout << "would you like to add task?(yes or no): ";
    cin >> input1;
    if (input1 == "yes" || input1 == "Yes") {
        Manager.add_task();
        system("CLS");
        Manager.sche_UI();
        Manager.printSomething();
        Manager.tasks();
    }
    return 0;
}