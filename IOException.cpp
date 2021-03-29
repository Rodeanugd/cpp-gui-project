#include "IOException.h"

IOException::IOException()
{

}

const char *IOException::what() const throw()
{
    return "IOError";
}
