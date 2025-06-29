#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include <deque>
#include <Windows.h>
#include <Vector>
#include<string>

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
	int quiz_count = 0;


public:
	const int TimeLimit = 10;
	int LastShowSecond = -1;
	string InputBuffer;
	int x;
	int y;

	void easy()
	{
		auto GameStart = steady_clock::now();
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "easy모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "+" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x + y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score++;
							quiz_count++;
						}
						else if (Answer != x + y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x + y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						x = rand() % 9 + 1;
						y = rand() % 9 + 1;
						cout << "easy모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "+" << y << endl;
						cout << "정답 : " << InputBuffer;
					}

				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();

	}
	void nomal()
	{
		auto GameStart = steady_clock::now();
		x = rand() % 99 + 1;
		y = rand() % 99 + 1;

		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{

				system("cls");
				cout << "normal모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "+" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x + y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score += 5;
							quiz_count++;
						}
						else if (Answer != x + y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x + y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						x = rand() % 99 + 1;
						y = rand() % 99 + 1;
						cout << "normal모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "+" << y << endl;
						cout << "정답 : " << InputBuffer;
					}

				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 5 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}
	void hard()
	{
		auto GameStart = steady_clock::now();
		int x = rand() % 999 + 1;
		int y = rand() % 999 + 1;
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "hard모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "+" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x + y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score += 10;
							quiz_count++;
						}
						else if (Answer != x + y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x + y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						x = rand() % 999 + 1;
						y = rand() % 999 + 1;
						cout << "hard모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "+" << y << endl;
						cout << "정답 : " << InputBuffer;
					}

				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 10 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}

};
// 덧셈영역
/// 뺄셈영역
class Minus_Quiz
{
	int score = 0;
	int quiz_count = 0;


public:

	int x;
	int y;
	const int TimeLimt = 10;
	int LastShowSecond = -1;
	string InputBuffer;

	void easy()
	{
		system("cls");
		do {
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
		} while (x < y);

		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimt - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "easy모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "-" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x - y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score++;
							quiz_count++;

						}
						else if (Answer != x - y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x - y << endl;
							quiz_count++;
						}

						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						do {
							x = rand() % 9 + 1;
							y = rand() % 9 + 1;
						} while (x < y);

						cout << "easy모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "-" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				} if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}
	void nomal()
	{
		system("cls");
		do {
			x = rand() % 99 + 1;
			y = rand() % 99 + 1;
		} while (x < y);

		cout << "normal모드" << endl;
		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimt - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "normal모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "-" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x - y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score++;
							quiz_count++;

						}
						else if (Answer != x - y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x - y << endl;
							quiz_count++;
						}

						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						do {
							x = rand() % 99 + 1;
							y = rand() % 99 + 1;
						} while (x < y);

						cout << "normal모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "-" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				} if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 5 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}
	void hard()
	{
		system("cls");
		do {
			x = rand() % 999 + 1;
			y = rand() % 999 + 1;
		} while (x < y);

		cout << "hard모드" << endl;
		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimt - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "hard모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "-" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x - y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score += 10;
							quiz_count++;

						}
						else if (Answer != x - y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x - y << endl;
							quiz_count++;
						}

						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						system("cls");
						do {
							x = rand() % 999 + 1;
							y = rand() % 999 + 1;
						} while (x < y);

						cout << "hard모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "-" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				} if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 10 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}

};
/// 뺄셈영역
/// 곱셈영역
class MultyPly_Quiz
{
	int score = 0;
	int quiz_count = 0;

public:


	const int TimeLimit = 30;
	int LastShowSecond = -1;//매초마다 화면갱신을 위한 -1 / 시간은 -1이 될수 없기에 시간이 -1이 아니면 cls
	string InputBuffer;// 한글자만 쳐도 자동으로 넘어가는 것을 방지하고 답이 2자릿수 이상일 때를 위해 넣는 버퍼

