#include <iostream>
#include <string>

using namespace std;

class Comment {
private:
    int id;
    string content;
    int authorId;
    string creationDate; // can be formatted as string for simplicity

public:
    // Constructor
    Comment(int id, const string& content, int authorId, const string& creationDate)
        : id(id), content(content), authorId(authorId), creationDate(creationDate) {}

    // Getters
    int getId() const {
        return id;
    }

    string getContent() const {
        return content;
    }

    int getAuthorId() const {
        return authorId;
    }

    string getCreationDate() const {
        return creationDate;
    }

    // Display comment details
    void displayComment() const {
        cout << "Comment ID: " << id << endl;
        cout << "Content: " << content << endl;
        cout << "Author ID: " << authorId << endl;
        cout << "Creation Date: " << creationDate << endl;
    }
}
