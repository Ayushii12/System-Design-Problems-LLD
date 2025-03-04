#include <ctime>
#include "4-Flight.cpp"

class FlightManager {
private:
    vector<Flight>& flights;

public:
    // Constructor
    FlightManager(vector<Flight>& flights) : flights(flights) {}

    // Search flights based on source, destination, and date
    vector<Flight> searchFlights(const string& source, const string& destination, const tm& date) {
        vector<Flight> result;
        for (const auto& flight : flights) {
            if (tolower(flight.getSource()) == tolower(source) &&
                tolower(flight.getDestination()) == tolower(destination) &&
                isSameDate(flight.getDepartureTime(), date)) {
                result.push_back(flight);
            }
        }
        return result;
    }

private:
    // Helper function to compare two dates
    static bool isSameDate(const tm& t1, const tm& t2) {
        return t1.tm_year == t2.tm_year && t1.tm_mon == t2.tm_mon && t1.tm_mday == t2.tm_mday;
    }
};
