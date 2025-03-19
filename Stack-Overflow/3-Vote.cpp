#include <iostream>
#include "3a-VoteType.cpp"
#include "3b-EntityType.cpp"
using namespace std;

class Vote {
private:
    int id;
    int userId;      // User who cast the vote
    int entityId;    // ID of 'question' or 'answer'
    EntityType entityType;
    VoteType voteType;

public:
    // Constructor
    Vote(int id, VoteType voteType, EntityType entityType, int entityId, int userId)
        : id(id), type(voteType), entity(entityType), entityId(entityId), userId(userId) {}

    // Getters
    int getId() const {
        return id;
    }

    VoteType getVoteType() const {
        return type;
    }

    EntityType getEntityType() const {
        return entity;
    }

    int getEntityId() const {
        return entityId;
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
