# ATM

## Requirements
- The ATM system should support basic operations such as **balance inquiry, cash withdrawal, and cash deposit**
- Users should be able to **authenticate** themselves using a PIN
- The system should interact with a bank's backend system to **validate user account** and perform transactions
- The ATM should have a **cash dispenser** to dispense cash to users
  
## Entities
- **Account**: Represents a bank account with an account number and balance. It provides methods to debit and credit the account balance
- **Card**: Represents an ATM card with a card number and PIN
- **Transaction**: An abstract base class for different types of transactions, such as withdrawal and deposit. It is extended by WithdrawalTransaction and DepositTransaction classes
- **BankingSystem**: Manages the bank accounts and processes transactions. It uses a thread-safe ConcurrentHashMap to store and retrieve account information
- **CashDispenser**: Represents the ATM's cash dispenser and handles the dispensing of cash. It uses synchronization to ensure thread safety when dispensing cash
- **ATM**: Main interface for ATM operations. It interacts with the BankingService and CashDispenser to perform user authentication, balance inquiry, cash withdrawal, and cash deposit
