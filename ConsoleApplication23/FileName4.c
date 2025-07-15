#include <stdio.h>
#include <stdlib.h> // malloc, free, exit を使用するために必要
#include "FileName1.h" // 必要に応じてFileName1.hの内容をここに含めるか、別途作成



// --- 再帰関数 ---

// 階乗の計算
int kaijou(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Factorial is not defined for negative numbers.\n");
        return -1; // エラーを示す
    }
    if (n == 0 || n == 1) // 0! = 1, 1! = 1
        return 1;
    else
        return n * kaijou(n - 1);
}

// フィボナッチ数の計算 (F(1)=1, F(2)=1, F(3)=2, ... の定義に基づいている)
int fibonacci(int n) {
    if (n <= 0) {
        fprintf(stderr, "Error: Fibonacci sequence is typically defined for n >= 0 or n >= 1.\n");
        return 0; // またはエラーを示す値
    }
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// ハノイの塔
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// --- スタックの実装 ---

// スタックの初期化
void initialize(struct Stack* stack) {
    stack->top = -1; // 空の状態を示す
}

// 要素をスタックにプッシュ
void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push %d, stack is full.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
    printf("Pushed: %d\n", value);
}

// 要素をスタックからポップ
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow: Stack is empty.\n");
        return -1; // エラーを示す
    }
    int item = stack->items[stack->top--];
    return item;
}

// --- キューの実装 ---

// キューの作成
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

// キューが空かどうかのチェック
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// キューが満杯かどうかのチェック
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// 要素をキューに追加 (enqueue)
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

// 要素をキューから取り出し (dequeue)
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;

        // キューが空になった場合、front と rear をリセット
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        printf("Dequeued %d\n", item);
        return item;
    }
}

// キューのメモリ解放
void freeQueue(struct Queue* queue) {
    if (queue != NULL) {
        free(queue);
        printf("Queue memory freed.\n");
    }
}

// --- 各アルゴリズム/データ構造の動作確認関数 ---
void algo2_show(void) {
    printf("--- Factorial Calculation ---\n");
    for (int i = 0; i <= 5; i++) { // 0の階乗も試す
        int res = kaijou(i);
        if (res != -1) {
            printf("%d! = %d\n", i, res);
        }
    }
    printf("\n");

    printf("--- Fibonacci Sequence ---\n");
    for (int i = 1; i <= 10; i++) { // フィボナッチ数列
        printf("f(%d) = %d\n", i, fibonacci(i));
    }
    printf("\n");

    printf("--- Tower of Hanoi (n=3) ---\n");
    int n_hanoi = 3;
    hanoi(n_hanoi, 'A', 'C', 'B');
    printf("\n");

    printf("--- Stack Operations ---\n");
    struct Stack myStack; // スタックは直接宣言
    initialize(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack));
    push(&myStack, 40); // ポップ後にプッシュ
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack));
    printf("Popped item: %d\n", pop(&myStack)); // スタックアンダーフローを試す
    printf("\n");

    printf("--- Queue Operations ---\n");
    struct Queue* myQueue = createQueue(); // キューは動的に確保

    enqueue(myQueue, 100);
    enqueue(myQueue, 200);
    enqueue(myQueue, 300);

    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue); // キューが空の場合のdequeueを試す

    enqueue(myQueue, 400);
    enqueue(myQueue, 500);

    freeQueue(myQueue); // 最後にメモリを解放
    printf("\n");
}
