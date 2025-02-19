<p align="center">
	<img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-philosophers.png?raw=true">
</p>

# Philosophers
Simulated the classical Dining Philosophers problem using multithreading (mandatory) and multiprocessing (bonus) while ensuring deadlock-free synchronization. Utilized mutexes (mandatory) and semaphores (bonus) to manage shared resources efficiently. Implemented robust timing mechanisms and race condition prevention strategies to ensure correctness and performance.

## How to run
	cd philo  --for mandatory part
	./philo "number_of_philosophers" "time_to_die" "time_to_eat" "time_to_sleep" "number_of_times_each_philosopher_must_eat(optional)"

	cd philo_bonus --for bonus part
	./philo_bonus "number_of_philosophers" "time_to_die" "time_to_eat" "time_to_sleep" "number_of_times_each_philosopher_must_eat(optional)"
	
The last argument is optional and is used to specify the number of times each philosopher must eat before exiting. With this, the program will stop once all philosophers have eaten the specified number of times.