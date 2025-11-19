#include <iostream>
using namespace std;
int printMenu();
double accountbalance_test = 1523.75;
double getAccountBalance();
bool saveMoney(double moneyToSave);
double updateAccountBalance(double newBalance);
bool withdrawMoney(double moneyToWithdraw);

// for iteration 5 , add function of operation history
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

// Define a fixed-size array to store the last 10 operations
constexpr int MAX_COUNT_OPERATIONS = 10;
Operation operationHistory[MAX_COUNT_OPERATIONS];
static int operationCount = 0;
void addOperationToHistory(BankOperationsType type, double amount);
void printOperationHistory();
int main()
{
    const string password = "2580";
    string pin = "";
    double solde_db = getAccountBalance();
    for (int i = 1; i <= 3; i++)
    {
        pin = "";
        cout << "donnez votre pin " << endl;
        cin >> pin;

        if (pin != password)
        {
            cout << "Code incorrect, il vous reste " << 3 - i << " essais." << endl;
        }
        else
        {
            cout << "Accès autorisé." << endl;
            printMenu();
            int choix;
            cin >> choix;
            while (choix != 5)
            {
                switch (choix)
                {
                case 1:
                    cout << "Votre solde actuel est de " << solde_db << "€" << endl;
                    break;
                case 2:
                {
                    double montant;
                    cout << "Entrez le montant à déposer : ";
                    cin >> montant;
                    if (!saveMoney(montant))
                    {
                        cout << "Montant invalide. Le dépôt a échoué." << endl;
                    }
                    else
                    {
                        addOperationToHistory(BankOperationsType::DEPOSIT_MONEY, montant);
                        cout << "Dépôt réussi. Nouveau solde : " << getAccountBalance() << "€" << endl;
                    }
                    break;
                }
                case 3:
                {
                    double moneyToWithdraw;
                    cout << "Entrez le montant à retirer : ";
                    cin >> moneyToWithdraw;
                    if (!withdrawMoney(moneyToWithdraw))
                    {
                        cout << "Solde insuffisant. Votre solde est de " << getAccountBalance() << "€" << endl;
                    }
                    else
                    {
                        addOperationToHistory(BankOperationsType::WITHDRAW_MONEY, moneyToWithdraw);
                        cout << "Retrait accepté. Nouveau solde : " << getAccountBalance() << "€" << endl;
                    }
                    break;
                }
                case 4: // print operation history
                    printOperationHistory();
                    break;

                default:
                    break;
                }
                printMenu();
                cin >> choix;
            }
        }
    }

    return 0;
}

int printMenu()
{
    cout << "menu principal" << endl;
    cout << 1 << " Consulter solde" << endl;
    cout << 2 << " Déposer de l’argent" << endl;
    cout << 3 << " Retirer de l’argent" << endl;
    cout << 4 << " Printer Historique des opérations" << endl;
    cout << 5 << " Quitter" << endl;
    cout << "donnez votre Choix " << endl;
    return 0;
}

double getAccountBalance()
{
    return accountbalance_test;
}
double updateAccountBalance(double newBalance)
{
    accountbalance_test = newBalance;
    return accountbalance_test;
}

bool saveMoney(double moneyToSave)
{
    if (moneyToSave < 0)
    {
        return false;
    }
    double solde_db = getAccountBalance();
    solde_db += moneyToSave;
    updateAccountBalance(solde_db);
    return true;
}

bool withdrawMoney(double moneyToWithdraw)
{
    double solde_db = getAccountBalance();
    if (moneyToWithdraw < 0 || moneyToWithdraw > solde_db)
    {
        return false;
    }
    solde_db -= moneyToWithdraw;
    updateAccountBalance(solde_db);
    return true;
}

void printOperationHistory()
{
    cout << "Historique des opérations :" << endl;
    int start = operationCount > MAX_COUNT_OPERATIONS ? (operationCount - MAX_COUNT_OPERATIONS) : 0;
    int end = operationCount;

    for (int i = start; i < end; i++)
    {
        int index = (i) % MAX_COUNT_OPERATIONS;
        string operationType = operationHistory[index].type == BankOperationsType::DEPOSIT_MONEY ? "Dépôt" : "Retrait";
        cout << operationType << " de " << operationHistory[index].amount << "€" << endl;
    }
}

/**
 * addOperationToHistory
 *
 * Record a bank operation into the fixed-size operationHistory ring buffer.
 *
 * Behavior:
 *  - Increments the global operationCount (total number of operations recorded).
 *  - Computes an insertion index as (operationCount % MAX_COUNT_OPERATIONS).
 *  - Stores the provided operation type and amount at the computed index,
 *    overwriting the oldest entry when more than MAX_COUNT_OPERATIONS operations
 *    have been recorded (circular/ring buffer behavior).
 *
 * Parameters:
 *  - BankOperationsType type: type of the operation (DEPOSIT_MONEY or WITHDRAW_MONEY).
 *  - double amount: amount involved in the operation (expected to be non-negative;
 *    no validation is performed by this function).
 *
 * Notes:
 *  - operationHistory is a global fixed-size array used as a circular buffer.
 *  - operationCount is a global counter tracking the total number of recorded operations.
 *  - This function does not perform validation of inputs and is not thread-safe.
 */
void addOperationToHistory(BankOperationsType type, double amount)
{
    operationCount++;
    int currentIndex = (operationCount - 1) % MAX_COUNT_OPERATIONS;

    // using ring buffer logic to store operations
    operationHistory[currentIndex].type = type;
    operationHistory[currentIndex].amount = amount;
}
