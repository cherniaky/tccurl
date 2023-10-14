# tccurl 
Add ability to include over https in tcc compiler.
<br/>
<br/>
![alt text](tccurl-example.jpg)

## Installation
Start by ensuring you have docker installed. <br/>
Then do:
```
$ docker-compose up -d 
$ docker-compose exec tccurl bash
```
Inside the container run `build.sh`, it will compile the compiler and install it, and compile main.c <br/>
Then run:
```
./main img.png gray.png
```
This will run C program compiled with updated ```tcc``` source code <br/>
Was done wathing Tsoding programming [stream](https://www.youtube.com/watch?v=4vSyqK3SK-0)
