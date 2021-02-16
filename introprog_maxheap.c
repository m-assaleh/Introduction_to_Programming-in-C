#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "introprog_heap.h"

heap* heap_create(size_t capacity) {

    heap * hp = (heap*)malloc(sizeof(heap));
    hp -> elements = (int*)malloc(capacity * sizeof(int));
    hp -> capacity = capacity;
    hp -> size = 0;
    return hp;
}

void heapify(heap* h, size_t i) {
    size_t l = (i+1)*2 - 1;
    size_t r = (i+1) * 2;

    size_t largest;

    if (l < h -> size && h -> elements[l] > h -> elements[i]){
        largest = l;
    } else {
        largest = i;
    }
    if (r < h -> size && h -> elements[r] > h -> elements[largest]){

        largest=r;

    }
    if (largest != i ){
        size_t m =   h -> elements[i];
        h -> elements[i] = h -> elements[largest];
        h -> elements[largest] = m;
        heapify(h, largest);

    }
}

int heap_extract_max(heap* h) {

    int max;
    if(h -> size < 1)
    {
        return -1;
    }

        max = h -> elements[0];
        h -> elements[0] = h -> elements[h -> size-1];
        h -> size = h -> size - 1;
        heapify(h, 0);
        return max;
}

int heap_insert(heap* h, int key) {

    size_t i = h -> size;

    if(h -> size == h -> capacity)
    {
        return -1;
    }
    h -> size = (h -> size) +1;

    while(i != 0 && h -> elements[(i+1)/2 -1] < key)
    {
        h -> elements[i] = h -> elements[(i+1)/2 -1];
        i = (i+1)/2 - 1;
    }
    h -> elements[i] = key;
    return 0;
}

void heap_free(heap* h) {
    free(h -> elements);
    free(h);
}