#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include <string>

using namespace std;
using namespace chrono;

class MultyPly_Quiz
{
    int score = 0;
    int quiz_count = 0;

public:
    void easy()
    {
        const int GameDuration = 30; // 제한시간 30초
        auto GameStart = steady_clock::now();
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        string inputBuffer;

        int lastShownSecond = -1;

        while (true)
        {
            auto now = steady_clock::now();
            int elapsed = duration_cast<seconds>(now - GameStart).count();
            int leftTime = GameDuration - elapsed;

            if (leftTime <= 0)
            {

                system("cls");
                cout << "시간 종료!\n";
                cout << "총 문제 수: " << quiz_count << "\n";
                cout << "총 점수: " << score << "\n";
                break;
            }

            // 남은 시간 및 문제 출력 갱신 (초가 바뀔 때마다)
            if (leftTime != lastShownSecond)
            {
                system("cls");
                cout << "easy 모드\n";
                cout << "남은 시간: " << leftTime << "초\n";
                cout << "문제 수: " << quiz_count << "  점수: " << score << "\n";
                cout << x << " * " << y << " = " << inputBuffer;
                lastShownSecond = leftTime;
            }

            // 입력 처리
            if (_kbhit())
            {
                char ch = _getch();

                if (ch == '\r') // Enter 키
                {
                    if (!inputBuffer.empty())
                    {
                        int userAnswer = stoi(inputBuffer);
                        quiz_count++;

                        if (userAnswer == x * y)
                        {
                            cout << "\n정답입니다!\n";
                            score++;
                        }
                        else
                        {
                            cout << "\n오답입니다.\n";
                        }
                        inputBuffer.clear();

                        // 잠깐 결과 보여주기
                        this_thread::sleep_for(milliseconds(800));

                        // 다음 문제 출제
                        x = rand() % 9 + 1;
                        y = rand() % 9 + 1;

                        system("cls");
                        cout << "easy 모드\n";
                        cout << "남은 시간: " << leftTime << "초\n";
                        cout << "문제 수: " << quiz_count << "  점수: " << score << "\n";
                        cout << x << " * " << y << " = ";
                        lastShownSecond = leftTime;
                    }
                }
                else if (ch == '\b') // Backspace 처리
                {
                    if (!inputBuffer.empty())
                    {
                        inputBuffer.pop_back();

                        // 지우기 위해 커서 한 칸 앞으로 이동 후 공백 출력 후 다시 이동
                        cout << "\b \b";
                    }
                }
                else if (isdigit(ch)) // 숫자만 입력 허용
                {
                    inputBuffer += ch;
                    cout << ch; // 입력한 문자 출력
                }
            }

            this_thread::sleep_for(milliseconds(30));
        }
    }
};

int main()
{
    srand((unsigned int)time(NULL));

    MultyPly_Quiz game;
    game.easy();

    return 0;
}
