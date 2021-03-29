#ifndef PERSISTENCEENGINEFROMJSON_H
#define PERSISTENCEENGINEFROMJSON_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "PersistenceEngine.h"


class PersistenceEngineFromJson : public PersistenceEngine
{
public:
    PersistenceEngineFromJson();
    void load(std::string filepath, std::vector<Book *> &books) override;
    void save(std::string filepath, std::vector<Book *> &books) override;

};

#endif // PERSISTENCEENGINEFROMJSON_H
