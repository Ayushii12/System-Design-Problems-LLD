#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "1-User.cpp"
#include "2-tag.cpp"
#include "3-Vote.cpp"
#include "4-Question.cpp"
#include "5-Answer.cpp"
#include "6-Comment.cpp"
using namespace std;

class StackOverflow {
private:
    static StackOverflow* instance;
    unordered_map<int, User> users;
    unordered_map<int, Question> questions;
    unordered_map<int, Answer> answers;
    unordered_map<int, Comment> comments;
    unordered_map<int, Vote> votes;
    unordered_map<int, Tag> tags;
    int userIdCounter = 1;
    int questionIdCounter = 1;
    int answerIdCounter = 1;
    int commentIdCounter = 1;
    int voteIdCounter = 1;
    int tagIdCounter = 1;
    // Private constructor for Singleton pattern
    StackOverflow() : userIdCounter(1), questionIdCounter(1), answerIdCounter(1), commentIdCounter(1), voteIdCounter(1), tagIdCounter(1) {}

public:
    static StackOverflow* getInstance() {
        if (!instance)
            instance = new StackOverflow();
        return instance;
    }
      
    // User creation
    int createUser(const string& username, const string& email) {
        User user(userIdCounter, username, email);
        users[userIdCounter] = user;
        return userIdCounter++;
    }

    // Tag creation
    int createTag(const string& tagName) {
        Tag tag(tagIdCounter, tagName);
        tags[tagIdCounter] = tag;
        return tagIdCounter++;
    }

    // Post Question
    int postQuestion(const string& title, const string& description, int authorId, const vector<string>& tagNames) {
        Question question(questionIdCounter, title, description, authorId, tagNames);
        questions[questionIdCounter] = question;
        users[authorId].incrementReputation(5); // +5 points for posting a question
        return questionIdCounter++;
    }

    // Post Answer
    int postAnswer(int questionId, int authorId, const string& content, const string& creationDate) {
        Answer answer(answerIdCounter, content, authorId, questionId, creationDate);
        answers[answerIdCounter] = answer;
        questions[questionId].addAnswer(answer);
        users[authorId].incrementReputation(10); // +10 points for answering
        return answerIdCounter++;
    }

    // Post Comment on Question
    int postCommentOnQuestion(int questionId, int authorId, const string& content, const string& creationDate) {
        Comment comment(commentIdCounter, content, authorId, creationDate);
        comments[commentIdCounter] = comment;
        questions[questionId].addComment(comment);
        return commentIdCounter++;
    }

    // Post Comment on Answer
    int postCommentOnAnswer(int answerId, int authorId, const string& content, const string& creationDate) {
        Comment comment(commentIdCounter, content, authorId, creationDate);
        comments[commentIdCounter] = comment;
        answers[answerId].addComment(comment);
        return commentIdCounter++;
    }

    // Vote on Question
    int voteQuestion(int questionId, int userId, VoteType voteType) {
        Vote vote(voteIdCounter, voteType);
        votes[voteIdCounter] = vote;
        questions[questionId].addVote(vote);

        int questionAuthorId = questions[questionId].getUserId();
        if (type == UPVOTE)
          users[questionAuthorId].incrementReputation(5); // +5 points for question upvote
        else if (type == DOWNVOTE)
          users[questionAuthorId].decrementReputation(2); // -2 points for question downvote
      
        return voteIdCounter++;
    }

    // Vote on Answer
    int voteOnAnswer(int answerId, int userId, VoteType type) {
        Vote vote(voteIdCounter, type);
        votes[voteIdCounter] = vote;
        answers[answerId].addVote(vote);

        int answerAuthorId = answers[answerId].getAuthorId();
        if (type == UPVOTE)
            users[answerAuthorId].incrementReputation(10);  // +10 points for an upvote received
        else if (type == DOWNVOTE)
            users[answerAuthorId].decrementReputation(2);   // -2 points for a downvote received
        
        return voteIdCounter++;
    }

    // Search questions by keyword
    vector<Question> searchQuestionsByKeyword(const string& keyword) {
        vector<Question> result;
        for (const auto& [id, question] : questions) {
            if (question.getTitle().find(keyword) != string::npos ||
                question.getDescription().find(keyword) != string::npos)
                result.push_back(question);
        }
        return result;
    }

    // Retrieve questions by Tag
    vector<Question> getQuestionsByTag(const string& tagName) {
        vector<Question> result;
        for (const auto& [qid, question] : questions) {
            for (const auto& tag : question.getTags()) {
                if (tag == tagName) {
                    result.push_back(question);
                    break;
                }
        }
        return result;
    }

    // Retrieve questions by User
    vector<Question> getQuestionsByUser(int userId) {
        vector<Question> result;
        for (const auto& [qid, question] : questions) {
            if (question.getUserId() == userId)
                result.push_back(question);
        }
        return result;
    }
}
