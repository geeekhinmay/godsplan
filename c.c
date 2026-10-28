#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;       // dynamic array
    int front;      // index of front element
    int rear;       // index of rear element
    int size;       // current queue size
    int capacity;   // maximum capacity
} CircularQueue;

CircularQueue* createQueue(int capacity) {
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!q) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    q->arr = (int *)malloc(capacity * sizeof(int));
    if (!q->arr) {
        printf("Memory allocation failed.\n");
        free(q);
        exit(1);
    }

    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;

    return q;
}

int isEmpty(CircularQueue *q) {
    return q->size == 0;
}

int isFull(CircularQueue *q) {
    return q->size == q->capacity;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    return value;
}

int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}

void freeQueue(CircularQueue *q) {
    free(q->arr);
    free(q);
}

int main() {
    CircularQueue *q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // will show full if capacity is 5

    display(q);

    printf("Front element: %d\n", peek(q));

    freeQueue(q);
    return 0;
}