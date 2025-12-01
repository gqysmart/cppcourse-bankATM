#ifndef ATM_FILESTORAGE_H
#define ATM_FILESTORAGE_H

#include <string>
#include "operation.h"

namespace ATM
{
    bool load_user_data(const std::string &accountNo, Operation operationHistory[],
                        const int maxOperations, double &balance, std::string &password, int &loadedOperationsCount);

    bool save_user_data(const std::string &accountNo, const std::string &password, const double balance,
                        const Operation operationHistory[], const int operationCount);
}

#endif // ATM_FILESTORAGE_H
