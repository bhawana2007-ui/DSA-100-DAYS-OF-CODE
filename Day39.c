#include <stdio.h>

#define MAX 1000

int heap[MAX], size = 0;

// Swap helper
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

// Heapify up
void up(int i) {
    while(i && heap[i] < heap[(i-1)/2]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void down(int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;
    if(l < size && heap[l] < heap[smallest]) smallest = l;
    if(r < size && heap[r] < heap[smallest]) smallest = r;
    if(smallest != i) { swap(&heap[i], &heap[smallest]); down(smallest); }
}

// Insert
void insert(int x) { heap[size] = x; up(size++); }

// Peek
int peek() { return size ? heap[0] : -1; }

// Extract min
int extractMin() {
    if(!size) return -1;
    int min = heap[0];
    heap[0] = heap[--size];
    down(0);
    return min;
}

int main() {
    int N, x;
    char op[20];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s", op);
        if(op[0]=='i'){ scanf("%d",&x); insert(x); }
        else if(op[0]=='p') printf("%d\n", peek());
        else if(op[0]=='e') printf("%d\n", extractMin());
    }
}