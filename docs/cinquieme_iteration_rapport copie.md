# rapport de cinquième iteration

Github: [https://github.com/gqysmart/cppcourse-bankATM]( https://github.com/gqysmart/cppcourse-bankATM)

file: src/App.cpp

## **Fonctionnalités :**

- Enregistrement des opérations
- Affrichage de l'historique des opérations
- Limitation de l'historique(10)

## Algorithme

```cpp
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
```

```cpp
    /**
     * addOperationToHistory

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

```

```cpp

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
```

*Exemple d’utilisation :*

|![retirer](./testResults/iteration5_showHistory.png)|
|:--:|
|Affrichage l'historique|
