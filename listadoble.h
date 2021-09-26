#ifndef _LISTADOBLE_
#define _LISTADOBLE_ 1

#include "nododoble.h"


struct listadoble {
    struct nododoble* start = nullptr;
    struct nododoble* end = nullptr;
    int size =0;


    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void addToEnd(struct bodega pData) {
        struct nododoble* newNode = (struct nododoble*)malloc(sizeof(struct nododoble)); 
        newNode->data = pData;

        if (size==0) {
            start = newNode;
            end = newNode;
        } else {
            newNode->previous = end;
            end->next = newNode;
            end = newNode;
        }

        size++;
    }

    void addToBegining(struct bodega pData) {
        struct nododoble* newNode = (struct nododoble*)malloc(sizeof(struct nododoble)); 
        newNode->data = pData;

        if (size==0) {
            start = newNode;
            end = newNode;
        } else {
            newNode->next = start;
            start->previous = newNode;
            start = newNode;
        }

        size++;
    }

    void removeFirst() {
        struct nododoble* cursor = start;

        if (size>1) {
            start->next->previous = nullptr;
            start = start->next;
            cursor->next = nullptr;
            size--;
        } else if (size==1) {
            start = nullptr;
            end = nullptr;
            size--;
        }
    }   
};

#endif