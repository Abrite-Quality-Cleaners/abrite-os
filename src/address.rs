#[derive(Debug)]
pub struct Address {
    pub street: String,
    pub city: String,
    pub state: String,
    pub postal_code: String,
    pub country: String,
}

impl Address {
    pub fn new(street: String, city: String, state: String, postal_code: String, country: String) -> Self {
        Self {
            street,
            city,
            state,
            postal_code,
            country,
        }
    }
}
