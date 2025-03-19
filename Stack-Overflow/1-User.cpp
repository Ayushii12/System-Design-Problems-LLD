#include <iostream>
#include <string>
#include <vector>
#include "4-Question.cpp"
#include "5-Answer.cpp"
#include "6-Comment.cpp"
using namespace std;

class User {
private:
    int id;
    string username;
    string email;
    int reputation;
    vector<int> questionsPosted;  // storing IDs
    vector<int> answersPosted;    // storing IDs
    vector<int> commentsPosted;   // storing IDs

public:
    // Constructor
    User(int id, const string& username, const string& email)
        : id(id), username(username), email(email), reputation(0) {}

    // Getters
    int getId() const {
        return id;
    }

    string getUsername() const {
        return username;
    }

    string getEmail() const {
        return email;
    }

    int getReputation() const {
        return reputation;
    }

    vector<int> getQuestionsPosted() const {
        return questionsPosted;
    }

    vector<int> getAnswersPosted() const {
        return answersPosted;
    }

    vector<int> getCommentsPosted() const {
        return commentsPosted;
    }

    // Setters
    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    // Reputation handling
    void incrementReputation(int points) {
        reputation += points;
    }

    void decrementReputation(int points) {
        reputation -= points;
        if (reputation < 0) reputation = 0;
    }

    void addQuestionPosted(int questionId) {
        questionsPosted.push_back(questionId);
    }

    void addAnswerPosted(int answerId) {
        answersPosted.push_back(answerId);
    }

    void addCommentPosted(int commentId) {
        commentsPosted.push_back(commentId);
    }
};
