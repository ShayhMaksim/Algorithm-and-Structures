#ifndef EXERCISE2QUEUUE_H
#define EXERCISE2QUEUUE_H
#include <exception>
template<class T>
class MyQueue{
    class QueueNode{
    public:
        T data;
        QueueNode * next=nullptr;
        public:
        QueueNode (T data){
            this->data=data;
        }
        ~QueueNode(){
            next=nullptr;
        }
    };
public:
    QueueNode * first=nullptr;
    QueueNode *last=nullptr;
    void add(T item){
        QueueNode * t=new QueueNode(item);
        if (last!=nullptr)
        {
            last->next=t;
        }
        last=t;
        if (first==nullptr){
            first=last;
        }
    }
    T remove()
    {
        //if (first==nullptr) return;
        T data=first->data;
        first=first->next;
        if (first==nullptr){
            last=nullptr;
        }
        return data;
    }
    T peek()
    {
        if (first==nullptr) throw std::exception();
        return first->data;
    }
    bool isEmpty()
    {
         return first==nullptr;
    }
};

#endif // EXERCISE2QUEUUE_H
