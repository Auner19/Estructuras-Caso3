#include <iostream>

using namespace std;

class Stack {

    private:
        int *arr;
        int indexTop;
        int maxSize;
        
        int columnas;
        int paletasXcolumna;
        int unidadesXpaletas;
    
    public:
        Stack(int maxSize = 15);
        int size() const;
        bool empty() const;
        int top() const;
        void push(int unidadesXpaletas);
        void pop();
        ~Stack();
        string producto;
};

Stack::Stack(int max){
    indexTop = -1;
    maxSize = max;
    arr = new int[max];
}

int Stack::size() const{
    return indexTop +1;
}

bool Stack::empty() const{
    return(indexTop == -1);
}

int Stack::top() const{
    return arr[indexTop];
}

void Stack::push(int unidadesXpaletas){
    if(indexTop +1 < maxSize)
        arr[++indexTop] = unidadesXpaletas;
}

void Stack::pop(){
    if(!empty())
        indexTop--;
}

Stack::~Stack(){
    delete []arr;
}