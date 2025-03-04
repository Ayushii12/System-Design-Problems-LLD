#include <iostream>
#include <string>
#include <vector>
#include "Show.cpp"  

class Theater {
private:
    std::string id;
    std::string name;
    std::string location;
    std::vector<Show> shows;  

public:
    // Constructor
    Theater(const std::string& theater_id, const std::string& theater_name, 
            const std::string& theater_location, const std::vector<Show>& theater_shows)
        : id(theater_id), name(theater_name), location(theater_location), shows(theater_shows) {}

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getLocation() const { return location; }
    std::vector<Show> getShows() const { return shows; }
};
