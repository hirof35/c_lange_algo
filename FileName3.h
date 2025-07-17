#ifndef __FILENAME3__
#define __FILENAME3__
#include<stdbool.h>
// マップの最大サイズ (必要に応じて調整)
#define MAX_MAP_WIDTH 100
#define MAX_MAP_HEIGHT 100
#define MAX_OPEN_LIST_SIZE (MAX_MAP_WIDTH * MAX_MAP_HEIGHT) // オープンリストの最大サイズ

struct Node {
    int x; // x座標
    int y; // y座標
    int g_cost; // g値（開始点からのコスト）
    int h_cost; // h値（ゴールまでの推定コスト）
    int f_cost; // f値（g値 + h値）
    struct Node* parent; // 親ノードへのポインタ
    // その他、状態管理フラグなど必要に応じて追加
    bool in_open_list; // オープンリストに存在するか
    bool in_close_list; // クローズリストに存在するか
};

// 全てのノードを保持する2次元配列 (ポインタの配列)
// 通常は main 関数内で動的に確保しますが、ここでは簡略化のためグローバル変数とします。
struct Node* all_nodes[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];

// マップの実際の幅と高さ (main関数で設定)
int current_map_width;
int current_map_height;

// --- 優先度付きキュー（オープンリスト）の実装 ---
// ヒープを表現するための配列
struct Node* open_list[MAX_OPEN_LIST_SIZE];
extern int open_list_size; // 現在のオープンリスト内のノード数

void push_to_open_list(struct Node*);
struct Node* pop_from_open_list(void);
bool is_open_list_empty(void); // 修正: 引数リストを明示的に void に変更
void update_node_in_open_list(struct Node*);
void algo11_show(void);

#endif
