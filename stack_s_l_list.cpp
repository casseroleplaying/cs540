/* Potenza, Matthew
 * cs 540 section 13481/13468
 * implementation of stack using singly linked list in c++
 */

#include<iostream>
using namespace std;

struct node {
    int info;
    node *link;
};

void s_push(int data, node *&top);
int s_pop(node *&top);
void s_print(node *top);

int main(void)
{
    node *top = NULL;
    
    for (int i = 0; i < 10; i++)
        s_push(i, top);
              
    s_print(top);
    
    cout << "Popped from stack: ";
    for (int i = 0; i < 12; i++)
        cout << s_pop(top) << " ";
    cout << endl;

    s_print(top);

    system("pause");
    return 0;
}

void s_push(int data, node *&top)
{
    node *np = new node;
    np->info = data;
    np->link = top;
    top = np;       
}

int s_pop(node *&top)
{
    if (top != NULL) {
        int popped = top->info;
        node *np = top;
        top = top->link;
        np->link = NULL;
        delete np;
        return popped;
    }
    else {
        cout << endl << "Stack is empty, returning ";
        return 0;
    }
}

void s_print(node *top)
{
    node *np = top;
    cout << "Stack contents: ";
    while (np != NULL) {
        cout << np->info << " ";
        np = np->link;
    }
    cout << endl;
}
