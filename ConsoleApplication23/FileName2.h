#ifndef __FILENAME2__
#define __FILENAME2__
//MAX�̒�`
#define MAX 5
//�v���C���[�\���̂̒�`
typedef struct {
	int x;//x���W
	int y;//y���W
}Player;
//�e�\���̂̒�`
typedef struct {
	int x;//x���W
	int y;//y���W
	int vx;//x�����̑��x
	int vy;//y�����̑��x
	int isActive;//�e���L�����ǂ����̃t���O�i1:�L���A0:�����j
}Ball;

//�l�̍\���̂̒�`
struct Person {
	char name[32];
	int age;
};
//�֐��̃v���g�^�C�v�錾
// n �܂ł̑f�������ׂĕ\�����܂��B
int sosuu_func1(int);
// �w�肳�ꂽ�� num ���f���ł��邩���肵�A���ʂ̕������Ԃ��܂��B
char* sosuu_hantei(int);
// --- ���C���̑���C���^�[�t�F�[�X�֐� ---
void algo3_show(void);
//�z��̍ő�l�ƍŏ��l�����߂�֐��̃v���g�^�C�v�錾
int max_num(int*,int);
int min_num(int*,int);
//�z��̍ő�l�ƍŏ��l�����߂�֐��̕\���֐�
void algo4_show(void);
//�����蔻��̊֐��̃v���g�^�C�v�錾
//�Z�`���m�̓����蔻��
float rectcheckColision(float, float, float, float, float, float, float, float);
//�~���m�̓����蔻��
float circlecheckColision(float, float, float, float, float,float);
//�O�p�`���m�̓����蔻��
float trianglecheckColision(float, float, float, float, float, float, float, float);
//�e�퓖���蔻��̊֐��̕\���֐�
void algo5_show(void);
//���ԍ��A���S���Y���̊֐��̃v���g�^�C�v�錾
// �b���ɕϊ�����֐�
int timer_calc(int, int, int);
// 2�̎��ԁi�b���j�̍��̐�Βl���擾����֐�
int get_absolute_time_difference(int, int);
// �b�������A���A�b�ɕϊ����A�|�C���^�Ō��ʂ�Ԃ��֐�
void time_get_func(int* , int*, int*, int);
// �v�����v�g��\�����Đ������͂��󂯎��֐�
int get_int_input(const char*);
//���ԍ��A���S���Y���̊֐��̕\���֐�
void algo6_show(void);
//�e�𔭎˂���֐��̃v���g�^�C�v�錾
//�e�𔭎˂���֐�
void ball_shoot(Ball*, Player*, int);
//�e���X�V����֐�
void ball_update(Ball*);
//�e�̔��˂�\������֐�
void algo7_show(void);
#endif