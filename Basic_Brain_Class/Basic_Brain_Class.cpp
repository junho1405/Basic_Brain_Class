#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>
#include <deque>
#include <Windows.h>
#include <Vector>

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
			system("cls");
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
			system("cls");
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
			system("cls");
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
			system("cls");
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
			system("cls");
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
			system("cls");
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
		system("cls");
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
		system("cls");
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
		system("cls");
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
					system("cls");
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
					system("cls");
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
//사칙연산 난이도 선택

//기억력테스트
class MemoryQuiz
{
	int score = 0;
public:
	char QuizLetter()
	{
		return 'a' + rand() % 26;
	}
	int MemoryQuizLevel = 1;
	vector<char> Letter;
	string input;

	void easy()
	{
		Letter.clear();
		cout << "이지모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(1500);
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
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << MemoryQuizLevel-1 << endl << endl;
				cout << "아무키나 입력해주세요" << endl;
				_getch();
				break;
			}
		}
	}
	void normal() 
	{
		Letter.clear();
		cout << "이지모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(1000);
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
				Sleep(1000);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << MemoryQuizLevel-1 << endl << endl;
				cout << "아무키나 입력해주세요" << endl;
				_getch();
				break;
			}
		}
	}
	void hard() 
	{
		Letter.clear();
		cout << "이지모드" << endl;
		while (true)
		{
			system("cls");
			char quiz = QuizLetter();
			Letter.push_back(quiz);
			cout << MemoryQuizLevel << "단계" << endl;
			cout << "아래에 나오는 글자를 기억하세요." << endl;
			cout << quiz << endl;
			Sleep(500);
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
				Sleep(500);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "오답입니다." << endl;
				cout << "지금까지 나온 글자들" << endl;
				for (char a : Letter) cout << a << endl;
				cout << "최종 점수:" << MemoryQuizLevel-1 << endl << endl;
				cout << "아무키나 입력해주세요" << endl;
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
public :
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
	void easy()
	{

	}
	void normal()
	{

	}
	void hard()
	{

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
			cout << "난이도를 선택해 주세요." << endl;
			cout << "쉬움 [1] 보통[2] 어려움[3] 뒤로가기[0]" << endl;
			int Level;
			cin >> Level;

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
			if (SelectGame == 0) break;
			if (SelectGame == 1)
			{
				QuizMath SelectMath;
				SelectMath.math();
			}  if(SelectGame == 2)
			{
				QuizMemory SelectMemory;
				SelectMemory.Memory();
			}


		}

	}
};
//게인시작
 

//말랑말랑두뇌교실
int main()
{
	srand(time(NULL));

	ProgramStart ProgramStarter;
	ProgramStarter.start();

}