#ifndef LIST_TF_H
#define LIST_TF_H
#include <cstdlib>

class Node;

class List{
    size_t size;
    Node *Head;
    Node *Tail;

public:
    explicit List();
    ~List();

    void push_back(int value = 0);
    int popback();

    void push_front(int value = 0);
    int pop_front();

    size_t get_size(){return size;}

    Node *getHead(){return Head;}
    void setHead(Node *_Head){Head = _Head;}

    Node *getTail(){return Tail;}
    void setTail(Node *_Tail){Tail = _Tail;}

    void show_list();

    bool isempty(){if(size == 0) return true; return false;}

    Node* operator[](int index);

};

class Node{
    int Data;
    Node *Next;
    Node *Prev;

public:
    explicit Node();
    explicit Node(int value = 0);

    int getData(){return Data;}
    void setData(int value){Data = value;}

    Node *getNext(){return Next;}
    void setNext(Node *_Next){Next = _Next;}

    Node *getPrev(){return Prev;}
    void setPrev(Node *_Prev){Prev = _Prev;}

    bool operator>(Node *obj);  // ЧЕ ОНА НЕ РАБОТАЕТ??? Я Ж ВСЕ ПО КРАСОТЕ СДЕЛАЛ
    bool comp(Node *obj);       // True если this->data > obj->data
};

void bubble_sort_list_byData(List &list);
void bubble_sort_list_byPointer(List &list);

#endif // LIST_TF_H
