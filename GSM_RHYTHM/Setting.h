#include <stdio.h>
#include <SDL.h>
#include <Windows.h>
#include <stdbool.h>

extern int SoundSetting;
extern bool isTutorialoff;
extern int CoinNum;
extern int NewRecord;
int TutorialSetting();

void Setting(SDL_Renderer* rend, SDL_Texture* BG, SDL_Texture* Window, SDL_Texture* Check) {
    SDL_SetTextureAlphaMod(Window, 80);
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, BG, NULL, NULL);
    SDL_RenderCopy(rend, Window, NULL, NULL);
    SDL_RenderCopy(rend, Check, NULL, NULL);
    SDL_RenderPresent(rend);
}
int SoundSettingWindow() {
    int num;
    int Sound;
    int Admin;
    Sound = SoundSetting;
    int CoinAnswer = CoinNum;
    int RecordNew = NewRecord;
    int buffer[256];
    int Score, Coin;
    printf("\n설정하고 싶은 것을 선택하세요.\n");
    printf("1. 사운드 설정\n");
    printf("2. 튜토리얼 설정\n\n");
    printf("취소하려면 0을 입력하세요.\n\n");
    printf("추후 추가 예정\n");
    scanf_s("%d", &num);
    if (num == 1225) {
        Admin = 0;
        system("cls");
        FILE* fip = NULL;
        fip = fopen("data.txt", "r");
        if (fip == NULL) {
            printf("파일열기 실패\n");
        }
        while (true) {
            system("cls");
            printf("관리자 모드\n\n");
            printf("설정할 기능을 선택하세요\n");
            printf("1. 최고 점수 초기화\n");
            printf("2. 코인 초기화\n");
            scanf_s("%d", &Admin);

            // 파일 읽기
            fip = fopen("data.txt", "r");
            if (fip == NULL) {
                perror("파일을 열 수 없습니다.");
                return 1;
            }

            // 첫 번째 줄 읽기 (최고 점수)
            fgets(buffer, sizeof(buffer), fip);
            sscanf(buffer, "%d", &Score);

            // 두 번째 줄 읽기 (코인)
            fgets(buffer, sizeof(buffer), fip);
            sscanf(buffer, "%d", &Coin);

            fclose(fip);

            // 파일 쓰기 모드로 다시 열기
            fip = fopen("data.txt", "w");
            if (fip == NULL) {
                perror("파일을 열 수 없습니다.");
                return 1;
            }

            if (Admin == 1) {
                // 최고 점수 초기화
                fprintf(fip, "%d\n%d", 0, Coin);
                fclose(fip);
                system("cls");
                return 0;
            }
            else if (Admin == 2) {
                // 코인 초기화
                fprintf(fip, "%d\n%d", Score, 0);
                fclose(fip);
                system("cls");
                return 0;
            }
            else {
                printf("잘못된 입력입니다!\n");
                Sleep(500);
                continue;
            }
        }
    }
    if (num == 0) {
        system("cls");
        return 0;
    }
    if (num > 2) {
        printf("범위가 잘못되었습니다!");
        Sleep(1000);
        system("cls");
    }
    else if (num == 1) {
        while (true)
        {
            system("cls");
            printf("사운드 설정\n");
            printf("현재 사운드 값 : %d\n", Sound);
            printf("0 ~ 100 사이의 값을 입력하세요 : ");
            scanf_s("%d", &Sound);
            if (Sound > 100 || Sound < 0) {
                printf("범위가 잘못되었습니다!");
                Sleep(1000);
                system("cls");
                continue;
            }
            else {
                printf("설정이 완료되었습니다!\n");
                Sleep(500);
                SoundSetting = Sound;
                system("cls");
                return Sound;
            }
        }
    }
    else if (num == 2) {
        int x;
        x = TutorialSetting();
        if (x == 1) {
            isTutorialoff = true;
            printf("설정이 완료되었습니다!\n");
            return Sound;
        }
        else {
            isTutorialoff = false;
            printf("설정이 완료되었습니다!\n");
            return Sound;
        }
    }
}

int TutorialSetting() {
    system("cls");
    char check = 0;
    while (true)
    {
        printf("튜토리얼을 끄시겠습니까?(이 설정을 활성화 시, 앞으로 튜토리얼은 나오지 않습니다!)\n");
        printf("당신은 이 설정을 언제든 키고 끌 수 있습니다!\n");
        printf("(y/n) : ");
        scanf_s("%c", &check);
        if (check == 'y' || check == 'Y') {
            return 1;
            break;
        }
        else if (check == 'n' || check == 'N') {
            return 0;
            break;
        }
        else {
            printf("입력 값이 잘못되었습니다!\n");
            Sleep(500);
            system("cls");
            continue;
        }
    }

}