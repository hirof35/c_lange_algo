#include <stdio.h>
#include <stdlib.h> // malloc, free を使用するために必要
#include <string.h> // memcpy を使用するために必要

// FileName.h は内容が不明のため、ここでは削除するか、適切な定義があるものと仮定します。
// 例: #include "my_utility_functions.h"

// --- 検索アルゴリズム ---

// 線形探索
int linear_search(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // 見つからなかった場合
}

// 二分探索 (配列がソートされている必要があります)
int binary_search(int* arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // 見つからなかった場合
}

// --- ソートアルゴリズムのヘルパー関数 ---

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// --- ソートアルゴリズム ---

// バブルソート
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 選択ソート
void selection_sort(int* arr, int n) {
    int min_idx; // 変数名を 'mid_idx' から 'min_idx' に変更すると分かりやすい
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// 挿入ソート (修正済み)
void insert_sort(int* arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) { // iを1から開始し、nまで繰り返す
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ヒープソートのヘルパー関数 (ヒープ化)
void heapify(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// ヒープソート
void heap_sort(int* arr, int n) {
    // 最初に最大ヒープを構築
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // ヒープから要素を1つずつ取り出してソート
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // 現在のルート (最大要素) を末尾に移動
        heapify(arr, i, 0);      // 残りのヒープを再構成
    }
}

// クイックソートのヘルパー関数 (分割)
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // ピボットを最後の要素とする
    int i = low - 1;       // より小さい要素のインデックス

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // ピボットを正しい位置に配置
    return i + 1;                  // ピボットのインデックスを返す
}

// クイックソート
void quik_sort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high); // ピボットのインデックスを取得
        quik_sort(arr, low, pivot_index - 1);       // 左側を再帰的にソート
        quik_sort(arr, pivot_index + 1, high);      // 右側を再帰的にソート
    }
}

// マージソートのヘルパー関数 (マージ)
void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Memory allocation failed in merge function!\n");
        if (L != NULL) free(L);
        if (R != NULL) free(R);
        exit(EXIT_FAILURE); // メモリ確保失敗でプログラムを終了
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// マージソート
void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- 各アルゴリズムの動作確認関数 ---
void algo_show(void) {
    int original_array[] = { 4, 2, 3, 5, 6, 1, 9, 7, 8, 0 }; // 複数のテストケースに対応
    int len = sizeof(original_array) / sizeof(int);
    int test_array[10] = { 4, 2, 3, 5, 6, 1, 9, 7, 8, 0 }; // 各ソートのための作業用配列

    printf("--- Original Array ---\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", original_array[i]);
    }
    printf("\n\n");

    // 線形探索のテスト
    printf("--- Linear Search ---\n");
    int key_linear = 5;
    int result_linear = linear_search(original_array, len, key_linear);
    if (result_linear != -1) {
        printf("Element %d found at index: %d\n", key_linear, result_linear);
    }
    else {
        printf("Element %d not found.\n", key_linear);
    }
    printf("\n");

    // 二分探索のテスト (ソート済み配列が必要)
    printf("--- Binary Search (requires sorted array) ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    bubble_sort(test_array, len); // まずソートする
    printf("Sorted array for Binary Search: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    int key_binary = 7;
    int result_binary = binary_search(test_array, 0, len - 1, key_binary);
    if (result_binary != -1) {
        printf("Element %d found at index: %d\n", key_binary, result_binary);
    }
    else {
        printf("Element %d not found.\n", key_binary);
    }
    printf("\n");

    // バブルソートのテスト
    printf("--- Bubble Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array)); // オリジナルからコピー
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    bubble_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // 選択ソートのテスト
    printf("--- Selection Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    selection_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // 挿入ソートのテスト
    printf("--- Insertion Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    insert_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // ヒープソートのテスト
    printf("--- Heap Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    heap_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // クイックソートのテスト
    printf("--- Quick Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    quik_sort(test_array, 0, len - 1);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // マージソートのテスト
    printf("--- Merge Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    merge_sort(test_array, 0, len - 1);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");
}

