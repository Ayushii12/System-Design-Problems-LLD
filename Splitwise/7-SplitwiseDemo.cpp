#include "1-User.cpp"
#include "2-Split.cpp"
#include "3-Expense.cpp"
#incldue "4-Group.cpp"
#include "5-Transaction.cpp"
#include "6-Splitwise.cpp"
using namespace std;

class SplitwiseDemo {
public:
    static void demo() {
        // Get the singleton instance of Splitwise
        Splitwise& app = Splitwise::getInstance();
        
        // Create users
        User* alice = new User(1, "Alice");
        User* bob = new User(2, "Bob");
        User* charlie = new User(3, "Charlie");
        
        // Add users to the system
        app.addUser(alice);
        app.addUser(bob);
        app.addUser(charlie);
        
        // Create a group and add the users as members
        Group* tripGroup = new Group(101, "Weekend Trip");
        tripGroup->addMember(alice);
        tripGroup->addMember(bob);
        tripGroup->addMember(charlie);
        app.addGroup(tripGroup);
        
        // Create an expense
        Expense* expense = new Expense(201, 300.0, "Hotel Bill", alice);

        // Add Splits to the 'expense'
        expense->addSplit(new EqualSplit(alice, 3));
        expense->addSplit(new EqualSplit(bob, 3));
        expense->addSplit(new EqualSplit(charlie, 3));
        
        // For each split, calculate the share based on the expense total
        for (auto s : expense->getSplits()) {
            s->calculateShare(expense->getAmount());
        }

        // Add the expense to the list of expenses
        app.addExpense(expense);

        // Process the expense to update user balances
        app.splitExpense(expense);
        
        // Settle outstanding balances by creating transactions
        app.settleBalances();
        
        // Cleanup: Delete users and group
        delete alice;
        delete bob;
        delete charlie;
        delete tripGroup;
    }
};

int main() {
    SplitwiseDemo::demo();
    return 0;
}
