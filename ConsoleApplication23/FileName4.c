#include <stdio.h>
#include <stdlib.h> // malloc, free, exit ���g�p���邽�߂ɕK�v
#include "FileName1.h" // �K�v�ɉ�����FileName1.h�̓��e�������Ɋ܂߂邩�A�ʓr�쐬



// --- �ċA�֐� ---

// �K��̌v�Z
int kaijou(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Factorial is not defined for negative numbers.\n");
        return -1; // �G���[������
    }
    if (n == 0 || n == 1) // 0! = 1, 1! = 1
        return 1;
    else
        return n * kaijou(n - 1);
}

// �t�B�{�i�b�`���̌v�Z (F(1)=1, F(2)=1, F(3)=2, ... �̒�`�Ɋ�Â��Ă���)
int fibonacci(int n) {
    if (n <= 0) {
        fprintf(stderr, "Error: Fibonacci sequence is typically defined for n >= 0 or n >= 1.\n");
        return 0; // �܂��̓G���[�������l
    }
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// �n�m�C�̓�
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// --- �X�^�b�N�̎��� ---

// �X�^�b�N�̏�����
void initialize(struct Stack* stack) {
    stack->top = -1; // ��̏�Ԃ�����
}

// �v�f���X�^�b�N�Ƀv�b�V��
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push %d, stack is full.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
    printf("Pushed: %d\n", value);
}

// �v�f���X�^�b�N����|�b�v
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow: Stack is empty.\n");
        return -1; // �G���[������
    }
    int item = stack->items[stack->top--];
    return item;
}

// --- �L���[�̎��� ---

// �L���[�̍쐬
struct Queue* createQueue(void) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed for queue!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// �L���[���󂩂ǂ����̃`�F�b�N
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// �L���[�����t���ǂ����̃`�F�b�N
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// �v�f���L���[�ɒǉ� (enqueue)
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// �v�f���L���[������o�� (dequeue)
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;

        // �L���[����ɂȂ����ꍇ�Afront �� rear �����Z�b�g
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        printf("Dequeued %d\n", item);
        return item;
    }
}

// �L���[�̃��������
void freeQueue(struct Queue* queue) {
    if (queue != NULL) {
        free(queue);
        printf("Queue memory freed.\n");
    }
}

// --- �e�A���S���Y��/�f�[�^�\���̓���m�F�֐� ---
void algo2_show(void) {
    printf("--- Factorial Calculation ---\n");
    for (int i = 0; i <= 5; i++) { // 0�̊K�������
        int res = kaijou(i);
        if (res != -1) {
            printf("%d! = %d\n", i, res);
        }
    }
    printf("\n");

    printf("--- Fibonacci Sequence ---\n");
    for (int i = 1; i <= 10; i++) { // �t�B�{�i�b�`����
        printf("f(%d) = %d\n", i, fibonacci(i));
    }
    printf("\n");

    printf("--- Tower of Hanoi (n=3) ---\n");
    int n_hanoi = 3;
    hanoi(n_hanoi, 'A', 'C', 'B');
    printf("\n");

    printf("--- Stack Operations ---\n");
    struct Stack myStack; // �X�^�b�N�͒��ڐ錾
    initialize(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack));
    push(&myStack, 40); // �|�b�v��Ƀv�b�V��
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack)); // �X�^�b�N�A���_�[�t���[������
    printf("\n");

    printf("--- Queue Operations ---\n");
    struct Queue* myQueue = createQueue(); // �L���[�͓��I�Ɋm��

    enqueue(myQueue, 100);
    enqueue(myQueue, 200);
    enqueue(myQueue, 300);

    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue); // �L���[����̏ꍇ��dequeue������

    enqueue(myQueue, 400);
    enqueue(myQueue, 500);

    freeQueue(myQueue); // �Ō�Ƀ����������
    printf("\n");
}
