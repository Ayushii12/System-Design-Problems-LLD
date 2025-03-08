# Food Delivery System

## Requirements
- The system should manage different restaurants/delivery agents
- Customers should be able to **browse** different restaurants and menu items
- Customers should be able to **place** order
- Customer should be able to **cancel** their orders
- Delivery agents should be able to **receive** and **accept** orders
- The system should **calculate** the final **amount** for the order
- The system should calculate the **estimated time of delivery**
- Should allow customers to **make payments**

## Entities
- **Restaurant**: Represents a restraunt with properties such as Id, Name, Address, Description, Menu. And include methods to add/removu menu items and display the menu
- **Customer**: Represents a customer who can place orders. It contains customer details such as ID, name, email, and phone number
- **Menu**: Represents a menu at the restaurant with a list of menu items
  - **ItemCategory**: Represent category of an item (Appetizer, Main-Course, Dessert, Bevarage) 
  - **MenuItem**: Represent a menu item with properties such as Id, name, price, description
- **DeliveryAgent**: Represents an agents that deliver orders with properties such as Id, name, phone no. and availability
- **Order**: Represents an order placed by a customer with properties such as Id, Customer, Restaurant, list of menu items, total amount, order status
  - **OrderStatus**: Represents the different statuses for an order (Pending, Confirmed, Preparing, Out-for-delivery, Delivered, and Cancelled)
  - **OrderManager**: Provides methods to generate order id, create orders and cancel orders. It follows the Singleton pattern to ensure a single instance of the booking manager
- **Payment**: Represents a payment for an order, with properties such as ID, amount, and status
  - **PaymentStatus**: Represents payment status (Completed, Pending, Failed)
  - **PaymentProcessor**: Provides a method to process payments. It follows the Singleton pattern to ensure a single instance of the 
- **FoodDeliverySystem**: The main class that manages the food delivery service
  - It follows the Singleton pattern to ensure only one instance of the service exists
  - It provides methods to register customers, restaurants, and delivery agents, retrieve available restaurants and menus
