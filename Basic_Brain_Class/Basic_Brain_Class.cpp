#include<iostream>
#include<ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
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


//덧셈영역
class Plus_Quiz
{
	int score = 0;
	int quiz_count = 1;

public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "+" << y << endl;
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 99 + 1;
			int y = rand() % 99 + 1;
			int answer;
			cout << x << "+" << y << endl;
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 999 + 1;
			int y = rand() % 999 + 1;
			int answer;
			cout << x << "+" << y << endl;
			cin >> answer;
			if (x + y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

};
// 덧셈영역
/// 뺄셈영역
class Minus_Quiz
{
	int score = 0;
	int quiz_count = 1;

public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "-" << y << endl;
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 99 + 1;
			int y = rand() % 99 + 1;
			int answer;
			cout << x << "-" << y << endl;
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		while (quiz_count < 10)
		{
			int x = rand() % 999 + 1;
			int y = rand() % 999 + 1;
			int answer;
			cout << x << "-" << y << endl;
			cin >> answer;
			if (x - y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

};
/// 뺄셈영역
/// 곱셈영역
class MultyPly_Quiz
{
	int score = 0;
	int quiz_count = 1;

public:
	void easy()
	{
		cout << "easy모드" << endl;
		int score = 0;
		const int TimeLimit = 60;
		auto StartTimeAttack = steady_clock::now();

		while (true)
		{

			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - StartTimeAttack).count();
			cout << "[남은 시간: " << TimeLimit - elapsed << "초]" << endl;

			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "*" << y << endl;
			cin >> answer;
			if (x * y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void nomal()
	{
		cout << "nomal모드" << endl;
		int score = 0;
		const int TimeLimit = 30;
		auto StartTimeAttack = steady_clock::now();

		while (true)
		{

			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - StartTimeAttack).count();
			cout << "[남은 시간: " << TimeLimit - elapsed << "초]" << endl;
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "*" << y << endl;

			cin >> answer;
			if (x * y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}
	void hard()
	{
		cout << "hard모드" << endl;
		int score = 0;
		const int TimeLimit = 1;
		auto StartTimeAttack = steady_clock::now();

		while (true)
		{
			auto now = steady_clock::now();
			auto elapsed = duration_cast<seconds>(now - StartTimeAttack).count();
			int remaining = TimeLimit - elapsed;
			if (remaining <= 0) break;  // 시간 초과 시 종료

			cout << "[남은 시간: " << remaining << "초]" << endl;
			int x = rand() % 9 + 1;
			int y = rand() % 9 + 1;
			int answer;
			cout << x << "*" << y << endl;

			cin >> answer;
			if (x * y == answer)
			{
				cout << "정답입니다." << endl;
				score++;
				quiz_count++;
			}
			else
			{
				cout << "오답입니다." << endl;
				quiz_count++;
			}
		}
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
	}

};
/// 곱셈영역
class QuizMath 
{
public:
	int SelectMath;
	void math()
	{

		while (true)
		{
			cout << "종목을 선택해주세요" << endl;
			cout << "덧셈[1] 뺄셈[2] 곱셈[3] 뒤로가기[0]" << endl;
			int MathChoice;
			cin >> MathChoice;

			if (MathChoice == 0) break;
			if (MathChoice == 1)
			{
				while (true)
				{

					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;
					
					MiniGame;
					if (Level == 0) break;
					if (Level == 1)
					{
						Plus_Quiz Select_PQ;
						Select_PQ.easy();
					}
					if (Level == 2)
					{
						Plus_Quiz Select_PQ;
						Select_PQ.nomal();
					}
					if (Level == 3)
					{
						Plus_Quiz Select_PQ;
						Select_PQ.hard();
					}
					
					else
					{
						cout << "잘돗된 값을 입력했습니다." << endl;
						break;
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
					MiniGame;
					if (Level == 0) break;
					if (Level == 1)
					{
						Minus_Quiz Select_MQ;
						Select_MQ.easy();
					}
					if (Level == 2)
					{
						Minus_Quiz Select_MQ;
						Select_MQ.nomal();
					}
					if (Level == 3)
					{
						Minus_Quiz Select_MQ;
						Select_MQ.hard();
					}
					else
					{
						cout << "잘돗된 값을 입력했습니다." << endl;
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
					MiniGame;
					if (Level == 0) break;
					if (Level == 1)
					{
						MultyPly_Quiz Select_MQ;
						Select_MQ.easy();
					}
					if (Level == 2)
					{
						MultyPly_Quiz Select_MQ;
						Select_MQ.nomal();
					}
					if (Level == 3)
					{
						MultyPly_Quiz Select_MQ;
						Select_MQ.hard();
					}
					else
					{
						cout << "잘돗된 값을 입력했습니다." << endl;
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
			if (SelectGame == 0) break;
			if (SelectGame == 1)
			{
				QuizMath SelectMath;
				SelectMath.math();
			} 


		}

	}
};

//말랑말랑두뇌교실
int main()
{
	ProgramStart ProgramStarter;
	ProgramStarter.start();

}