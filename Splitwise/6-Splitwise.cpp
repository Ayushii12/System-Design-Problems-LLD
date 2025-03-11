#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include "1-User.cpp"
#include "2-Split.cpp"
#include "3-Expense.cpp"
#incldue "4-Group.cpp"
#include "5-Transaction.cpp"
using namespace std;

class Splitwise {
private:
    static Splitwise* instance;
    vector<User*> users;
    vector<Group*> groups;
    vector<Expense*> expenses;
    vector<Transaction*> transactions;

    // Private constructor (Singleton)
    Splitwise() {}

public:
    // Get the singleton instance
    static Splitwise* getInstance() {
        if (!instance) {
            instance = new Splitwise();
        }
        return instance;
    }

    // Destructor
    ~Splitwise() {
        for (auto expense : expenses) { delete expense; }
        for (auto txn : transactions) { delete txn; }
    }

    // Add a user to the system
    void addUser(User* user) {
        users.push_back(user);
    }

    // Add a group
    void addGroup(Group* group) {
        groups.push_back(group);
    }

    // Add an expense
    void addExpense(Expense* expense) {
        expenses.push_back(expense);
    }

    void splitExpense(Expense* expense) {
        if (!expense) return;
        User* paidBy = expense->getPaidBy();
        // Ensure the splits sum up to the expense amount
        if (!expense->validate()) {
            cout << "Expense validation failed! Splits do not add up to the total amount." << endl;
            return;
        }
        // Update balances for each split participant
        for (auto split : expense->getSplits()) {
            User* participant = split->getUser();
            double share = split->getAmount();
            if (participant != paidBy) {
                paidBy->updateBalance(participant->getId(), share);
                participant->updateBalance(paidBy->getId(), -share);
            }
        }
    }

    // Create a transaction between two users.
    Transaction* createTransaction(User* sender, User* receiver, double amount);

    // Settle outstanding balances by creating transactions
    // A naive implementation: for each pair of users, if one owes the other, create a transaction
    void settleBalances() {
        for (auto payer : users) {
            for (auto payee : users) {
                if (payer == payee)
                    continue;
                const unordered_map<int, double>& balances = payer->getBalances();
                auto it = balances.find(payee->getId());
                if (it != balances.end() && it->second < 0) {
                    // Convert negative balance to positive amount while creating a transaction for settlement
                    Transaction* txn = createTransaction(payer, payee, -it->second);
                    payer->updateBalance(payee->getId(), settleAmount);
                    payee->updateBalance(payer->getId(), -settleAmount);
                }
            }
        }
    }
    
};
