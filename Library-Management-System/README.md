# Library Management System
This project implements a Library Management System in C++ using SOLID principles along with the Factory and Singleton design patterns.


## Requirements 
- **Media Management:**
  - Add new media (Books, Magazines, DVDs) to the library
  - Display a comprehensive list of all media items available
- **User Management:**
  - Add new patrons (Students, Teachers, Visitors) to the system
  - Display a list of all registered users
- **Search Functionality:**
  - Search media by **Title**
  - Search media by **Author** (applicable for books)
  - Search media by **ISBN** (applicable for books)
- **Borrowing and Returning:**
  - Borrow a media item and record a due date
  - Return a media item and update the borrow records
  - Display all currently borrowed media along with their due dates


## Entities
- **Media (Abstract Base Class):** Defines a common interface for all library media items
  - **Book:** Attributes: `title`, `author`, `ISBN`
  - **Magazine:** Attributes: `title`, `issue`
  - **DVD:** Attributes: `title`, `duration`

- **MediaFactory:** Implements object creation for different media types.
  - Accepts parameters:
    - Media type (Book, Magazine, DVD)
    - Title
    - Extra information (author & ISBN for books, issue number for magazines, duration for DVDs)

- **User (Abstract Base Class):**  Stores basic patron information such as `name` and `ID`
  - **Student**
  - **Teacher**
  - **Visitor**

- **UserFactory:** Implements the creation of various user types (Student, Teacher, Visitor)

- **BorrowTransaction:** Represents a borrowing transaction by linking:
  - A media item
  - A user (patron)
  - A due date for the borrowed item

- **Library (Singleton):** Manages all media items, user records, and borrowing transactions
  - Provides functionality for:
    - Adding media and users
    - Searching media (by title, author, ISBN)
    - Borrowing and returning media
    - Displaying current collections and borrowed items with due dates


## Code Structure
- `main.cpp`  
  Contains the main function and demonstrates usage of the system.
  
- Class Files:  
  - `Media` (Abstract Base Class) with derived classes: `Book`, `Magazine`, `DVD`
  - `User` (Abstract Base Class) with derived classes: `Student`, `Teacher`, `Visitor`
  - `MediaFactory` for media object creation.
  - `UserFactory` for user object creation.
  - `BorrowTransaction` to record borrow transactions.
  - `Library` (Singleton) to manage collections and transactions.


