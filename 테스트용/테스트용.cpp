#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <windows.h>
#include <chrono>

using namespace std;
using namespace chrono;

char getArrowKey() {
    int key = _getch();
    if (key == 224) {
        key = _getch();
        switch (key) {
        case 72: return 'U'; // ↑
        case 80: return 'D'; // ↓
        case 75: return 'L'; // ←
        case 77: return 'R'; // →
        }
    }
    return 'X';
}

char getRandomDirection() {
    int r = rand() % 4;
    switch (r) {
    case 0: return 'U';
    case 1: return 'D';
    case 2: return 'L';
    case 3: return 'R';
    }
    return 'U';
}

void printArrow(char dir) {
    switch (dir) {
    case 'U': cout << "↑ "; break;
    case 'D': cout << "↓ "; break;
    case 'L': cout << "← "; break;
    case 'R': cout << "→ "; break;
    }
}

// 키 입력을 기다리면서 화면을 0.1초마다 업데이트
// 전체 제한 시간과 입력 제한 시간 모두 체크
char getArrowKeyWithRealtimeDisplay(
    int inputTimeoutMillis,
    steady_clock::time_point gameStart,
    int gameDuration,
    const deque<char>& arrows
) {
    auto inputStart = steady_clock::now();
    int lastShownSecond = -1;

    while (true) {
        auto now = steady_clock::now();
        int elapsedGame = duration_cast<seconds>(now - gameStart).count();
        int timeLeft = gameDuration - elapsedGame;

        if (timeLeft <= 0)
            return 'G'; // 게임 시간 초과

        auto elapsedInput = duration_cast<milliseconds>(now - inputStart).count();
        if (elapsedInput >= inputTimeoutMillis)
            return 'T'; // 입력 시간 초과

        // 화면 새로 그리기 (1초 단위로만 출력 갱신)
        if (timeLeft != lastShownSecond) {
            system("cls");
            cout << "[방향키 게임] 가장 왼쪽 화살표를 입력하세요!" << endl;
            cout << "남은 시간: " << timeLeft << "초" << endl;

            for (char dir : arrows) {
                printArrow(dir);
            }
            cout << endl;
            lastShownSecond = timeLeft;
        }

        // 키 입력 체크
        if (_kbhit()) {
            return getArrowKey();
        }

        Sleep(50); // 0.05초 대기 후 루프 반복
    }
}

int main() {
    srand((unsigned int)time(NULL));

    deque<char> arrows;
    for (int i = 0; i < 10; ++i) {
        arrows.push_back(getRandomDirection());
    }

    int score = 0;
    const int GAME_DURATION = 30; // 전체 게임 제한 (초)
    auto gameStartTime = steady_clock::now();

    while (true) {
        // 입력 기다리면서 남은 시간 계속 화면에 표시
        char input = getArrowKeyWithRealtimeDisplay(
            2000,               // 입력 제한 2초
            gameStartTime,
            GAME_DURATION,
            arrows              // 현재 화살표 상태
        );

        if (input == 'G') {
            cout << "\n⏰ 30초 경과! 게임 종료." << endl;
            cout << "최종 점수: " << score << endl;
            return 0;
        }

        if (input == 'T') {
            cout << "⏱️ 입력 시간 초과! 게임 종료." << endl;
            cout << "최종 점수: " << score << endl;
            return 0;
        }

        if (input == arrows.front()) {
            arrows.pop_front();
            arrows.push_back(getRandomDirection());
            score++;
        }
        else {
            cout << "❌ 오답! 게임 종료." << endl;
            cout << "최종 점수: " << score << endl;
            return 0;
        }
    }

    return 0;
}
