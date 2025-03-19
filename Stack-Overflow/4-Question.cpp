#include <iostream>
#include <vector>
#include <string>
#include "2-tag.cpp"
#include "3-Vote.cpp"
#include "5-Answer.cpp"
#include "6-Comment.cpp"
using namespace std;

class Question {
private:
    int id;
    string title;
    string description;
    int userId;
    vector<string> tags;
    vector<Answer> answers;
    vector<Comment> comments;
    vector<Vote> votes;

public:
    // Constructor
    Question(int id, const string& title, const string& description, int userId, const vector<string>& tags)
        : id(id), title(title), description(description), userId(userId), tags(tags) {}

    // Add methods
    void addAnswer(const Answer& answer) {
        answers.push_back(answer);
    }

    void addComment(const Comment& comment) {
        comments.push_back(comment);
    }

    void addVote(const Vote& vote) {
        votes.push_back(vote);
    }

    // Count votes
    pair<int, int> countVotes() const {
        int upvotes = 0, downvotes = 0;
        for (const auto& vote : votes) {
            if (vote.type == UPVOTE)
                upvotes++;
            else if (vote.type == DOWNVOTE)
                downvotes++;
        }
        return {upvotes, downvotes};
    }

    // Display details
    void displayQuestion() const {
        cout << "Question ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Asked by User ID: " << userId << endl;

        cout << "Tags: ";
        for (const auto& tag : tags) cout << tag << " ";
        cout << endl;

        auto [upvotes, downvotes] = countVotes();
        cout << "Upvotes: " << upvotes << ", Downvotes: " << downvotes << endl;
    }
}
