#include<stdio.h>
#include <stdlib.h> // malloc, free, qsort
#include <limits.h> // INT_MAX
#include"FileName3.h"
int open_list_size = 0;
// --- ヒューリスティック関数 (例: マンハッタン距離) ---
int calculate_heuristic(struct Node* current, struct Node* target) {
    return abs(current->x - target->x) + abs(current->y - target->y);
}

// --- メインのA*探索関数 ---
struct Node* a_star_search(struct Node* start_node, struct Node* target_node, int map_width, int map_height) {
    // 全ノードの初期化 (必要に応じて動的確保または2次元配列など)
    // この例では、Nodeポインタの2次元配列とします
    struct Node*** all_nodes = (struct Node***)malloc(map_height * sizeof(struct Node**));
    for (int i = 0; i < map_height; i++) {
        all_nodes[i] = (struct Node**)malloc(map_width * sizeof(struct Node*));
        for (int j = 0; j < map_width; j++) {
            all_nodes[i][j] = (struct Node*)malloc(sizeof(struct Node));
            all_nodes[i][j]->x = j;
            all_nodes[i][j]->y = i;
            all_nodes[i][j]->g_cost = INT_MAX; // 初期値は無限大
            all_nodes[i][j]->h_cost = 0;
            all_nodes[i][j]->f_cost = INT_MAX;
            all_nodes[i][j]->parent = NULL;
            all_nodes[i][j]->in_open_list = false;
            all_nodes[i][j]->in_close_list = false;
            // 障害物の情報などもここで初期化
        }
    }

    // スタートノードの初期設定
    struct Node* current_start_node = all_nodes[start_node->y][start_node->x];
    current_start_node->g_cost = 0;
    current_start_node->h_cost = calculate_heuristic(current_start_node, target_node);
    current_start_node->f_cost = current_start_node->g_cost + current_start_node->h_cost;

    push_to_open_list(current_start_node);
    current_start_node->in_open_list = true;

    while (!is_open_list_empty()) {
        struct Node* current = pop_from_open_list();
        current->in_close_list = true; // クローズドリストに追加

        // 目標ノードに到達したら終了
        if (current->x == target_node->x && current->y == target_node->y) {
            // ここでメモリ解放などの後処理を行う
            return current; // 目標ノードへのポインタを返す
        }

        // 隣接ノードの探索 (上下左右、斜めなども考慮するなら追加)
        int dx[] = { 0, 0, 1, -1 }; // 上下左右
        int dy[] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int neighbor_x = current->x + dx[i];
            int neighbor_y = current->y + dy[i];

            // マップの範囲内かチェック
            if (neighbor_x >= 0 && neighbor_x < map_width &&
                neighbor_y >= 0 && neighbor_y < map_height) {

                struct  Node* neighbor = all_nodes[neighbor_y][neighbor_x];

                // 障害物の場合や既にクローズドリストにある場合はスキップ
                // if (neighbor->is_obstacle || neighbor->in_close_list) {
                if (neighbor->in_close_list) { // 障害物判定は別途追加
                    continue;
                }

                int tentative_g_cost = current->g_cost + 1; // 隣接ノードへのコスト (1マス移動を1とする)

                // より良い経路が見つかった場合
                if (tentative_g_cost < neighbor->g_cost) {
                    neighbor->parent = current;
                    neighbor->g_cost = tentative_g_cost;
                    neighbor->h_cost = calculate_heuristic(neighbor, target_node);
                    neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                    if (!neighbor->in_open_list) {
                        push_to_open_list(neighbor);
                        neighbor->in_open_list = true;
                    }
                    else {
                        // オープンリスト内で更新 (優先度付きキューの実装による)
                        update_node_in_open_list(neighbor);
                    }
                }
            }
        }
    }

    // 経路が見つからなかった場合
    // メモリ解放などの後処理を行う
    return NULL;
}

// --- 経路再構築の関数 (例) ---
void reconstruct_path(struct Node* target_node) {
    if (target_node == NULL) {
        printf("経路が見つかりませんでした。\n");
        return;
    }

   struct Node* current = target_node;
    // スタックなどを使って逆順に経路を保存し、後で出力すると良い
    // ここでは単純に親を辿って出力
    printf("経路 (逆順):\n");
    while (current != NULL) {
        printf("(%d, %d) <- ", current->x, current->y);
        current = current->parent;
    }
    printf("START\n");
}
// --- ヘルパー関数: 子ノードのインデックスを取得 ---
static int get_left_child_idx(int parent_idx) {
    return 2 * parent_idx + 1;
}

static int get_right_child_idx(int parent_idx) {
    return 2 * parent_idx + 2;
}

// --- ヘルパー関数: 親ノードのインデックスを取得 ---
static int get_parent_idx(int child_idx) {
    return (child_idx - 1) / 2;
}

