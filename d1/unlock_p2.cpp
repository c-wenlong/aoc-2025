#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int cnt = 0;
  int dial = 50;
  ifstream inputFile("./assets/input.txt");
  string line;
  while (getline(inputFile, line)) {
    char direction = line[0];
    int distance = stoi(line.substr(1));
    int quotient = distance / 100;
    int remainder = distance % 100;
    if (direction == 'L') {
      if (dial == 0) {
        cnt--;
      };
      dial -= remainder;
      if (dial < 0) {
        dial += 100;
        cnt++;
      };
    } else {
      dial += remainder;
      if (dial > 99) {
        dial -= 100;
        cnt++;
      };
      if (dial == 0) {
        cnt--;
      }
    };
    if (dial == 0) {
      cnt++;
    }
    cnt += quotient;
    cout << "line: " << line << ", count: " << cnt << ", dial: " << dial
         << endl;
  }
  cout << cnt << endl;
}
