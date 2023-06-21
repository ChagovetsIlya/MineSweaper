#include "mainwindow.h"
#include "playerwindow.h"

#include <QApplication>

/**
 * @brief Функция main является входной точкой приложения.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код возврата приложения.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
