#include <stdio.h>
// #include "FileName2.h" // 必要に応じてFileName2.hの内容をここに含めるか、別途作成
#include <math.h> // sqrt関数を使用する場合に必要 (ここでは使用せず、j*j <= iで代替)

// --- 素数を表示する関数 ---
// n までの素数をすべて表示します。
void sosuu_func1(int n) {
    if (n < 2) {
        printf("素数は2以上です。\n");
        return;
    }
    printf("2から%dまでの素数:\n", n);
    for (int i = 2; i <= n; ++i) {
        int is_prime = 1; // 素数であると仮定

        // i の約数をチェック。j*j <= i で効率化
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = 0; // 約数が見つかったので素数ではない
                break;
            }
        }
        if (is_prime == 1) { // is_prime が 0 にならなかった場合、素数
            printf("%d\n", i);
        }
    }
}

// --- 素数判定を行う関数 ---
// 指定された数 num が素数であるか判定し、結果の文字列を返します。
char* sosuu_hantei(int num) {
    if (num < 2) { // 2未満の数は素数ではない
        return "素数ではありません。";
    }
    // 約数をチェック。j*j <= num で効率化
    for (int j = 2; j * j <= num; ++j) {
        if (num % j == 0) {
            return "素数ではありません。"; // 約数が見つかったので素数ではない
        }
    }
    return "素数です。"; // 約数が見つからなかった場合、素数
}

// --- メインの操作インターフェース関数 ---
void algo3_show(void) {
    while (1) {
        printf("素数プログラムです。\n");
        printf("終了する場合は0を入力してください。\n");
        printf("素数を表示するか(1を入力)、素数判定を行いますか(2を入力)？\n");
        int choice; // s を choice に変更
        // scanf_s はサイズ引数が必要な場合がありますが、int の場合は不要です
        if (scanf_s("%d", &choice) != 1) {
            printf("無効な入力です。終了します。\n");
            // 入力バッファをクリア（不正な入力が残らないように）
            while (getchar() != '\n');
            return;
        }

        switch (choice) {
        case 1: { // case 1 のスコープ
            printf("表示する素数の最大値を入力してください。\n");
            int n_max; // n を n_max に変更
            if (scanf_s("%d", &n_max) != 1) {
                printf("無効な入力です。\n");
                while (getchar() != '\n');
                break; // このcaseを抜ける
            }
            sosuu_func1(n_max);
            break;
        }
        case 2: { // case 2 のスコープ
            printf("素数判定を行います。\n");
            printf("判定する数を入力してください。\n");
            int num_to_check; // m を num_to_check に変更
            if (scanf_s("%d", &num_to_check) != 1) {
                printf("無効な入力です。\n");
                while (getchar() != '\n');
                break; // このcaseを抜ける
            }
            char* result = sosuu_hantei(num_to_check);
            printf("%dは%s\n", num_to_check, result);
            break;
        }
        case 0: // 0 を入力で終了
            printf("終了します。\n");
            return;
        default:
            printf("無効な選択です。もう一度入力してください。\n");
            break;
        }
        printf("\n"); // 各操作の後に改行を入れて見やすくする
    }
}