# tccurl 
Add ability to include over https in tcc compiler.

## Installation
Start by ensuring you have docker installed. <br/>
Then do:
```
$ docker-compose up -d 
$ docker-compose exec tccurl bash
```
Inside the container run `build.sh`, it will compile the compiler and install it
Then run:
```
./main img.png gray.png
```
This will run C program compiled with updated ```tcc``` source code
