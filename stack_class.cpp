// Potenza, Matthew
// cs 540 section 13481/13468
// implementation of stack as class (using singly linked list) in C++


#include<iostream>
using namespace std;

class Stack {
private: 
    static int size;
    struct node {
        int info;
        node *link;
    };
    node *top;
public:
    Stack();
    void s_push(int data);
    int s_pop();
    int s_peek();
    static int s_size();
    void s_print();
    void s_clear();
};

int Stack::size = 0;

int main(void)
{
    class Stack s1;        
    
    cout << "Stack size: " << s1.s_size() << endl;
    
    for (int i = 0; i < 10; i++)
        s1.s_push(i);
                 
    cout << "Stack size: " << s1.s_size() << endl;   
    s1.s_print();
    
    cout << "Popped from stack: ";
    for (int i = 0; i < 5; i++)
        cout << s1.s_pop() << " ";
    cout << endl;
    
    cout << "Stack size: " << s1.s_size() << endl;    
    cout << "Data in top element: " << s1.s_peek() << endl;
    s1.s_print();
    
    s1.s_clear();
    cout << "cleared stack." << endl;
    
    s1.s_print();    
    cout << "Stack size: " << s1.s_size() << endl;

    // system("pause");
    return 0;
}

Stack::Stack()
{
    top = NULL;
}

void Stack::s_push(int data)
{
    node *np = new node;
    np->info = data;
    np->link = top;
    top = np; 
    size++;      
}

int Stack::s_peek()
{
    return top->info;
}

int Stack::s_size()
{
    return size;
}

int Stack::s_pop()
{
    if (top != NULL) {
        int popped = top->info;
        node *np = top;
        top = top->link;
        delete np;
        size--;
        return popped;
    }
    else {
        cout << endl << "Stack is empty, returning ";
        return 0;
    }
}

void Stack::s_print()
{
    node *np = top;
    cout << "Stack contents: ";
    while (np != NULL) {
        cout << np->info << " ";
        np = np->link;
    }
    cout << endl;
}

void Stack::s_clear()
{
    while (top != NULL) {
        node *np = top;
        top = top->link;
        delete np;
    } 
    size = 0;   
}



