# Splitwise

## Requirements
- The system should allow users to **create accounts**
- The system should allow user to **create groups**
- Within a group, the system should allow a user to **add other users** to the group
- Within a group, the system should allow a user to **add total expense, description, participants**
- The system should automatically **split the expenses** among the participants
- The system should support different split methods, such as **equal split, percentage split, and exact amounts**
- The system should allow users to view their **outstanding payments** to other users
- The system should allow users to **make payments**
- The system should allow users to **settle expenses**
  
## Entities
- **User**: Represents a user in the Splitwise system, with properties such as ID, name, email, and a map to store balances with other users
- **Group**: Represents a group in Splitwise, containing a list of member users and a list of expenses
- **Expense**: Represents an expense within a group, with properties such as ID, amount, description, the user who paid, and a list of splits
- **Split**: An **abstract** class including the logic for how an expense is divided
  - It has properties such as user (the participant for whom the split is being calculated), amount (The amount that the user owes, this value will be calculated rather than being inputed by the user)
  - calculateShare(expenseTotal): An **abstract** method that each concrete subclass implements to calculate the specific share based on the type of split.
  - validate(): A method to ensure that the split details are correct. For instance, in percentage splits, this method would ensure that the total percentage across all splits sums to 100%
  - Extended classes
    - **EqualSplit**: Divides the total expense equally among all participants
    - **PercentageSplit**: Divides the expense based on predefined percentages for each participant
    - **ExactSplit**: Uses exact amounts provided for each participant
- **Transaction**: Represents a transaction between two users, with properties such as ID, sender, receiver, and amount
- **Splitwise**: The main class that manages the Splitwise system. It follows the Singleton pattern to ensure only one instance of the service exists
  - It provides methods for adding users, groups, and expenses, splitting expenses, updating balances, settling balances, and creating transactions
