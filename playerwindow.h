#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include "jsonsimplifier.h"
#include "fieldgenerator.h"

#include <QDebug>
#include <QJsonObject>
#include <QPushButton>
#include <vector>
#include <QDialog>

/**
 * @struct StatusValue
 * @brief Структура, представляющая состояние кнопки игрового поля.
 */
struct StatusValue {
    bool isMine = false;
    bool isActivated = false;
    bool isFlaged = false;
    QPushButton* button;
    int value;
};

namespace Ui {
class PlayerWindow;
}

/**
 * @class PlayerWindow
 * @brief Класс, представляющий окно игрока.
 */
class PlayerWindow : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Конструктор класса PlayerWindow.
     * @param parent Указатель на родительский объект QWidget.
     */
    explicit PlayerWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса PlayerWindow.
     */
    ~PlayerWindow();

public slots:

    /**
     * @brief Обработчик события нажатия кнопки.
     */
    void on_pushButton_clicked();

    /**
     * @brief Обработчик события нажатия кнопки.
     */
    void on_Restart_clicked();

    /**
     * @brief Обработчик события нажатия кнопки.
     */
    void on_resetScore_clicked();

public:

    /**
     * @brief ui Указатель на объект пользовательского интерфейса.
     */
    Ui::PlayerWindow *ui;

    /**
     * @brief ableToPlay Флаг, определяющий возможность игры.
     */
    bool ableToPlay = true;

    /**
     * @brief jsonObj Объект JSON, содержащий данные из файла "data.json".
     */
    QJsonObject jsonObj = readDataJsonFile("data.json");

    /**
     * @brief width Ширина игрового поля.
     */
    int width = jsonObj["width"].toInt();

    /**
     * @brief height Высота игрового поля.
     */
    int height = jsonObj["height"].toInt();

    /**
     * @brief staticMineCounter Статическое количество мин на игровом поле.
     */
    int staticMineCounter = jsonObj["mineCount"].toInt();

    /**
     * @brief mineCounter Количество оставшихся мин на игровом поле.
     */
    int mineCounter = staticMineCounter;

    /**
     * @brief cellCounter Количество оставшихся неоткрытых клеток на игровом поле.
     */
    int cellCounter = width * height - mineCounter;

    /**
     * @brief field Двумерный вектор, представляющий игровое поле.
     */
    std::vector<std::vector<int>> field = generateMineField(width, height, mineCounter);

    /**
     * @brief field Двумерный вектор, представляющий состояния ячеек поля.
     */
    std::vector<std::vector<StatusValue>> statusField;

    /**
     * @brief Очищает игровое поле.
     */
    void clearField();

    /**
     * @brief Обрабатывает событие поражения в игре.
     */
    void gameLost();

    /**
     * @brief Обрабатывает событие победы в игре.
     */
    void gameWon();

    /**
     * @brief Устанавливает состояние клетки на пустое.
     * @param xCord Координата X клетки.
     * @param yCord Координата Y клетки.
     */
    void setStateBlank(int xCord, int yCord);

    /**
     * @brief Устанавливает состояние активной клетки.
     * @param xCord Координата X клетки.
     * @param yCord Координата Y клетки.
     */
    void setStateActive(int xCord, int yCord);

    /**
     * @brief Устанавливает состояние флажка на клетке.
     * @param xCord Координата X клетки.
     * @param yCord Координата Y клетки.
     */
    void setStateFlaged(int xCord, int yCord);

    /**
     * @brief Раскрывает соседние клетки.
     * @param xCord Координата X клетки.
     * @param yCord Координата Y клетки.
     * @param maxWidth Максимальная ширина игрового поля.
     * @param maxHeight Максимальная высота игрового поля.
     */
    void revialNeighbour(int xCord, int yCord, int maxWidth, int maxHeight);

    /**
     * @brief Обновляет отображение игрового поля.
     * @param field Игровое поле.
     * @param width Ширина игрового поля.
     * @param height Высота игрового поля.
     */
    void updateField(std::vector<std::vector<int>>& field, int width, int height);

};

/**
 * @brief Генерирует поле состояния для игрового поля.
 * @param fieldWidth Ширина игрового поля.
 * @param fieldHeight Высота игрового поля.
 * @param mineField Игровое поле с минами.
 * @return Вектор векторов, представляющий поле состояния.
 */
std::vector<std::vector<StatusValue>> genrateStatusField(int fieldWidth, int fieldHeight, std::vector<std::vector<int>> mineField);

/**
 * @brief Очищает поле состояния игрового поля.
 * @param statusField Ссылка на вектор векторов, представляющий поле состояния.
 */
void clearStatusField(std::vector<std::vector<StatusValue>>& statusField);

#endif // PLAYERWINDOW_H
