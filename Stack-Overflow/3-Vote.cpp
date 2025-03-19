#include <iostream>
#include "3a-VoteType.cpp"
using namespace std;

class Vote {
private:
    int id;
    int userId;    // User who cast the vote
    VoteType type;

public:
    // Constructor
    Vote(int id, VoteType type, int userId)
        : id(id), type(type), userId(userId) {}

    // Getters
    int getId() const {
        return id;
    }

    VoteType getVoteType() const {
        return type;
    }

    int getUserId() const {
        return userId;
    }

    // Method to toggle vote type (if needed)
    void toggleVote() {
        if (type == UPVOTE) {
            type = DOWNVOTE;
        } else {
            type = UPVOTE;
        }
    }
}
