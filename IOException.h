#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H
#include <exception>


class IOException : public std::exception
{
public:
    IOException();
    const char* what() const throw();
};

#endif // IOEXCEPTION_H
