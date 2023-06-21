#include "playerwindow.h"
#include "ui_playerwindow.h"


/**
 * @brief Конструктор класса PlayerWindow.
 * @param parent Родительский виджет.
 */
PlayerWindow::PlayerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerWindow)
{
    ui->setupUi(this);

    mineCounter = staticMineCounter;
    cellCounter = width * height - mineCounter;

    field = generateMineField(width, height, staticMineCounter);
    statusField = genrateStatusField(width, height, field);

    updateField(field, width, height);

    QJsonObject jsonObj = readDataJsonFile("data.json");

    int loseScore = jsonObj[ "playerLoseScore"].toInt();
    int winScore = jsonObj[ "playerWinScore"].toInt();

    ui->playerLoseScore->setText(QString::number(loseScore));
    ui->playerLoseScore->setAlignment(Qt::AlignCenter);

    ui->playerWinScore->setText(QString::number(winScore));
    ui->playerWinScore->setAlignment(Qt::AlignCenter);

    ui->mineCounter->setText(QString::number(mineCounter));

}

/**
 * @brief Деструктор класса PlayerWindow.
 */
PlayerWindow::~PlayerWindow()
{
    delete ui;
}

/**
 * @brief Слот для закрытия окна.
 */
void PlayerWindow::on_pushButton_clicked()
{
    close();
}

/**
 * @brief Слот для перезапуска игры.
 */
void PlayerWindow::on_Restart_clicked()
{
    ableToPlay = true;

    mineCounter = staticMineCounter;
    cellCounter = width * height - mineCounter;


    field = generateMineField(width, height, staticMineCounter);

    clearStatusField(statusField);
    statusField = genrateStatusField(width, height, field);

    clearField();
    updateField(field, width, height);

    ui->statusLabel->setText("...");
    ui->statusLabel->setAlignment(Qt::AlignCenter);
}

/**
 * @brief Обновляет отображение игрового поля.
 * @param field Игровое поле.
 * @param width Ширина игрового поля.
 * @param height Высота игрового поля.
 */
void PlayerWindow::updateField(std::vector<std::vector<int>>& field, int width, int height)
{
    ui->MineField->setSpacing(0);


    ui->mineCounter->setText(QString::number(mineCounter));

    for (int i = 0; i < height; ++i) {
        ui->MineField->setRowMinimumHeight(i, 24);
        for (int j = 0; j < width; ++j) {
            ui->MineField->setColumnMinimumWidth(j, 24);

            statusField[i][j].button = new QPushButton("");
            statusField[i][j].button->setFixedSize(24, 24);
            statusField[i][j].button->setMinimumSize(24,24);
            statusField[i][j].button->setMaximumSize(24,24);

            ui->MineField->addWidget(statusField[i][j].button, i, j);

            setStateBlank(i, j);
            statusField[i][j].button->setContextMenuPolicy(Qt::CustomContextMenu);

            // Установка обработчика события для нажатия правой кнопкой мыши
            QObject::connect(statusField[i][j].button, &QPushButton::customContextMenuRequested, [=]() {


                if (ableToPlay){

                    //Снятие флажка
                    if (!statusField[i][j].isActivated){

                        if (statusField[i][j].isFlaged){

                            setStateBlank(i, j);

                            mineCounter++;
                            ui->mineCounter->setText(QString::number(mineCounter));

                        }

                        //установка флажка
                        else if (!statusField[i][j].isFlaged && mineCounter > 0){

                            setStateFlaged(i, j);
                            statusField[i][j].isFlaged = true;

                            mineCounter--;
                            ui->mineCounter->setText(QString::number(mineCounter));

                            if (ableToPlay && cellCounter == 0 && mineCounter == 0){
                                gameWon();
                            }
                        }

                    }
                }

            });

            // Установка обработчика события для нажатия левой кнопкой мыши
            QObject::connect(statusField[i][j].button, &QPushButton::clicked, [=]() {

                if (ableToPlay){

                    if (!statusField[i][j].isFlaged && statusField[i][j].isActivated && !statusField[i][j].isMine){

                        revialNeighbour(i, j, width, height);

                        if (ableToPlay && cellCounter == 0 && mineCounter == 0){
                            gameWon();
                        }

                    }


                    if (!statusField[i][j].isFlaged && !statusField[i][j].isActivated){

                        setStateActive(i, j);

                        cellCounter--;


                        if (ableToPlay && cellCounter == 0 && mineCounter == 0){
                            gameWon();
                        }
                    }


                }
            });
        }
    }
}

/**
 * @brief Устанавливает состояние кнопки как пустая.
 * @param xCord Координата x кнопки.
 * @param yCord Координата y кнопки.
 */
void PlayerWindow::setStateBlank(int xCord, int yCord)
{
    statusField[xCord][yCord].button->setText("");
    statusField[xCord][yCord].button->setStyleSheet("QPushButton { border-radius: 1px; border: 1px solid #222222; background-color: #525252 }");
    statusField[xCord][yCord].isFlaged = false;
}

/**
 * @brief Устанавливает состояние кнопки как активирована.
 * @param xCord Координата x кнопки.
 * @param yCord Координата y кнопки.
 */
void PlayerWindow::setStateActive(int xCord, int yCord)
{
    int element = statusField[xCord][yCord].value;

    statusField[xCord][yCord].button->setText(QString::number(element));
    statusField[xCord][yCord].button->setStyleSheet("QPushButton { border-radius: 1px; border: 1px solid #222222; background-color: #8f8f8f }");

    statusField[xCord][yCord].isActivated = true;


    if (element == -1){
        statusField[xCord][yCord].button->setStyleSheet("QPushButton { border-radius: 1px; border: 1px solid #222222; background-color: red }");
//
        gameLost();
    }
}

