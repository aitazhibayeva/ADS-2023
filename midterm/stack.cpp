#include<iostream>

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

using namespace std;

class Stack {
private:
    int item, i;
    int arr_stack[MAX_SIZE];
    int top;

public:

    Stack() {
        top = 0;

    }

    void push() {
        if (top == MAX_SIZE)
            cout << "\n## Stack is Full!";
        else {
            cout << "\nEnter The Value to be pushed : ";
            cin>>item;
            cout << "\n## Position : " << top << ", Pushed Value  :" << item;
            arr_stack[top++] = item;
        }
    }

    void pop() {
        if (top == 0)
            cout << "\n## Stack is Empty!";
        else {
            --top;
            cout << "\n## Position : " << top << ", Popped Value  :" << arr_stack[top];
        }
    }

    void display() {
        cout << "\n## Stack Size : " << top;
        for (i = (top - 1); i >= 0; i--)
            cout << "\n## Position : " << i << ", Value  :" << arr_stack[i];
    }
};

int main() {
    int choice, exit_p = 1;
    Stack obj;
    cout << "\nSimple Stack Example - Class and Member Functions - C++";
    do {
        cout << "\n\nStack Main Menu";

        cout << "\n1.Push \n2.Pop \n3.Display \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                obj.push();
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.display();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}