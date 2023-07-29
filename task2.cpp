      // ***SIMPLE CALCULATOR***
/* Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform */

#include <iostream>
using namespace std;
  
int main() {
    char op;
    float num1, num2;
      
    cout << "Enter two numbers:\n";
    cin >> num1 >> num2;

    cout << "Enter an arithmetic operator(+ - * /) to perform the operation\n";
    cin >> op;
  
    switch(op) {
        case '+': 
                cout << "The addition of num1 and num2 is:\n" << num1+num2;
                break;
        case '-':
                cout << "The subtraction of num1 and num2 is:\n"  << num1+num2;
                break;
        case '*':
                cout << "The multiplication of num1 and num2 is:\n"  << num1*num2;
                break;
        case '/':
                cout << "The division of num1 and num2 is:\n"  << num1/num2;
                break;
        default: 
                printf("not supported this operator\n");
    }
      
    return 0;
}