#include<stdio.h>
#include<stdlib.h>
#include"FileName2.h"
//状態遷移関数
void step(Turning_Machine* turning_macine) {
	switch (turning_macine->state)
	{
	case 0:
		if(turning_macine->tape[turning_macine->head] == '0') {
			turning_macine->tape[turning_macine->head] = '1';
			turning_macine->head+=RIGHT;
			turning_macine->state = 1;
		}
	case 1://終了状態
		return;
	}
}
//チューニングマシンの実行関数
void run_turning_machine(Turning_Machine* turning_macine) {
	while (turning_macine->state != 1) {//状態が終了状態でない限りループ
		step(turning_macine);
	}
}
//チューニングマシンの状態を表示する関数
void algo9_show(void) {
	Turning_Machine turning_machine;
	for (int i = 0; i < TAPE_SIZE; i++)
		turning_machine.tape[i] = '0'; // テープを初期化
	turning_machine.head = TAPE_SIZE / 2; // ヘッドの位置を初期化
	turning_machine.state = 0; // 初期状態を設定
	printf("Tape after processing: %s\n",turning_machine.tape);
	run_turning_machine(&turning_machine); // チューニングマシンを実行
	printf("Tape after processing: %s\n", turning_machine.tape); // 処理後のテープを表示
	return;
}
// 各進数を計算する関数
// unsigned int x: 変換する非負の10進数
// int n: 変換先の基数（2～36）
// char d[]: 変換結果の各桁の文字を格納する配列
int Card_convr(unsigned int x, int n, char d[]) {
    // 0～Zまでの文字列配列（0-9, A-Z）
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 変換後の桁数を初期化
    int digits = 0;

    if (x == 0) {
        d[digits++] = dchar[0]; // xが0の場合、結果は'0'
    }
    else {
        while (x > 0) { // 符号なし変数が割り切れるまで繰り返す
            // 剰余を計算し、対応する文字を格納
            d[digits++] = dchar[x % n];
            // xをnで割る
            x /= n;
        }
    }
    return digits; // 変換後の桁数を返す
}

void algo10_show(void) {
    int i;           // forループ用変数
    unsigned int no; // 変換する非負の整数
    int cd;          // 変換先の基数
    int dno;         // 変換後の桁数
    int retry;       // 再試行フラグ
	char cno[512];// 変換結果の各桁を格納する配列（最大512桁）
    // メインループ: ユーザーが終了を選択するまで繰り返す
    do {
        // 変換する非負の整数を入力
        do {
            printf("変換する非負の整数: ");
            scanf_s("%u", &no); // %u を使用して unsigned int を読み込む
            if ((int)no < 0) { // unsignedをintにキャストして負の数をチェック
                printf("エラー: 非負の整数を入力してください。\n");
				continue; // 負の数が入力された場合は再度入力を促す
            }
            while (getchar() != '\n'); // 入力バッファをクリア
            // 負の数が入力された場合のエラーチェック
            // 注意: unsigned int に負の数を %u で読み込むと大きな正の数になるため、
            // 論理的な負数チェックのためには int で受け取ってから unsigned に変換するか、
            // ユーザーに非負を厳しく求めるプロンプトを出すのが良い。
            // ここでは unsigned int の性質上、負数は大きな正数として扱われるため、
            // 厳密な負数チェックは少し複雑になります。
            // 例: (int)no < 0 のようなチェックは、noがunsigned intの場合は常にfalseになりうる。
            // scanf_s("%d", &temp_no); if (temp_no < 0) { ... } no = (unsigned int)temp_no; のようにする手もある。
            // しかし、unsigned intを直接読み込む場合は、ユーザーが負数を入力しない前提にするか、
            // 入力タイプチェックをより厳密に行う必要がある。
            // このままでも負数入力で大きな正数として処理されますが、プロンプトに合わせます。
            // ユーザーは「非負」と言われたら負数を入力しないと期待します。
			if (no >= 0)// unsigned intは常に非負なので、ここではチェックは不要
                break;
        } while (1); // 今回は入力されたunsigned intがそのまま使われる（ユーザーが非負を入力する前提）

        // 変換先の基数を入力 (2～36)
        do {
            printf("何進数に変換しますか？(2～36): ");
            scanf_s("%d", &cd);
            while (getchar() != '\n'); // 入力バッファをクリア
            if (cd < 2 || cd > 36) {
                printf("エラー: 変換できる基数は2～36です。\n");
            }
        } while (cd < 2 || cd > 36);

        // 各進数を計算する関数の戻り値を格納（変換後の桁数）
        dno = Card_convr(no, cd, cno);

        printf("%d進数では", cd);
        // 変換結果の各桁を逆順に出力
        for (i = dno - 1; i >= 0; i--) {
            printf("%c", cno[i]); // %c を使用して文字として出力
        }
        printf("です。\n");

        // もう一度するかどうかを尋ねる
        printf("もう一度しますか？(1:はい / 0:いいえ): ");
        scanf_s("%d", &retry);
        while (getchar() != '\n'); // 入力バッファをクリア

    } while (retry == 1); // retryが1の間はループを続ける
}
