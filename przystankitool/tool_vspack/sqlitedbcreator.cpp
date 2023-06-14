#include <iostream>
#include <sqlite3.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

static int createDB(const char* s)
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open(s, &DB);
    sqlite3_close(DB);
    return 0;
}

static int createTable(const char* s)
{
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
        if (exit != SQLITE_OK)
        {
            cerr << "Error Create Table" << endl;
            sqlite3_free(messageError);
        }
        else { cout << "Table created successfully!" << endl; }
        sqlite3_close(DB);
    }
    catch (const exception& e) { cerr << e.what(); }
    return 0;
}

static int insertData(const char* s, string sql) {
    sqlite3* DB;
    char* messageError;

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error while inserting" << endl;
        sqlite3_free(messageError);
    }
    else { cout << "Records created!" << endl; }
    return 0;
}

static int callback(void* NotUsed, int argc, char** argv, char** azColname) {
    std::cout << "\n\n argv: " << argv << "argc: " << argc << "\n\n";
    std::cout << "_______________________________________" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < argc; i++) {
        //cout << azColname[i] << ": " << argv[i] << endl;
        std::cout << "  |   " << azColname[i] << ": " << argv[i] << std::endl;
        if (i == argc - 1) { std::cout << "_______________________________________" << std::endl; }

    }
    return 0;
}

static int selectData(const char* s, string sql) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);
    char* mesEr;
    
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &mesEr);
    if (exit != SQLITE_OK) { return 12; }
    return 0;
}

static int selectDataClear(const char* s, string sql) {

}
static int creatingThruwayTable(const char* s, string line, string status) {
    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS \"" + status + line +
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

void CreatingRequests(char* dir)
{
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

                    insertData(dir, request);
                }
            }
        }
    }
    else { cout << "Not good!" << endl; }
}

void Searching(const char* s, string table, string findable) {
    sqlite3* DB;
    int exit = sqlite3_open(s, &DB);
    string sql = "SELECT stop FROM " + table + " WHERE stop ='" + findable + "';";
    std::cout << sql << "\n";
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
}

int main()
{
    const char* dir = "C:\\Users\\admin\\Desktop\\PrzystankiTool\\przystankitool\\sqlite\\przystanki.db";
    sqlite3* DB;
    string sql;
    /*
    char* messageError;
    int exit = sqlite3_open(dir, &DB);
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit==SQLITE_OK)
    {
        cerr << "DaamnError while inserting" << endl;
        sqlite3_free(messageError);
    }
    else { cout << "DaaamnBadRecords created!" << endl; }*/

    std::fstream db(dir);
    if (!db.is_open()) { std::cout << "Your file or database does not exist, try another adress!\n"; return 1; }


    // const char* dir = "c:\\Users\\checkthistape\\Desktop\\PrzystankiTool\\sqlitedbcreator\\przystanki.db";

    for (int i = 0; i < 70; i++) {
        string t = "SELECT id FROM t" + to_string(i) + " WHERE stop=\'Biprostal\'";
        std::cout << t << "\n\n";
        selectData(dir, t);
    }

    std::cout << "*exit to exit the program" << std::endl;
    std::cout << "*help to show all things you can do" << std::endl;
    while (true) {
        std::cout << std::endl << "> "; std::getline(std::cin, sql);

        if (sql == "*help") { std::cout << "*help to help;\n*exit to exit;\n*trams to show all tram lines;\n*buses to show all bus lines;\n"; }
        if (sql == "*sql") { std::cout << "(Example: SELECT stop FROM b100;)   "; std::getline(std::cin, sql); std::cout << std::endl << sql << std::endl; selectData(dir, sql); }
        if (sql == "*exit") { break; }
        if (sql == "*search") { Searching(dir, "t4", "Struga"); }
        if (sql == "*line") {
            std::cout << "Tram or bus?(t - tram, b - bus): ";
            std::getline(std::cin, sql);
            if (sql != "t" or sql != "T" or sql != "b" or sql != "B") { std::cerr << "Sorry, your input is not correct!" << std::endl; }
            else { std::cout << "Write your line: "; std::getline(std::cin, sql); }
        }
        if (sql == "*trams") { sql = "SELECT name FROM SQLITE_SCHEMA WHERE name LIKE \"t_%\";"; selectData(dir, sql); }
        if (sql == "*buses") { sql = "SELECT name FROM SQLITE_SCHEMA WHERE name LIKE \"b_%\";"; selectData(dir, sql); }
        if (sql[0] == 't' && sql.size()<=3) { std::cout<<"You r searching for "<< sql <<" tram\n"; selectData(dir, "SELECT stop FROM " + sql);}
        if (sql[0] == 't' && sql.size()>3) { std::cout << "We dont have " << sql << " tram line in our db\n"; }
        if (sql[0] == 'b' && sql.size()<=4) { std::cout << " You r searching for " << sql << " bus\n"; selectData(dir, "SELECT stop FROM " + sql); }
        if (sql[0] == 'b' && sql.size()>4) { std::cout << "We dont have " << sql << " bus line in our db\n"; }
    }

}
