#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream inputFile("./assets/input.txt");
  string line;
  getline(inputFile, line);
  cout << line << endl;
}