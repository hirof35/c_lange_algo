#include <stdio.h> // printf�̂��߂ɕK�v
#include<math.h>
#include "FileName2.h"


// �ő�l�𐳂���������֐�
int max_num(int* arr, int len) {
    if (len <= 0) {
        // �G���[�n���h�����O: �z�񂪋�܂��͖����ȏꍇ
        fprintf(stderr, "Error: Array length must be positive in max function.\n");
        return -1; // �܂��͓K�؂ȃG���[�l
    }

    int maxValue = arr[0]; // �ŏ��̗v�f�������̍ő�l�Ƃ���
    for (int i = 1; i < len; i++) { // 2�Ԗڂ̗v�f�����r���J�n
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// �ŏ��l�𐳂���������֐�
int min_num(int* arr, int len) {
    if (len <= 0) {
        // �G���[�n���h�����O: �z�񂪋�܂��͖����ȏꍇ
        fprintf(stderr, "Error: Array length must be positive in min function.\n");
        return -1; // �܂��͓K�؂ȃG���[�l
    }

    int minValue = arr[0]; // �ŏ��̗v�f�������̍ŏ��l�Ƃ���
    for (int i = 1; i < len; i++) { // 2�Ԗڂ̗v�f�����r���J�n
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

void algo4_show(void) {
    struct Person person[] = { {"hiro", 41}, {"sin", 40}, {"koki", 21}, {"tomo", 45}, {"yuko", 23} };

    // �N������i�[����z����쐬
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
    printf("%d\n", max_num(ages, MAX)); // ages�z���max�֐��ɓn��

    printf("--- Min Age ---\n"); // min�֐����g�p���Ă݂�
    printf("%d\n", min_num(ages, MAX));
}
//�Z�^�̏Փ˔���֐�
float rectcheckColision(float x1, float y1, float x2, float y2, float w1, float h1, float w2, float h2) {
    // ��`�̏Փ˔���
    return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
}
//�~�^�̏Փ˔���֐�
float circlecheckColision(float x1,float y1,float x2,float y2,float r1,float r2) {
	// �~�̏Փ˔���
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) < r1*r2;
}
//�O�p�`�̏Փ˔���֐�
float trianglecheckColision(float x1, float y1, float x2, float y2, float h1, float w1, float h2, float w2) {
    // �O�p�`�̏Փ˔���i�O�ڋ�`��p�����ȈՔ���j
    // w1, h1�͍ŏ��̎O�p�`�̊O�ڋ�`�̕��ƍ���
    // w2, h2��2�Ԗڂ̎O�p�`�̊O�ڋ�`�̕��ƍ���
    // c�͂����ł͎g���Ă��܂���i�R�����g�A�E�g���邩�폜�𐄏��j
    return !(x1 + w1 < x2 || x2 + w2 < x1 || y1 + h1 < y2 || y2 + h2 < y1);
    // ���̃R�[�h�ɂ����� && (y1 - y2) * (x1 - x2) > c * (x1 - x2) * (y1 - y2) �́A
    // �O�p�`�̏Փ˔���Ƃ��ĈӖ����Ȃ��Ȃ����ߍ폜�܂��͏C�����K�v�ł��B
    // ����͊ȈՓI�ȋ�`����݂̂ɂ��܂����B
}


void algo5_show(void) {
        int num;
        float x1, y1, x2, y2, w1, h1, w2, h2, c, r1,r2; // `c`�͎O�p�`�̊֐��Ŏg���܂��񂪁A����͎c���Ă����܂�

        while (1) {
            printf("������e�퓖���蔻��̌v�Z���s���܂��B\n");
            printf("(1)�Z�`�i��`�j�̓����蔻�� (2)�~�`�̓����蔻�� (3)�O�p�`�̓����蔻�� (0)�I��\n"); // ���j���[�\�����C��
            printf("�I�����Ă�������: "); // ���̓v�����v�g��ǉ�
            scanf_s("%d", &num);

            switch (num) {
            case 1:
                printf("�Z�`�i��`�j�̓����蔻����s���܂��B\n");
                printf("��ڂ̋�`�̍���X���W����͂��Ă�������: ");
                scanf_s("%f", &x1);
                printf("��ڂ̋�`�̍���Y���W����͂��Ă�������: ");
                scanf_s("%f", &y1);
                printf("��ڂ̋�`�̕�����͂��Ă�������: ");
                scanf_s("%f", &w1);
                printf("��ڂ̋�`�̍�������͂��Ă�������: ");
                scanf_s("%f", &h1);

                printf("��ڂ̋�`�̍���X���W����͂��Ă�������: ");
                scanf_s("%f", &x2);
                printf("��ڂ̋�`�̍���Y���W����͂��Ă�������: ");
                scanf_s("%f", &y2);
                printf("��ڂ̋�`�̕�����͂��Ă�������: ");
                scanf_s("%f", &w2);
                printf("��ڂ̋�`�̍�������͂��Ă�������: ");
                scanf_s("%f", &h2);

                if (rectcheckColision(x1, y1, x2, y2, w1, h1, w2, h2)) {
                    printf("�Փ˂��Ă��܂��B\n");
                }
                else {
                    printf("�Փ˂��Ă��܂���B\n");
                }
                break;
            case 2:
                printf("�~�`�̓����蔻����s���܂��B\n");
                printf("�_��X���W����͂��Ă�������: "); // �R�����g�ɍ��킹�Đ������C��
                scanf_s("%f", &x1);
                printf("�_��Y���W����͂��Ă�������: ");
                scanf_s("%f", &y1);
                printf("�~�̒��SX���W����͂��Ă�������: ");
                scanf_s("%f", &x2);
                printf("�~�̒��SY���W����͂��Ă�������: ");
                scanf_s("%f", &y2);
                printf("�~1�̔��a����͂��Ă�������: ");
                scanf_s("%f", &r1);
                printf("�~2�̔��a����͂��Ă�������: ");
                scanf_s("%f", &r2);

                if (circlecheckColision(x1, y1, x2, y2, r1,r2)) {
                    printf("�Փ˂��Ă��܂��B\n");
                }
                else {
                    printf("�Փ˂��Ă��܂���B\n");
                }
                break;
            case 3:
                printf("�O�p�`�̓����蔻����s���܂��i�O�ڋ�`�ɂ��ȈՔ���j�B\n"); // �������C��
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍���X���W����͂��Ă�������: "); // �������C��
                scanf_s("%f", &x1);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍���Y���W����͂��Ă�������: "); // �������C��
                scanf_s("%f", &y1);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̕�����͂��Ă�������: "); // �������C��
                scanf_s("%f", &w1);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍�������͂��Ă�������: "); // �������C��
                scanf_s("%f", &h1);

                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍���X���W����͂��Ă�������: "); // �������C��
                scanf_s("%f", &x2);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍���Y���W����͂��Ă�������: "); // �������C��
                scanf_s("%f", &y2);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̕�����͂��Ă�������: "); // �������C��
                scanf_s("%f", &w2);
                printf("��ڂ̎O�p�`�̊O�ڋ�`�̍�������͂��Ă�������: "); // �������C��
                scanf_s("%f", &h2);
                // `c` �͂��̊֐��ł͎g���Ȃ��̂ŁA���͕͂s�v�ł����A���̃R�[�h�ɍ��킹�Ďc���ꍇ�͈ȉ��̂悤�ɂ��܂��B
                // printf("c����͂��Ă��������i���̊ȈՔ���ł͎g�p����܂���j: ");
                // scanf_s("%f", &c);

                if (trianglecheckColision(x1, y1, x2, y2, w1, h1, w2, h2)) {
                    printf("�Փ˂��Ă��܂��B\n");
                }
                else {
                    printf("�Փ˂��Ă��܂���B\n");
                }
                break;
            case 0:
                printf("�v���O�������I�����܂��B\n");
                goto end_loop; // ���[�v�𔲂��邽�߂�goto
            default:
                printf("�����ȑI���ł��B0����3�̊Ԃ̐�������͂��Ă��������B\n");
                break;
            }
            printf("\n"); // �e����̌�ɉ��s��ǉ����Č��₷������
        }
    end_loop:; // goto�̃^�[�Q�b�g
 }
