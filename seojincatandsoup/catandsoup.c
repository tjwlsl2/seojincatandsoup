#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)
#define ROOM_HEIGHT 4

int main(void) {
    int soup = 0, relationship = 2, foot, cat = 1, interaction, cp = 0, feeling = 3,
        scratcher = 0, tower = 0, mouse = 0, lazer = 0, up, down, toy = 1;
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
        printf("�˶����� ���(0~3): %d\n", feeling);

        switch (feeling) {
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
            if (feeling > 0) {
                feeling--;
                printf("%d->%d\n", feeling + 1, feeling);
            }
            else
                printf("0->0\n");
        }

        switch (feeling) {
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
                if (feeling > 0)
                    feeling--;
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

        if (cat == HME_POS && cat == foot) {
            printf("�˶���(��) �ڽ��� ������ ������� �����ϴ�.\n");
            if (feeling < 3)
                feeling++;
        }

        if (cat == scratcher) {
            printf("�˶���(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n");
            if (feeling == 3)
                printf("����� ���� ���������ϴ�: %d->%d\n", feeling, feeling);
            else {
                feeling++;
                printf("����� ���� ���������ϴ�: %d->%d\n", feeling - 1, feeling);
            }
        }

        if (cat == tower) {
            printf("�˶���(��) ĹŸ���� �پ�ٴմϴ�.\n");
            if (feeling > 1) {
                printf("����� ���� ���������ϴ�: %d->3\n", feeling);
                feeling = 3;
            }
            else {
                feeling += 2;
                printf("������������������ϴ�: %d->%d\n", feeling - 2, feeling);
            }
        }

        Sleep(500);

        for (int i = 0; i < ROOM_HEIGHT; i++) {
            for (int j = 0; j < ROOM_WIDTH; j++) {
                if (i == 0 || j == 0 || i == ROOM_HEIGHT - 1 || j == ROOM_WIDTH - 1)
                    printf("#");
                else if (i == 1 && j == HME_POS)
                    printf("H");
                else if (i == 1 && j == BWL_PO)
                    printf("B");
                else if (i == 2 && j == cat)
                    printf("C");
                else if (scratcher == j && i == 1)
                    printf("S");
                else if (foot != cat && i == 2 && j == foot)
                    printf(".");
                else if (tower == j && i == 1)
                    printf("T");
                else
                    printf(" ");
            }
            printf("\n");
        }

        Sleep(500);

        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n   0. �ƹ��͵� ���� ����\n   1. �ܾ� �ֱ�\n");

        if (mouse != 0 && lazer != 0) {
            if (lazer == 2)
                printf("   2. ������ �����ͷ� ��� �ֱ�\n   3. �峭�� ��� ��� �ֱ�\n");
            else
                printf("   2. �峭�� ��� ��� �ֱ�\n   3. ������ �����ͷ� ��� �ֱ�\n");
        }
        else if (mouse == 0 && lazer == 2)
            printf("   2. ������ �����ͷ� ��� �ֱ�\n");
        else if (mouse == 2 && lazer == 0)
            printf("   2. �峭�� ��� ��� �ֱ�\n");

        do {
            printf(">>");
            scanf_s("%d", &interaction);
        } while (interaction < 0 || interaction > toy);

        Sleep(2500);
        system("cls");
    }
    return 0;
}