#ifndef PERSISTENCEENGINEFROMCSV_H
#define PERSISTENCEENGINEFROMCSV_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "IOException.h"
#include "PersistenceEngine.h"


class PersistenceEngineFromCsv : public PersistenceEngine
{
public:
    PersistenceEngineFromCsv();
    void load(std::string filepath, std::vector<Book *> &books) override;
    void save(std::string filepath, std::vector<Book *> &books) override;
};

#endif // PERSISTENCEENGINEFROMCSV_H
