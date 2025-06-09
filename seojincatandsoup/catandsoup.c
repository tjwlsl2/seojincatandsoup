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
        scratcher = 0, tower = 0, mouse = 0, lazer = 0, up, down, toy = 1, count = 0;
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

        printf("\n");
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

                        if (up < down)
                            cat++;
                        else if (down < up)
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

        printf("\n");
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

        printf("\n");
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

        if (interaction == 2) {
            if (lazer == 2)
                printf("������ �����ͷ� �˶��̿� ��� �־����ϴ�.\n");
            else
                printf("�峭�� ��� �˶��̿� ��� �־����ϴ�.\n");
        }

        if (interaction == 3) {
            if (lazer == 3)
                printf("������ �����ͷ� �˶��̿� ��� �־����ϴ�.\n");
            else
                printf("�峭�� ��� �˶��̿� ��� �־����ϴ�.\n");
        }

        if (interaction == 0) {
            if (feeling == 0)
                printf("�˶��� ����� ����� ���������ϴ�: %d->%d\n", feeling, feeling);
            else {
                printf("�˶��� ����� ����� ���������ϴ�: %d->%d\n", feeling, feeling - 1);
                feeling--;
            }
            printf("ģ�е��� �ֻ����� ������ ���� 5�����̸� 1����\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

            dice = rand() % 6 + 1;

            printf("%d��(��) ���Խ��ϴ�.\n", dice);

            if (dice <= 5) {
                printf("������� ���谡 �������ϴ�.\n");
                if (relationship > 0)
                    relationship--;
            }
            else
                printf("������� ���谡 �������� �ʾҽ��ϴ�.\n");

        }
        else if (interaction == 1) {
            printf("�˶��� ����� �״�� �Դϴ�: %d\n", feeling);
            printf("�ֻ����� ������ 5�̻��̸� ģ�е��� �����մϴ�.\n");

            dice = rand() % 6 + 1;

            printf("%d��(��) ���Խ��ϴ�.\n", dice);

            if (dice >= 5)
                if (relationship <= 3)
                    relationship++;
        }

        else if ((interaction == 2 && lazer == 2) || (interaction == 3 && lazer == 3)) {
            printf("������ �����ͷ� �˶��� �ų��� ��� �־����ϴ�.\n");

            if (feeling >= 2) {
                printf("�˶��� ����� �� ���������ϴ�: %d->3\n", feeling);
                feeling = 3;
            }
            else {
                printf("�˶��� ����� �� ���������ϴ�: %d->%d\n", feeling, feeling + 2);
                feeling += 2;
            }
            printf("�ֻ����� ������ 2�̻��̸� ģ�е��� 1�����մϴ�.\n");
            dice = rand() % 6 + 1;
            if (dice >= 2)
                if (relationship <= 3)
                    relationship++;

        }
        else {
            printf("�峭�� ��� �˶��� ��� �־����ϴ�.\n");
            if (feeling == 3)
                printf("�˶��� ����� ���� ���������ϴ�: %d->3\n", feeling);
            else {
                printf("�˶��� ����� ���� ���������ϴ�: %d->%d\n", feeling, feeling + 1);
                feeling += 1;
            }
            printf("�ֻ����� ������ 4�̻��̸� ģ�е��� 1�����մϴ�.\n");
            dice = rand() % 6 + 1;
            if (dice >= 4)
                if (relationship <= 3)
                    relationship++;

        }
        printf("���� ģ�е� : %d\n", relationship);

        printf("\n");

        cp += max(0, feeling - 1) + relationship;
        printf("�˶��� ���(0~3): %d\n", feeling);
        printf("������� ģ�е�(0~4): %d\n", relationship);
        printf("�˶��� ��а� ģ�е��� ���� CP�� %d����Ʈ ���� �Ǿ����ϴ�.\n", max(0, feeling - 1) + relationship);
        printf("���� CP: %d����Ʈ\n", cp);

        printf("\n");

        printf("�������� ������ �� �� �ֽ��ϴ�.\n");
        printf("� ������ �����ұ��?\n");
        printf("    0. �ƹ��͵� ���� �ʴ´�.\n");

        printf("    1. �峭�� ��: 1CP");
        if (mouse != 0)
            printf(" (ǰ��)");
        printf("\n");

        printf("    2. ������ ������: 2CP");
        if (lazer != 0)
            printf(" (ǰ��)");
        printf("\n");

        printf("    3. ��ũ��ó: 4CP");
        if (scratcher != 0)
            printf(" (ǰ��)");
        printf("\n");

        printf("    4. Ĺ Ÿ��: 6CP");
        if (tower != 0)
            printf(" (ǰ��)");
        printf("\n");

        count = 0;
        while (count == 0) {
            do {
                printf(">>");
                scanf_s("%d", &interaction);
            } while (interaction < 0 || interaction > 4);

            if (interaction == 0)
                count = 1;
            else if (interaction == 1) {
                if (mouse != 0)
                    printf("�峭�� �㸦 �̹� �����߽��ϴ�.\n");
                else if (cp < 1)
                    printf("CP�� �����մϴ�.\n");
                else if (lazer == 0) {
                    mouse = 2;
                    cp--;
                    printf("�峭�� �㸦 �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);
                    toy++;
                    count = 1;
                }
                else {
                    mouse = 3;
                    cp--;
                    printf("�峭�� �㸦 �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);
                    toy++;
                    count = 1;
                }

            }
            else if (interaction == 2) {
                if (lazer != 0)
                    printf("������ �����͸� �̹� �����߽��ϴ�.\n");
                else if (cp < 2)
                    printf("CP�� �����մϴ�.\n");
                else if (mouse == 0) {
                    lazer = 2;
                    cp -= 2;
                    printf("������ �����͸� �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);
                    toy++;
                    count = 1;
                }
                else {
                    lazer = 3;
                    cp -= 2;
                    printf("������ �����͸� �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);
                    toy++;
                    count = 1;
                }
                break;
            }
            else if (interaction == 3) {
                if (scratcher != 0)
                    printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
                else if (cp < 4)
                    printf("CP�� �����մϴ�.\n");
                else if (scratcher == 0) {
                    cp -= 4;
                    printf("��ũ��ó�� �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);

                    while (scratcher == 0 || scratcher == tower || scratcher == BWL_PO || scratcher == HME_POS || scratcher == ROOM_WIDTH)
                        scratcher = rand() % (ROOM_WIDTH - 4) + 2;

                    count = 1;
                }
            }
            else if (interaction == 4) {
                if (tower != 0)
                    printf("Ĺ Ÿ���� �̹� �����߽��ϴ�.\n");
                else if (cp < 6)
                    printf("CP�� �����մϴ�.\n");
                else if (tower == 0) {
                    cp -= 6;
                    printf("Ĺ Ÿ���� �����߽��ϴ�.\n");
                    printf("���� CP %d����Ʈ\n", cp);

                    while (tower == 0 || tower == scratcher || tower == BWL_PO || tower == HME_POS || tower == ROOM_WIDTH)
                        tower = rand() % (ROOM_WIDTH - 4) + 2;

                    count = 1;
                }
            }
        }
        Sleep(2500);
        system("cls");
    }
    return 0;
}