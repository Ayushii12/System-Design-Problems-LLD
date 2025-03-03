# Movie Ticket Booking System

## Requirements
- Should allow theater administrators to **add, update, and remove movies, shows, and seating arrangements**
- Should allow users to **view the list of movies** in different theaters
- Customers should be able to **select a movie, theater, and show timing**
- Should **display the seating arrangement** of the selected show and allow users to choose seats
- Should support different **types of seats** (e.g., normal, premium)
- Users should be able to **make payment** and confirm their booking
- Users should be able to **cancel** their booking

## Entities
- **Customer**: Represents a customer, with properties such as ID, name, email, and phone number
- **Movie**: Represents a movie with properties such as ID, title, description, and duration
- **Theater**: Represents a theater with properties such as ID, name, location, and a list of shows
- **Show**: Represents a movie show in a theater, with properties such as ID, movie, theater, start time, end time, and seating arrangements
- **Seat**: Represents a seat in a show with properties such as Id, row, col, type, price, status
  - **SeatType**: Represents different seat types (Regular, Premium)
  - **SeatStatus**: Represents seat status (Available, Booked)
- **Booking**: Represents a booking made by a user, with properties such as ID, customer, show, selected seats, total price, and status
  - **BookingStatus**: Represents booking status (Pending, Confirmed, Cancelled)
- **Payment**: Represents a payment for a booking, with properties such as ID, booking, amount, and status
  - **PaymentStatus**: Represents payment status (Completed, Pending, Failed)
- **TicketBookingSystem**: Main class that manages the movie ticket booking service
  - Follows the Singleton pattern to ensure only one instance of the service exists
  - Provides methods for adding customers/theaters/shows/seats, booking tickets (calculate the total price), canceling a booking, processing a payment 
