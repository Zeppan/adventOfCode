#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define PLUS_OPERATOR 1
#define MULTIPLIKATION_OPERATOR 2
#define END_OPERATOR 99

class strange_calc
{
public:

  void populate_list(std::string filename)
  {
    size_t pos;
    std::string token, str;
    std::string delimiter = ",";
    std::ifstream file(filename);
    std::getline(file, str);
    while ((pos = str.find(delimiter)) != std::string::npos) {
      token = str.substr(0, pos);
      list.push_back(std::stoi(token));
      str.erase(0, pos + delimiter.length());
    }
  }

  int calculate(int i1, int i2)
  {
    int i = 0;
    std::vector<int> tmp(list);
    tmp[1] = i1;
    tmp[2] = i2;
    while (tmp[i] != END_OPERATOR) {
      if (tmp[i] == PLUS_OPERATOR) {
        tmp[tmp[i+3]] = tmp[tmp[i+1]] + tmp[tmp[i+2]];
      } else if (tmp[i] == MULTIPLIKATION_OPERATOR) {
        tmp[tmp[i+3]] = tmp[tmp[i+1]] * tmp[tmp[i+2]];
      }
      i = i + 4;
    }
    return tmp[0];
  }

private:
  std::vector<int> list;
};

int main(void)
{
  strange_calc s;
  s.populate_list("input");
  int a = s.calculate(12, 2);
  std::cout << a << std::endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (s.calculate(i, j) == 19690720) {
	std::cout << "noun=" << i << ", verb=" << j << std::endl;
	break;
      }
    }
  }
  return 0;
}
