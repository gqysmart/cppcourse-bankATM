#include <iostream>
#include <string>
#include <algorithm>
#include "operation.h"
#include "fileStorage.h"

using namespace std;
using namespace ATM;
void printMenu();
// double accountbalance_test = 1523.75;
// double getAccountBalance();
bool saveMoney(double moneyToSave, double &balance);
// double updateAccountBalance(double newBalance);
bool withdrawMoney(double moneyToWithdraw, double &balance);

// for iteration 5 , add function of operation history

// Define a fixed-size array to store the last 10 operations
constexpr int MAX_COUNT_OPERATIONS = 10;
// Operation operationHistory[MAX_COUNT_OPERATIONS];
void addOperationToHistory(Operation operationHistory[], int &operationCount, BankOperationsType type, double amount);
// void printOperationHistory();
bool welcome_user(string &accountNo, double &balance, string &password_db,
                  Operation operationHistory[], int &loadedOperationsCount);
bool do_service(string &accountNo, double &balance, string &password_db,
                Operation operationHistory[], int &operationCount);
int main()
{
    string accountNo = "00001";
    double balance_file = 0.0;
    int loadedOperationsCount = 0;
    string password_db;
    constexpr int MAX_COUNT_OPERATIONS = 10;
    Operation operationHistory[MAX_COUNT_OPERATIONS];
    do
    {
        while (!welcome_user(accountNo, balance_file, password_db, operationHistory, loadedOperationsCount))
        {
            cout << "Merci d'avoir utilisé notre ATM. Au revoir!" << endl;
        }
        cout << accountNo << " Welcome back!" << endl;

        /* code */
    } while (do_service(accountNo, balance_file, password_db, operationHistory, loadedOperationsCount));
}

bool welcome_user(string &accountNo, double &balance, string &password_db,
                  Operation operationHistory[], int &loadedOperationsCount)
{
    cout << "Bienvenue dans l'ATM!" << endl;

    string pin = "";
    bool accessGranted = false;
    // while (true)
    // {
    cout << "Insert your bankAccountCard : ";
    cin >> accountNo;

    load_user_data(accountNo, operationHistory, MAX_COUNT_OPERATIONS, balance, password_db, loadedOperationsCount);
    int count = 3;
    while (count-- > 0)
    {
        cout << "Input your pin : ";
        cin >> pin;
        if (pin == password_db)
        {
            cout << "Accès autorisé." << endl;
            accessGranted = true;
            break;
        }
        else
        {
            cout << "Code incorrect, il vous reste " << count << " essais." << endl;
        }
    }
    // }
    return accessGranted;
}
bool do_service(string &accountNo, double &balance, string &password_db,
                Operation operationHistory[], int &operationCount)
{
    Operation new_operation_history[MAX_COUNT_OPERATIONS];
    std::copy(operationHistory,
              operationHistory + operationCount,
              new_operation_history);

    int new_operationCount = operationCount;

    while (true)
    {
        printMenu();
        int choix;
        cin >> choix;
        if (choix == 5)
        {
            // before save ,reoreder le history

            const int keepCount = std::min(new_operationCount, MAX_COUNT_OPERATIONS);

            Operation temp_[MAX_COUNT_OPERATIONS];

            // ring buffer “头部位置”：最老的记录所在位置
            int head = new_operationCount - keepCount; // 最老元素的全局序号
            int startIndex = head % MAX_COUNT_OPERATIONS;

            // 循环展开：从 startIndex 开始，取 keepCount 条，按顺序写入 temp_
            for (int i = 0; i < keepCount; ++i)
            {
                temp_[i] = new_operation_history[(startIndex + i) % MAX_COUNT_OPERATIONS];
            }

            save_user_data(accountNo, password_db, balance, temp_, new_operationCount > MAX_COUNT_OPERATIONS ? MAX_COUNT_OPERATIONS : new_operationCount);
            return true;
        }

        switch (choix)
        {
        case 1:
            cout << "Votre solde actuel est de " << balance << "€" << endl;
            /* code */
            break;
        case 2:

            double montant;
            cout << "Entrez le montant à déposer : ";
            cin >> montant;
            if (!saveMoney(montant, balance))
            {
                cout << "Montant invalide. Le dépôt a échoué." << endl;
            }
            else
            {
                addOperationToHistory(new_operation_history, new_operationCount, BankOperationsType::DEPOSIT_MONEY, montant);
                cout << "Dépôt réussi. Nouveau solde : " << balance << "€" << endl;
            }
            break;

        case 3:
        {
            double moneyToWithdraw;
            cout << "Entrez le montant à retirer : ";
            cin >> moneyToWithdraw;
            if (!withdrawMoney(moneyToWithdraw, balance))
            {
                cout << "Solde insuffisant. Votre solde est de " << balance << "€" << endl;
            }
            else
            {
                addOperationToHistory(new_operation_history, new_operationCount, BankOperationsType::WITHDRAW_MONEY, moneyToWithdraw);
                cout << "Retrait accepté. Nouveau solde : " << balance << "€" << endl;
            }
            break;
        }
        break;
        case 4:
            cout << "Historique des opérations :" << endl;
            {
                int start = new_operationCount > MAX_COUNT_OPERATIONS ? (new_operationCount - MAX_COUNT_OPERATIONS) : 0;
                int end = new_operationCount;

                for (int i = start; i < end; i++)
                {
                    int index = (i) % MAX_COUNT_OPERATIONS;
                    string operationType = new_operation_history[index].type == BankOperationsType::DEPOSIT_MONEY ? "Dépôt" : "Retrait";
                    cout << operationType << " de " << new_operation_history[index].amount << "€" << endl;
                }
            }
            break;
        default:
            break;
        }
    }
    return true;
}
// while (true)
// {
//     printMenu();
//     int choix;
//     cin >> choix;
//     if (choix == 5)
//     {
//         SaveUserData(accountNo, balance_file, password_db, operationHistory, operationCount);
//         break;
//     }
//     switch (choix)
//     {
//     case 1:
//         cout << "Votre solde actuel est de " << balance_file << "€" << endl;
//         break;
//     case 2:
//     {
//         double montant;
//         cout << "Entrez le montant à déposer : ";
//         cin >> montant;
//         if (!saveMoney(montant))
//         {
//             cout << "Montant invalide. Le dépôt a échoué." << endl;
//         }

