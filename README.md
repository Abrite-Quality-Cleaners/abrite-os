# abrite-os
Point-of-sale and local inventory management software for an Abrite store.

## References
- https://www.mongodb.com/docs/manual/tutorial/install-mongodb-on-ubuntu-tarball/

## Install the latest MongoDB Community Server
### Import the public key
```
sudo apt install gnupg curl
curl -fsSL https://www.mongodb.org/static/pgp/server-8.0.asc | \
   sudo gpg -o /usr/share/keyrings/mongodb-server-8.0.gpg \
   --dearmor
```

### Create the list file
#### For Ubuntu 20.04
```
echo "deb [ arch=amd64,arm64 signed-by=/usr/share/keyrings/mongodb-server-8.0.gpg ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/8.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-8.0.list
```
#### For Ubuntu 24.04
```
echo "deb [ arch=amd64,arm64 signed-by=/usr/share/keyrings/mongodb-server-8.0.gpg ] https://repo.mongodb.org/apt/ubuntu noble/mongodb-org/8.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-8.0.list
```

### Reload the package database and install MongoDB Community Server
```
sudo apt update && sudo apt upgrade
sudo apt-get install -y mongodb-org
```

### If not using the `systemd` service
#### Create the data and log directories
```
sudo mkdir -p /var/lib/mongo
sudo mkdir -p /var/log/mongodb
sudo chown <user> /var/lib/mongo
sudo chown <user> /var/log/mongodb
```
#### Run MongoDB
```
mongod --dbpath /var/lib/mongo --logpath /var/log/mongodb/mongod.log --fork
```

## MongoDB shell
### Start the Mongo Shell
```
mongosh
```
### List the databases
```
show dbs
```
### Switch to or create a database (if new, the database is not created until data is inserted)
```
use <database name>
```
### Insert data into the database (creates the database if it was new/empty)
```
db.myCollection.insertOne({ <field>: "<data>" })
```
### Delete the current database
```
db.dropDatabase()
```

## Managing services with systemctl (e.g. mongod)
```
sudo systemctl <start|stop|restart|status|enable> <service>
```
__NOTE:__ If `start` fails, run: `sudo systemctl daemon-reload`