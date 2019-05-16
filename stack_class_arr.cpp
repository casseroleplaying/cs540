/* Potenza, Matthew
 * cs 540 section 13481/13468
 * implementation of stack as class (using array) in c++
 */

#include <iostream>
using namespace std;

# define MAX 10

class Stack {
private:  
    int top = -1;
public:
    int stack_arr[MAX];
    void s_push(int data);
    int s_pop();
    int s_peek(); 
    void s_print();
};

int main(void)
{
    class Stack s1;        
    for (int i = 0; i < MAX; i++)
        s1.s_push(i);
   
    s1.s_print();

    cout << "Top of stack: " << s1.s_peek() << endl;
    
    cout << "Popped from stack: ";
    for (int i = 0; i < MAX; i++)
        cout << s1.s_pop() << " ";
    cout << endl;

    s1.s_print();

    system("pause");
    return 0;
}

void Stack::s_push(int data)
{       
    if (top >= MAX - 1)
        cout << "Stack full." << endl;
    else {
        top++;
        stack_arr[top] = data; 
    }      
}

int Stack::s_pop()
{
    if (top >= 0) {
        int popped = stack_arr[top];
        top--;
        return popped;
    }
    else {
        cout << "Stack empty, returning ";
        return 0;
    }
}

int Stack::s_peek()
{
    return stack_arr[top];
}

void Stack::s_print()
{
    int pos = top;
    cout << endl << "Stack contents: ";
    while (pos >= 0) {
        cout << stack_arr[pos] << " ";
        pos--;
    }
    cout << endl;
}
