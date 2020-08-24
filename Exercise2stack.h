#ifndef EXERCISE2_H
#define EXERCISE2_H
#include <exception>
template<class T>
class MyStack{
    class StackNode{
    public:
        T data;
        StackNode * last=nullptr;
        public:
        StackNode (T data){
            this->data=data;
        }
        ~StackNode(){
            last=nullptr;
        }
    };

    StackNode * top=nullptr;

public:

    T pop(){
        if (top==nullptr) throw "Empty Stack Exception!";
        T item=top->data;
        top=top->last;
        return item;
    }

    void push(T item){
        StackNode * t =new StackNode(item);
        t->last=top;
        top=t;
    }

    T peek(){
        if (top==nullptr) throw std::exception();
        return top->data;
    }
    bool isEmpty(){
        return top==nullptr;
    }

};

#endif // EXERCISE2_H
