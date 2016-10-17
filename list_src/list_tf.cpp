#include <iostream>
#include "list_tf.h"
#include <stdio.h>
#include "../list_err.h"

Node::Node(){
    Data = 0;
    Next = NULL;
    Prev = NULL;
}

Node::Node(int value):Data(value){
    Next = NULL;
    Prev = NULL;
}

List::List(){
    size = 0;
    Head = NULL;
    Tail = NULL;
}

List::~List(){
    std::cout<<"~List"<<std::endl;

    Node *cur = Head;
    Node *next = NULL;

    while(cur){
        next = cur->getNext();
//        delete Data   //Если ну вдруг буду инты хранить в куче ;)
        delete cur;
        cur = next;
    }
}

void List::push_back(int value){

    Node *new_node = new Node(value);

    new_node->setNext(NULL);
    new_node->setPrev(Tail);

    if (Tail) {
         Tail->setNext(new_node);
    }

    Tail = new_node;

    if (Head == NULL) {
         Head = new_node;
    }

    ++size;
}

int List::popback(){

    if(size == 0){
        throw BAD_BOUNDARY;
    }

    int return_data = 0;

    Node *node_tail = Tail;         //присваиваем в node_tail текущий хвост
    Tail = Tail->getPrev();         //присваваем хвосту предыдущий узел, в случае если prev == NULL, то хвост
                                    // указывет на NULL. То есть голова и хвост указывали на один и тот же узел

    if(Tail){
        Tail->setNext(NULL);        //в хорошем случае, в next записываем NULL
    }
    else{
        Head = NULL;                //в противном, голове присваиваем тоже NULL (список пуст)
//        Tail = NULL;              //хвост уже указывает на NULL
    }

    return_data = node_tail->getData();     //вытаскиваем данные
    delete node_tail;                       //освобождаем память, выделенную под бывший хвост
    --size;                                 //уменьшаем размер списка

    return return_data;                     //возвращаем данные
}

void List::push_front(int value){

    Node *new_node = new Node(value);

    new_node->setNext(Head);
    new_node->setPrev(NULL);

    if(Head){
        Head->setPrev(new_node);
    }

    Head = new_node;

    if(Tail == NULL){
        Tail = new_node;
    }

    ++size;
}

int List::pop_front(){

    if(size == 0){
        throw BAD_BOUNDARY;
    }

    int return_data = 0;

    Node *node_head = Head;

    Head = Head->getNext();
    if(Head){
        Head->setPrev(NULL);
    }
    else{
//        list->Head = NULL;    //голова и так уже указывает на NULL
        Tail = NULL;            //Хвост теперь тоже указывает на NULL(список пуст)
    }

    return_data = node_head->getData();
    delete node_head;
    --size;

    return return_data;
}

void List::show_list(){

    if(size == 0){
        throw EMPTY_LIST;
    }

    Node *cur = Head;

    if(cur == NULL){
        std::cout<<"[!!!ATTENTION!!!] List is empty"<<std::endl;
        return;
    }

    while(cur) {
        std::cout<<cur->getData()<<" ";
        cur = cur->getNext();
    }
    std::cout<<std::endl;
}


Node * List::operator[](int index){

    int index_cnt = -1;

    if((size_t)index >= size || index < 0){
        std::cout<<"BAD INPUT INDEX"<<std::endl;
        return NULL;
    }

    Node *cur = Head;

    while(cur) {
        ++index_cnt;
        if(index_cnt == index){
            return cur;
        }
        cur = cur->getNext();
    }

    return NULL;;
}

bool Node::operator>(Node *obj){
    return (this->getData() > obj->getData());
}

bool Node::comp(Node *obj){
    return (this->getData() > obj->getData());
}

void bubble_sort_list_byData(List &list){

    int tmp_data = 0;
    for (size_t i = 0; i < list.get_size() - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < list.get_size()-i-1; ++j) {
            if (list[j]->comp(list[j+1])) {

                tmp_data = list[j]->getData();
                list[j]->setData(list[j+1]->getData());
                list[j+1]->setData(tmp_data);

                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

void bubble_sort_list_byPointer(List &list){

    Node *first_Prev = NULL;
    Node *second_Next = NULL;

    Node *first = NULL;
    Node *second = NULL;

    for (size_t i = 0; i < list.get_size() - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < list.get_size()-i-1; ++j) {
            if (list[j]->comp(list[j+1])) {

                first = list[j];
                second = list[j+1];

                first_Prev = first->getPrev();
                second_Next = second->getNext();

                first->setNext(second_Next);
                first->setPrev(second);

                second->setNext(first);
                second->setPrev(first_Prev);

                if(j == 0){
                    list.setHead(second);
                }
                else{
                    first_Prev->setNext(second);
                }
                if((j + 1) == list.get_size() - 1){
                    list.setTail(first);
                }
                else{
                    second_Next->setPrev(first);
                }

                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

