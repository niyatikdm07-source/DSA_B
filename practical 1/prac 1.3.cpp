#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence, w = "", longest = "";

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == ' ') {

            if (w.length() > longest.length()) {
                longest = w;
            }

            w = "";
        }
        else {
            w += sentence[i];
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;

    return 0;
}
