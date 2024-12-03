#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

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

// Тесты метода contains
//тест 1 : проверка вхождения цены в диапазон тела и тени свечи "Длинноногий доджи"
// Цена открытия : 4
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 4
// Проверка цены: 3
bool test4()
{
    Candle candle{ 4.0, 6.0, 2.0, 4.0 };
    return candle.contains(3.0); //passed
}

//тест 2 : проверка вхождения цены в диапазон тела и тени свечи "Доджи стрекоза"
// Цена открытия: 5
// Цена максимальная: 5
// Цена минимальная: 1
// Цена закрытия: 5
// Проверка цены: 3
bool test5()
{
    Candle candle{ 5.0, 5.0, 1.0, 5.0 };
    return candle.contains(3.0); //passed
}

//тест 3 : проверка вхождения цены в диапазон тела и тени свечи "Доджи надгробие"
// Цена открытия: 2
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 2
// Проверка цены: 3
bool test6()
{
    Candle candle{ 2.0, 6.0, 2.0, 2.0 };
    return candle.contains(3.0); //passed
}

// Тесты метода full_size
//тест 1 : проверка разницы между минимальной и максимальной цены в свече "Длинноногий доджи"
// Цена открытия : 4
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 4
// Проверка разницы: 4
bool test7()
{
    Candle candle{ 4.0, 6.0, 2.0, 4.0 };
    return 4 == candle.full_size(); //passed
}

//тест 2 : проверка разницы между минимальной и максимальной цены в свече "Доджи стрекоза"
// Цена открытия: 5
// Цена максимальная: 5
// Цена минимальная: 1
// Цена закрытия: 5
// Проверка разницы: 4
bool test8()
{
    Candle candle{ 5.0, 5.0, 1.0, 5.0 };
    return 4 == candle.full_size(); //passed
}

//тест 3 : проверка разницы между минимальной и максимальной цены в свече "Доджи надгробие"
// Цена открытия: 2
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 2
// Проверка разницы: 4
bool test9()
{
    Candle candle{ 2.0, 6.0, 2.0, 2.0 };
    return 4 == candle.full_size(); //passed
}

// Тесты метода body_size
//тест 1 : проверка разницы между ценой открытия и закрытия в падающей свече "Марубозу"
// Цена открытия : 6
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 2
// Проверка разницы: 4
bool test10()
{
    Candle candle{ 6.0, 6.0, 2.0, 2.0 };
    return 4 == candle.body_size(); //passed
}

//тест 2 : проверка разницы между минимальной и максимальной цены в свече "Доджи стрекоза"
// Цена открытия: 5
// Цена максимальная: 5
// Цена минимальная: 1
// Цена закрытия: 5
// Проверка разницы: 0
bool test11()
{
    Candle candle{ 5.0, 5.0, 1.0, 5.0 };
    return 0 == candle.body_size(); //passed
}

//тест 3 : проверка разницы между минимальной и максимальной цены в свече "Доджи надгробие"
// Цена открытия: 2
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 2
// Проверка разницы: 0
bool test12()
{
    Candle candle{ 2.0, 6.0, 2.0, 2.0 };
    return 0 == candle.body_size(); //passed
}

// Тесты метода is_red
//тест 1 : проверка падающая ли свеча "Марубозу"
// Цена открытия : 6
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 2
bool test13()
{
    Candle candle{ 6.0, 6.0, 2.0, 2.0 };
    return candle.is_red(); //passed
}

//тест 2 : проверка падающая ли свеча
// Цена открытия: 4
// Цена максимальная: 5
// Цена минимальная: 1
// Цена закрытия: 2
bool test14()
{
    Candle candle{ 4.0, 5.0, 1.0, 2.0 };
    return candle.is_red(); //passed
}

//тест 3 : проверка падающая ли свеча "Молот"
// Цена открытия: 3
// Цена максимальная: 6
// Цена минимальная: 1
// Цена закрытия: 2
bool test15()
{
    Candle candle{ 3.0, 6.0, 1.0, 2.0 };
    return candle.is_red(); //passed
}

// Тесты метода is_green
//тест 1 : проверка растущая ли свеча "Марубозу"
// Цена открытия : 2
// Цена максимальная: 6
// Цена минимальная: 2
// Цена закрытия: 6
bool test16()
{
    Candle candle{ 2.0, 6.0, 2.0, 6.0 };
    return candle.is_green(); //passed
}

//тест 2 : проверка растущая ли свеча
// Цена открытия: 2
// Цена максимальная: 5
// Цена минимальная: 1
// Цена закрытия: 4
bool test17()
{
    Candle candle{ 2.0, 5.0, 1.0, 4.0 };
    return candle.is_green(); //passed
}

//тест 3 : проверка растущая ли свеча "Молот"
// Цена открытия: 4
// Цена максимальная: 6
// Цена минимальная: 1
// Цена закрытия: 5
bool test18()
{
    Candle candle{ 4.0, 6.0, 1.0, 5.0 };
    return candle.is_green(); //passed
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  tests.push_back(test4);
  tests.push_back(test5);
  tests.push_back(test6);
  tests.push_back(test7);
  tests.push_back(test8);
  tests.push_back(test9);
  tests.push_back(test10);
  tests.push_back(test11);
  tests.push_back(test12);
  tests.push_back(test13);
  tests.push_back(test14);
  tests.push_back(test15);
  tests.push_back(test16);
  tests.push_back(test17);
  tests.push_back(test18);
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
