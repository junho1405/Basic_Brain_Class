#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

class MiniGame
{
private:
public:
	virtual void play() = 0;
	virtual ~MiniGame() {}
};

// 덧셈영역
class Plus_Quiz
{
public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << " + " << y << " = ";
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}

	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 99 + 1;
			int y = rand() % 99 + 1;
			int answer;
			cout << x << " + " << y << " = ";
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}

	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 999 + 1;
			int y = rand() % 999 + 1;
			int answer;
			cout << x << " + " << y << " = ";
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}
};

// 뺄셈영역
class Minus_Quiz
{
public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << " - " << y << " = ";
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}

	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 99 + 1;
			int y = rand() % 99 + 1;
			int answer;
			cout << x << " - " << y << " = ";
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}

	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		int quiz_count = 1;
		while (quiz_count <= 9)
		{
			int x = rand() % 999 + 1;
			int y = rand() % 999 + 1;
			int answer;
			cout << x << " - " << y << " = ";
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
			}
			else
			{
				cout << "오답입니다." << endl;
			}
			quiz_count++;
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count - 1 << endl;
	}
};

// 곱셈영역 (시간 제한 있음)
class MultyPly_Quiz
{
public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		int quiz_count = 0;
		const int TimeLimit = 60; // 60초 제한
		auto startTime = steady_clock::now();

		while (true)
		{
			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - startTime).count();
			int remaining = TimeLimit - elapsed;
			if (remaining <= 0)
				break;

			cout << "[남은 시간: " << remaining << "초]" << endl;

			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;

			cout << x << " * " << y << " = ";

			// 입력 대기 + 시간 경과 체크
			if (_kbhit())
			{
				int answer;
				cin >> answer;
				if (x * y == answer)
				{
					cout << "정답입니다." << endl;
					score++;
				}
				else
				{
					cout << "오답입니다." << endl;
				}
				quiz_count++;
			}
			else
			{
				// 시간이 다 될 때까지 기다리지 말고 계속 루프 돌면서 남은 시간 체크
				// sleep 조금 주면 CPU 과부하 줄일 수 있음
				this_thread::sleep_for(milliseconds(100));
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		int quiz_count = 0;
		const int TimeLimit = 30; // 30초 제한
		auto startTime = steady_clock::now();

		while (true)
		{
			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - startTime).count();
			int remaining = TimeLimit - elapsed;
			if (remaining <= 0)
				break;

			cout << "[남은 시간: " << remaining << "초]" << endl;

			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;

			cout << x << " * " << y << " = ";

			if (_kbhit())
			{
				int answer;
				cin >> answer;
				if (x * y == answer)
				{
					cout << "정답입니다." << endl;
					score++;
				}
				else
				{
					cout << "오답입니다." << endl;
				}
				quiz_count++;
			}
			else
			{
				this_thread::sleep_for(milliseconds(100));
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		int quiz_count = 0;
		const int TimeLimit = 15; // 15초 제한
		auto startTime = steady_clock::now();

		while (true)
		{
			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - startTime).count();
			int remaining = TimeLimit - elapsed;
			if (remaining <= 0)
				break;

			cout << "[남은 시간: " << remaining << "초]" << endl;

			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;

			cout << x << " * " << y << " = ";

			if (_kbhit())
			{
				int answer;
				cin >> answer;
				if (x * y == answer)
				{
					cout << "정답입니다." << endl;
					score++;
				}
				else
				{
					cout << "오답입니다." << endl;
				}
				quiz_count++;
			}
			else
			{
				this_thread::sleep_for(milliseconds(100));
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
};

class QuizMath
{
public:
	void math()
	{
		while (true)
		{
			cout << "종목을 선택해주세요" << endl;
			cout << "덧셈[1] 뺄셈[2] 곱셈[3] 뒤로가기[0]" << endl;
			int MathChoice;
			cin >> MathChoice;

			if (MathChoice == 0)
				break;

			if (MathChoice == 1)
			{
				while (true)
				{
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;

					if (Level == 0)
						break;
					if (Level == 1)
					{
						Plus_Quiz pq;
						pq.easy();
					}
					else if (Level == 2)
					{
						Plus_Quiz pq;
						pq.nomal();
					}
					else if (Level == 3)
					{
						Plus_Quiz pq;
						pq.hard();
					}
					else
					{
						cout << "잘못된 값을 입력했습니다." << endl;
					}
				}
			}
			else if (MathChoice == 2)
			{
				while (true)
				{
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;

					if (Level == 0)
						break;
					if (Level == 1)
					{
						Minus_Quiz mq;
						mq.easy();
					}
					else if (Level == 2)
					{
						Minus_Quiz mq;
						mq.nomal();
					}
					else if (Level == 3)
					{
						Minus_Quiz mq;
						mq.hard();
					}
					else
					{
						cout << "잘못된 값을 입력했습니다." << endl;
					}
				}
			}
			else if (MathChoice == 3)
			{
				while (true)
				{
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;

					if (Level == 0)
						break;
					if (Level == 1)
					{
						MultyPly_Quiz mq;
						mq.easy();
					}
					else if (Level == 2)
					{
						MultyPly_Quiz mq;
						mq.nomal();
					}
					else if (Level == 3)
					{
						MultyPly_Quiz mq;
						mq.hard();
					}
					else
					{
						cout << "잘못된 값을 입력했습니다." << endl;
					}
				}
			}
			else
			{
				cout << "잘못된 값을 입력하셨습니다." << endl;
			}
		}
	}
};

class ProgramStart
{
public:
	void start()
	{
		while (true)
		{
			cout << "게임을 시작합니다." << endl;
			cout << "[1]사칙연산 [2]기억력테스트 [3]반응속도테스트 [0]게임종료" << endl;
			int SelectGame;
			cin >> SelectGame;
			if (SelectGame == 0)
				break;
			if (SelectGame == 1)
			{
				QuizMath qmath;
				qmath.math();
			}
			else
			{
				cout << "해당 게임은 아직 구현되지 않았습니다." << endl;
			}
		}
	}
};

// 말랑말랑두뇌교실
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	ProgramStart ProgramStarter;
	ProgramStarter.start();

	return 0;
}
