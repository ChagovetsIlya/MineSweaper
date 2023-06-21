#include "jsonsimplifier.h"

/**
 * @brief Читает содержимое файла JSON и возвращает объект JSON.
 * @param filePath Путь к файлу JSON.
 * @return Объект JSON.
 */
QJsonObject readDataJsonFile(const QString& filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

    QJsonObject jsonObj = jsonDoc.object();
    return jsonObj;
}

/**
 * @brief Обновляет значение переменной в файле JSON.
 * @param filePath Путь к файлу JSON.
 * @param key Ключ переменной.
 * @param value Новое значение переменной.
 */
void updateJsonValue(const QString& filePath, const QString& key, const QJsonValue& value)
{
    // Открываем файл JSON
    QFile file(filePath);
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    // Читаем содержимое файла JSON
    QByteArray jsonData = file.readAll();

    // Создаем JSON документ и проверяем его корректность
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &jsonError);

    // Получаем объект JSON из документа
    QJsonObject jsonObj = jsonDoc.object();

    // Заменяем значение переменной на новое
    jsonObj[key] = value;

    // Записываем обновленные данные обратно в JSON документ
    jsonDoc.setObject(jsonObj);

    // Записываем обновленный JSON документ в файл
    file.resize(0);
    file.write(jsonDoc.toJson());
    file.close();
}
