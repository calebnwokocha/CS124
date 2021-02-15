#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	char plural_noun[256];
	char type_of_liquid[256];
	char adjective[256];
	char funny_noise[256];
	char another_funny_noise[256];
	char animal[256];
	char another_animal[256];
	char fileName[256];
	char textInput;

	do
	{
		cout << "\nPlease enter the filename of the Mad Lib: ";
		cin >> fileName;

		ofstream fout;
		fout.open(fileName);

		cout << "\tPlural noun: ";
		cin >> plural_noun;
		fout << plural_noun << "\n";

		cout << "\tPlural noun: ";
		cin >> plural_noun;
		fout << plural_noun << "\n";

		cout << "\tType of liquid: ";
		cin >> type_of_liquid;
		fout << type_of_liquid << "\n";

		cout << "\tAdjective: ";
		cin >> adjective;
		fout << adjective << "\n";

		cout << "\tFunny noise: ";
		cin >> funny_noise;
		fout << funny_noise << "\n";

		cout << "\tAnother funny noise: ";
		cin >> another_funny_noise;
		fout << another_funny_noise << "\n";

		cout << "\tAdjective: ";
		cin >> adjective;
		fout << adjective << "\n";

		cout << "\tAnimal: ";
		cin >> animal;
		fout << animal << "\n";

		cout << "\tAnother animal: ";
		cin >> another_animal;
		fout << another_animal << "\n";

		fout.close();

		cout << "\nZoos are places where wild ";
		ifstream fin;
		fin.open(fileName);
		string str;
		getline(fin, str);
		cout << str << " are kept in pens or cages\n"
			<< "so that ";
		getline(fin, str);
		cout << str << " can come and look at them. There is a zoo\n"
			<< "in the park beside the ";
		getline(fin, str);
		cout << str << " fountain. When it is feeding time,\n"
			<< "all the animals make ";
		getline(fin, str);
		cout << str << " noises. The elephant goes \"";
		getline(fin, str);
		cout << str << "\"\n"
			<< "and the turtledoves go \"";
		getline(fin, str);
		cout << str << ".\" My favorite animal is the\n";
		getline(fin, str);
		cout << str << " ";
		getline(fin, str);
		cout << str << ", so fast it can outrun a/an ";
		getline(fin, str);
		cout << str << ".\nYou never know what you will find at the zoo.";

		fin.close();

		cout << "\n\nDo you want to play again (y/n)? ";
		cin >> textInput;
		if (textInput == 'y' || textInput == 'Y')
			cout << "\nNew game!" << endl;
		else if (textInput == 'n' || textInput == 'N')
			cout << "\nThank you for playing." << endl;
		else
			cout << "\nInvalid input.";

	} while (textInput == 'y' || textInput == 'Y');

	return 0;
}