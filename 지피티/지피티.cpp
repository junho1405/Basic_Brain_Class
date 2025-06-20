#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// 추상 클래스
class MiniGame {
protected:
    int level;
public:
    MiniGame(int lvl) : level(lvl) {}
    virtual void play() = 0;
    virtual ~MiniGame() {}
};

// 덧셈 퀴즈 게임
class PlusQuiz : public MiniGame {
public:
    PlusQuiz(int lvl) : MiniGame(lvl) {}
    void play() override {
        int max_num = (level == 1) ? 9 : (level == 2) ? 99 : 999;
        int score = 0;
        for (int i = 0; i < 10; i++) {
            int x = rand() % max_num + 1;
            int y = rand() % max_num + 1;
            int answer;
            cout << x << " + " << y << " = ";
            cin >> answer;
            if (answer == x + y) {
                cout << "정답!\n";
                score++;
            }
            else {
                cout << "오답! 정답은 " << x + y << "\n";
            }
        }
        cout << "총점수: " << score << "/10\n";
    }
};

// 게임 관리자: 게임 선택, 난이도 선택, 실행
class GameManager {
public:
    void run() {
        while (true) {
            cout << "\n게임을 선택하세요:\n1. 덧셈 퀴즈\n0. 종료\n선택: ";
            int gameChoice;
            cin >> gameChoice;
            if (gameChoice == 0) break;

            cout << "난이도 선택 (1: 쉬움, 2: 보통, 3: 어려움): ";
            int level; cin >> level;

            MiniGame* game = nullptr;
            if (gameChoice == 1) {
                game = new PlusQuiz(level);
            }

            if (game) {
                game->play();
                delete game;
            }
            else {
                cout << "잘못된 선택입니다.\n";
            }
        }
        cout << "게임 종료!\n";
    }
};

int main() {
    srand(time(0));
    GameManager gm;
    gm.run();
    return 0;
}
