#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// -----------------------------
// Media Classes and Factory
// -----------------------------

// Base class for media (SRP: single responsibility, exposes only necessary interfaces)
class Media {
public:
    virtual void display() const = 0;
    virtual std::string getTitle() const = 0;
    // Default implementations for attributes that might not be applicable.
    virtual std::string getAuthor() const { return ""; }
    virtual std::string getISBN() const { return ""; }
    virtual ~Media() = default;
};

// Book – includes title, author, and ISBN.
class Book : public Media {
private:
    std::string title;
    std::string author;
    std::string isbn;
public:
    Book(const std::string &title, const std::string &author, const std::string &isbn)
        : title(title), author(author), isbn(isbn) {}
    void display() const override {
        std::cout << "Book: " << title << " by " << author 
                  << ", ISBN: " << isbn << "\n";
    }
    std::string getTitle() const override { return title; }
    std::string getAuthor() const override { return author; }
    std::string getISBN() const override { return isbn; }
};

// Magazine – includes title and issue number.
class Magazine : public Media {
private:
    std::string title;
    int issue;
public:
    Magazine(const std::string &title, int issue)
        : title(title), issue(issue) {}
    void display() const override {
        std::cout << "Magazine: " << title << ", Issue: " << issue << "\n";
    }
    std::string getTitle() const override { return title; }
};

// DVD – includes title and duration.
class DVD : public Media {
private:
    std::string title;
    int duration; // in minutes
public:
    DVD(const std::string &title, int duration)
        : title(title), duration(duration) {}
    void display() const override {
        std::cout << "DVD: " << title << ", Duration: " 
                  << duration << " minutes\n";
    }
    std::string getTitle() const override { return title; }
};

// MediaFactory encapsulates object creation.
// For a Book, extraInfo is expected to be in the format "author,ISBN".
class MediaFactory {
public:
    enum class MediaType { Book, Magazine, DVD };

    static std::unique_ptr<Media> createMedia(MediaType type,
                                              const std::string &title,
                                              const std::string &extraInfo) {
        switch (type) {
            case MediaType::Book: {
                std::istringstream iss(extraInfo);
                std::string author, isbn;
                if (std::getline(iss, author, ',') && std::getline(iss, isbn)) {
                    return std::make_unique<Book>(title, author, isbn);
                }
                return nullptr;
            }
            case MediaType::Magazine: {
                int issue = std::stoi(extraInfo);
                return std::make_unique<Magazine>(title, issue);
            }
            case MediaType::DVD: {
                int duration = std::stoi(extraInfo);
                return std::make_unique<DVD>(title, duration);
            }
            default:
                return nullptr;
        }
    }
};

// -----------------------------
// User/Patron Classes and Factory
// -----------------------------

// Base class for a library user (patron).
class User {
protected:
    std::string name;
    std::string id;
public:
    User(const std::string &name, const std::string &id)
        : name(name), id(id) {}
    virtual void displayRole() const = 0;
    std::string getName() const { return name; }
    std::string getId() const { return id; }
    virtual ~User() = default;
};

class Student : public User {
public:
    Student(const std::string &name, const std::string &id)
        : User(name, id) {}
    void displayRole() const override {
        std::cout << "Role: Student, Name: " << name 
                  << ", ID: " << id << "\n";
    }
};

class Teacher : public User {
public:
    Teacher(const std::string &name, const std::string &id)
        : User(name, id) {}
    void displayRole() const override {
        std::cout << "Role: Teacher, Name: " << name 
                  << ", ID: " << id << "\n";
    }
};

class Visitor : public User {
public:
    Visitor(const std::string &name, const std::string &id)
        : User(name, id) {}
    void displayRole() const override {
        std::cout << "Role: Visitor, Name: " << name 
                  << ", ID: " << id << "\n";
    }
};

// Factory to create user objects.
class UserFactory {
public:
    enum class UserType { Student, Teacher, Visitor };

    static std::unique_ptr<User> createUser(UserType type,
                                              const std::string &name,
                                              const std::string &id) {
        switch (type) {
            case UserType::Student:
                return std::make_unique<Student>(name, id);
            case UserType::Teacher:
                return std::make_unique<Teacher>(name, id);
            case UserType::Visitor:
                return std::make_unique<Visitor>(name, id);
            default:
                return nullptr;
        }
    }
};

// -----------------------------
// Borrow Transaction Class
// -----------------------------
//
// This class records a borrowing transaction by storing pointers
// to the media item and the user (patron) along with a due date.
class BorrowTransaction {
public:
    Media* media;
    User* user;
    std::string dueDate;
    BorrowTransaction(Media* m, User* u, const std::string &due)
        : media(m), user(u), dueDate(due) {}
};

// -----------------------------
// Singleton Library Class
// -----------------------------
//
// Library manages media collections, user (patron) records, and borrowing 
// transactions. It provides methods for searching, borrowing, returning, 
// and displaying information.
class Library {
private:
    std::vector<std::unique_ptr<Media>> mediaCollection;
    std::vector<std::unique_ptr<User>> userCollection;
    std::vector<BorrowTransaction> borrowTransactions;

