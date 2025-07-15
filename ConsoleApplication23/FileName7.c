#include <stdio.h>  // printf, scanf_sのために必要
#include <stdlib.h> // abs関数のために必要
#include"FileName2.h"
// 秒数に変換する関数
int timer_calc(int h, int m, int s) {
    return (h * 3600) + (m * 60) + s;
}

// 2つの時間（秒数）の差の絶対値を取得する関数
int get_absolute_time_difference(int time1_in_seconds, int time2_in_seconds) {
    return abs(time1_in_seconds - time2_in_seconds);
}

// 秒数を時、分、秒に変換し、ポインタで結果を返す関数
void time_get_func(int* h_ptr, int* m_ptr, int* s_ptr, int total_seconds) {
    int remaining_seconds = total_seconds;

    *h_ptr = remaining_seconds / 3600;
    remaining_seconds %= 3600;

    *m_ptr = remaining_seconds / 60;
    *s_ptr = remaining_seconds % 60;
}

// プロンプトを表示して整数入力を受け取る関数
int get_int_input(const char* prompt) {
    int n;
    printf("%s", prompt); // 改行は不要な場合もあるので、呼び出し側で付与する
    scanf_s("%d", &n);
    return n;
}

// 時間計算のメインロジックを表示する関数
void algo6_show() {
    int h_result = 0, m_result = 0, s_result = 0; // 結果格納用変数を初期化
    int num; // ループ制御用

    int h1, m1, s1; // 1つ目の時間
    int h2, m2, s2; // 2つ目の時間
    int total_seconds1 = 0; // 1つ目の時間を秒数に変換した値
    int total_seconds2 = 0; // 2つ目の時間を秒数に変換した値
    int absolute_difference_seconds = 0; // 時間差（秒）

    while (1) {
        printf("時間計算を始めます。\n");
        printf("開始(1以上または-1以下) / 終了(0) を入力してください: "); // プロンプトをより明確に
        scanf_s("%d", &num);

        if (num == 0) {
            printf("プログラムを終了します。\n");
            break; // 0が入力されたらループを終了
        }

        printf("\n--- 1つ目の時間を入力 ---\n");
        h1 = get_int_input("h1の数値を入力してください (時): ");
        m1 = get_int_input("m1の数値を入力してください (分): ");
        s1 = get_int_input("s1の数値を入力してください (秒): ");

        printf("\n--- 2つ目の時間を入力 ---\n");
        h2 = get_int_input("h2の数値を入力してください (時): ");
        m2 = get_int_input("m2の数値を入力してください (分): ");
        s2 = get_int_input("s2の数値を入力してください (秒): ");

        // 各時間を秒数に変換
        total_seconds1 = timer_calc(h1, m1, s1);
        total_seconds2 = timer_calc(h2, m2, s2);

        // 2つの時間の差の絶対値を計算
        absolute_difference_seconds = get_absolute_time_difference(total_seconds1, total_seconds2);

        // 時間差を時、分、秒に変換
        time_get_func(&h_result, &m_result, &s_result, absolute_difference_seconds);

        printf("\n--- 計算結果 ---\n");
        printf("差分時間: %d時 %d分 %d秒\n", h_result, m_result, s_result);
        printf("\n"); // 各回の終わりに改行を入れて見やすくする
    }
}
// 弾を発射する関数
void ball_shoot(Ball* ball, Player* player, int speed) {
    // 弾が非活動中の場合のみ発射
    if (ball->isActive == 0) {
        // 弾の位置をプレイヤーの位置に設定
        ball->x = player->x;
        ball->y = player->y;
        // プレイヤーx座標から発射（真横に発射する例）
        ball->vx = speed;
        // プレイヤーy座標から発射（y方向の速度は0、つまり垂直方向には動かない）
        ball->vy = 0; // 必要に応じてspeedなどに変更
        // 弾を活動状態にする
        ball->isActive = 1;
        printf("弾を発射しました！\n");
    }
    else {
        printf("弾はすでに発射されています。\n");
    }
}

// 弾を更新する関数
void ball_update(Ball* ball) {
    if (ball->isActive) {
        ball->x += ball->vx; // x座標を速度分更新
        ball->y += ball->vy; // y座標を速度分更新

        // 画面外に出た場合は非活動状態にする
        // 仮に画面範囲をX:0-800, Y:0-600と想定
        if (ball->x < 0 || ball->x > 800 || ball->y < 0 || ball->y > 600) {
            ball->isActive = 0; // 弾を非活動状態にする
            printf("弾は画面外に出ました。\n");
        }
    }
}

// 弾の発射シミュレーションを表示する関数
void algo7_show(void) {
    // プレイヤーと弾の初期化
    Player player = { 50, 300 }; // プレイヤーの初期位置
    Ball ball = { 0, 0, 0, 0, 0 }; // 弾の初期状態（非活動）
    int speed; // 弾の速度

    while (1) {
        printf("\n----------------------------------------\n");
        printf("弾を発射するには1を入力、終了するには0を入力してください: ");
        int choice;
        // scanf_sはWindows固有のセキュリティ強化関数です。
        // Linux/macOSなどの環境ではscanfを使用してください。
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("プログラムを終了します。\n");
            break; // 0が入力されたらループを終了
        }
        else if (choice != 1) {
            printf("無効な入力です。もう一度試してください。\n");
            // 入力バッファをクリア（不正な入力が残るのを防ぐ）
            while (getchar() != '\n');
            continue; // 無効な入力の場合は再度ループ
        }

        // 弾の速度を入力
        printf("弾の速度を入力してください: ");
        scanf_s("%d", &speed);
        // 入力バッファをクリア
        while (getchar() != '\n');

        // 弾を発射
        ball_shoot(&ball, &player, speed);

        // 弾が活動状態である限り、更新を繰り返す
        if (ball.isActive) {
            printf("弾が移動中です...\n");
            int update_count = 0; // 更新回数をカウント
            while (ball.isActive) {
                ball_update(&ball);
                printf("現在の弾の位置: x = %d, y = %d\n", ball.x, ball.y);
                update_count++;

                // 例: 20回の更新ごとに一時停止して見やすくする（オプション）
                // if (update_count % 20 == 0) {
                //     printf("--- 一時停止。Enterで続行 ---");
                //     while (getchar() != '\n');
                // }

                // 非常に速く動くため、Sleep関数などで少し待機させると動きが見やすくなる
                // Sleep(50); // Windowsの場合 (50ミリ秒待機)
            }
            printf("弾の移動が終了しました（%d回更新）。\n", update_count);
        }
        else {
            // ball_shootで「弾はすでに発射されています」と表示された場合
            printf("弾は発射されませんでした。\n");
        }
    }
}
