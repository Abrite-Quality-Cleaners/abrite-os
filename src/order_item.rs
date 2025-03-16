use crate::item::Item;
use mongodb::bson::{doc, Document};

#[derive(Debug)]
pub struct OrderItem {
    pub item: Item,
    pub quantity: i64,
    pub subtotal: i64,
}

impl OrderItem {
    pub fn new(name: String, price: i64, quantity: i64) -> Self {
        let item = Item::new(name, price);
        let subtotal = price * quantity;
        Self {
            item,
            quantity,
            subtotal,
        }
    }

    pub fn with_icon(name: String, price: i64, icon_png: String, quantity: i64) -> Self {
        let item = Item::with_icon(name, price, icon_png);
        let subtotal = price * quantity;
        Self {
            item,
            quantity,
            subtotal,
        }
    }

    pub fn update_subtotal(&mut self) {
        self.subtotal = self.item.price * self.quantity;
    }

    pub fn to_document(&self) -> Document {
        doc! {
            "item": {
                "name": &self.item.name,
                "price": self.item.price,
                "icon_png": self.item.icon_png.clone(),
            },
            "quantity": self.quantity,
            "subtotal": self.subtotal,
        }
    }
}
