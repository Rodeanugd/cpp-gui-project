#ifndef PERSISTENCEENGINE_H
#define PERSISTENCEENGINE_H

#include <string>
#include <vector>
#include "Book.h"


class PersistenceEngine{
public:
    PersistenceEngine();
    virtual void load(std::string filepath, std::vector<Book*>& books) = 0;
    virtual void save(std::string filepath, std::vector<Book*>& books) = 0;

};

#endif // PERSISTENCEENGINE_H
