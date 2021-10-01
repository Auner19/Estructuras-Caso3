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
        int StackId;

    public:
        Stack(int maxSize = 15);
        int size() const;
        bool empty() const;
        void top() const;
        void push(int unidadesXpaletas);
        void pop();
        ~Stack();
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

void Stack::top() const{
    cout << arr[indexTop] << endl;
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



