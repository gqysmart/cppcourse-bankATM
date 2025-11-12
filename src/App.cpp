#include <iostream>
using namespace std;
int printMenu();
double accountbalance_test = 1523.75;
double getAccountBalance();
bool saveMoney(double moneyToSave);
double updateAccountBalance(double newBalance);
bool withdrawMoney(double moneyToWithdraw);
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
            while (choix != 4)
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
                        cout << "Retrait accepté. Nouveau solde : " << getAccountBalance() << "€" << endl;
                    }
                    break;
                }

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
    cout << 4 << " Quitter" << endl;
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