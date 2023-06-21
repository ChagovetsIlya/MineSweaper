#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "jsonsimplifier.h"
#include "playerwindow.h"

#include <QDebug>
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Класс главного окна приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow.
     * @param parent Родительский виджет.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса MainWindow.
     */
    ~MainWindow();

public slots:
    /**
     * @brief Увеличивает значение статистического параметра.
     * @param stat Имя статистического параметра.
     * @param label Указатель на QLabel для обновления значения.
     * @param border Граница для проверки увеличения.
     */
    void IncreaseStat(const QString& stat, QLabel* label, int border);

    /**
     * @brief Уменьшает значение статистического параметра.
     * @param stat Имя статистического параметра.
     * @param label Указатель на QLabel для обновления значения.
     * @param border Граница для проверки уменьшения.
     */
    void DecreaseStat(const QString& stat, QLabel* label, int border);

    /**
     * @brief Слот для увеличения количества мин на поле.
     */
    void on_increaseFieldMine_clicked();

    /**
     * @brief Слот для уменьшения количества мин на поле.
     */
    void on_DecreaseFieldMine_clicked();

    /**
     * @brief Слот для запуска игры.
     */
    void on_startGame_clicked();

    /**
     * @brief Слот для увеличения высоты поля.
     */
    void on_increaseFieldHeight_clicked();

    /**
     * @brief Слот для увеличения ширины поля.
     */
    void on_increaseFieldWidth_clicked();

    /**
     * @brief Слот для уменьшения высоты поля.
     */
    void on_decreaseFieldHeight_clicked();

    /**
     * @brief Слот для уменьшения ширины поля.
     */
    void on_decreaseFieldWidth_clicked();

private:

    /**
     * @brief ui Указатель на объект пользовательского интерфейса.
     */
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
