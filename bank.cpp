#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int balance(const string& file, int month, int year){
    int total = 0;
    ifstream infile(file);
    if(!infile.is_open())return 0;

    string line;

    while(getline(infile, line)){
        istringstream iss(line);
        string date, type;
        int amount;

        if(!(iss >> date >> type >> amount)) continue;

        int d, m, y;
        char dash1, dash2;
        istringstream dateStream(date);
        dateStream >> d >> dash1 >> m >> dash2 >> y;

        if((m == month) && (y == year)){
            if(type == "deposit") total +=amount;
            else if(type == "withdrawal") total -= amount;
        }
    }


  return total;
}