#ifndef _LISTADOBLE_
#define _LISTADOBLE_ 1

#include "bodega.h"


struct listadoble {

    struct bodega* start = nullptr;
    struct bodega* end = nullptr;
    int size =0;


    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void addToEnd(void* pData) {
        struct bodega* newNode = (struct bodega*)malloc(sizeof(struct bodega)); 
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

    void addToBegining(void* pData) {
        struct bodega* newNode = (struct bodega*)malloc(sizeof(struct bodega)); 
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

    void* removeFirst() {
        void* result = nullptr;
        struct bodega* cursor = start;

        if (size>1) {
            start->next->previous = nullptr;
            start = start->next;
            cursor->next = nullptr;
            result = cursor->data;
            size--;
        } else if (size==1) {
            start = nullptr;
            end = nullptr;
            result = cursor->data;
            size--;
        }

        return result;
    }   
};

#endif