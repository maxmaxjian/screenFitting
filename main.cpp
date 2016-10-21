#include <iostream>
#include <vector>
#include <string>

class solution {
  public:
    int wordsTyping(const std::vector<std::string> & sentence, int rows, int cols) {
        using std::vector;
        using std::string;

        string str;
        int curr = 0, count = 0;
        size_t len = sentence.size();
        while (curr < rows*cols) {
            if (sentence[count%len].size() <= cols-curr%cols) {
                str.append(sentence[count%len]);
                curr += sentence[count%len].size();
                count++;
                if (curr%cols != 0) {
                    curr++;
                    str.append("^");
                }
            }
            else {
                while (curr%cols != cols-1) {
                    curr++;
                    str.append("^");
                }
                curr++;
                str.append("^");
            }
        }

        vector<string> screen;
        size_t i = 0;
        while (i < str.size()) {
            screen.push_back(str.substr(i, cols));
            std::cout << screen.back() << std::endl;
            i += cols;
        }

        return count/len;
    }
};

int main() {
    // std::vector<std::string> sentences{"hello", "world"};
    // int rows = 2, cols = 8;

    // std::vector<std::string> sentences{"a", "bcd", "e"};
    // int rows = 3, cols = 6;

    std::vector<std::string> sentences{"I", "had", "apple", "pie"};
    int rows = 4, cols = 5;

    solution soln;
    int num = soln.wordsTyping(sentences, rows, cols);
    std::cout << "The given sentence can be fitted on the screen for " << num << " times.\n";
}
