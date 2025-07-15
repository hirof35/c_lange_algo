#include <stdio.h>  // printf, scanf_s�̂��߂ɕK�v
#include <stdlib.h> // abs�֐��̂��߂ɕK�v
#include"FileName2.h"
// �b���ɕϊ�����֐�
int timer_calc(int h, int m, int s) {
    return (h * 3600) + (m * 60) + s;
}

// 2�̎��ԁi�b���j�̍��̐�Βl���擾����֐�
int get_absolute_time_difference(int time1_in_seconds, int time2_in_seconds) {
    return abs(time1_in_seconds - time2_in_seconds);
}

// �b�������A���A�b�ɕϊ����A�|�C���^�Ō��ʂ�Ԃ��֐�
void time_get_func(int* h_ptr, int* m_ptr, int* s_ptr, int total_seconds) {
    int remaining_seconds = total_seconds;

    *h_ptr = remaining_seconds / 3600;
    remaining_seconds %= 3600;

    *m_ptr = remaining_seconds / 60;
    *s_ptr = remaining_seconds % 60;
}

// �v�����v�g��\�����Đ������͂��󂯎��֐�
int get_int_input(const char* prompt) {
    int n;
    printf("%s", prompt); // ���s�͕s�v�ȏꍇ������̂ŁA�Ăяo�����ŕt�^����
    scanf_s("%d", &n);
    return n;
}

// ���Ԍv�Z�̃��C�����W�b�N��\������֐�
void algo6_show() {
    int h_result = 0, m_result = 0, s_result = 0; // ���ʊi�[�p�ϐ���������
    int num; // ���[�v����p

    int h1, m1, s1; // 1�ڂ̎���
    int h2, m2, s2; // 2�ڂ̎���
    int total_seconds1 = 0; // 1�ڂ̎��Ԃ�b���ɕϊ������l
    int total_seconds2 = 0; // 2�ڂ̎��Ԃ�b���ɕϊ������l
    int absolute_difference_seconds = 0; // ���ԍ��i�b�j

    while (1) {
        printf("���Ԍv�Z���n�߂܂��B\n");
        printf("�J�n(1�ȏ�܂���-1�ȉ�) / �I��(0) ����͂��Ă�������: "); // �v�����v�g����薾�m��
        scanf_s("%d", &num);

        if (num == 0) {
            printf("�v���O�������I�����܂��B\n");
            break; // 0�����͂��ꂽ�烋�[�v���I��
        }

        printf("\n--- 1�ڂ̎��Ԃ���� ---\n");
        h1 = get_int_input("h1�̐��l����͂��Ă������� (��): ");
        m1 = get_int_input("m1�̐��l����͂��Ă������� (��): ");
        s1 = get_int_input("s1�̐��l����͂��Ă������� (�b): ");

        printf("\n--- 2�ڂ̎��Ԃ���� ---\n");
        h2 = get_int_input("h2�̐��l����͂��Ă������� (��): ");
        m2 = get_int_input("m2�̐��l����͂��Ă������� (��): ");
        s2 = get_int_input("s2�̐��l����͂��Ă������� (�b): ");

        // �e���Ԃ�b���ɕϊ�
        total_seconds1 = timer_calc(h1, m1, s1);
        total_seconds2 = timer_calc(h2, m2, s2);

        // 2�̎��Ԃ̍��̐�Βl���v�Z
        absolute_difference_seconds = get_absolute_time_difference(total_seconds1, total_seconds2);

        // ���ԍ������A���A�b�ɕϊ�
        time_get_func(&h_result, &m_result, &s_result, absolute_difference_seconds);

        printf("\n--- �v�Z���� ---\n");
        printf("��������: %d�� %d�� %d�b\n", h_result, m_result, s_result);
        printf("\n"); // �e��̏I���ɉ��s�����Č��₷������
    }
}
// �e�𔭎˂���֐�
void ball_shoot(Ball* ball, Player* player, int speed) {
    // �e���񊈓����̏ꍇ�̂ݔ���
    if (ball->isActive == 0) {
        // �e�̈ʒu���v���C���[�̈ʒu�ɐݒ�
        ball->x = player->x;
        ball->y = player->y;
        // �v���C���[x���W���甭�ˁi�^���ɔ��˂����j
        ball->vx = speed;
        // �v���C���[y���W���甭�ˁiy�����̑��x��0�A�܂萂�������ɂ͓����Ȃ��j
        ball->vy = 0; // �K�v�ɉ�����speed�ȂǂɕύX
        // �e��������Ԃɂ���
        ball->isActive = 1;
        printf("�e�𔭎˂��܂����I\n");
    }
    else {
        printf("�e�͂��łɔ��˂���Ă��܂��B\n");
    }
}

