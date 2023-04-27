#include <windows.h>
#include "headers\txtworkingclass.h"

// C:\Users\Public\Desktop



int main() 
{
	SetConsoleOutputCP(CP_UTF8);

	/*
	string file1 = "locale.txt";
	string file2 = "przystanki.txt";
	string file3 = "save.txt";
	*/
	
	try {
		textworking file;

		string request;
		while (true)
		{
			cout << " > "; cin >> request;
			if (request == "*remove" and file.getmode() == 1) { file.removingfile(); }
			if (request == "*showmode") { cout << file.getmode() << std::endl; }
			if (request == "*help") { file.instructions(); }
			else { std::cout << std::endl << "There is no command: " << request << "." << std::endl << "Maybe try again or write *help to check all available commands ^^" << std::endl << std::endl; }
			if (request == "*open" and file.getmode() == 1) { file.open(); }
			if (request == "*fileexist" and file.getmode() == 1) { file.fileexist(); }
			if (request == "*create" and file.getmode() == 1) { file.create(); }
			if (request == "*showfilename" and file.getmode() == 1) { cout << "\nFile name: " << file.getfullfile() << std::endl; }
			if (request == "*exit") { break; return 0; }
			if (request == "*write" and file.getmode() == 1) { file.writing(); }
			if ((request == "*exit -r" or request == "*exit -d") and file.getmode() == 1) { file.removingfile(); break; }
			if (request == "*showadress" and file.getmode() == 1) { cout << "\nAdress: " << file.getadress() << std::endl; }
			// if (request == "*create -n"){}
			if (request == "*showword") { cout << "\nWord: " << file.getword() << std::endl; }
			/*~~~~~~~~~.Second Mode.~~~~~~~~~*/
			if (request == "*mode2" and file.getmode() == 1) { file.setmode(2); cout << "\nYou've changed mode to: " << file.getmode() << std::endl; }
			if (request == "*mode1" and file.getmode() == 2) { file.setmode(1); cout << "\nYou've changed mode to: " << file.getmode() << std::endl; }
			else { cout << "Your mode is actually: " << file.getmode() << std::endl; }
			if (request == "*createdefaultfiles" and file.getmode() == 2) { cout << "u"; }

		}
		//file.fileexist();


		return 0;

	}
	catch (...) {
		std::cout << "Error" << std::endl;
	}
	

	// 

	/*
	fstream file(file1, ios::out | ios::in);
	string findable;
	*/

	/*
	if (file.is_open()) 
	{
		getline(file, findable); // "najblizsze przyjazdy" to variable findable
		int findable_length = findable.length(); // length of variable findable

		fstream przystanki(file2, ios::out | ios::in);
		string data; // variable for data from "przystanki.txt"

		cout << "Przystanki length: " << file_length(file2) << endl << endl;

		if (przystanki.is_open())
		{
			fstream save(file3, ios::out | ios::in);
			string saving;

			while (getline(przystanki, data)) // while we get data from "przystanki.txt"
			{
				auto findable_pos = data.find(findable); // finding a position of variable finding
		
				if (findable_pos >= 0 and findable_pos < sizeof(unsigned long long))
				{
					data.replace(findable_pos, findable_length, "  ,  ");
				}

				if (x == 0) {
					save << "  "; // adding spaces in start
				}

				save << data;

				cout << x++ << ": " << data << endl;
				if (save.is_open())
				{
					// if (space_pos >= 0 and space_pos < meganumb) { data.replace(space_pos, 2, "hey"); }
					
				}
				else {
					cout << "Error while opening: " << file3 << "..." << endl;
				}

			}

			przystanki.close();
			save.close();

			przystanki.open(file2, ios::out | ios::in | ios::trunc);
			save.open(file3, ios::out | ios::in);

			if (przystanki.is_open() and save.is_open()) 
			{
				getline(save, saving);
				int saving_length = saving.length();

				while (saving_length>0) 
				{
					saving_length = saving_length - 1;

					auto space_pos = saving.find(spaces);

					if (space_pos >= 0 and space_pos < sizeof(unsigned long long) and space_pos!=string::npos)
					{
						saving.replace(space_pos, 2, wow);
					}
				}
				
				cout << "\n\nOperation is did\n" << endl;
				cout <<"Data is: " << saving;
			
				przystanki << "[" << saving << "]";
			}
			else {
				cout << 'n';
			}
		}
		else {
			cout << "Error while opening: " << file2 << "..." << endl;
		}

	}
	else {
		cout << "Error while opening: " << file1 << "..." << endl;
	}
	return 0;
	*/
}




