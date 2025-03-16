use std::time::SystemTime;

#[derive(Debug)]
pub struct Note {
    pub id: u64,
    pub created_at: SystemTime,
    pub updated_at: SystemTime,
    pub content: String,
}

impl Note {
    pub fn new(content: String) -> Self {
        let now = SystemTime::now();
        Self {
            id: 0,
            created_at: now,
            updated_at: now,
            content,
        }
    }
}