// --- ヒープ構造を上方向に調整 (追加または更新時) ---
// ノードがその親よりもF値が小さい場合、上に移動させる
void heapify_up(int idx) {
    while (idx > 0 && open_list[get_parent_idx(idx)]->f_cost > open_list[idx]->f_cost) {
        // 親と子をスワップ
       struct Node* temp = open_list[idx];
        open_list[idx] = open_list[get_parent_idx(idx)];
        open_list[get_parent_idx(idx)] = temp;
        idx = get_parent_idx(idx);
    }
}

// --- ヒープ構造を下方向に調整 (要素削除時) ---
// ノードがその子よりもF値が大きい場合、下に移動させる
void heapify_down(int idx) {
    int smallest = idx;
    int left_child_idx = get_left_child_idx(idx);
    int right_child_idx = get_right_child_idx(idx);

    // 左の子と比較
    if (left_child_idx < open_list_size &&
        open_list[left_child_idx]->f_cost < open_list[smallest]->f_cost) {
        smallest = left_child_idx;
    }

    // 右の子と比較
    if (right_child_idx < open_list_size &&
        open_list[right_child_idx]->f_cost < open_list[smallest]->f_cost) {
        smallest = right_child_idx;
    }

    // 最小値が現在のノードでなければスワップして再帰的に呼び出し
    if (smallest != idx) {
        struct Node* temp = open_list[idx];
        open_list[idx] = open_list[smallest];
        open_list[smallest] = temp;
        heapify_down(smallest);
    }
}

// --- オープンリストにノードを追加 (push_to_open_list) ---
void push_to_open_list(struct Node* node) {
    if (open_list_size >= MAX_OPEN_LIST_SIZE) {
        fprintf(stderr, "Error: Open list is full!\n");
        return;
    }
    open_list[open_list_size] = node;
    node->in_open_list = true;
    heapify_up(open_list_size); // 新しく追加したノードを適切な位置に調整
    open_list_size++;
}

// --- オープンリストから最小F値のノードを取り出す (pop_from_open_list) ---
struct Node* pop_from_open_list() {
    if (open_list_size == 0) {
        return NULL; // オープンリストが空
    }

    struct Node* min_node = open_list[0]; // ルートノードが最小
    min_node->in_open_list = false; // オープンリストから取り除くのでフラグをfalseに

    open_list_size--;
    if (open_list_size > 0) {
        open_list[0] = open_list[open_list_size]; // 末尾の要素をルートに移動
        heapify_down(0); // 新しいルートノードを適切な位置に調整
    }
    return min_node;
}

// --- オープンリストが空かどうかを判定 (is_open_list_empty) ---
bool is_open_list_empty() {
    return open_list_size == 0;
}

// --- オープンリスト内のノードを更新 (update_node_in_open_list) ---
// ノードのg_costが改善され、f_costが変わった場合に使用
// ヒープ内の既存のノードを直接探して、heapify_upで調整します。
// F値が小さくなる方向にしか調整しないため、g_costが大きくなる方向への変更には対応しません。
void update_node_in_open_list(struct Node* node) {
    // ノードがオープンリスト内に存在することを確認
    if (!node->in_open_list) {
        return; // オープンリストにないノードは更新できません
    }

    // 対象ノードがオープンリスト内のどこにあるかを探す
    // 本来はノード構造体にヒープ内のインデックスを保持させると効率的ですが、
    // ここでは簡易的に線形探索します。
    int i;
    for (i = 0; i < open_list_size; i++) {
        if (open_list[i] == node) {
            break;
        }
    }

    if (i < open_list_size) { // ノードが見つかった
        // g_costが改善された場合、f_costも小さくなるのでheapify_upで調整
        heapify_up(i);
        // もしg_costが改善されず、f_costが大きくなった場合（A*では通常発生しないが）、
        // その場合はheapify_downも考慮する必要がある。
        // 一般的なA*の実装では、f_costが小さくなる更新しか発生しないため、heapify_upのみで十分。
    }
}
// --- メモリ解放関数 ---
void cleanup_nodes(int map_width, int map_height) {
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (all_nodes[i][j] != NULL) {
                free(all_nodes[i][j]);
                all_nodes[i][j] = NULL;
            }
        }
    }
}
void algo11_show(void) {
    int map_width = 10;
    int map_height = 10;

    // マップの初期化 (今回は障害物なしの簡単なマップ)
    // 実際には、int map_grid[HEIGHT][WIDTH]のような配列で障害物を定義できます
    // 例えば、map_grid[y][x] == 1 が壁、0 が通路など

    // スタートとゴールノードの作成 (単なる座標情報)
   struct Node start_pos = { 0, 0 };
   struct Node target_pos = { 9, 9 };

    // A*探索の実行
   struct Node* result_node = a_star_search(&start_pos, &target_pos, map_width, map_height);

    // 経路の表示
    reconstruct_path(result_node);

    // メモリの解放
    cleanup_nodes(map_width, map_height);
}
