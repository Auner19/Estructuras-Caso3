#include <iostream>
using namespace std;

class Node{

    private:
        Node *next;
        Node *prev;
        Queue colaMontacargas;

        int id;
        friend class Queue;
};

class Queue{

    public:

    Queue(int tm =100);
    const int &front();
    void enqueue(const int & dt);
    void dequeue();
    bool empty() const;
    int size() const;
    void printFoward();
    ~Queue();
    

    private:
        Node *header;
        Node *trailer;
        int tam;
        int tamMax;
};

Queue::Queue(int tm){

    header = new Node;
    trailer = new Node;

    trailer->prev = header;
    header->next = trailer;

    trailer->next = NULL;
    header->prev= NULL;

    tam = 0;
    tamMax = tm;

}
Queue::~Queue(){

    while(!empty())
        dequeue();

    delete header;
    delete trailer;

}
const int & Queue::front(){

    return header->next->id;
}
void Queue::enqueue(const int & dt){

    if(tam<tamMax){

        Node *nd = new Node;
        nd->id = dt;
        nd->next = trailer;
        nd->prev= trailer->prev;

        trailer->prev->next = nd;
        trailer->prev = nd;
        tam++;
    }
}
void Queue::dequeue(){

    if(!empty()){

        Node *nd = header->next->next;
        delete header->next;
        header->next = nd;
        nd->prev = header;
        tam--;
    }
}
bool Queue::empty() const{
    return(tam==0);
}
int Queue::size() const{
    return(tam);
}
void Queue::printFoward(){
    Node *nd = header->next;

    while(nd != trailer){
        cout << nd->id << " ";
        nd = nd->next;
    }
}

