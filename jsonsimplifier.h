#ifndef JSONSIMPLIFIER_H
#define JSONSIMPLIFIER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

/**
 * @brief Читает содержимое файла JSON и возвращает объект JSON.
 * @param filePath Путь к файлу JSON.
 * @return Объект JSON.
 */
QJsonObject readDataJsonFile(const QString& filePath);

/**
 * @brief Обновляет значение переменной в файле JSON.
 * @param filePath Путь к файлу JSON.
 * @param key Ключ переменной.
 * @param value Новое значение переменной.
 */
void updateJsonValue(const QString& filePath, const QString& key, const QJsonValue& value);

#endif // JSONSIMPLIFIER_H
