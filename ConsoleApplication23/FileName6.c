#include <stdio.h> // printfのために必要
#include<math.h>
#include "FileName2.h"


// 最大値を正しく見つける関数
int max_num(int* arr, int len) {
    if (len <= 0) {
        // エラーハンドリング: 配列が空または無効な場合
        fprintf(stderr, "Error: Array length must be positive in max function.\n");
        return -1; // または適切なエラー値
    }

    int maxValue = arr[0]; // 最初の要素を初期の最大値とする
    for (int i = 1; i < len; i++) { // 2番目の要素から比較を開始
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// 最小値を正しく見つける関数
int min_num(int* arr, int len) {
    if (len <= 0) {
        // エラーハンドリング: 配列が空または無効な場合
        fprintf(stderr, "Error: Array length must be positive in min function.\n");
        return -1; // または適切なエラー値
    }

    int minValue = arr[0]; // 最初の要素を初期の最小値とする
    for (int i = 1; i < len; i++) { // 2番目の要素から比較を開始
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

void algo4_show(void) {
    struct Person person[] = { {"hiro", 41}, {"sin", 40}, {"koki", 21}, {"tomo", 45}, {"yuko", 23} };

    // 年齢だけを格納する配列を作成
    int ages[MAX];
    for (int i = 0; i < MAX; i++) {
        ages[i] = person[i].age;
    }

    printf("--- Names ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s\n", person[i].name);
    }

    printf("--- Ages ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\n", person[i].age);
    }

    printf("--- Max Age ---\n");
    printf("%d\n", max_num(ages, MAX)); // ages配列をmax関数に渡す

    printf("--- Min Age ---\n"); // min関数も使用してみる
    printf("%d\n", min_num(ages, MAX));
}
//短型の衝突判定関数
float rectcheckColision(float x1, float y1, float x2, float y2, float w1, float h1, float w2, float h2) {
    // 矩形の衝突判定
    return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
}
//円型の衝突判定関数
float circlecheckColision(float x1,float y1,float x2,float y2,float r1,float r2) {
	// 円の衝突判定
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < r1*r2;
}
//三角形の衝突判定関数
float trianglecheckColision(float x1, float y1, float x2, float y2, float h1, float w1, float h2, float w2) {
    // 三角形の衝突判定（外接矩形を用いた簡易判定）
    // w1, h1は最初の三角形の外接矩形の幅と高さ
    // w2, h2は2番目の三角形の外接矩形の幅と高さ
    // cはここでは使われていません（コメントアウトするか削除を推奨）
    return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
    // 元のコードにあった && (y1 - y2) * (x1 - x2) > c * (x1 - x2) * (y1 - y2) は、
    // 三角形の衝突判定として意味をなさないため削除または修正が必要です。
    // 今回は簡易的な矩形判定のみにしました。
}


void algo5_show(void) {
        int num;
        float x1, y1, x2, y2, w1, h1, w2, h2, c, r1,r2; // `c`は三角形の関数で使われませんが、今回は残しておきます

        while (1) {
            printf("これより各種当たり判定の計算を行います。\n");
            printf("(1)短形（矩形）の当たり判定 (2)円形の当たり判定 (3)三角形の当たり判定 (0)終了\n"); // メニュー表示を修正
            printf("選択してください: "); // 入力プロンプトを追加
            scanf_s("%d", &num);

            switch (num) {
            case 1:
                printf("短形（矩形）の当たり判定を行います。\n");
                printf("一つ目の矩形の左上X座標を入力してください: ");
                scanf_s("%f", &x1);
                printf("一つ目の矩形の左上Y座標を入力してください: ");
                scanf_s("%f", &y1);
                printf("一つ目の矩形の幅を入力してください: ");
                scanf_s("%f", &w1);
                printf("一つ目の矩形の高さを入力してください: ");
                scanf_s("%f", &h1);

                printf("二つ目の矩形の左上X座標を入力してください: ");
                scanf_s("%f", &x2);
                printf("二つ目の矩形の左上Y座標を入力してください: ");
                scanf_s("%f", &y2);
                printf("二つ目の矩形の幅を入力してください: ");
                scanf_s("%f", &w2);
                printf("二つ目の矩形の高さを入力してください: ");
                scanf_s("%f", &h2);

                if (rectcheckColision(x1, y1, x2, y2, w1, h1, w2, h2)) {
                    printf("衝突しています。\n");
                }
                else {
                    printf("衝突していません。\n");
                }
                break;
            case 2:
                printf("円形の当たり判定を行います。\n");
                printf("点のX座標を入力してください: "); // コメントに合わせて説明を修正
                scanf_s("%f", &x1);
                printf("点のY座標を入力してください: ");
                scanf_s("%f", &y1);
                printf("円の中心X座標を入力してください: ");
                scanf_s("%f", &x2);
                printf("円の中心Y座標を入力してください: ");
                scanf_s("%f", &y2);
                printf("円1の半径を入力してください: ");
                scanf_s("%f", &r1);
                printf("円2の半径を入力してください: ");
                scanf_s("%f", &r2);

                if (circlecheckColision(x1, y1, x2, y2, r1,r2)) {
                    printf("衝突しています。\n");
                }
                else {
                    printf("衝突していません。\n");
                }
                break;
            case 3:
                printf("三角形の当たり判定を行います（外接矩形による簡易判定）。\n"); // 説明を修正
                printf("一つ目の三角形の外接矩形の左上X座標を入力してください: "); // 説明を修正
                scanf_s("%f", &x1);
                printf("一つ目の三角形の外接矩形の左上Y座標を入力してください: "); // 説明を修正
                scanf_s("%f", &y1);
                printf("一つ目の三角形の外接矩形の幅を入力してください: "); // 説明を修正
                scanf_s("%f", &w1);
                printf("一つ目の三角形の外接矩形の高さを入力してください: "); // 説明を修正
                scanf_s("%f", &h1);

                printf("二つ目の三角形の外接矩形の左上X座標を入力してください: "); // 説明を修正
                scanf_s("%f", &x2);
                printf("二つ目の三角形の外接矩形の左上Y座標を入力してください: "); // 説明を修正
                scanf_s("%f", &y2);
                printf("二つ目の三角形の外接矩形の幅を入力してください: "); // 説明を修正
                scanf_s("%f", &w2);
                printf("二つ目の三角形の外接矩形の高さを入力してください: "); // 説明を修正
                scanf_s("%f", &h2);
                // `c` はこの関数では使われないので、入力は不要ですが、元のコードに合わせて残す場合は以下のようにします。
                // printf("cを入力してください（この簡易判定では使用されません）: ");
                // scanf_s("%f", &c);

                if (trianglecheckColision(x1, y1, x2, y2, w1, h1, w2, h2)) {
                    printf("衝突しています。\n");
                }
                else {
                    printf("衝突していません。\n");
                }
                break;
            case 0:
                printf("プログラムを終了します。\n");
                goto end_loop; // ループを抜けるためのgoto
            default:
                printf("無効な選択です。0から3の間の数字を入力してください。\n");
                break;
            }
            printf("\n"); // 各操作の後に改行を追加して見やすくする
        }
    end_loop:; // gotoのターゲット
 }
