#include <list>
#include <string>
#include <iostream>
#include <fstream>

class module_calc
{
public:
  module_calc()
  {
    total_sum = 0;
  }

  void poplate_list(std::string filename)
  {
    std::ifstream file(filename);
    std::string str;
    while (std::getline(file, str)) {
      list.push_back(std::stoi(str));
    }
  }

  int calculate_total_sum(void)
  {
    for (int i : list) {
      i = (i / 3) - 2;
      total_sum += i;
      get_total_fuel(i);
    }
    return total_sum;
  }

private:
  int total_sum;
  std::list<int> list;

  void get_total_fuel(int fuel)
  {
    fuel = (fuel / 3) - 2;
    if (fuel <= 0) {
      return;
    }
    else {
      total_sum += fuel;
      get_total_fuel(fuel);
    }

  }
};

int main(void)
{
  module_calc c;
  c.poplate_list("input");
  std::cout << c.calculate_total_sum() << "\n";
}
