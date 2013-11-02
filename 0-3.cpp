#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

void bubblesort(std::vector<int> &mas) {
  int temp = 0;
  bool exit = false;
  std::vector<int>::iterator it;
  while (!exit) {
  exit = true;
  for (it = mas.begin(); it < mas.end()-1; ++it)
  if ((*it) > *(it+1)) {
    temp = *it;
    *it = *(it+1);
    *(it+1) = temp;
    exit = false;
    }
  }
}

int main() {
  std::vector<int> mas;
  while (!std::cin.eof()) {
  std::string line;
  std::getline(std::cin, line);
  if (!(line.empty() && std::cin.eof())) {
      int num = atoi(line.c_str());
      mas.push_back(num);
    }
  }
  bubblesort(mas);
  std::vector<int>::iterator it;
  for (it = mas.begin(); it < mas.end(); ++it) {
  std::cout << (*it) << std::endl;
  }
  return 0;
}