# minitalk
Built a client-server communication system using UNIX signals (SIGUSR1 and SIGUSR2) to transmit messages character by character. Focused on synchronization, signal handling, and ensuring reliable data transmission. The bonus implementation included additional features such as enhanced error handling and extended message formats(unicode).

## How to run
	make or make bonus 
	./server
	pid of server will show on terminal

	open a new terminal(same directory)
	./client <server_pid> <message>

message will show on server