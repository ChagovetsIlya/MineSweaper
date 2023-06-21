#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fieldgenerator.h"

#include <vector>
#include <stdexcept>
#include <iostream>
#include <cassert>

TEST_CASE("Test getRandomNumber")
{
    SUBCASE("Positive number")
    {
        CHECK_NOTHROW(getRandomNumber(10));  // Положительное число, не должно быть ошибки
    }

    SUBCASE("Zero")
    {
        CHECK_NOTHROW(getRandomNumber(0));   // 0, не должно быть ошибки
    }

    SUBCASE("Negative number")
    {
        CHECK_THROWS_AS(getRandomNumber(-5), std::invalid_argument);  // Отрицательное число, ожидается исключение
    }
}

TEST_CASE("Test generateMineField")
{
    SUBCASE("Valid inputs")
    {
        // Проверка для валидных входных данных
        int fieldWidth = 5;
        int fieldHeight = 5;
        int mineCount = 5;

        CHECK_NOTHROW(generateMineField(fieldWidth, fieldHeight, mineCount));
    }

    SUBCASE("Invalid inputs")
    {
        // Проверка для невалидных входных данных
        int fieldWidth = -1;
        int fieldHeight = 5;
        int mineCount = 5;

        CHECK_THROWS_AS(generateMineField(fieldWidth, fieldHeight, mineCount), std::invalid_argument);

        fieldWidth = 5;
        fieldHeight = -1;
        mineCount = 5;

        CHECK_THROWS_AS(generateMineField(fieldWidth, fieldHeight, mineCount), std::invalid_argument);

        fieldWidth = 5;
        fieldHeight = 5;
        mineCount = -1;

        CHECK_THROWS_AS(generateMineField(fieldWidth, fieldHeight, mineCount), std::invalid_argument);

        fieldWidth = 3;
        fieldHeight = 3;
        mineCount = 10;  // Число мин больше, чем размер поля

        CHECK_THROWS_AS(generateMineField(fieldWidth, fieldHeight, mineCount), std::invalid_argument);
    }
}

// Тесты для функции updateFieldValues
TEST_CASE("Test updateFieldValues")
{
    SUBCASE("Valid field")
    {
        // Проверка для валидного поля без ошибок
        std::vector<std::vector<int>> field = {
            {0, 0, 0},
            {0, -1, 0},
            {0, 0, 0}
        };

        CHECK_NOTHROW(updateFieldValues(field));
    }

    SUBCASE("Invalid field")
    {
        // Проверка для невалидного поля с ошибкой
        std::vector<std::vector<int>> field = {
            {0, 0, 0},
            {0, -1, 0},
            {0, 10, 0}  // Значение поля вне допустимого диапазона
        };

        CHECK_THROWS_AS(updateFieldValues(field), std::invalid_argument);
    }
}
