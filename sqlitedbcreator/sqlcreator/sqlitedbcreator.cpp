#include <iostream>
#include <sqlite3.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

static int createDB(const char* s) {
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return 0;
}

static int createTable(const char* s) {
    sqlite3* DB;
    string sql = "CREATE TABLE IF NOT EXISTS GRADES("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "NAME TEXT NOT NULL,"
        "LNAME TEXT NOT NULL,"
        "AGE INT NOT NULL,"
        "ADRESS CHAR(50),"
        "GRADE CHAR(50) );";
    try {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error Create Table" << endl;
            sqlite3_free(messageError);

        }
        else {
            cout << "Table created successfully!"<<endl;
        }
        sqlite3_close(DB);

    }
    catch (const exception& e) { cerr << e.what(); }
    return 0;
}

static int insertData(const char* s, string sql) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    //string sql("INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');"
    //    "INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');"
    //    "INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        cerr << "Error while inserting" << endl;
        sqlite3_free(messageError);
    }
    else {
        cout << "Records created!" << endl;
    }
    return 0;
}

static int callback(void* NotUsed, int argc, char** argv, char** azColname) {
    for (int i = 0; i < argc; i++) {
        cout << azColname[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

static int selectData(const char* s, string sql) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);
    //string sql = "SELECT * FROM GRADES";

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    return 0;
}

static int creatingThruwayTable(const char* s, string line, string status) {
    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS \""+status+line+
            "\"(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "stop VARCHAR(255) );";

    cout << sql << endl;
    try {
        int exit = 0;

        exit = sqlite3_open(s, &DB);

        char* messageError;

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK) {
            cerr << "Error Create Table" << endl;
            sqlite3_free(messageError);

        }
        else {
            cout << "Table created successfully!" << endl;
        }
        sqlite3_close(DB);

    }
    catch (const exception& e) { cerr << e.what(); }
    return 0;
}

int main()
{
    sqlite3* DB;
    //const char* dir = "c:\\Users\\checkthistape\\Desktop\\SQLiteProject\\stud.sqlite";
    const char* dir = "c:\\Users\\checkthistape\\Desktop\\SQLiteProject\\stud.db";

    fstream file("../forsqlite.txt", ios::in | ios::out);
    fstream fileOut("../1.txt", ios::in | ios::out);
    string data;
    if (file.good() == true) {
        while (getline(file, data))
        {
            if (data != "\n") {
                // "Global" variables for each thruway
                string line = data.substr(0, data.find("."));
                int intl = stoi(line);
                string qua = data.substr(data.find(".") + 1, data.find("=") - data.find(".") - 1);
                string req = data.substr(data.find("[") + 1, data.find("]") - 1 - data.find("["));
                string status = "t"; // "t" - tram, "b" - bus

                if (intl >= 69) { status = "b"; }

                // Variables for cutting all stops in the thruway
                int comma = 0;
                int occurences = 0;
                vector <string> vec;

                /*cout << "line: " << line << " qua: " << qua << endl;
                cout << req << endl;*/

                cout << endl;

                creatingThruwayTable(dir, line, status);

                cout << endl;



                // Cutting whole stops string (string req) into the each element
                for (int i = 0; i < req.length(); i++)
                {
                    if (req.at(i) == ',')
                    {
                        occurences++;
                        if (occurences == 1) { string stop = req.substr(0, i - comma - 1); vec.push_back(stop); }
                        else { string stop = req.substr(comma + 1, i - comma - 1); vec.push_back(stop); }
                        comma = i;
                    }

                    if (i == req.length() - 1)
                    {
                        occurences++;
                        string stop = req.substr(comma + 1, req.find("]") - comma);
                        vec.push_back(stop);
                    }
                }

                // Printing SQL request
                for (int j = 0; j < vec.size(); j++) {
                    
                    string request = "INSERT INTO " + status + line + " (stop)VALUES(" + vec.at(j) + "); ";
                    
                    insertData(dir,request);
                    //fileOut << "INSERT INTO " << line << status << " (stop) VALUES(" << vec.at(j) << ");" << endl;
                }

                //fileOut << endl;
                cout << endl;

                /*fileOut << endl;

                fileOut << req << endl;*/
            
            
            }
            
        }
    }
    else {
        cout << "Not good!" << endl;
    }
    

    //createTable(dir); 
    //insertData(dir);
    
    //string sql("INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');"
    //    "INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');"
    //    "INSERT INTO GRADES (NAME, LNAME, AGE,ADRESS,GRADE) VALUES('Alice','Chapa',35,'Tampa','A');");

    //selectData(dir, "SELECT * FROM GRADES");
    //cout <<endl<< sql << endl;
    
    //createDB(dir);
    std::cout << "Hello World!\n";
}
