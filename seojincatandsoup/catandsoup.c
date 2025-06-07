#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main(void) {
    int soup = 0, relationship = 2, foot, cat = 1, a, cp = 0, mood = 3,
        scratcher = 0, tower = 0, mouse = 0, lazer = 0, up, down;
    printf("         /\\_/\\   \n");
    printf("   /\\   / o o \\  \n");
    printf("  //\\\\  \\~(*)~/  \n");
    printf("  `   \\/   ^ /   \n");
    printf("      |  \\|| ||  \n");
    printf("      \\  '|| ||  \n");
    printf("       \\) ()-()) \n");
    printf("�߿����� �̸��� �˶��Դϴ�.\n");

    Sleep(1000); //1�ʴ��
    system("cls");

    srand((unsigned int)time(NULL));

    while (1) {
        int dice = rand() % 6 + 1;

        printf("==================== �������===================\n");
        printf("������� ���� ����: %d��\n", soup);
        printf("CP: %d ����Ʈ\n", cp);
        printf("�˶����� ���(0~3): %d\n", mood);

        switch (mood) {
        case 0:
            printf("����� �ſ� ���޴ϴ�.\n");
            break;
        case 1:
            printf("�ɽ����մϴ�.\n");
            break;
        case 2:
            printf("�Ļ��� �����ϴ�.\n");
            break;
        case 3:
            printf("������ �θ��ϴ�.\n");
            break;
        }

        printf("������� ����(0~4): %d\n", relationship);
        switch (relationship) {
        case 0:
            printf("�翡 ���°����� �Ⱦ��մϴ�.\n");
            break;
        case 1:
            printf("���� ���Ǳ� ����Դϴ�.\n");
            break;
        case 2:
            printf("�׷����� ������ �����Դϴ�.\n");
            break;
        case 3:
            printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
            break;
        case 4:
            printf("���� ������ �Դϴ�.\n");
            break;
        }
        printf("==================================================\n");

        Sleep(500); //0.5�ʴ��

        foot = cat;

        printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", relationship, 6 - relationship);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        printf("%d��(��) ���Խ��ϴ�.\n", dice);

        if (dice <= 6 - relationship) {
            printf("�˶��� ����� �������ϴ�: ");
            if (mood > 0) {
                mood--;
                printf("%d->%d\n", mood + 1, mood);
            }
            else
                printf("0->0\n");
        }

        switch (mood) {
        case 0:
            printf("����� �ſ쳪�� �˶���(��) ���������մϴ�.\n");
            cat--;
            break;
        case 1:
            printf("�˶���(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
            if (scratcher != 0 && tower != 0) {
                if (cat != scratcher && cat != tower) {
                    if (cat - scratcher > 0 && cat - tower > 0)
                        cat--;
                    else if (cat - scratcher < 0 && cat - tower < 0)
                        cat++;
                    else {
                        if (tower > scratcher) {
                            up = tower;
                            down = scratcher;
                        }
                        else {
                            up = scratcher;
                            down = tower;
                        }

                        up = up - cat;
                        down = cat - down;

                        if (up > down)
                            cat++;
                        else if (down > up)
                            cat--;
                        else
                            cat++;
                    }
                }

            }
            else if (tower != 0) {
                if (cat > tower)
                    cat--;
                else if (cat < tower)
                    cat++;
                printf("�˶���(��) �ɽ��ؼ� Ÿ�������� �̵��մϴ�.\n");
            }
            else if (scratcher != 0) {
                if (cat > scratcher)
                    cat--;
                else if (cat < scratcher)
                    cat++;
                printf("�˶���(��) �ɽ��ؼ� ��ũ��ó������ �̵��մϴ�.\n");
            }
            else {
                printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0)
                    mood--;
            }
            break;
        case 2:
            printf("�˶���(��) ������� �Ļ��� �����ֽ��ϴ�.\n");
            break;
        case 3:
            printf("�˶���(��) ������ �θ��� ������ ���鷯���ϴ�.\n");
            cat++;
            break;
        }

        if (cat == BWL_PO) {
            soup++;
            dice = rand() % 3 + 1;
            switch (dice) {
            case 1:
                printf("�˶��� ���ڼ����� ��������ϴ�.\n");
                break;
            case 2:
                printf("�˶��� ����̼����� ��������ϴ�,\n");
                break;
            case 3:
                printf("�˶��� ����ݸ������� ��������ϴ�.\n");
                break;
            }
            printf("������� ���� ����: %d\n", soup);
        }

        if (cat == HME_POS) {
            printf("�˶��� �ڽ��� ������ ������� �����ϴ�.\n");
        }

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0 || i == ROOM_WIDTH - 1) {
                printf("#");
            }
            else if (i == 1) {
                printf("H");
            }
            else if (i == BWL_PO) {
                printf("B");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0 || i == ROOM_WIDTH - 1) {
                printf("#");
            }
            else if (i == cat) {
                printf("C");
            }
            else if (i == foot) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }
        printf("\n");

        Sleep(500); //0.5�ʴ��

        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ����   1. �ܾ��ֱ�\n>> ");
        scanf_s("%d", &a);

        while (a != 0 && a != 1) {
            printf(">>");
            scanf_s("%d", &a);
        }

        switch (a) {
        case 0:
            printf("�ƹ��͵� ���� ����\n");
            printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            dice = rand() % 6 + 1;
            printf("%d�� ���Խ��ϴ�.\n", dice);
            if (dice <= 4) {
                printf("ģ�е��� �������ϴ�.\n");
                if (relationship > 0) {
                    relationship--;
                }
            }
            else {
                printf("�����̵� ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
            break;
        case 1:
            printf("�˶��� ���� �ܾ��־����ϴ�.\n");
            printf("2/6Ȯ���� ģ�е��� �������ϴ�.\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            dice = rand() % 6 + 1;
            printf("%d�� ���Խ��ϴ�.\n", dice);
            if (dice >= 5) {
                printf("ģ�е��� �������ϴ�\n");
                if (relationship <= 3) {
                    relationship++;
                }
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
            break;
        }
        printf("���� ģ�е� : %d\n", relationship);
        Sleep(2500);
        system("cls");
    }
    return 0;
}