#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
// C:\Users\Public\Desktop

class file_action {
private:
	/*.~~~~~~~~~~.Default mode.~~~~~~~~~~.*/
	string _filename;
	string _extension = ".txt";
	string _file; //= _filename.append(_extension);
	string _documents = "C:\\Users\\Public\\Documents\\";
	string _adress;

	int _longlongsize = 184467440737095516;
	string _wow = string(1, '"');
	string _spaces = "  ";

	/*.~~~~~~~~~~.Second mode.~~~~~~~~~~.*/
	string _word = _documents + "word" + _extension;
	string _przystanki = _documents + "przystanki" + _extension;
	string _result = _documents + "result" + _extension;
	int _mode = 1;

public:
	

	void setfilename(string filename) { _filename = filename;	_file = filename + _extension; _adress = _documents + _file; }

	void create() {
		cout << " Write a name of file you want to create: ";
		string name;
		cin >> name;
		setfilename(name);
		creatingfile();
		if (fileexistbool() == true) { cout << "\nFile " << _file << " was created on adress " << _adress << std::endl; }
		else { cout << "\nEr!\n"; }
	}

	void creatingfile() { ofstream{ _adress }; }
	string createfile(string adress) { ofstream{ adress }; }

	string getfilename() { return _filename; }
	string getfullfile() { return _file;  }
	string getadress() { return _adress;  }

	void removingfile() 
	{
		const char* c_adress = _adress.c_str();

		if (fileexistbool() == false) { cout << "\nFile does not exist\n"; }

		while (fileexistbool() == true)
		{
			std::remove(c_adress);
			if (fileexistbool() == false) { cout << "\nFile on adress "<< _adress << " deleted successfuly!\n"; break; }
		}
	}
	
	bool fileexistbool() 
	{	ifstream filex(_adress);
		if (filex.good()==true) { return true; }
		else { return false; }	}

	void fileexist()
	{
		ifstream filex(_adress);
		if (filex.good()==true) { cout << "\nFile " << _file << " on adress " << _adress << " exists.\n"; }
		else { cout << "\nFile " << _file << " does not exist\n"; }
	}

	void open()
	{
		fstream filex(_adress, ios::in);
		string data;

		if (filex.good() and filex.is_open())
		{	std::cout << "\n*.~~~~~~~~~~~~~~.*.~~~~~~~~~~~~~~.*" << std::endl;
			while (getline(filex, data) ){ cout << data << endl; }
			std::cout << "*.~~~~~~~~~~~~~~.*.~~~~~~~~~~~~~~.*\n" << std::endl;	}

	}
	void writing()
	{	ofstream filex;
		filex.open(_adress, /*ios::ate || ios::out*/ ios::app);

		string data;
		std::cout << " " << std::endl;
		if (filex.is_open())
		{
			cout << "## ";
			getline(std::cin, data,'\n');
			// cin >> data;
			filex << data;
		}
	}

	unsigned int file_length(string filename) // finding a length of file (quantity of characters in it)
	{
		ifstream infile(filename.c_str());
		unsigned int file_length = 0;
		while (infile.get() != EOF) { file_length++; }
		infile.close();
		return file_length;
	}
	void instructions()
	{	
		cout << "\nWrite *create to create a new file\nWrite *mode to select different mods: 1 - mod is created for default actions with files; 2 - ??\nWrite *opeb to open created file\nWrite *fileexist to check file existing\nWrite *remove to remove file\nWrite *showfilename to show file name\nWrite *showadress to show adress of file\nWrite *exit to exit " << std::endl << std::endl;
	}
	/*.~~~~~~~~~~~~.Second mode.~~~~~~~~~~~~.*/
	int getmode() {
		return _mode;
	}

	void setmode(int mode) {
		_mode = mode;
	}

	void impfilescreate()
	{
		ofstream{ _documents };
	}
	
	string getword() { return _word; }
	string getprzystanki() { return _przystanki; }
	string getresult() { return _result; }

	void autocreating() {
		createfile(_word);
		createfile(_przystanki);
		createfile(_result);
	}
};

int main() 
{
	SetConsoleOutputCP(CP_UTF8);

	/*
	string file1 = "locale.txt";
	string file2 = "przystanki.txt";
	string file3 = "save.txt";
	*/
	
	try {
		file_action file;

		string request;
		while (true)
		{
			cout << " > "; cin >> request;
			if (request == "*remove" and file.getmode() == 1) { file.removingfile(); }
			if (request == "*showmode") { cout << file.getmode() << std::endl; }
			if (request == "*help") { file.instructions(); }
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
			if{  }
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




