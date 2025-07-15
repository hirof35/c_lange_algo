#include <stdio.h>
// #include "FileName2.h" // �K�v�ɉ�����FileName2.h�̓��e�������Ɋ܂߂邩�A�ʓr�쐬
#include <math.h> // sqrt�֐����g�p����ꍇ�ɕK�v (�����ł͎g�p�����Aj*j <= i�ő��)

// --- �f����\������֐� ---
// n �܂ł̑f�������ׂĕ\�����܂��B
void sosuu_func1(int n) {
    if (n < 2) {
        printf("�f����2�ȏ�ł��B\n");
        return;
    }
    printf("2����%d�܂ł̑f��:\n", n);
    for (int i = 2; i <= n; ++i) {
        int is_prime = 1; // �f���ł���Ɖ���

        // i �̖񐔂��`�F�b�N�Bj*j <= i �Ō�����
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = 0; // �񐔂����������̂őf���ł͂Ȃ�
                break;
            }
        }
        if (is_prime == 1) { // is_prime �� 0 �ɂȂ�Ȃ������ꍇ�A�f��
            printf("%d\n", i);
        }
    }
}

// --- �f��������s���֐� ---
// �w�肳�ꂽ�� num ���f���ł��邩���肵�A���ʂ̕������Ԃ��܂��B
char* sosuu_hantei(int num) {
    if (num < 2) { // 2�����̐��͑f���ł͂Ȃ�
        return "�f���ł͂���܂���B";
    }
    // �񐔂��`�F�b�N�Bj*j <= num �Ō�����
    for (int j = 2; j * j <= num; ++j) {
        if (num % j == 0) {
            return "�f���ł͂���܂���B"; // �񐔂����������̂őf���ł͂Ȃ�
        }
    }
    return "�f���ł��B"; // �񐔂�������Ȃ������ꍇ�A�f��
}

// --- ���C���̑���C���^�[�t�F�[�X�֐� ---
void algo3_show(void) {
    while (1) {
        printf("�f���v���O�����ł��B\n");
        printf("�I������ꍇ��0����͂��Ă��������B\n");
        printf("�f����\�����邩(1�����)�A�f��������s���܂���(2�����)�H\n");
        int choice; // s �� choice �ɕύX
        // scanf_s �̓T�C�Y�������K�v�ȏꍇ������܂����Aint �̏ꍇ�͕s�v�ł�
        if (scanf_s("%d", &choice) != 1) {
            printf("�����ȓ��͂ł��B�I�����܂��B\n");
            // ���̓o�b�t�@���N���A�i�s���ȓ��͂��c��Ȃ��悤�Ɂj
            while (getchar() != '\n');
            return;
        }

        switch (choice) {
        case 1: { // case 1 �̃X�R�[�v
            printf("�\������f���̍ő�l����͂��Ă��������B\n");
            int n_max; // n �� n_max �ɕύX
            if (scanf_s("%d", &n_max) != 1) {
                printf("�����ȓ��͂ł��B\n");
                while (getchar() != '\n');
                break; // ����case�𔲂���
            }
            sosuu_func1(n_max);
            break;
        }
        case 2: { // case 2 �̃X�R�[�v
            printf("�f��������s���܂��B\n");
            printf("���肷�鐔����͂��Ă��������B\n");
            int num_to_check; // m �� num_to_check �ɕύX
            if (scanf_s("%d", &num_to_check) != 1) {
                printf("�����ȓ��͂ł��B\n");
                while (getchar() != '\n');
                break; // ����case�𔲂���
            }
            char* result = sosuu_hantei(num_to_check);
            printf("%d��%s\n", num_to_check, result);
            break;
        }
        case 0: // 0 ����͂ŏI��
            printf("�I�����܂��B\n");
            return;
        default:
            printf("�����ȑI���ł��B������x���͂��Ă��������B\n");
            break;
        }
        printf("\n"); // �e����̌�ɉ��s�����Č��₷������
    }
}