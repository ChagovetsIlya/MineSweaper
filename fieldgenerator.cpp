#include "fieldgenerator.h"

#include <vector>
#include <iostream>
#include <random>

/**
 * @brief Генерирует поле с минами.
 * @param fieldWidth Ширина поля.
 * @param fieldHeight Высота поля.
 * @param mineCount Количество мин.
 * @return Двумерный вектор, представляющий поле с минами.
 * @throw std::invalid_argument Если исходные данные невалидны.
 */
std::vector<std::vector<int>> generateMineField(int fieldWidth, int fieldHeight, int mineCount)
{
    if (mineCount > fieldWidth * fieldHeight || mineCount < 0 || fieldWidth < 1 || fieldHeight < 1){
        throw std::invalid_argument("исходные данные не валидные");
    }

    std::vector<std::vector<int>> mineField(fieldHeight, std::vector<int>(fieldWidth));

    for (int i = 0; i < fieldHeight; ++i) {
        for (int j = 0; j < fieldWidth; ++j) {
            mineField[i][j] = 0;
        }
    }

    int placeMines = mineCount;
    do{
        bool spotSearch = true;
        do{
            int row = getRandomNumber(fieldHeight);
            int col = getRandomNumber(fieldWidth);

            if (mineField[row][col] != -1){
                mineField[row][col] = -1;
                spotSearch = false;
                --placeMines;
            }

        } while (spotSearch);

    }while (placeMines != 0 );

    updateFieldValues(mineField);
    return mineField;
}

/**
 * @brief Обновляет значения поля на основе расположения мин.
 * @param field Двумерный вектор, представляющий поле с минами.
 * @throw std::invalid_argument Если на поле присутствуют невалидные значения.
 */
void updateFieldValues(std::vector<std::vector<int>>& field) {
    int rows = field.size();
    int columns = field[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (field[i][j] == 0) {
                int count = 0;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0)
                            continue;

                        int ni = i + dx;
                        int nj = j + dy;

                        if (ni >= 0 && ni < rows && nj >= 0 && nj < columns) {
                            if (field[ni][nj] < -1 || field[ni][nj] > 8){
                                throw std::invalid_argument("на поле не валидные значения");
                            }

                            if (field[ni][nj] == -1)
                                count++;
                        }
                    }
                }

                field[i][j] = count;
            }
        }
    }
}

/**
 * @brief Возвращает случайное число от 0 до num - 1.
 * @param num Верхняя граница для случайного числа.
 * @return Случайное число.
 * @throw std::invalid_argument Если num меньше 0.
 */
int getRandomNumber(int num)
{
    if (num < 0)
    {
        throw std::invalid_argument("num должен быть >= 0");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, num - 1);

    return distribution(gen);
}
