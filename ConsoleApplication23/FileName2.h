#ifndef __FILENAME2__
#define __FILENAME2__
//MAXの定義
#define MAX 5
//プレイヤー構造体の定義
typedef struct {
	int x;//x座標
	int y;//y座標
}Player;
//弾構造体の定義
typedef struct {
	int x;//x座標
	int y;//y座標
	int vx;//x方向の速度
	int vy;//y方向の速度
	int isActive;//弾が有効かどうかのフラグ（1:有効、0:無効）
}Ball;

//人の構造体の定義
struct Person {
	char name[32];
	int age;
};
typedef struct {
	char tape[TAPE_SIZE];
	int head; // テープのヘッド位置
	int state; // 現在の状態
}Turning_Machine;
//関数のプロトタイプ宣言
// n までの素数をすべて表示します。
int sosuu_func1(int);
// 指定された数 num が素数であるか判定し、結果の文字列を返します。
char* sosuu_hantei(int);
// --- メインの操作インターフェース関数 ---
void algo3_show(void);
//配列の最大値と最小値を求める関数のプロトタイプ宣言
int max_num(int*,int);
int min_num(int*,int);
//配列の最大値と最小値を求める関数の表示関数
void algo4_show(void);
//当たり判定の関数のプロトタイプ宣言
//短形同士の当たり判定
float rectcheckColision(float, float, float, float, float, float, float, float);
//円同士の当たり判定
float circlecheckColision(float, float, float, float, float,float);
//三角形同士の当たり判定
float trianglecheckColision(float, float, float, float, float, float, float, float);
//各種当たり判定の関数の表示関数
void algo5_show(void);
//時間差アルゴリズムの関数のプロトタイプ宣言
// 秒数に変換する関数
int timer_calc(int, int, int);
// 2つの時間（秒数）の差の絶対値を取得する関数
int get_absolute_time_difference(int, int);
// 秒数を時、分、秒に変換し、ポインタで結果を返す関数
void time_get_func(int* , int*, int*, int);
// プロンプトを表示して整数入力を受け取る関数
int get_int_input(const char*);
//時間差アルゴリズムの関数の表示関数
void algo6_show(void);
//弾を発射する関数のプロトタイプ宣言
//弾を発射する関数
void ball_shoot(Ball*, Player*, int);
//弾を更新する関数
void ball_update(Ball*);
//弾の発射を表示する関数
void algo7_show(void);
//ジャンプの関数のプロトタイプ宣言
//プレイヤーの初期化関数
void jump_player_init(Jump_Player*,int,int,int,int);
//プレイヤーのジャンプ関数
void jump_player_jump(Jump_Player*);
//プレイヤーの更新関数
void jump_player_update(Jump_Player*);
//プレイヤーの現在を表示する関数
void display_jump_player(Jump_Player*);
//プレイヤーのジャンプを表示する関数
void algo8_show(void);
//チューニングマシンの関数のプロトタイプ宣言
//状態遷移関数
void step(Turning_Machine*);
//チューニングマシンの実行関数
void run_turning_machine(Turning_Machine*);
//チューニングマシンの状態を表示する関数
void algo9_show(void);
//進数アルゴリズム関数のプロトタイプ宣言
//各進数を計算する関数
int Card_convr(unsigned x, int n, char d[]);
//各進数を表示する関数
void algo10_show(void);
#endif