/**
 * @brief Устанавливает состояние кнопки как отмеченную флагом.
 * @param xCord Координата x кнопки.
 * @param yCord Координата y кнопки.
 */
void PlayerWindow::setStateFlaged(int xCord, int yCord)
{
    statusField[xCord][yCord].button->setText("F");
    statusField[xCord][yCord].button->setStyleSheet("QPushButton { border-radius: 1px; border: 1px solid #222222; background-color: blue }");
    statusField[xCord][yCord].isFlaged = true;

}

/**
 * @brief Раскрывает соседние кнопки при открытии пустой кнопки.
 * @param xCord Координата x кнопки.
 * @param yCord Координата y кнопки.
 * @param maxWidth Максимальная ширина игрового поля.
 * @param maxHeight Максимальная высота игрового поля.
 */
void PlayerWindow::revialNeighbour(int xCord, int yCord, int maxWidth, int maxHeight)
{
    bool validNeighbors = true;

    // Проверяем окружающие элементы по диагонали, вертикали и горизонтали
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            // Пропускаем текущий элемент
            if (dx == 0 && dy == 0)
                continue;

            int ni = xCord + dx;
            int nj = yCord + dy;

            // Проверяем границы поля
            if (ni >= 0 && ni < maxHeight && nj >= 0 && nj < maxWidth) {
                //проверяем сосодние элементы на то подходят ли они все для вскратия
                if ((statusField[ni][nj].isMine && !statusField[ni][nj].isFlaged) || (!statusField[ni][nj].isMine && statusField[ni][nj].isFlaged)){
                    validNeighbors = false;
                }
            }
        }
    }

    //все элементы проходят
    if (validNeighbors){
        // Проверяем окружающие элементы по диагонали, вертикали и горизонтали
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                // Пропускаем текущий элемент
                if (dx == 0 && dy == 0)
                    continue;

                int ni = xCord + dx;
                int nj = yCord + dy;

                // Проверяем границы поля
                if (ni >= 0 && ni < maxHeight && nj >= 0 && nj < maxWidth) {
                    // Если поле не мина и не отмечено флагом вскрываем его
                    if (!statusField[ni][nj].isMine && !statusField[ni][nj].isActivated){
                        setStateActive(ni, nj);

                        cellCounter--;

                        if (ableToPlay && cellCounter == 0 && mineCounter == 0){
                            gameWon();
                        }
                    }

                }
            }
        }
    }
}

/**
 * @brief Очищает игровое поле.
 */
void PlayerWindow::clearField()
{
    QLayoutItem* item;
    while ((item = ui->MineField->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

/**
 * @brief Обрабатывает событие поражения игрока.
 */
void PlayerWindow::gameLost()
{
    ableToPlay = false;

    QJsonObject jsonObj = readDataJsonFile("data.json");
    int loseScore = jsonObj[ "playerLoseScore"].toInt();

    updateJsonValue("data.json", "playerLoseScore", ++loseScore);
    ui->playerLoseScore->setText(QString::number(loseScore));
    ui->playerLoseScore->setAlignment(Qt::AlignCenter);

    ui->statusLabel->setText("Поражение");
    ui->statusLabel->setAlignment(Qt::AlignCenter);
}

/**
 * @brief Обрабатывает событие победы игрока.
 */
void PlayerWindow::gameWon()
{
    ableToPlay = false;

    QJsonObject jsonObj = readDataJsonFile("data.json");
    int winScore = jsonObj[ "playerWinScore"].toInt();

    updateJsonValue("data.json", "playerWinScore", ++winScore);
    ui->playerWinScore->setText(QString::number(winScore));
    ui->playerWinScore->setAlignment(Qt::AlignCenter);

    ui->statusLabel->setText("Победа");
    ui->statusLabel->setAlignment(Qt::AlignCenter);
}

/**
 *@brief Очищает поле статуса.
 *@param statusField Поле статуса, которое нужно очистить.
 */
void clearStatusField(std::vector<std::vector<StatusValue>>& statusField) {

    for (auto& row : statusField) {

        for (auto& cell : row) {
            cell.isMine = false;
            cell.isActivated = false;
            cell.isFlaged = false;
        }
    }
}

/**
 *@param fieldWidth Ширина игрового поля.
 *@param fieldHeight Высота игрового поля.
 *@param field Вектор векторов, представляющий поле значений.
 *@return Возвращает вектор векторов, представляющий поле состояния.
 */
std::vector<std::vector<StatusValue>> genrateStatusField(int fieldWidth, int fieldHeight, std::vector<std::vector<int>> field){

     std::vector<std::vector<StatusValue>> statusField(fieldHeight, std::vector<StatusValue>(fieldWidth));

    for (int i = 0; i < fieldHeight; ++i) {
        for (int j = 0; j < fieldWidth; ++j) {
            statusField[i][j].value = field[i][j];
            if (field[i][j] == -1){
                statusField[i][j].isMine = true;
            }
        }
    }

    return statusField;
}


/**
 *@brief Обрабатывает нажатие кнопки сброса счета.
 */
void PlayerWindow::on_resetScore_clicked()
{
    updateJsonValue("data.json", "playerLoseScore", 0);
    updateJsonValue("data.json","playerWinScore", 0);

    ui->playerLoseScore->setText(QString::number(0));
    ui->playerLoseScore->setAlignment(Qt::AlignCenter);

    ui->playerWinScore->setText(QString::number(0));
    ui->playerWinScore->setAlignment(Qt::AlignCenter);
}

