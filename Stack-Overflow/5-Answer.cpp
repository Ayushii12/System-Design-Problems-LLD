#include <iostream>
#include <vector>
#include <string>
#include "3-Vote.cpp"
#include "6-Comment.cpp"
using namespace std;

class Answer {
private:
    int id;
    string content;
    int authorId;       // User who posted this answer
    int questionId;     // Associated question ID
    vector<Comment> comments;
    vector<Vote> votes;
    string creationDate;  // simplified as string, can use timestamp if desired

public:
    // Constructor
    Answer(int id, const string& content, int authorId, int questionId, const string& creationDate)
        : id(id), content(content), authorId(authorId), questionId(questionId), creationDate(creationDate) {}

    // Getters
    int getId() const { return id; }
    string getContent() const { return content; }
    int getAuthorId() const { return authorId; }
    int getQuestionId() const { return questionId; }
    string getCreationDate() const { return creationDate; }

    // Add comment
    void addComment(const Comment& comment) {
        comments.push_back(comment);
    }

    // Add vote
    void addVote(const Vote& vote) {
        votes.push_back(vote);
    }

    // Count votes
    pair<int, int> countVotes() const {
        int upvotes = 0, downvotes = 0;
        for(const Vote& vote : votes) {
            if(vote.type == UPVOTE) upvotes++;
            else if(vote.type == DOWNVOTE) downvotes++;
        }
        return {upvotes, downvotes};
    }

    // Display Answer Details
    void displayAnswer() const {
        cout << "Answer ID: " << id << endl;
        cout << "Content: " << content << endl;
        cout << "Author ID: " << authorId << endl;
        cout << "Question ID: " << questionId << endl;
        cout << "Creation Date: " << creationDate << endl;

        auto [upvotes, downvotes] = countVotes();
        cout << "Votes: " << upvotes << " Upvotes, " << downvotes << " Downvotes" << endl;

        cout << "Comments: " << endl;
        for(const Comment& comment : comments) {
            cout << "  Comment ID: " << comment.id << ", Content: " << comment.content 
                 << ", User ID: " << comment.userId << endl;
        }
    }
}
