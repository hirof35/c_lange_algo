#ifndef __FILENAME__
#define __FILENAME__
//�Ԃ̍\���̒�`�Ɗ֐��v���g�^�C�v�錾
typedef struct CAR {
    char* name;
    float gas;
} car;
// �ԍ\���̂̏������֐�
void set_car(car*, const char*, float);
// �ԍ\���̂̕\���֐�
void set_car_show(void);
// �T�[�`�ƃ\�[�g�A���S���Y���̃v���g�^�C�v�錾
// ���`�T��
int linear_search(int* ,int,int);
// �񕪒T�� (�z�񂪃\�[�g����Ă���K�v������܂�)
int binary_search(int*, int, int,int);
// �o�u���\�[�g
void bubble_sort(int*, int);
// �I���\�[�g
void selection_sort(int*, int);
// �}���\�[�g (�C���ς�)
void insert_sort(int*, int);
// �q�[�v�\�[�g�̃w���p�[�֐� (�q�[�v��)
void heapify(int*, int,int);
// �q�[�v�\�[�g
void heap_sort(int*, int);
// --- �\�[�g�A���S���Y���̃w���p�[�֐� ---
void swap(int*,int*);
// �N�C�b�N�\�[�g�̃w���p�[�֐� (����)
int partition(int*, int, int);
// �N�C�b�N�\�[�g
void quik_sort(int*, int, int);
// �}�[�W�\�[�g�̃w���p�[�֐� (�}�[�W)
void merge(int*, int, int, int);
// �}�[�W�\�[�g
void merge_sort(int*, int, int);
// --- �e�A���S���Y���̓���m�F�֐� ---
void algo_show(void);
#endif // !__FILENAME__
