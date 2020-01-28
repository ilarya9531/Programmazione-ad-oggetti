#include <model/exception.h>

Exception::Exception(QString toError): error(toError) {}

QString Exception::getError() const {
    return error;
}

