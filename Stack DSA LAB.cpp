#include <iostream>
#include<string>
using namespace std;


string* stackArray = NULL;
int top = -1;
int bottom = -1;
int s;

void declareArray(int size)
{
    s = size;
    stackArray = new string[size];
}


void push(string val) {
    if (top >= s - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stackArray[top] = val;
    }
}
void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << stackArray[top] << endl;
        top--;
        bottom++;
    }
}


void ReverseStack()
{
        if (stackArray->empty())
        {
            return;
        }

        if (top >= 0) {
            if (sizeof(stackArray) == 0)
            {
                return;
            }
            
            cout << top<<endl;

            pop();


            cout << bottom<<endl;



            string x = stackArray[bottom];
            
            cout << x << endl;
            
           
            ReverseStack();



            push(x);
        }        
}
void display() {
    if (top >= 0) {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stackArray[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "Stack is empty";
    }
}
int main() {
    int ch;
    string val;

    cout << "\nEnter the size of stack you want: \n";
    int s;
    cin >> s;
    declareArray(s);
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Stack reverse" << endl;
    cout << "5) Exit" << endl;
    do {
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2: {
            pop();
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            ReverseStack();
            break;
        }
        case 5: {
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
            delete[] stackArray;
            stackArray = NULL;
        }
        }
    } while (ch != 5);
    delete[] stackArray;
    return 0;
}
