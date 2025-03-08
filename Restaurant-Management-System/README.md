# Restaurant Management System

## Requirements
- System should **display the list of available items** (i.e menu)
- Should allow customers to **place an order**
- Should allow customers to **make a reservation**
- Should allow customers to **cancel an order**
- Should allow customers to **cancel reservation**
- Should calculate the **final amount** for the order
- Should allow customers to **make payments**
- Should manage **staff** (i.e waiters, managers, chefs)

## Entities
- **Staff**: Represents staff at the restaurant with different roles (i.e Waiters, Manager, Chef) with properties such as ID, Name, Role
- **Table**: Represents a table at the restaurant with properties such as table no, Capacity, Status
  - **TableStatus**: Represents table status such as (Reserved, Occupied, Available)
- **Menu**: Represents a menu at the restaurant with a list of menu items
  - **ItemCategory**: Represent category of an item (Appetizer, Main-Course, Dessert, Bevarage)
  - **MenuItem**: Represent a menu item with properties such as Id, name, price, description, availability
- **Order**: Represents an order placed by a customer with properties such as Id, table, list of menu items, total amount, order status
  - **OrderStatus**: Represents the different statuses for an order (Pending, Preparing, Ready, Completed, Cancelled)
  - **OrderManager**: Provides methods to generate order id, create orders and cancel orders. It follows the Singleton pattern to ensure a single instance of the booking manager
- **Reservation**: Represents a reservation made by a customer with properties such as Id, table, name, contact information, party size, reservation time and status
  - **ReservationStatus**: Represents reservation status ( Confirmed, Failed, Cancelled)
  - **ReservationManager**: Provides methods to generate reservation id, create reservations and cancel reservations. It follows the Singleton pattern to ensure a single instance of the booking manager
- **Payment**: Represents a payment for an order, with properties such as ID, amount, and status
  - **PaymentStatus**: Represents payment status (Completed, Pending, Failed)
  - **PaymentProcessor**: Provides a method to process payments. It follows the Singleton pattern to ensure a single instance of the payment processor
- **RestaurantManagementSystem**: Represents the restaurant management system
  - Follows the Singleton pattern to ensure only one instance of the service exists
  - Provides methods for adding tables/menu items/staff/, display menu items, placing an order (calculate the total price), canceling an order, making a reservation, cancelling a reservation,  processing a payment
