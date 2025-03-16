mod address;
mod customer;
mod order;
mod order_item;
mod note;
mod item;

use address::Address;
use customer::Customer;
use order::Order;
use order_item::OrderItem;

#[tokio::main]
async fn main() {
    // Create an address
    let address = Address::new(
        "123 Main St".to_string(),
        "Springfield".to_string(),
        "IL".to_string(),
        "62704".to_string(),
        "USA".to_string(),
    );

    // Create a customer
    let mut customer = Customer::new(
        "John".to_string(),
        "Doe".to_string(),
        "555-1234".to_string(),
        address,
        "john.doe@example.com".to_string(),
    );

    // Create an order without borrowing the customer
    let mut order = Order::new(&customer, 7.5);

    // Add items to the order
    let item1 = OrderItem::new("Widget".to_string(), 1000, 2);
    let item2 = OrderItem::new("Gadget".to_string(), 1500, 1);

    order.add_item(item1);
    order.add_item(item2);

    // Add the order to the customer's orders
    let order_to_add = order; // Move the order to avoid borrowing issues
    //customer.orders.push(order_to_add);

    println!("Customer created: {:#?}", customer);
}
