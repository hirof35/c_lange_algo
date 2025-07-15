#ifndef __FILENAME1__
#define __FILENAME1__
// --- グローバル定義 
#define MAX_SIZE 10

// スタックの構造体を定義
struct Stack {
    int items[MAX_SIZE]; // スタックの要素を格納する配列
    int top;             // スタックのトップを示すインデックス
};

// キューの構造体を定義
struct Queue {
    int items[MAX_SIZE]; // キューの要素を格納する配列
    int front;           // キューの先頭を示すインデックス
    int rear;            // キューの末尾を示すインデックス
};
// --- 関数のプロトタイプ宣言 ---
// キューの作成
struct Queue* createQueue(void);
// キューが空かどうかのチェック
int isEmpty(struct Queue*);
// 要素をキューに追加 (enqueue)
void enqueue(struct Queue*, int);
// 要素をキューから取り出し (dequeue)
int dequeue(struct Queue*);
// キューが満杯かどうかのチェック
int isFull(struct Queue*);
// キューのメモリ解放
void freeQueue(struct Queue*);
// スタックの初期化
void initialize(struct Stack*);
// 要素をスタックにプッシュ
void push(struct Stack*, int);
// 要素をスタックからポップ
int pop(struct Stack*);
// 階乗の計算
int kaijou(int);
// フィボナッチ数の計算 (F(1)=1, F(2)=1, F(3)=2, ... の定義に基づいている)
int fibonacci(int);
// ハノイの塔
void hanoi(int,char,char,char);
// --- 各アルゴリズム/データ構造の動作確認関数 ---
void algo2_show(void);
#endif