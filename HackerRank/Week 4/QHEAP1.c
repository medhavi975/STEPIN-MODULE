#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int size = 0;

// swap utility
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify up
void heapifyUp(int i) {
    while (i > 1 && heap[i] < heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= size && heap[left] < heap[smallest])
        smallest = left;
    if (right <= size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}


void insert(int x) {
    heap[++size] = x;
    heapifyUp(size);
}

void deleteElement(int x) {
    int i;
    for (i = 1; i <= size; i++) {
        if (heap[i] == x)
            break;
    }
    if (i <= size) {
        heap[i] = heap[size--];  
        heapifyUp(i);
        heapifyDown(i);
    }
}


int getMin() {
    return heap[1];
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type, val;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &val);
            insert(val);
        }
        else if (type == 2) {
            scanf("%d", &val);
            deleteElement(val);
        }
        else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
