#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL,"ru");
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	int point = 1000;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
	{"wall", "Do you feel you're banging your head against something?"},
	{"glasses", "These might help you see the answer. "},
	{"labored", "Going slowly. is it?"},
	{"persistent", "Кеер at it."},
	{"jumble", "It's what the game is all about."}
	};
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //слово. которое нужно угадать
	string theHint = WORDS[choice][HINT]; //подсказка
	string jumble = theWord; // перемешанный вариант слова
	int length = jumble.size();
	for (int i = 0 ; i < length ; ++i)
	{
		int indexl = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[indexl];
		jumble[indexl] = jumble[index2];
		jumble[index2] = temp;
	}
	cout << "\t\t\tДобро пожаловать в Cловомеску!\n\n";
	cout << "Расшифруйте буквы, чтобы составить слово. \n";
	cout << "Напишите 'hint' чтобы получить подсказку (-500 очков). \n";
	cout << "За каждую ошибку -100 очков. \n";
	cout << "Напишите 'quit' чтобы выйти из игры. \n\n";
	cout << "расшифруй слово: " << jumble;
	string guess;
	cout << "\n\nВаше предположение: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
			point = point - 500;
		}
		else
		{
			cout << "Извини. Это не так. ";
			point = point - 100;
		}
		cout << "\n\nВаше предположение: ";
		cin >> guess;
	}
	if (guess == theWord)
{
		cout << "\nВот и все! Ты угадал!\n";
		cout << "\nваши очки = " << point<< "\n";
}
	cout << "\nСпасибо за игру.\n";
	return  0;
}