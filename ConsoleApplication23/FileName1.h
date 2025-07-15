#ifndef __FILENAME1__
#define __FILENAME1__
// --- �O���[�o����` 
#define MAX_SIZE 10

// �X�^�b�N�̍\���̂��`
struct Stack {
    int items[MAX_SIZE]; // �X�^�b�N�̗v�f���i�[����z��
    int top;             // �X�^�b�N�̃g�b�v�������C���f�b�N�X
};

// �L���[�̍\���̂��`
struct Queue {
    int items[MAX_SIZE]; // �L���[�̗v�f���i�[����z��
    int front;           // �L���[�̐擪�������C���f�b�N�X
    int rear;            // �L���[�̖����������C���f�b�N�X
};
// --- �֐��̃v���g�^�C�v�錾 ---
// �L���[�̍쐬
struct Queue* createQueue(void);
// �L���[���󂩂ǂ����̃`�F�b�N
int isEmpty(struct Queue*);
// �v�f���L���[�ɒǉ� (enqueue)
void enqueue(struct Queue*, int);
// �v�f���L���[������o�� (dequeue)
int dequeue(struct Queue*);
// �L���[�����t���ǂ����̃`�F�b�N
int isFull(struct Queue*);
// �L���[�̃��������
void freeQueue(struct Queue*);
// �X�^�b�N�̏�����
void initialize(struct Stack*);
// �v�f���X�^�b�N�Ƀv�b�V��
void push(struct Stack*, int);
// �v�f���X�^�b�N����|�b�v
int pop(struct Stack*);
// �K��̌v�Z
int kaijou(int);
// �t�B�{�i�b�`���̌v�Z (F(1)=1, F(2)=1, F(3)=2, ... �̒�`�Ɋ�Â��Ă���)
int fibonacci(int);
// �n�m�C�̓�
void hanoi(int,char,char,char);
// --- �e�A���S���Y��/�f�[�^�\���̓���m�F�֐� ---
void algo2_show(void);
#endif