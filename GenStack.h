#ifndef GEN_STACK_H
#define GEN_STACK_H

#include <iostream>

using namespace std;

template <typename T>
class GenStack
{
    public:
        GenStack();
        GenStack(int maxSize);
        ~GenStack();

        void push(T x);
        T pop();
        T peak();

        bool isFull();
        bool isEmpty();

    private:
        int size;
        int top;
        T *myArray;


};

template <typename T>
GenStack<T>::GenStack()
{
    myArray = new T[128];
    size = 128;
    top = -1;
}

template <typename T>
GenStack<T>::GenStack(int maxSize)
{
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

template <typename T>
GenStack<T>::~GenStack()
{
    delete []myArray;
}

template <typename T>
void GenStack<T>::push(T x)
{
    if(top < (size-1))
        myArray[++top] = x;

    else //create a new stack of greater size and adds to it
    {
        GenStack<T>* revtemp = new GenStack<T>(this->size);
        revtemp->push(this->pop());//reveses the Stack
        GenStack<T>* final = new GenStack<T>(this->size + 10); //makes a stack 10 larger
        final->push(revtemp->pop());//adds rev to final stack
        myArray = final->myArray;
    }

}

template <typename T>
T GenStack<T>::pop()
{
    if (this->isEmpty())
        throw string("Stack is empty");

    return myArray[top--];

}

template <typename T>
T GenStack<T>::peak()
{
    if (this->isEmpty())
        throw string("Stack is empty");

    return myArray[top];
}

template <typename T>
bool GenStack<T>::isFull()
{
    return(top == size-1);
}

template <typename T>
bool GenStack<T>::isEmpty()
{
    return(top == -1);
}

#endif
