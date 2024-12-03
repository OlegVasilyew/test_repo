#include <vector>
#include <functional>
#include <iostream>

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// Тесты метода body_contains
//тест 1 : проверка вхождения цены в диапазон тела растущей свечи
// Цена открытия : 3
// Цена максимальная: 6
// Цена минимальная: 1
// Цена закрытия: 5
// Проверка цены: 4
bool test1()
{
    Candle candle{ 3.0, 6.0, 1.0, 5.0 };
    return candle.body_contains(4.0); //passed
}

//тест 2 : проверка вхождения цены в диапазон тела падающей свечи
// Цена открытия : 5
// Цена максимальная: 6
// Цена минимальная: 1
// Цена закрытия: 3
// Проверка цены: 4
bool test2()
{
    Candle candle{ 5.0, 6.0, 1.0, 3.0 };
    return candle.body_contains(4.0); //passed
}

//тест 3 : проверка вхождения цены в диапазон тела свечи "Доджи 4-х цен"
// Цена открытия : 3
// Цена максимальная: 3
// Цена минимальная: 3
// Цена закрытия: 3
// Проверка цены: 3
bool test3()
{
    Candle candle{ 3.0, 3.0, 3.0, 3.0 };
    return candle.body_contains(3.0); //passed
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
