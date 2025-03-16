use std::time::SystemTime;
use crate::address::Address;
use crate::order::Order;
use crate::note::Note; // This should now resolve correctly
use mongodb::bson::{doc, Bson, Document};
use mongodb::Collection;

#[derive(Debug)]
pub struct Customer<'a> {
    pub id: Option<Bson>, // MongoDB ObjectId
    pub created_at: SystemTime,
    pub modified_at: SystemTime,
    pub first_name: String,
    pub last_name: String,
    pub phone_number: String,
    pub address: Address,
    pub email: String,
    pub balance: i64,
    pub orders: Vec<Order<'a>>, // Specify the lifetime for Order
    pub notes: Vec<Note>,
}

impl<'a> Customer<'a> {
    pub fn new(first_name: String, last_name: String, phone_number: String, address: Address, email: String) -> Self {
        let now = SystemTime::now();
        Self {
            id: None,
            created_at: now,
            modified_at: now,
            first_name,
            last_name,
            phone_number,
            address,
            email,
            balance: 0,
            orders: Vec::new(),
            notes: Vec::new(),
        }
    }

    pub async fn save(&mut self, collection: &Collection<Document>) -> mongodb::error::Result<()> {
        let doc = self.to_document();
        if let Some(id) = &self.id {
            collection.update_one(doc! { "_id": id }, doc! { "$set": doc }, None).await?;
        } else {
            let result = collection.insert_one(doc, None).await?;
            self.id = result.inserted_id.as_object_id().map(Bson::ObjectId);
        }
        Ok(())
    }

    pub fn update_modified_at(&mut self) {
        self.modified_at = SystemTime::now();
    }

    pub fn to_document(&self) -> Document { // Made public
        doc! {
            "created_at": Bson::Int64(self.created_at.duration_since(SystemTime::UNIX_EPOCH).unwrap().as_secs() as i64), // Fixed Bson conversion
            "modified_at": Bson::Int64(self.modified_at.duration_since(SystemTime::UNIX_EPOCH).unwrap().as_secs() as i64), // Fixed Bson conversion
            "first_name": &self.first_name,
            "last_name": &self.last_name,
            "phone_number": &self.phone_number,
            "address": {
                "street": &self.address.street,
                "city": &self.address.city,
                "state": &self.address.state,
                "postal_code": &self.address.postal_code,
                "country": &self.address.country,
            },
            "email": &self.email,
            "balance": self.balance,
            "orders": self.orders.iter().map(|order| order.to_document()).collect::<Vec<_>>(),
            "notes": self.notes.iter().map(|note| note.content.clone()).collect::<Vec<_>>(),
        }
    }
}
