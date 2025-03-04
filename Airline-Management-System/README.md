# Airline Management System

## Requirements
- Should allow the administrators to add, update, and remove flights, passangers, and seating arrangements
- Should allow users to **search for flights** based on source, destination, and date
- Should support different **classes** such as economy, business
- Should display the **seating arrangement** of the selected flights and allow users to choose seats
- Should allow users to **book flights**
- Should allow users to **cancel flights**
- Should allow users to **make payments**
  
## Entities
- **Passanger**: Represents a passanger, with properties such as ID, name, email, and phone number
- **Aircraft**: Represents an aircraft with properties such as tail number, model, and seating arrangement 
- **Flight**: Represents a flight in the airline management system, with properties such as flight number, source, destination, departure time, arrival time
- **Seat**: Represents a seat in an aircraft with properties such as seat_no, type, price, status
  - **SeatType**: Represents different seat types (ECONOMY,PREMIUM_ECONOMY,BUSINESS,FIRST_CLASS)
  - **SeatStatus**: Represents seat status (Available, Booked)
- **Booking**: Represents a booking made by a user, with properties such as ID, customer, show, selected seats, total price, and status
  - **BookingStatus**: Represents booking status (Pending, Confirmed, Cancelled)
- **Payment**: Represents a payment for a booking, with properties such as ID, amount, and status
  - **PaymentStatus**: Represents payment status (Completed, Pending, Failed)
- **AirlineSystem**: Main class that manages the movie ticket booking service
  - Follows the Singleton pattern to ensure only one instance of the service exists
  - Provides methods for adding customers/theaters/shows/seats, booking tickets (calculate the total price), canceling a booking, processing a payment
