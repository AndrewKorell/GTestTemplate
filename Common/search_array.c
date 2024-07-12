#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "search_array.h"

static compareints(const void * a, const void * b);

int compareints(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );  
}


int find_value_recursive(size_t size, const int *base, int key, int offset)
{

    //printf("test_%d__size_%d", *base, size);
   // if(offset < 0 || offset > size) return 0;
    if(base == NULL) return 0;


    int test =  key - *(base+offset);
    if(test == 0) 
    {
        return true;
    }
    if(size == 0) return false; //there is nothing to find
    if(test < 0 && offset == 0) return false;

    int shift = (int)(size+1)>>1;
    if(shift < 1) shift = 1;

    //printf("_shift_%d\n", shift);

    offset = test < 0 ? offset - shift : offset + shift;
    return find_value_recursive((size)>>1, base, key, offset);

}   

int find_value(size_t size, const int *base, int key)
{
    if(size == 0) return 0;

    int index = (int)size >> 1;
    //base += (int)size >> 1;

    while(size >= 0)
    {
        int test = key - *(int*)(base + index); 
        //printf("Key test %d, size %d ", (int)*(int*)(base), (int)size);
        if(test == 0)
        {
            //printf("key found\n\n");
            return 1;
        }            
        
        if(size == 0) {
            //printf("key not found\n\n");
            return 0;
        }
        // printf("%d_%d\n", base, size);
        size = size > 1 ? (size + 1) >> 1 : 0;
        int jump = (int)(size >> 1);
        if(jump < 1) 
            jump = 1;
        if(test >= 1) //the value is in the top half
        {
            //printf("add");
            index+=jump;
        }
        else
        {
            //printf("del");
            index-=jump;
        }
    }
    //small colleciton co-out 
    return 0;
}