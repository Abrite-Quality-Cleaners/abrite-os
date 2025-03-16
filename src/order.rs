use crate::customer::Customer;
use crate::order_item::OrderItem;
use crate::note::Note;
use mongodb::bson::{doc, Document};

#[derive(Debug)]
pub struct Order<'a> {
    pub customer: &'a Customer<'a>, // Specify the lifetime for Customer
    pub items: Vec<OrderItem>,
    pub note: Option<Note>,
    pub tax_percent: f64,
    pub total: i64,
}

impl<'a> Order<'a> {
    pub fn new(customer: &'a Customer<'a>, tax_percent: f64) -> Self { // Update parameter type
        Self {
            customer,
            items: Vec::new(),
            note: None,
            tax_percent,
            total: 0,
        }
    }

    pub fn add_item(&mut self, item: OrderItem) {
        if !self.items.iter().any(|i| i.item.name == item.item.name) {
            self.items.push(item);
            self.update_total();
        }
    }

    pub fn remove_item(&mut self, item_name: &str) {
        self.items.retain(|item| item.item.name != item_name);
        self.update_total();
    }

    pub fn update_total(&mut self) {
        self.total = self.items.iter().map(|item| item.subtotal).sum::<i64>();
        self.total += (self.total as f64 * self.tax_percent / 100.0) as i64;
    }

    pub fn to_document(&self) -> Document {
        doc! {
            "customer": self.customer.to_document(),
            "items": self.items.iter().map(|item| item.to_document()).collect::<Vec<_>>(),
            "note": self.note.as_ref().map(|note| note.content.clone()),
            "tax_percent": self.tax_percent,
            "total": self.total,
        }
    }
}