//         for (int i = 1; i <= 3; i++)
//         {
//             pin = "";
//             cout << "donnez votre pin " << endl;
//             cin >> pin;

//             if (pin != password)
//             {
//                 cout << "Code incorrect, il vous reste " << 3 - i << " essais." << endl;
//             }
//             else
//             {
//                 cout << "Accès autorisé." << endl;
//                 printMenu();
//                 int choix;
//                 cin >> choix;
//                 while (choix != 5)
//                 {
//                     switch (choix)
//                     {
//                     case 1:
//                         cout << "Votre solde actuel est de " << solde_db << "€" << endl;
//                         break;
//                     case 2:
//                     {
//                         double montant;
//                         cout << "Entrez le montant à déposer : ";
//                         cin >> montant;
//                         if (!saveMoney(montant))
//                         {
//                             cout << "Montant invalide. Le dépôt a échoué." << endl;
//                         }
//                         else
//                         {
//                             addOperationToHistory(BankOperationsType::DEPOSIT_MONEY, montant);
//                             cout << "Dépôt réussi. Nouveau solde : " << getAccountBalance() << "€" << endl;
//                         }
//                         break;
//                     }
//                     case 3:
//                     {
//                         double moneyToWithdraw;
//                         cout << "Entrez le montant à retirer : ";
//                         cin >> moneyToWithdraw;
//                         if (!withdrawMoney(moneyToWithdraw))
//                         {
//                             cout << "Solde insuffisant. Votre solde est de " << getAccountBalance() << "€" << endl;
//                         }
//                         else
//                         {
//                             addOperationToHistory(BankOperationsType::WITHDRAW_MONEY, moneyToWithdraw);
//                             cout << "Retrait accepté. Nouveau solde : " << getAccountBalance() << "€" << endl;
//                         }
//                         break;
//                     }
//                     case 4: // print operation history
//                         printOperationHistory();
//                         break;

//                     default:
//                         break;
//                     }
//                     printMenu();
//                     cin >> choix;
//                 }
//             }
//         }

//         return 0;
//     }

void printMenu()
{
    cout << "menu principal" << endl;
    cout << 1 << " Consulter solde" << endl;
    cout << 2 << " Déposer de l’argent" << endl;
    cout << 3 << " Retirer de l’argent" << endl;
    cout << 4 << " Printer Historique des opérations" << endl;
    cout << 5 << " Quitter" << endl;
    cout << "donnez votre Choix " << endl;
}

//         double getAccountBalance()
//         {
//             return accountbalance_test;
//         }
//         double updateAccountBalance(double newBalance)
//         {
//             accountbalance_test = newBalance;
//             return accountbalance_test;
//         }

bool saveMoney(double moneyToSave, double &balance)
{
    if (moneyToSave < 0)
    {
        return false;
    }
    balance += moneyToSave;

    return true;
}

bool withdrawMoney(double moneyToWithdraw, double &balance)
{

    if (moneyToWithdraw < 0 || moneyToWithdraw > balance)
    {
        return false;
    }
    balance -= moneyToWithdraw;
    return true;
}

//         void printOperationHistory()
//         {
//             cout << "Historique des opérations :" << endl;
//             int start = operationCount > MAX_COUNT_OPERATIONS ? (operationCount - MAX_COUNT_OPERATIONS) : 0;
//             int end = operationCount;

//             for (int i = start; i < end; i++)
//             {
//                 int index = (i) % MAX_COUNT_OPERATIONS;
//                 string operationType = operationHistory[index].type == BankOperationsType::DEPOSIT_MONEY ? "Dépôt" : "Retrait";
//                 cout << operationType << " de " << operationHistory[index].amount << "€" << endl;
//             }
//         }

//         /**
//          * addOperationToHistory
//          *
//          * Record a bank operation into the fixed-size operationHistory ring buffer.
//          *
//          * Behavior:
//          *  - Increments the global operationCount (total number of operations recorded).
//          *  - Computes an insertion index as (operationCount % MAX_COUNT_OPERATIONS).
//          *  - Stores the provided operation type and amount at the computed index,
//          *    overwriting the oldest entry when more than MAX_COUNT_OPERATIONS operations
//          *    have been recorded (circular/ring buffer behavior).
//          *
//          * Parameters:
//          *  - BankOperationsType type: type of the operation (DEPOSIT_MONEY or WITHDRAW_MONEY).
//          *  - double amount: amount involved in the operation (expected to be non-negative;
//          *    no validation is performed by this function).
//          *
//          * Notes:
//          *  - operationHistory is a global fixed-size array used as a circular buffer.
//          *  - operationCount is a global counter tracking the total number of recorded operations.
//          *  - This function does not perform validation of inputs and is not thread-safe.
//          */
void addOperationToHistory(Operation operationHistory[], int &operationCount, BankOperationsType type, double amount)
{
    operationCount++;
    int currentIndex = (operationCount - 1) % MAX_COUNT_OPERATIONS;

    // using ring buffer logic to store operations
    operationHistory[currentIndex].type = type;
    operationHistory[currentIndex].amount = amount;
}
