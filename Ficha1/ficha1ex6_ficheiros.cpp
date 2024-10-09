#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

    // Create a text string, which is used to output the text file
    string myText;
    string nome;
    cout <<"Indique o nome do ficheiro.txt , acrescente o .txt no final \n ->";
    cin >> nome;
    // Read from the text file
    ifstream MyReadFile(nome);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }

    // Close the file
    MyReadFile.close();
}
