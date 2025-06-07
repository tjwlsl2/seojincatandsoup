#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main(void) {
    int soup = 0, relationship = 2, foot, cat = 1, a, cp = 0, mood = 3;
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


        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프: %d개\n", soup);
        printf("CP: %d 포인트\n", cp);
        printf("쫀떡이의 기분(0~3): %d\n", mood);

        switch (mood) {
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

        Sleep(500); //0.5초대기
        foot = cat;
        printf("쫀떡 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n");
        printf("주사위 눈이 %d이상이면 냄비 쪽으로 이동합니다.\n", 6 - relationship);
        printf("주사위를 굴립니다. 또르륵...\n");

        int dice;
        dice = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다.\n", dice);

        if (dice >= 6 - relationship) {
            if (cat < BWL_PO)
                cat++;
            printf("냄비 쪽으로 움직입니다.\n");
        }
        else if (cat != HME_POS) {
            cat--;
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
        if (cat == HME_POS) {
            printf("쫀떡은 자신의 집에서 편안함을 느낍니다.\n");
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

        Sleep(500); //0.5초대기

        printf("어떤 상호작용을 하시겠습니까?   0. 아무것도 하지 않음   1. 긁어주기\n>> ");
        scanf_s("%d", &a);

        while (a != 0 && a != 1) {
            printf(">>");
            scanf_s("%d", &a);
        }

        switch (a) {
        case 0:
            printf("아무것도 하지 않음\n");
            printf("4/6의 확률로 친밀도가 떨어집니다.\n");
            printf("주사위를 돌립니다. 또르륵...\n");
            dice = rand() % 6 + 1;
            printf("%d가 나왔습니다.\n", dice);
            if (dice <= 4) {
                printf("친밀도가 떨어집니다.\n");
                if (relationship > 0) {
                    relationship--;
                }
            }
            else {
                printf("다행이도 친밀도가 떨어지지 않았습니다.\n");
            }
            break;
        case 1:
            printf("쫀떡의 턱을 긁어주었습니다.\n");
            printf("2/6확률로 친밀도가 높아집니다.\n");
            printf("주사위를 돌립니다. 또르륵...\n");
            dice = rand() % 6 + 1;
            printf("%d가 나왔습니다.\n", dice);
            if (dice >= 5) {
                printf("친밀도가 높아집니다\n");
                if (relationship <= 3) {
                    relationship++;
                }
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
            break;
        }
        printf("현재 친밀도 : %d\n", relationship);
        Sleep(2500);
        system("cls");
    }
    return 0;
}