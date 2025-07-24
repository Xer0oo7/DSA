#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
int value;
if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
printf("Queue Overflow\n");
return;
}
printf("Enter value to enqueue: ");
scanf("%d", &value);
if (front == -1) {
front = rear = 0;
} else if (rear == SIZE - 1 && front != 0) {
rear = 0;
} else {
rear++;
}
queue[rear] = value;
}

void dequeue() {
if (front == -1) {
printf("Queue Underflow\n");
return;
}
printf("Dequeued: %d\n", queue[front]);
if (front == rear) {
front = rear = -1;
} else if (front == SIZE - 1) {
front = 0;
} else {
front++;
}
}

void display() {
if (front == -1) {
printf("Queue is Empty\n");
return;
}
printf("Queue: ");
if (rear >= front) {
for (int i = front; i <= rear; i++)
printf("%d ", queue[i]);
} else {
for (int i = front; i < SIZE; i++)
printf("%d ", queue[i]);
for (int i = 0; i <= rear; i++)
printf("%d ", queue[i]);
}
printf("\n");
}

int main() {
int choice;
while (1) {
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: enqueue(); break;
case 2: dequeue(); break;
case 3: display(); break;
case 4: return 0;
default: printf("Invalid choice\n");
}
}
}
