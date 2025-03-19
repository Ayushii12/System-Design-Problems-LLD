using namespace std;

int main() {
    // Get singleton instance of StackOverflow
    StackOverflow& so = StackOverflow::getInstance();

    // Creating Users
    int aliceId = so.createUser("Alice", "alice@example.com");
    int bobId = so.createUser("Bob", "bob@example.com");
    int charlieId = so.createUser("Charlie", "charlie@example.com");

    // Alice posts a Question
    vector<string> tags = {"C++", "DesignPatterns"};
    int questionId = so.postQuestion("Explain Singleton pattern",
                                     "How does the Singleton design pattern work in C++?",
                                     aliceId, tags);

    // Bob posts an Answer
    int answerId = so.postAnswer(questionId, bobId,
                                 "Singleton ensures only one instance of a class exists.",
                                 "2024-03-19");

    // Users vote on Question and Answer
    so.voteOnQuestion(questionId, bobId, UPVOTE);   // Bob upvotes Alice's question
    so.voteOnAnswer(answerId, aliceId, UPVOTE);     // Alice upvotes Bob's answer

    // Adding Comments
    so.postCommentOnQuestion(questionId, bobId, "Could you elaborate your question?", "2024-03-19");
    so.postCommentOnAnswer(answerId, aliceId, "Clear explanation, thanks!", "2024-03-19");

    
    // Search for Questions containing keyword
    vector<Question> searchResults = so.searchQuestions("Singleton");
    for (const Question& q : searchResults) {
        q.displayQuestion();
        cout << endl;
    }

    // Retrieve and display Questions by Tag
    vector<Question> cppQuestions = so.getQuestionsByTag("C++");
    for (const auto& q : cppQuestions) {
        q.displayQuestion();
        cout << endl;
    }

    // Retrieve and display Questions posted by Alice
    vector<Question> aliceQuestions = so.getQuestionsByUser(aliceId);
    for (const auto& q : aliceQuestions) {
        q.displayQuestion();
        cout << endl;
    }

    return 0;
}
