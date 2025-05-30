# Airline Management System

## Requirements
- Should allow the administrators to add, update, and remove flights, passengers, and seating arrangements
- Should allow users to **search for flights** based on source, destination, and date
- Should support different **seat types** such as Economy, Premium_economy, Business, First_class
- Should display the **seating arrangement** of the selected flights and allow users to choose seats
- Should allow users to **book flights**
- Should allow users to **cancel flights**
- Should allow users to **make payments**
  
## Entities
- **Passenger**: Represents a passenger, with properties such as ID, name, email, and phone number
- **Aircraft**: Represents an aircraft with properties such as tail number, model, and total no. of seats
- **Flight**: Represents a flight in the airline management system, with properties such as flight number, aircraft, source, destination, departure time, arrival time and available seats
  - **FlightManager**: Provides a method to **search** for flights based on source, destination, and date 
- **Seat**: Represents a seat in an aircraft with properties such as seat no., type, price, status
  - **SeatType**: Represents different seat types (Economy, Premium_economy, Business, First_class)
  - **SeatStatus**: Represents seat status (Available, Booked)
- **Booking**: Represents a booking made by a user, with properties such as ID, passenger, flight, selected seat, total price, and status
  - **BookingStatus**: Represents booking status (Pending, Confirmed, Cancelled)
  - **BookingManager**: Provides methods to **generate** booking id, **create bookings** and **cancel bookings**. It follows the Singleton pattern to ensure a single instance of the booking manager
- **Payment**: Represents a payment for a booking, with properties such as ID, amount, and status
  - **PaymentStatus**: Represents payment status (Completed, Pending, Failed)
  - **PaymentProcessor**: Provides a method to process payments. It follows the Singleton pattern to ensure a single instance of the payment processor
- **AirlineSystem**: Main class that manages the movie airline management service
  - Follows the Singleton pattern to ensure only one instance of the service exists
  - Provides methods for adding passengers/aircrafts/flights/seats, booking flights (calculate the total price), canceling a booking, processing a payment
