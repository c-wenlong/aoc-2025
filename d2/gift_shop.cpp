#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ifstream inputFile("./assets/input_test.txt");
  ostringstream ss;
  ss << inputFile.rdbuf();
  string content = ss.str();

  istringstream stream(content);

  string line;
  int cnt = 0;
  string s, l;

  istringstream tmp;
  while (getline(stream, line, ',')) {
    istringstream tmp(line);
    getline(tmp, s, '-');
    getline(tmp, l, '-');
    if (s.size() % 2 == 1){
      s = "1" + string(s.size(), '0');
    }
    if (l.size() % 2 == 1){
      l = string(l.size() - 1, '9');
    }
    string s_left = s.substr(0, s.size()/2);
    string s_right = s.substr(s.size()/2, s.size());
    string l_left = l.substr(0, l.size()/2);
    string l_right = l.substr(l.size()/2, l.size());

    left_min = min(stoi(s_left), stoi(l_left));
    left_max = max(stoi(s_left), stoi(l_left));
    int s_int = stoi(s);
    int l_int = stoi(l);

    // no valid range between right and left
    if (s_int > l_int){
      continue;
    }
    
    cout << s_int << " " << l_int << endl;
    cout << s_left << " " << s_right << endl;
    cout << l_left << " " << l_right << endl;
    cout << left_min << " " << left_max << endl;
  };

  return cnt;
}