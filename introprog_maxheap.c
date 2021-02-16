#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "introprog_heap.h"

heap* heap_create(size_t capacity) {
    heap * heap_create = (heap*)malloc(sizeof(heap));
    heap_create -> elements = (int*)malloc(capacity * sizeof(int));
    heap_create -> size = 0;
    heap_create -> capacity = capacity;
    return heap_create;
}

void heapify(heap* h, size_t i) {
int l = i*2;
int r =i * 2 + 1;
int largest;

    if (l <= h -> size && h -> elements[r] > h -> elements[i]){
        largest = l;
    } else {

        largest = i;
        
    }
    if (r <= h -> size && h -> elements[r] > h -> elements[largest]){

        largest=r;

    }
    if (largest =!i ){
        int m;
      m =   h -> elements[i];
              h -> elements[i] = h -> elements[largest];
      h -> elements[largest] = m;


    }
    heapify(h, largest);
    
}

int heap_extract_max(heap* h) {

    int max;
    if(h -> size =! 0)
    {
        max = h -> elements[0];
        h -> elements[0] = h -> elements[h -> size];
        h -> size = h -> size - 1;
        heapify(h, 0);
        return max;
    }
    else {
        return -1;

    }
    
}

int heap_insert(heap* h, int key) {
    h -> size = h -> size +1;
    int i = h -> size;

    while(i > 1 && h -> elements[i / 2] < key)
    {
        h -> elements[i] = h -> elements[i/2];
        i = i/2;
    }
    h -> elements[i] = key;
    
    return 0;
}

void heap_free(heap* h) {
    free(h -> elements);
    free(h);
}
