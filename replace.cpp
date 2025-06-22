#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void replace_word(const std::string& fname, const std::string& old_word, const std::string& new_word, const std::string& out_fname)
{
    ifstream infile(fname);
    ofstream outfile(out_fname);
    string line;

    string lower_old = old_word;
    transform(lower_old.begin(), lower_old.end(), lower_old.begin(), ::tolower);

    while (getline(infile, line)) {
        string lowered_line = line;
        transform(lowered_line.begin(), lowered_line.end(), lowered_line.begin(), ::tolower);

        size_t pos = 0;
        while ((pos = lowered_line.find(lower_old, pos)) != string::npos) {
            line.replace(pos, old_word.length(), new_word);
            lowered_line.replace(pos, old_word.length(), new_word); // keep lowered_line in sync
            pos += new_word.length();
        }

        outfile << line << '\n';
    }
}
