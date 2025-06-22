#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int count_lines(const string& fname, const string& word){
    ifstream infile(fname);
    string line;
    int count = 0;

    string target = word;
    for(char& c : target) c = tolower(c);

    while(getline(infile, line)){
        istringstream iss(line);
        string token;

        while (iss >> token) {
            for(char& c : token) c = tolower(c);
            if(token == target){
                count++;
                break;
            }
        }

    }
    return count;
}