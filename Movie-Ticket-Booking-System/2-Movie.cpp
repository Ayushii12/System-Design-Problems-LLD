class Movie {
private:
    string id;
    string title;
    string description;
    int duration; // Duration in minutes

public:
    // Constructor
    Movie(const string& movie_id, const string& movie_title, 
          const string& movie_description, int movie_duration)
        : id(movie_id), title(movie_title), description(movie_description), duration(movie_duration) {}

    // Getters
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    int getDuration() const { return duration; }

    // Display function
    void display() const {
        cout << "Movie ID: " << id << "\nTitle: " << title 
             << "\nDescription: " << description << "\nDuration: " << duration << " mins" << endl;
    }
};
