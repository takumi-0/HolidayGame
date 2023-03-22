#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define QUIZ_NUMBER 8
#define NEW_QUIZ_NUMBER 2

//=============================================
// ���炩���ߍ쐬���Ă���N�C�Y(�O���[�o���ϐ�)
//=============================================
char quiz[QUIZ_NUMBER][100] = {"11���ɏj���͉�������H", "�Q���P�P���͉��̓�", "�݂ǂ�̓��͉��������H", "�P�P���Q�R���͉����H", "�j�����Ȃ����́H", "�X�|�[�c�̓��͂P�O���̑扽���j���H", "�h�V�̓��͂X���̑扽���j���H", "�W���ɂ���j���́H"};
char option[QUIZ_NUMBER][100] = {"1:�P��  2:�Q��  3:�R��","1:�V�c�a����  2:���a�̓�  3:�����L�O�̓�", "1:�T���R��  2:�T���S��  3:�T���T��", "1:�ΘJ���ӂ̓� 2:�h�V�̓�  3:���@�L�O��",
                                 "1:�U���ƂP�Q��  2: �S���ƂP�Q�� 3:�S���ƂU��","1:��񌎗j��  2:��O���j��  3:��ꌎ�j��", "1:��񌎗j��  2:��O���j��  3:��ꌎ�j��", "1:�R�̓�  2:�C�̓�  3:�X�|�[�c�̓�"};
int answer[QUIZ_NUMBER] = {2, 3, 2, 1, 1, 1, 2, 1};

int answer_order[QUIZ_NUMBER] = {0, 1, 2, 3, 4, 5, 6, 7};

//=============================================
// �֐��v���g�^�C�v�錾
//=============================================
void shuffle_order(void);
void create_quiz(int * month, int * day);
int get_answer(int month, int day);

//=============================================
// �又��
//=============================================
int main(void){
    int yourAnswer;
    int correct_answer_count = 0;
    int month, day;
    int quiz_counter = 1;
    shuffle_order();
    system("cls");  //�^�[�~�i����ʂ��N���A (Linux�܂���macOS�̏ꍇ�́Aclrscr()��system("clear")�ɒu�������܂�)
    printf("\t�j���N�C�Y ~ �Q�O�Q�R�Nver ~  \n\n");
    Sleep(2000);
    system("cls");
    printf("\t�X�^�[�g!\n\n");
    Sleep(2000);
    system("cls");
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for (int i = 0; i < QUIZ_NUMBER; i++){
        printf("\t��%d��\n\n", quiz_counter);
        quiz_counter++;
        printf("\tQ,%s\n\n\t%s", quiz[answer_order[i]], option[answer_order[i]]);
        printf("\t\t���Ȃ��̉�:"); scanf("%d", &yourAnswer);
        if (yourAnswer == answer[answer_order[i]]){
            printf("\n\t����!\n");
            correct_answer_count++;
        }
        else{
            printf("\n\t�s����!\n");
        }
        Sleep(700);
        system("cls");
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    create_quiz(&month, &day);
    for (int j = 0; j < NEW_QUIZ_NUMBER; j++){
        printf("\t��%d��\n\n", quiz_counter);
        quiz_counter++;
        printf("\t%d��%d���͏j��(����Ɋ֌W�Ȃ��j���ł��錎���Ɍ���܂�)�H\n", month, day);
        printf("\t1:�j���ł���  2:�j���ł͂Ȃ�");
        printf("\t\t\t���Ȃ��̉�:"); scanf("%d", &yourAnswer);
        if (yourAnswer == get_answer(month, day)){
            printf("\n\t����!\n");
            correct_answer_count++;
        }
        else{
            printf("\n\t�s����!\n");
        }
        Sleep(700);
        system("cls"); 
        create_quiz(&month, &day);
        puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }

    printf("\n\n\t\t%d�⒆%d�␳�����܂����B\n\n\n", QUIZ_NUMBER + NEW_QUIZ_NUMBER, correct_answer_count);
    printf("\n\n\t\t��������%.0lf%%�ł��B\n\n", ( (double) correct_answer_count / (QUIZ_NUMBER + NEW_QUIZ_NUMBER) ) * 100);
    Sleep(3000);
    system("cls");
    if (correct_answer_count >= QUIZ_NUMBER + NEW_QUIZ_NUMBER-1){          
        printf("\n\n\n\t\t���߂łƂ��������܂��B\n\n\t\t���Ȃ���[�j���}�X�^�[]�ł��I\n\n\n\n\n\n\n\n");
    }
    else{
        printf("\n\n\n\t\t�c�O�Ȃ��炠�Ȃ���[�j���}�X�^�[]�ł͂���܂���B\n\n\n\n\n\n\n\n\n");
    }

    return 0;
}

//=============================================
// �Œ���̏��ԃV���b�t�� (�P�O�O��)
//=============================================
void shuffle_order(void){
    int random1, random2;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 100; i++){
        random1 = rand() % QUIZ_NUMBER;
        random2 = rand() % QUIZ_NUMBER;
        int temp = answer_order[random1];
        answer_order[random1] = answer_order[random2];
        answer_order[random2] = temp;
    }
    return;
}

//=============================================
// �����_�������N�C�Y(�j��or�j���ł͂Ȃ�)
//=============================================
void create_quiz(int * p_month, int * p_day){
    int month, day;
    srand((unsigned int)time(NULL));
    do{
        *p_month = rand() % 12 + 1;
        *p_day = rand() % 31 + 1;
    } while ( ( (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && (day == 31)) || (month == 2 && day >= 29) );
}

//=============================================
// �����_�������N�C�Y�̐��딻��
//=============================================
int get_answer(int month, int day){
    if ((month == 1 && day == 1) || (month == 2 && (day == 11 || day == 23)) || (month == 4 && day == 29) || (month == 5 && (day == 3 || day == 4 || day == 5)) || (month == 8 && day == 11) || (month == 11 && (day == 3 || day == 23))){
        return 1;
    }
    return 2;
}

