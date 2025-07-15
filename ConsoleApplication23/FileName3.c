#include <stdio.h>
#include <stdlib.h> // malloc, free ���g�p���邽�߂ɕK�v
#include <string.h> // memcpy ���g�p���邽�߂ɕK�v

// FileName.h �͓��e���s���̂��߁A�����ł͍폜���邩�A�K�؂Ȓ�`��������̂Ɖ��肵�܂��B
// ��: #include "my_utility_functions.h"

// --- �����A���S���Y�� ---

// ���`�T��
int linear_search(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // ������Ȃ������ꍇ
}

// �񕪒T�� (�z�񂪃\�[�g����Ă���K�v������܂�)
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
    return -1; // ������Ȃ������ꍇ
}

// --- �\�[�g�A���S���Y���̃w���p�[�֐� ---

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// --- �\�[�g�A���S���Y�� ---

// �o�u���\�[�g
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// �I���\�[�g
void selection_sort(int* arr, int n) {
    int min_idx; // �ϐ����� 'mid_idx' ���� 'min_idx' �ɕύX����ƕ�����₷��
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

// �}���\�[�g (�C���ς�)
void insert_sort(int* arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) { // i��1����J�n���An�܂ŌJ��Ԃ�
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// �q�[�v�\�[�g�̃w���p�[�֐� (�q�[�v��)
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

// �q�[�v�\�[�g
void heap_sort(int* arr, int n) {
    // �ŏ��ɍő�q�[�v���\�z
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // �q�[�v����v�f��1�����o���ă\�[�g
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // ���݂̃��[�g (�ő�v�f) �𖖔��Ɉړ�
        heapify(arr, i, 0);      // �c��̃q�[�v���č\��
    }
}

// �N�C�b�N�\�[�g�̃w���p�[�֐� (����)
int partition(int* arr, int low, int high) {
    int pivot = arr[high]; // �s�{�b�g���Ō�̗v�f�Ƃ���
    int i = low - 1;       // ��菬�����v�f�̃C���f�b�N�X

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // �s�{�b�g�𐳂����ʒu�ɔz�u
    return i + 1;                  // �s�{�b�g�̃C���f�b�N�X��Ԃ�
}

// �N�C�b�N�\�[�g
void quik_sort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high); // �s�{�b�g�̃C���f�b�N�X���擾
        quik_sort(arr, low, pivot_index - 1);       // �������ċA�I�Ƀ\�[�g
        quik_sort(arr, pivot_index + 1, high);      // �E�����ċA�I�Ƀ\�[�g
    }
}

// �}�[�W�\�[�g�̃w���p�[�֐� (�}�[�W)
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
        exit(EXIT_FAILURE); // �������m�ێ��s�Ńv���O�������I��
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

// �}�[�W�\�[�g
void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- �e�A���S���Y���̓���m�F�֐� ---
void algo_show(void) {
    int original_array[] = { 4, 2, 3, 5, 6, 1, 9, 7, 8, 0 }; // �����̃e�X�g�P�[�X�ɑΉ�
    int len = sizeof(original_array) / sizeof(int);
    int test_array[10] = { 4, 2, 3, 5, 6, 1, 9, 7, 8, 0 }; // �e�\�[�g�̂��߂̍�Ɨp�z��

    printf("--- Original Array ---\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", original_array[i]);
    }
    printf("\n\n");

    // ���`�T���̃e�X�g
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

    // �񕪒T���̃e�X�g (�\�[�g�ςݔz�񂪕K�v)
    printf("--- Binary Search (requires sorted array) ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    bubble_sort(test_array, len); // �܂��\�[�g����
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

    // �o�u���\�[�g�̃e�X�g
    printf("--- Bubble Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array)); // �I���W�i������R�s�[
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    bubble_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // �I���\�[�g�̃e�X�g
    printf("--- Selection Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    selection_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // �}���\�[�g�̃e�X�g
    printf("--- Insertion Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    insert_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // �q�[�v�\�[�g�̃e�X�g
    printf("--- Heap Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    heap_sort(test_array, len);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // �N�C�b�N�\�[�g�̃e�X�g
    printf("--- Quick Sort ---\n");
    memcpy(test_array, original_array, sizeof(original_array));
    printf("Before sorting: ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n");
    quik_sort(test_array, 0, len - 1);
    printf("After sorting:  ");
    for (int i = 0; i < len; i++) { printf("%d ", test_array[i]); }
    printf("\n\n");

    // �}�[�W�\�[�g�̃e�X�g
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

