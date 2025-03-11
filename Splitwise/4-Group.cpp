#include <iostream>
#include <string>
#include <vector>
#include "1-User.cpp"
#include "3-Expense.cpp"
using namespace std;

class Group {
private:
    int groupId;
    string groupName;
    vector<User*> members;      // List of member users
    vector<Expense*> expenses;  // List of expenses in the group

public:
    // Constructor 
    Group(int id, const string &name)
        : groupId(id), groupName(name) {}

    // Destructor
    ~Group() {
        for (auto expense : expenses) { delete expense; }
    }

    // Getter methods
    int getGroupId() const { return groupId; }
    string getGroupName() const { return groupName; }
    const vector<User*>& getMembers() const { return members; }
    const vector<Expense*>& getExpenses() const { return expenses; }

    // Add a member user to the group
    void addMember(User* user) {
        members.push_back(user);
    }

    // Add an expense to the group
    void addExpense(Expense* expense) {
        expenses.push_back(expense);
    }
};
