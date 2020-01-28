#ifndef EXCEPTION
#define EXCEPTION

#include <QString>

class Exception {
    private:
        QString error;
    protected:
        Exception(QString);
    public:
        QString getError() const;

};

class inputError: public Exception {
    public:
        inputError(QString toError = QString("Input Error")): Exception(toError) {}
};

class typeError: public Exception {
    public:
        typeError(QString toError = QString("Type Error")): Exception(toError) {}
};

#endif // EXCEPTION

