#include "mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief Конструктор класса MainWindow.
 * @param parent Родительский виджет.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Получаем объект JSON из документа
    QJsonObject jsonObj = readDataJsonFile("data.json");

    // Проверяем наличие переменных "width" и "height"
    if (jsonObj.contains("width") && jsonObj.contains("height"))
    {
        // Получаем значения переменных "width" и "height" из JSON
        int width = jsonObj["width"].toInt();
        int height = jsonObj["height"].toInt();
        int fieldMine = jsonObj["mineCount"].toInt();

        // Устанавливаем значения в соответствующие лейблы
        ui->fieldWidth->setText(QString::number(width));
        ui->fieldWidth->setAlignment(Qt::AlignCenter);

        ui->fieldHeight->setText(QString::number(height));
        ui->fieldHeight->setAlignment(Qt::AlignCenter);

        ui->fieldMine->setText(QString::number(fieldMine));
        ui->fieldMine->setAlignment(Qt::AlignCenter);
    }

}

/**
 * @brief Деструктор класса MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Слот для увеличения высоты поля.
 */
void MainWindow::on_increaseFieldHeight_clicked()
{
    IncreaseStat("height", ui->fieldHeight, 25);
}

/**
 * @brief Слот для уменьшения высоты поля.
 */
void MainWindow::on_decreaseFieldHeight_clicked()
{
    DecreaseStat("height", ui->fieldHeight, 4);
}

/**
 * @brief Слот для уменьшения ширины поля.
 */
void MainWindow::on_decreaseFieldWidth_clicked()
{
    DecreaseStat("width", ui->fieldWidth, 4);
}

/**
 * @brief Слот для увеличения ширины поля.
 */
void MainWindow::on_increaseFieldWidth_clicked()
{
    IncreaseStat("width", ui->fieldWidth, 50);
}

/**
 * @brief Слот для уменьшения количества мин на поле.
 */
void MainWindow::on_DecreaseFieldMine_clicked()
{
    DecreaseStat("mineCount", ui->fieldMine, 1);
}

/**
 * @brief Слот для увеличения количества мин на поле.
 */
void MainWindow::on_increaseFieldMine_clicked()
{
    QJsonObject jsonObj = readDataJsonFile("data.json");
    IncreaseStat("mineCount", ui->fieldMine, jsonObj["width"].toInt() * jsonObj["height"].toInt());
}

/**
 * @brief Увеличивает значение статистического параметра.
 * @param stat Имя статистического параметра.
 * @param label Указатель на QLabel для обновления значения.
 * @param border Граница для проверки увеличения.
 */
void MainWindow::IncreaseStat(const QString& stat, QLabel* label, int border)
{
    // Получаем объект JSON из документа
    QJsonObject jsonObj = readDataJsonFile("data.json");

    // Получаем текущее значение статистического параметра
    int parametr = jsonObj[stat].toInt();

    if (parametr < border){
        parametr++;
    }

    // Обновляем значение статистического параметра в объекте JSON
    jsonObj[stat] = parametr;

    // Записываем обновленные данные обратно в JSON документ
    updateJsonValue("data.json", stat, parametr);

    // Обновляем значение Label
    label->setText(QString::number(parametr));
    label->setAlignment(Qt::AlignCenter);
}

/**
 * @brief Уменьшает значение статистического параметра.
 * @param stat Имя статистического параметра.
 * @param label Указатель на QLabel для обновления значения.
 * @param border Граница для проверки уменьшения.
 */
void MainWindow::DecreaseStat(const QString& stat, QLabel* label, int border)
{
    // Получаем объект JSON из документа
    QJsonObject jsonObj = readDataJsonFile("data.json");

    // Получаем текущее значение статистического параметра
    int parametr = jsonObj[stat].toInt();

    if (parametr > border){
            parametr--;
    }

    // Обновляем значение статистического параметра в объекте JSON
    jsonObj[stat] = parametr;

    // Записываем обновленные данные обратно в JSON документ
    updateJsonValue("data.json", stat, parametr);

    // Обновляем значение Label
    label->setText(QString::number(parametr));
    label->setAlignment(Qt::AlignCenter);
}

/**
 * @brief Слот для запуска игры.
 */
void MainWindow::on_startGame_clicked()
{
    if (ui->radioButtonPlayer->isChecked())
    {
            PlayerWindow pWindow;
            pWindow.setModal(true);
            pWindow.exec();
    }
    else if (ui->radioButtonMachine->isChecked())
    {
            qDebug() << "NotPlayer радиокнопка выбрана";
    }
    else
    {
            qDebug() << "Ни одна радиокнопка не выбрана";
    }
}
