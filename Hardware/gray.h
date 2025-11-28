#ifndef _gray_h
#define _gray_h
#include "headfile.h"

typedef struct{
    uint8_t left[4];
    uint8_t right[4];
} gray_t;

void Gray_Read(void);
void Get_Light_TTL(void);

extern gray_t sensor;

#endif