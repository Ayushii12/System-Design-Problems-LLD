# StackOverflow

## Requirements
- Users should be able to **post questions and answers**
- Users should be able to **add comments** on questions ans answers
- Users should be able to **upvote/downvote** questions and answers
- All the **questions** should have **tags** assigned to them
- Users should be able to **search** questions based on keywords, tags and user profiles
- System should **assign reputation** to users based on their activity and quality of answers

## Entities
- **User**: Represents a user of the Stack Overflow system, with properties such as id, username, email, and reputation
- **Question**: Represents a question posted by a user, with properties such as id, title, content, author, answers, comments, tags, votes and creation date
- **Answer**: Represents an answer to a question, with properties such as id, content, author, associated question, comments, votes and creation date
- **Comment**: Represents a comment on a question or an answer, with properties such as id, content, author, and creation date
- **Tag**: Represents a tag associated with a question, with properties such as id and name
- **Vote**: Represents vote associated with a question/answer
- **StackOverflow**: Main class that manages the Stack Overflow system. It provides methods for creating user, posting questions, answers, and comments, voting on questions and answers, searching for questions, and retrieving questions by tags and users