// �e���X�V����֐�
void ball_update(Ball* ball) {
    if (ball->isActive) {
        ball->x += ball->vx; // x���W�𑬓x���X�V
        ball->y += ball->vy; // y���W�𑬓x���X�V

        // ��ʊO�ɏo���ꍇ�͔񊈓���Ԃɂ���
        // ���ɉ�ʔ͈͂�X:0-800, Y:0-600�Ƒz��
        if (ball->x < 0 || ball->x > 800 || ball->y < 0 || ball->y > 600) {
            ball->isActive = 0; // �e��񊈓���Ԃɂ���
            printf("�e�͉�ʊO�ɏo�܂����B\n");
        }
    }
}

// �e�̔��˃V�~�����[�V������\������֐�
void algo7_show(void) {
    // �v���C���[�ƒe�̏�����
    Player player = { 50, 300 }; // �v���C���[�̏����ʒu
    Ball ball = { 0, 0, 0, 0, 0 }; // �e�̏�����ԁi�񊈓��j
    int speed; // �e�̑��x

    while (1) {
        printf("\n----------------------------------------\n");
        printf("�e�𔭎˂���ɂ�1����́A�I������ɂ�0����͂��Ă�������: ");
        int choice;
        // scanf_s��Windows�ŗL�̃Z�L�����e�B�����֐��ł��B
        // Linux/macOS�Ȃǂ̊��ł�scanf���g�p���Ă��������B
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("�v���O�������I�����܂��B\n");
            break; // 0�����͂��ꂽ�烋�[�v���I��
        }
        else if (choice != 1) {
            printf("�����ȓ��͂ł��B������x�����Ă��������B\n");
            // ���̓o�b�t�@���N���A�i�s���ȓ��͂��c��̂�h���j
            while (getchar() != '\n');
            continue; // �����ȓ��͂̏ꍇ�͍ēx���[�v
        }

        // �e�̑��x�����
        printf("�e�̑��x����͂��Ă�������: ");
        scanf_s("%d", &speed);
        // ���̓o�b�t�@���N���A
        while (getchar() != '\n');

        // �e�𔭎�
        ball_shoot(&ball, &player, speed);

        // �e��������Ԃł������A�X�V���J��Ԃ�
        if (ball.isActive) {
            printf("�e���ړ����ł�...\n");
            int update_count = 0; // �X�V�񐔂��J�E���g
            while (ball.isActive) {
                ball_update(&ball);
                printf("���݂̒e�̈ʒu: x = %d, y = %d\n", ball.x, ball.y);
                update_count++;

                // ��: 20��̍X�V���ƂɈꎞ��~���Č��₷������i�I�v�V�����j
                // if (update_count % 20 == 0) {
                //     printf("--- �ꎞ��~�BEnter�ő��s ---");
                //     while (getchar() != '\n');
                // }

                // ���ɑ����������߁ASleep�֐��Ȃǂŏ����ҋ@������Ɠ��������₷���Ȃ�
                // Sleep(50); // Windows�̏ꍇ (50�~���b�ҋ@)
            }
            printf("�e�̈ړ����I�����܂����i%d��X�V�j�B\n", update_count);
        }
        else {
            // ball_shoot�Łu�e�͂��łɔ��˂���Ă��܂��v�ƕ\�����ꂽ�ꍇ
            printf("�e�͔��˂���܂���ł����B\n");
        }
    }
}
