/* 
 * File:   CircularBuffer.h
 * Author: ednei
 *
 * Created on December 23, 2013, 8:02 PM
 */

#ifndef CIRCULARBUFFER_H
#define	CIRCULARBUFFER_H

#include <stdint.h>

typedef struct CircularBuffer_t{
    uint16_t capacity;
    uint16_t count;
    uint16_t firstValid;
    uint8_t* buffer;
} CircularBuffer;

void CircularBuffer_Init(CircularBuffer* this,uint8_t* buffer,uint16_t capacity);
void CircularBuffer_Add(CircularBuffer* this, uint8_t data);
uint8_t CircularBuffer_Get(CircularBuffer* this,uint16_t index);
uint16_t CircularBuffer_Count(CircularBuffer* this);

/*
#define CircularBuffer_Create(name,capacity)            \
        uint8_t b##name[capacity];                     \
        CircularBuffer name;                            \
        CircularBuffer_Init(&name, b##name, capacity);    \
                                                       
*/

#endif	/* CIRCULARBUFFER_H */