	void easy()
	{
		system("cls");
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		cout << "easy모드" << endl;
		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "easy모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "*" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit()) {
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x * y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score++;
							quiz_count++;
						}
						else if (Answer != x * y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x * y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						x = rand() % 9 + 1;
						y = rand() % 9 + 1;
						system("cls");
						cout << "easy모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "*" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))//숫자인지 구분
				{
					InputBuffer += ch;
					cout << ch;
				}
				else if (ch == 27)
				{
					break;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}
	void nomal()
	{
		system("cls");
		int x = rand() % 99 + 1;
		int y = rand() % 99 + 1;
		cout << "normal모드" << endl;
		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "normal모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "*" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit()) {
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x * y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score += 5;
							quiz_count++;
						}
						else if (Answer != x * y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x * y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						x = rand() % 99 + 1;
						y = rand() % 99 + 1;
						system("cls");
						cout << "normal모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "*" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))//숫자인지 구분
				{
					InputBuffer += ch;
					cout << ch;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 5 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();

	}
	void hard()
	{
		system("cls");
		int x = rand() % 999 + 1;
		int y = rand() % 999 + 1;
		cout << "normal모드" << endl;
		auto GameStart = steady_clock::now();
		while (true)
		{
			auto now = steady_clock::now();
			int Timer = duration_cast<seconds>(now - GameStart).count();
			int LeftTime = TimeLimit - Timer;

			if (LeftTime <= 0)
			{
				break;
			}
			if (LeftTime != LastShowSecond)
			{
				system("cls");
				cout << "normal모드" << endl;
				cout << "남은 시간 : " << LeftTime << endl;
				cout << x << "*" << y << endl;
				cout << "정답 : " << InputBuffer;
				LastShowSecond = LeftTime;
			}
			if (_kbhit()) {
				char ch = _getch();
				if (ch == '\r')
				{
					if (!InputBuffer.empty())
					{
						int Answer = stoi(InputBuffer);
						if (Answer == x * y)
						{
							system("cls");
							cout << "정답입니다." << endl;
							score += 10;
							quiz_count++;
						}
						else if (Answer != x * y)
						{
							system("cls");
							cout << "오답입니다.." << endl;
							cout << "정답 : " << x * y << endl;
							quiz_count++;
						}
						InputBuffer.clear();
						cout << "아무키나 입력해주세요." << endl;
						_getch();
						x = rand() % 999 + 1;
						y = rand() % 999 + 1;
						system("cls");
						cout << "hard모드" << endl;
						cout << "남은 시간 : " << LeftTime << endl;
						cout << x << "*" << y << endl;
						cout << "정답 : " << InputBuffer;
					}
				}
				if (ch == '\b')
				{
					if (!InputBuffer.empty())
					{
						InputBuffer.pop_back();
						cout << "\b \b";
					}
				}
				else if (isdigit(ch))//숫자인지 구분
				{
					InputBuffer += ch;
					cout << ch;
				}
			}
		}
		system("cls");
		cout << "총점수 : " << score << endl;
		cout << "총문제수 : " << quiz_count << endl;
		cout << "맞춘 문제수" << score / 10 << endl;
		Sleep(3000);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << "아무키나 입력해주세요." << endl;
		score = 0;
		_getch();
	}

};
/// 곱셈영역

//사칙연산 난이도 선택
class QuizMath
{
public:
	int SelectMath;
	void math()
	{

		while (true)
		{
			system("cls");
			cout << "종목을 선택해주세요" << endl;
			cout << "덧셈[1] 뺄셈[2] 곱셈[3] 뒤로가기[0]" << endl;
			int MathChoice;
			cin >> MathChoice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (MathChoice == 0) break;
			if (MathChoice == 1)
			{
				while (true)
				{
					system("cls");
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
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
					if (Level == 9)
					{
						system("cls");
						cout << "덧셈 게임" << endl;
						cout << "게임을 시작하면 화면에 간단한 덧셈 문제가 나옵니다." << endl;
						cout << "그 값을 입력하면 되고 총 10문제가 준비되어 있으며" << endl;
						cout << "난이도 별로 최대 자릿수가 달라집니다." << endl;
						cout << "쉬움- 최대 1자릿수 \n 보통- 최대 2자릿수 \n어려움- 최대 3자릿수" << endl;
						cout << "아무키나 눌러주세요." << endl;
						_getch();
						break;

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
					system("cls");
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "잘돗된 값을 입력했습니다." << endl;
					}
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
					}if (Level == 9)
					{
						system("cls");
						cout << "뺄셈 게임" << endl;
						cout << "게임을 시작하면 화면에 간단한 빼기 문제가 나옵니다." << endl;
						cout << "그 값을 입력하면 되고 총 10문제가 준비되어 있으며" << endl;
						cout << "난이도 별로 최대 자릿수가 달라집니다." << endl;
						cout << "쉬움- 최대 1자릿수 \n 보통- 최대 2자릿수 \n어려움- 최대 3자릿수" << endl;
						cout << "아무키나 눌러주세요." << endl;
						_getch();
						break;

					}
				}
			}
			else if (MathChoice == 3)
			{
				while (true)
				{
					system("cls");
					cout << "난이도를 선택해주세요." << endl;
					cout << "쉬움[1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
					int Level;
					cin >> Level;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
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
					}if (Level == 9)
					{
						//곱셈 룰설명
						cout << "" << endl;
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
//사칙연산 난이도 선택

//기억력테스트
class MemoryQuiz
{
	int score;
public:
	char QuizLetter()
	{
		return 'a' + rand() % 26;//a~z까지출력
	}
	int MemoryQuizLevel = 0;
	vector<char> Letter;
	string input;


	void easy()
	{
		Letter.clear();
		cout << "easy모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel + 1 << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(1500);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			system("cls");
			cout << "지금까지 나온 글자들을 입력해주세요." << endl;
			cout << "공백없이 입력해주세요." << endl;
			cin >> input;

			bool correct = true;
			if (input.length() != Letter.size())//글자수가 다르면 오답처리를 한다.
			{
				cout << "오답입니다." << endl;
				correct = false;
			}
			else //글자수가 같다면 정답인지에 대해 확인한다.
			{
				for (size_t i = 0; i < Letter.size(); i++)
				{
					if (input[i] != Letter[i])
					{
						correct = false;
						break;
					}
				}
			}if (correct)//정답이면 실행
			{
				cout << "정답입니다." << endl;
				MemoryQuizLevel++;
				score++;
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << score << endl << endl;
				Sleep(3000);
				MemoryQuizLevel = 0;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요" << endl;
				score = 0;
				_getch();
				break;
			}
		}
	}
	void normal()
	{
		Letter.clear();
		cout << "normal모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel + 1 << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(1000);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			system("cls");
			cout << "지금까지 나온 글자들을 입력해주세요." << endl;
			cout << "공백없이 입력해주세요." << endl;
			cin >> input;

			bool correct = true;
			if (input.length() != Letter.size())//글자수가 다르면 오답처리를 한다.
			{
				cout << "오답입니다." << endl;
				correct = false;
			}
			else //글자수가 같다면 정답인지에 대해 확인한다.
			{
				for (size_t i = 0; i < Letter.size(); i++)
				{
					if (input[i] != Letter[i])
					{
						correct = false;
						break;
					}
				}
			}if (correct)//정답이면 실행
			{
				cout << "정답입니다." << endl;
				MemoryQuizLevel++;
				score += 2;
				Sleep(1000);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << score << endl << endl;
				Sleep(3000);
				MemoryQuizLevel = 0;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요" << endl;
				score = 0;
				_getch();
				break;
			}
		}
	}
	void hard()
	{
		Letter.clear();
		cout << "hard모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(500);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			system("cls");
			cout << "지금까지 나온 글자들을 입력해주세요." << endl;
			cout << "공백없이 입력해주세요." << endl;
			cin >> input;

			bool correct = true;
			if (input.length() != Letter.size())//글자수가 다르면 오답처리를 한다.
			{
				cout << "오답입니다." << endl;
				correct = false;
			}
			else //글자수가 같다면 정답인지에 대해 확인한다.
			{
				for (size_t i = 0; i < Letter.size(); i++)
				{
					if (input[i] != Letter[i])
					{
						correct = false;
						break;
					}
				}
			}if (correct)//정답이면 실행
			{
				cout << "정답입니다." << endl;
				MemoryQuizLevel++;
				score += 3;
				Sleep(500);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << score << endl << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요" << endl;
				score = 0;
				_getch();
				break;
			}
		}
	}


};
//기억력테스트

//기억력테스트 난이도 선택
class QuizMemory
{
public:
	int SelectMemory;
	void Memory()
	{
		MemoryQuiz SelectMemory;
		while (true)
		{
			system("cls");
			cout << "난이도를 선택해 주세요." << endl;
			cout << "쉬움 [1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
			int Level;
			cin >> Level;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (Level == 0) break;
			if (Level == 1)
			{

				SelectMemory.easy();

			} if (Level == 2)
			{
				SelectMemory.normal();
			} if (Level == 3)
			{
				SelectMemory.hard();
			}
			else
			{
				cout << "잘못된 값을 입력했습니다" << endl;

			}
		}
	}
};
//기억력테스트 난이도 선택

//화살표게임
class ArrowGame
{
	int score = 0;
public:
	char GetArrowKey()
	{
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case 72: return 'U';
			case 80: return 'D';
			case 75: return 'L';
			case 77: return 'R';

			}
		}
	}
	char ArrowSetting()
	{
		int RandomArrow = rand() % 4;
		switch (RandomArrow) {
		case 0: return 'U';
		case 1: return 'D';
		case 2: return 'L';
		case 3: return 'R';
		}
	}

	void printArrow(char dir) {
		switch (dir) {
		case 'U': cout << "↑ "; break;
		case 'D': cout << "↓ "; break;
		case 'L': cout << "← "; break;
		case 'R': cout << "→ "; break;
		}
	}
	char TimeAttack(int TimeOut, steady_clock::time_point GameStart, int GameDuration, const deque<char>& arrow)
	{
		auto InputStart = steady_clock::now();//현재시간을 측정해 InputStart에 저장
		int lastShownSecond = -1;	//경과시간 카운팅

		while (true)
		{
			auto now = steady_clock::now();//지금 시간을 저장 플레이타임을 위한것
			int NowGameTime = duration_cast<seconds>(now - GameStart).count();//플레이시간을 구한다.
			int LeftTime = GameDuration - NowGameTime;//전체시간 - 플레이타임

			if (LeftTime <= 0) return 'G';
			//입력안하면 게임오버 코드
			auto NowGameInput = duration_cast<milliseconds>(now - InputStart).count();
			//실시간 입력카운트 = 밀리초 단위로 계산한 최근 입력한 시간 - 지금의 시간
			//즉 입력한 시간이 0이되고 거기서 경가한시간을 뺀다.
			if (NowGameInput >= TimeOut) return 'T';
			//만약 경과시간이 제한된 시간 초과서 T로 이동

			if (_kbhit())
			{
				return GetArrowKey();
			}
			//실시간 화면 초기화
			if (LeftTime != lastShownSecond)
			{
				system("cls");
				cout << "화살표게임 가장 왼쪽의 화살표에 맞는 방향키를 눌러주세요." << endl;
				cout << "남은시간: " << LeftTime << endl;

				for (char dir : arrow)
				{
					printArrow(dir);
				}
				cout << endl;
				lastShownSecond = LeftTime;//플레이시간이 제한시간과 같다.
				//0.5초마다 갱신하는 기능에 쓰일 예정
			}
		}
	}
	void easy()
	{

		deque<char> arrow;//deque말고 queue로 바꿔보기<<<독학으로 차이에 대해 좀더 알아보기
		for (int i = 0; i < 10; i++)
		{
			arrow.push_back(ArrowSetting());
		}
		int Timelimit = 30;
		auto gameStartTime = steady_clock::now();
		while (true)
		{
			char input = TimeAttack(5000, gameStartTime, Timelimit, arrow);
			if (input == 'G')
			{
				system("cls");
				cout << "GAME OVER" << endl;
				cout << "제한시간을 초과했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == 'T')
			{
				system("cls");
				cout << "게임이 종료되었습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == arrow.front())
			{
				arrow.pop_front();
				arrow.push_back(ArrowSetting());
				score++;
			}
			else if (input != arrow.front())
			{
				system("cls");
				cout << "잘못된 값을 입력했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
		}

	}
	void normal()
	{
		deque<char> arrow;//deque말고 queue로 바꿔보기<<<독학으로 차이에 대해 좀더 알아보기
		for (int i = 0; i < 10; i++)
		{
			arrow.push_back(ArrowSetting());
		}
		int Timelimit = 30;
		auto gameStartTime = steady_clock::now();
		while (true)
		{
			char input = TimeAttack(3000, gameStartTime, Timelimit, arrow);
			if (input == 'G')
			{
				system("cls");
				cout << "GAME OVER" << endl;
				cout << "제한시간을 초과했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == 'T')
			{
				system("cls");
				cout << "게임이 종료되었습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == arrow.front())
			{
				arrow.pop_front();
				arrow.push_back(ArrowSetting());
				score++;
			}
			else if (input != arrow.front())
			{
				system("cls");
				cout << "잘못된 값을 입력했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//슬립동안 키입력방지
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
		}
	}
	void hard()
	{
		deque<char> arrow;//deque말고 queue로 바꿔보기<<<독학으로 차이에 대해 좀더 알아보기
		for (int i = 0; i < 10; i++)
		{
			arrow.push_back(ArrowSetting());
		}
		int Timelimit = 30;
		auto gameStartTime = steady_clock::now();
		while (true)
		{
			char input = TimeAttack(2000, gameStartTime, Timelimit, arrow);
			if (input == 'G')
			{
				system("cls");
				cout << "GAME OVER" << endl;
				cout << "제한시간을 초과했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == 'T')
			{
				system("cls");
				cout << "게임이 종료되었습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
			else if (input == arrow.front())
			{
				arrow.pop_front();
				arrow.push_back(ArrowSetting());
				score++;
			}
			else if (input != arrow.front())
			{
				system("cls");
				cout << "잘못된 값을 입력했습니다." << endl;
				cout << "최종점수 :" << score << endl;
				Sleep(3000);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "아무키나 입력해주세요." << endl;
				score = 0;
				_getch();
				break;
			}
		}
	}
	void rule()
	{
		while (true)
		{
			system("cls");
			cout << "화살표게임" << endl;
			cout << "화면에 → ← ↑ ↓ 중 무작위의 화살표가 출력됩니다." << endl;
			cout << "그에 알맞은 방향키를 누르면 성공" << endl;
			cout << "다른 방향키를 누르면 실패" << endl;
			cout << "총 30초의 시간이 주어지며, 난이도 별로 입력제한 시간이 있습니다." << endl;
			cout << "제한된 시간동안 방향키를 입력하지 못하면 실패로 간주합니다." << endl;
			cout << "쉬움- 5초 \n보통- 3초 \n 어려움- 2초" << endl;
			cout << "아무키나 입력하시면 이전 화면으로 돌아갑니다." << endl;
			_getch();
			break;
		}


	}
};

//화살표게임
//화살표게임 난이도 선택
class ArrowSelect
{
public:
	int SelectMemory;
	void Arrow()
	{
		ArrowGame SelectArrow;
		while (true)
		{
			system("cls");
			cout << "반응속도 테스트" << endl;
			cout << "난이도를 선택해 주세요." << endl;
			cout << "쉬움 [1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
			int Level;
			cin >> Level;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (Level == 0) break;
			if (Level == 1)
			{

				SelectArrow.easy();
			}
			if (Level == 2)
			{
				SelectArrow.normal();
			}
			if (Level == 3)
			{
				SelectArrow.hard();
			}if (Level == 9)
			{
				SelectArrow.rule();
			}
			else
			{
				cout << "잘못된 값을 입력했습니다" << endl;

			}
		}
	}
};
// 화살표게임 난이도 선택
//게임시작
class ProgramStart
{
public:
	void start()
	{
		while (true)
		{
			system("cls");
			cout << "게임을 시작합니다." << endl;
			cout << "[1]사칙연산 \n[2]기억력테스트 \n[3]반응속도테스트 \n[0]게임종료" << endl;
			int SelectGame;
			cin >> SelectGame;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (SelectGame == 0) break;
			if (SelectGame == 1)
			{
				QuizMath SelectMath;
				SelectMath.math();
			}  if (SelectGame == 2)
			{
				QuizMemory SelectMemory;
				SelectMemory.Memory();
			} if (SelectGame == 3)
			{
				ArrowSelect SelectArrow;
				SelectArrow.Arrow();
			}

		}
	}
};
//게인시작


//말랑말랑두뇌교실
int main()
{
	srand((unsigned int)time(NULL));

	ProgramStart ProgramStarter;
	ProgramStarter.start();

}