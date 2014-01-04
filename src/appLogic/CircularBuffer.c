#include "CircularBuffer.h"
//#include "CException.h"
#include <string.h>
#include <stdio.h>

void CircularBuffer_Init(CircularBuffer* this, uint8_t* buffer, uint16_t capacity) {
    memset(buffer, 0, capacity);
    this->capacity = capacity;
    this->buffer = buffer;
    this->count = 0;
    this->firstValid = 0;
}

void CircularBuffer_Add(CircularBuffer* this, uint8_t data) {
    if (this->count < this->capacity) {
        this->buffer[this->count] = data;
        this->count++;
    }else{
        //we are full now we move first valid to make room for the data
        this->buffer[this->firstValid] = data;
        this->firstValid++;
        if(this->firstValid >=this->capacity){
            this->firstValid=0;
        }
    }
}

uint8_t CircularBuffer_Get(CircularBuffer* this, uint16_t index) {
    //TODO what happens if the index doesn't exist 
    uint16_t realIndex = this->firstValid + index;
    if (realIndex < this->capacity) {
        //printf("<%u,%u,%u>", realIndex, index, this->firstValid);
        return this->buffer[realIndex];
    } else {
        return this->buffer[realIndex - this->capacity];
    }
}

uint16_t CircularBuffer_Count(CircularBuffer* this) {
    //TODO ADD save guard to this pointer
    return this->count;
}
