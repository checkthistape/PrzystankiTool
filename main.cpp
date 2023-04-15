#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int meganumb = 18446744073709551615;

	fstream file("locale.txt", ios::out|ios::in);
	string findable;

	if (file.is_open()) 
	{

		getline(file, findable); // "najblizsze przyjazdy" to variable findable
		int findable_length = findable.length(); 

		fstream przystanki("przystanki.txt", ios::out | ios::in);
		string data; // variable for data from "przystanki.txt"

		if (przystanki.is_open())
		{
			//przystanki << findable;

			fstream save("save.txt", ios::out | ios::in);
			string saving;

			string wow = string(1, '"');
			string spaces = "  ";

			while (getline(przystanki, data)) // while we get data from "przystanki.txt"
			{
				auto findable_pos = data.find(findable); // finding a position of variable finding
				auto space_pos = data.find(spaces);

				if (findable_pos>=0 and findable_pos<meganumb)
				{ 
					data.replace(findable_pos, findable_length, "    ");
				}
				
				// przystanki.close();
				przystanki.open("przystanki.txt", ios::in | ios::ate | ios::out);
				przystanki << data;
				przystanki.close();
				przystanki.open("przystanki.txt", ios::in | ios::out);

				 /*
				 if (save.is_open())
				 {
					 if (space_pos >= 0 and space_pos < meganumb) {	 data.replace(space_pos, 2, "hey"); }
					 save << data;
				 }*/
				

				// if (save << data) { cout << endl << "Operation has been finished" << endl; }
				// else { cout << "Error" << endl; }
			}
			

			// auto data_length = length(data);

			// for(int x=0; x<)
				
				//if (save.is_open()) {  }
			}
			
			file.close();
			przystanki.close();

		}
		
	}
	

	

