#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class textworking {
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
	string getfullfile() { return _file; }
	string getadress() { return _adress; }

	void removingfile()
	{
		const char* c_adress = _adress.c_str();

		if (fileexistbool() == false) { cout << "\nFile does not exist\n"; }

		while (fileexistbool() == true)
		{
			std::remove(c_adress);
			if (fileexistbool() == false) { cout << "\nFile on adress " << _adress << " deleted successfuly!\n"; break; }
		}
	}

	bool fileexistbool()
	{
		ifstream filex(_adress);
		if (filex.good() == true) { return true; }
		else { return false; }
	}

	void fileexist()
	{
		ifstream filex(_adress);
		if (filex.good() == true) { cout << "\nFile " << _file << " on adress " << _adress << " exists.\n"; }
		else { cout << "\nFile " << _file << " does not exist\n"; }
	}

	void open()
	{
		fstream filex(_adress, ios::in);
		string data;

		if (filex.good() and filex.is_open())
		{
			std::cout << "\n*.~~~~~~~~~~~~~~.*.~~~~~~~~~~~~~~.*" << std::endl;
			while (getline(filex, data)) { cout << data << endl; }
			std::cout << "*.~~~~~~~~~~~~~~.*.~~~~~~~~~~~~~~.*\n" << std::endl;
		}

	}
	void writing()
	{
		ofstream filex;
		filex.open(_adress, /*ios::ate || ios::out*/ ios::app);

		string data;
		std::cout << " " << std::endl;
		if (filex.is_open())
		{
			cout << "## ";
			getline(std::cin, data, '\n');
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