#include <iostream>
using namespace std;
int main()
{
    const string password = "2580";
    string pin = "";
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
            break;
        }
    }
    return 0;
}
