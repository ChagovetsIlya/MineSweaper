#ifndef FIELDGENERATOR_H
#define FIELDGENERATOR_H

#include <vector>

/**
 * @brief Генерирует поле с минами.
 * @param fieldWidth Ширина поля.
 * @param fieldHeight Высота поля.
 * @param mineCount Количество мин.
 * @return Двумерный вектор, представляющий поле с минами.
 */
std::vector<std::vector<int>> generateMineField(int fieldWidth, int fieldHeight, int mineCount);

/**
 * @brief Обновляет значения поля на основе расположения мин.
 * @param field Двумерный вектор, представляющий поле с минами.
 */
void updateFieldValues(std::vector<std::vector<int>>& field);

/**
 * @brief Возвращает случайное число от 0 до num - 1.
 * @param num Верхняя граница для случайного числа.
 * @return Случайное число.
 */
int getRandomNumber(int num);

#endif // FIELDGENERATOR_H
