#ifndef ATM_OPERATION_H
#define ATM_OPERATION_H

enum class BankOperationsType
{
    DEPOSIT_MONEY = 0,
    WITHDRAW_MONEY = 1,
};

struct Operation
{
    BankOperationsType type;
    double amount;
};

#endif // ATM_OPERATION_H