    Library() {} // Private constructor

public:
    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    static Library& getInstance() {
        static Library instance;
        return instance;
    }

    // Methods to add media and users.
    void addMedia(std::unique_ptr<Media> media) {
        mediaCollection.push_back(std::move(media));
    }
    void addUser(std::unique_ptr<User> user) {
        userCollection.push_back(std::move(user));
    }

    // Display all media.
    void displayMedia() const {
        std::cout << "\nMedia Collection:\n";
        for (const auto &media : mediaCollection) {
            media->display();
        }
    }

    // Display all users.
    void displayUsers() const {
        std::cout << "\nUser Collection:\n";
        for (const auto &user : userCollection) {
            user->displayRole();
        }
    }

    // Search functions: by title, author, ISBN.
    std::vector<Media*> searchMediaByTitle(const std::string &title) const {
        std::vector<Media*> results;
        for (const auto &media : mediaCollection) {
            if (media->getTitle() == title)
                results.push_back(media.get());
        }
        return results;
    }

    std::vector<Media*> searchMediaByAuthor(const std::string &author) const {
        std::vector<Media*> results;
        for (const auto &media : mediaCollection) {
            if (media->getAuthor() == author)
                results.push_back(media.get());
        }
        return results;
    }

    std::vector<Media*> searchMediaByISBN(const std::string &isbn) const {
        std::vector<Media*> results;
        for (const auto &media : mediaCollection) {
            if (media->getISBN() == isbn)
                results.push_back(media.get());
        }
        return results;
    }

    // Helper function to check whether a media item is already borrowed.
    bool isMediaBorrowed(Media* media) const {
        for (const auto &txn : borrowTransactions) {
            if (txn.media == media) return true;
        }
        return false;
    }

    // Borrow a media item by title.
    // (In this simple example, we borrow the first available copy.)
    bool borrowMedia(const std::string &title, User* user, const std::string &dueDate) {
        for (auto &media : mediaCollection) {
            if (media->getTitle() == title && !isMediaBorrowed(media.get())) {
                borrowTransactions.emplace_back(media.get(), user, dueDate);
                std::cout << "Borrowed: " << title << " by " << user->getName() << "\n";
                return true;
            }
        }
        std::cout << "Media not available for borrowing: " << title << "\n";
        return false;
    }

    // Return a media item by title.
    bool returnMedia(const std::string &title, User* user) {
        auto it = std::find_if(borrowTransactions.begin(), borrowTransactions.end(),
            [&](const BorrowTransaction &txn) {
                return txn.media->getTitle() == title && txn.user == user;
            });
        if (it != borrowTransactions.end()) {
            std::cout << "Returned: " << title << " by " << user->getName() << "\n";
            borrowTransactions.erase(it);
            return true;
        }
        std::cout << "No borrow record found for: " << title << "\n";
        return false;
    }

    // Display all currently borrowed media and their due dates.
    void displayBorrowedMedia() const {
        std::cout << "\nBorrowed Media:\n";
        for (const auto &txn : borrowTransactions) {
            std::cout << "Media: " << txn.media->getTitle() 
                      << " borrowed by " << txn.user->getName() 
                      << " (Due: " << txn.dueDate << ")\n";
        }
    }
};

// -----------------------------
// Main function demonstrating the system
// -----------------------------
int main() {
    // Obtain the single Library instance.
    Library &library = Library::getInstance();

    // Create media items using the factory.
    auto book1 = MediaFactory::createMedia(MediaFactory::MediaType::Book, "The Great Gatsby", "F. Scott Fitzgerald,9780743273565");
    auto magazine1 = MediaFactory::createMedia(MediaFactory::MediaType::Magazine, "National Geographic", "202");
    auto dvd1 = MediaFactory::createMedia(MediaFactory::MediaType::DVD, "Inception", "148");

    library.addMedia(std::move(book1));
    library.addMedia(std::move(magazine1));
    library.addMedia(std::move(dvd1));

    // Create users (patrons) using the user factory.
    // We keep a local pointer to "Alice" for demonstration.
    auto alice = UserFactory::createUser(UserFactory::UserType::Student, "Alice", "S001");
    User* alicePtr = alice.get();
    auto bob = UserFactory::createUser(UserFactory::UserType::Teacher, "Bob", "T001");
    auto charlie = UserFactory::createUser(UserFactory::UserType::Visitor, "Charlie", "V001");

    library.addUser(std::move(alice));
    library.addUser(std::move(bob));
    library.addUser(std::move(charlie));

    // Display all media and user information.
    library.displayMedia();
    library.displayUsers();

    // Demonstrate search functionality.
    std::cout << "\nSearching for media titled 'Inception':\n";
    auto results = library.searchMediaByTitle("Inception");
    for (const auto &media : results) {
        media->display();
    }

    // Borrow a media item.
    library.borrowMedia("The Great Gatsby", alicePtr, "2025-05-01");
    library.displayBorrowedMedia();

    // Return the media item.
    library.returnMedia("The Great Gatsby", alicePtr);
    library.displayBorrowedMedia();

    return 0;
}
