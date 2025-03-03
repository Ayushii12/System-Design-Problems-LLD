#include <iostream>
#include <string>
#include <map>
#include <ctime> 

// Include the Movie, Theater, and Seat classes
#include "Movie.cpp"
#include "Theater.cpp"
#include "Seat.cpp"

class Show {
private:
    std::string id;
    Movie movie;
    Theater theater;
    std::tm startTime;  // struct tm is used for date and time representation in C++
    std::tm endTime;   
    std::map<std::string, Seat> seats;

public:
    Show(const std::string& show_id, const Movie& movie_obj, const Theater& theater_obj, 
         const std::tm& start_time, const std::tm& end_time, const std::map<std::string, Seat>& seat_map)
        : id(show_id), movie(movie_obj), theater(theater_obj), startTime(start_time), endTime(end_time), seats(seat_map) {}

    // Getters
    std::string getId() const { return id; }
    Movie getMovie() const { return movie; }
    Theater getTheater() const { return theater; }
    std::tm getStartTime() const { return startTime; }
    std::tm getEndTime() const { return endTime; }
    std::map<std::string, Seat> getSeats() const { return seats; }
};
