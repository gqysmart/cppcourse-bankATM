#include <iostream>
using namespace std;
int printMenu();
int main()
{
    const string password = "2580";
    string pin = "";
    double solde_db = 1523.75;
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
