use mongodb::{options::ClientOptions, Client};
use std::error::Error;

pub async fn establish_connection(uri: &str) -> Result<Client, Box<dyn Error>> {
    // Parse the connection string into client options
    let client_options = ClientOptions::parse(uri).await?;
    
    // Create a new MongoDB client
    let client = Client::with_options(client_options)?;
    
    // Test the connection by listing the databases
    println!("Connected to MongoDB! Databases:");
    for db_name in client.list_database_names(None, None).await? {
        println!("- {}", db_name);
    }
    
    Ok(client)
}

// If still needed, ensure this file exists and is correctly referenced in lib.rs.
