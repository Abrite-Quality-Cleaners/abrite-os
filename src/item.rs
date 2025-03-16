#[derive(Debug)]
pub struct Item {
    pub name: String,
    pub price: i64,
    pub icon_png: Option<String>,
}

impl Item {
    pub fn new(name: String, price: i64) -> Self {
        Self {
            name,
            price,
            icon_png: None,
        }
    }

    pub fn with_icon(name: String, price: i64, icon_png: String) -> Self {
        Self {
            name,
            price,
            icon_png: Some(icon_png),
        }
    }
}
