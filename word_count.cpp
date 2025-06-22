#include <fstream>
#include <sstream>
#include <string>
#include "show_file.h"

using namespace std;

void word_count(const string& input_fname, const string& output_fname){
    ifstream infile(input_fname);
    ofstream outstream(output_fname);

    string line;
    while(getline(infile,line)){
        istringstream iss(line);
        int count = 0;
        string t;
        while(iss >> t) count++;
        outstream << count << '\n';
    }
}
