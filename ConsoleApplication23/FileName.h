#ifndef __FILENAME__
#define __FILENAME__
//車の構造体定義と関数プロトタイプ宣言
typedef struct CAR {
    char* name;
    float gas;
} car;
// 車構造体の初期化関数
void set_car(car*, const char*, float);
// 車構造体の表示関数
void set_car_show(void);
// サーチとソートアルゴリズムのプロトタイプ宣言
// 線形探索
int linear_search(int* ,int,int);
// 二分探索 (配列がソートされている必要があります)
int binary_search(int*, int, int,int);
// バブルソート
void bubble_sort(int*, int);
// 選択ソート
void selection_sort(int*, int);
// 挿入ソート (修正済み)
void insert_sort(int*, int);
// ヒープソートのヘルパー関数 (ヒープ化)
void heapify(int*, int,int);
// ヒープソート
void heap_sort(int*, int);
// --- ソートアルゴリズムのヘルパー関数 ---
void swap(int*,int*);
// クイックソートのヘルパー関数 (分割)
int partition(int*, int, int);
// クイックソート
void quik_sort(int*, int, int);
// マージソートのヘルパー関数 (マージ)
void merge(int*, int, int, int);
// マージソート
void merge_sort(int*, int, int);
// --- 各アルゴリズムの動作確認関数 ---
void algo_show(void);
#endif // !__FILENAME__
