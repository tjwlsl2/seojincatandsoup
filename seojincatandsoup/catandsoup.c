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
    printf("야옹이의 이름은 쫀떡입니다.\n");

    Sleep(1000); //1초대기
    system("cls");

    srand((unsigned int)time(NULL));

    while (1) {
        int dice = rand() % 6 + 1;

        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프: %d개\n", soup);
        printf("CP: %d 포인트\n", cp);
        printf("쫀떡이의 기분(0~3): %d\n", feeling);

        switch (feeling) {
        case 0:
            printf("기분이 매우 나쁩니다.\n");
            break;
        case 1:
            printf("심심해합니다.\n");
            break;
        case 2:
            printf("식빵을 굽습니다.\n");
            break;
        case 3:
            printf("골골송을 부릅니다.\n");
            break;
        }

        printf("집사와의 관계(0~4): %d\n", relationship);
        switch (relationship) {
        case 0:
            printf("곁에 오는것조차 싫어합니다.\n");
            break;
        case 1:
            printf("간식 자판기 취급입니다.\n");
            break;
        case 2:
            printf("그럭저럭 쓸만한 집사입니다.\n");
            break;
        case 3:
            printf("훌륭한 집사로 인정받고 있습니다.\n");
            break;
        case 4:
            printf("집사 껌딱지 입니다.\n");
            break;
        }
        printf("==================================================\n");

        printf("\n");
        Sleep(500); //0.5초대기

        foot = cat;

        printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", relationship, 6 - relationship);
        printf("주사위를 굴립니다. 또르륵...\n");
        printf("%d이(가) 나왔습니다.\n", dice);

        if (dice <= 6 - relationship) {
            printf("쫀떡의 기분이 나빠집니다: ");
            if (feeling > 0) {
                feeling--;
                printf("%d->%d\n", feeling + 1, feeling);
            }
            else
                printf("0->0\n");
        }

        switch (feeling) {
        case 0:
            printf("기분이 매우나쁜 쫀떡은(는) 집으로향합니다.\n");
            cat--;
            break;
        case 1:
            printf("쫀떡은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
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
                printf("쫀떡은(는) 심심해서 타워쪽으로 이동합니다.\n");
            }
            else if (scratcher != 0) {
                if (cat > scratcher)
                    cat--;
                else if (cat < scratcher)
                    cat++;
                printf("쫀떡은(는) 심심해서 스크래처쪽으로 이동합니다.\n");
            }
            else {
                printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
                if (feeling > 0)
                    feeling--;
            }
            break;
        case 2:
            printf("쫀떡은(는) 기분좋게 식빵을 굽고있습니다.\n");
            break;
        case 3:
            printf("쫀떡은(는) 골골송을 부르며 수프를 만들러갑니다.\n");
            cat++;
            break;
        }

        if (cat == BWL_PO) {
            soup++;
            dice = rand() % 3 + 1;
            switch (dice) {
            case 1:
                printf("쫀떡이 감자수프를 만들었습니다.\n");
                break;
            case 2:
                printf("쫀떡이 양송이수프를 만들었습니다,\n");
                break;
            case 3:
                printf("쫀떡이 브로콜리수프를 만들었습니다.\n");
                break;
            }
            printf("현재까지 만든 수프: %d\n", soup);
        }

        if (cat == HME_POS && cat == foot) {
            printf("쫀떡은(는) 자신의 집에서 편안함을 느낍니다.\n");
            if (feeling < 3)
                feeling++;
        }

        if (cat == scratcher) {
            printf("쫀떡은(는) 스크래처를 긁고 놀았습니다.\n");
            if (feeling == 3)
                printf("기분이 조금 좋아졌습니다: %d->%d\n", feeling, feeling);
            else {
                feeling++;
                printf("기분이 조금 좋아졌습니다: %d->%d\n", feeling - 1, feeling);
            }
        }

        if (cat == tower) {
            printf("쫀떡은(는) 캣타워를 뛰어다닙니다.\n");
            if (feeling > 1) {
                printf("기분이 제법 좋아졌습니다: %d->3\n", feeling);
                feeling = 3;
            }
            else {
                feeling += 2;
                printf("기분이제법좋아졌습니다: %d->%d\n", feeling - 2, feeling);
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

        printf("어떤 상호작용을 하시겠습니까?\n   0. 아무것도 하지 않음\n   1. 긁어 주기\n");

        if (mouse != 0 && lazer != 0) {
            if (lazer == 2)
                printf("   2. 레이저 포인터로 놀아 주기\n   3. 장난감 쥐로 놀아 주기\n");
            else
                printf("   2. 장난감 쥐로 놀아 주기\n   3. 레이저 포인터로 놀아 주기\n");
        }
        else if (mouse == 0 && lazer == 2)
            printf("   2. 레이저 포인터로 놀아 주기\n");
        else if (mouse == 2 && lazer == 0)
            printf("   2. 장난감 쥐로 놀아 주기\n");

        do {
            printf(">>");
            scanf_s("%d", &interaction);
        } while (interaction < 0 || interaction > toy);

        if (interaction == 2) {
            if (lazer == 2)
                printf("레이저 포인터로 쫀떡이와 놀아 주었습니다.\n");
            else
                printf("장난감 쥐로 쫀떡이와 놀아 주었습니다.\n");
        }

        if (interaction == 3) {
            if (lazer == 3)
                printf("레이저 포인터로 쫀떡이와 놀아 주었습니다.\n");
            else
                printf("장난감 쥐로 쫀떡이와 놀아 주었습니다.\n");
        }

        if (interaction == 0) {
            if (feeling == 0)
                printf("쫀떡의 기분이 기분이 나빠졌습니다: %d->%d\n", feeling, feeling);
            else {
                printf("쫀떡의 기분이 기분이 나빠졌습니다: %d->%d\n", feeling, feeling - 1);
                feeling--;
            }
            printf("친밀도는 주사위를 던져서 눈이 5이하이면 1감소\n");
            printf("주사위를 돌립니다. 또르륵...\n");

            dice = rand() % 6 + 1;

            printf("%d이(가) 나왔습니다.\n", dice);

            if (dice <= 5) {
                printf("집사와의 관계가 나빠집니다.\n");
                if (relationship > 0)
                    relationship--;
            }
            else
                printf("집사와의 관계가 나빠지지 않았습니다.\n");

        }
        else if (interaction == 1) {
            printf("쫀떡의 기분은 그대로 입니다: %d\n", feeling);
            printf("주사위를 던져서 5이상이면 친밀도가 증가합니다.\n");

            dice = rand() % 6 + 1;

            printf("%d이(가) 나왔습니다.\n", dice);

            if (dice >= 5)
                if (relationship <= 3)
                    relationship++;
        }

        else if ((interaction == 2 && lazer == 2) || (interaction == 3 && lazer == 3)) {
            printf("레이저 포인터로 쫀떡와 신나게 놀아 주었습니다.\n");

            if (feeling >= 2) {
                printf("쫀떡의 기분이 꽤 좋아졌습니다: %d->3\n", feeling);
                feeling = 3;
            }
            else {
                printf("쫀떡의 기분이 꽤 좋아졌습니다: %d->%d\n", feeling, feeling + 2);
                feeling += 2;
            }
            printf("주사위를 던져서 2이상이면 친밀도가 1증가합니다.\n");
            dice = rand() % 6 + 1;
            if (dice >= 2)
                if (relationship <= 3)
                    relationship++;

        }
        else {
            printf("장난감 쥐로 쫀떡와 놀아 주었습니다.\n");
            if (feeling == 3)
                printf("쫀떡의 기분이 조금 좋아졌습니다: %d->3\n", feeling);
            else {
                printf("쫀떡의 기분이 조금 좋아졌습니다: %d->%d\n", feeling, feeling + 1);
                feeling += 1;
            }
            printf("주사위를 던져서 4이상이면 친밀도가 1증가합니다.\n");
            dice = rand() % 6 + 1;
            if (dice >= 4)
                if (relationship <= 3)
                    relationship++;

        }
        printf("현재 친밀도 : %d\n", relationship);

        printf("\n");

        cp += max(0, feeling - 1) + relationship;
        printf("쫀떡의 기분(0~3): %d\n", feeling);
        printf("집사와의 친밀도(0~4): %d\n", relationship);
        printf("쫀떡의 기분과 친밀도에 따라서 CP가 %d포인트 생산 되었습니다.\n", max(0, feeling - 1) + relationship);
        printf("보유 CP: %d포인트\n", cp);

        printf("\n");

        printf("상점에서 물건을 살 수 있습니다.\n");
        printf("어떤 물건을 구매할까요?\n");
        printf("    0. 아무것도 사지 않는다.\n");

        printf("    1. 장난감 쥐: 1CP");
        if (mouse != 0)
            printf(" (품절)");
        printf("\n");

        printf("    2. 레이저 포인터: 2CP");
        if (lazer != 0)
            printf(" (품절)");
        printf("\n");

        printf("    3. 스크래처: 4CP");
        if (scratcher != 0)
            printf(" (품절)");
        printf("\n");

        printf("    4. 캣 타워: 6CP");
        if (tower != 0)
            printf(" (품절)");
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
                    printf("장난감 쥐를 이미 구매했습니다.\n");
                else if (cp < 1)
                    printf("CP가 부족합니다.\n");
                else if (lazer == 0) {
                    mouse = 2;
                    cp--;
                    printf("장난감 쥐를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);
                    toy++;
                    count = 1;
                }
                else {
                    mouse = 3;
                    cp--;
                    printf("장난감 쥐를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);
                    toy++;
                    count = 1;
                }

            }
            else if (interaction == 2) {
                if (lazer != 0)
                    printf("레이저 포인터를 이미 구매했습니다.\n");
                else if (cp < 2)
                    printf("CP가 부족합니다.\n");
                else if (mouse == 0) {
                    lazer = 2;
                    cp -= 2;
                    printf("레이저 포인터를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);
                    toy++;
                    count = 1;
                }
                else {
                    lazer = 3;
                    cp -= 2;
                    printf("레이저 포인터를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);
                    toy++;
                    count = 1;
                }
                break;
            }
            else if (interaction == 3) {
                if (scratcher != 0)
                    printf("스크래처를 이미 구매했습니다.\n");
                else if (cp < 4)
                    printf("CP가 부족합니다.\n");
                else if (scratcher == 0) {
                    cp -= 4;
                    printf("스크래처를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);

                    while (scratcher == 0 || scratcher == tower || scratcher == BWL_PO || scratcher == HME_POS || scratcher == ROOM_WIDTH)
                        scratcher = rand() % (ROOM_WIDTH - 4) + 2;

                    count = 1;
                }
            }
            else if (interaction == 4) {
                if (tower != 0)
                    printf("캣 타워를 이미 구매했습니다.\n");
                else if (cp < 6)
                    printf("CP가 부족합니다.\n");
                else if (tower == 0) {
                    cp -= 6;
                    printf("캣 타워를 구매했습니다.\n");
                    printf("보유 CP %d포인트\n", cp);

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