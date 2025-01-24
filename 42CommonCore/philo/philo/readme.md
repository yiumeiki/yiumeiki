Summary of Workflow
Program Start (main):

Check and input arguments to variables
Allocates memory
Initializes data and mutexes.
Creates a thread for each philosopher to handle their actions.
Monitors the simulation and stops it when a philosopher dies or all have finished eating.


Philosopher Threads (thread):
Starts with a slight delay for even-number philosophers.
Continuously performs actions (taking forks, eating, sleeping, thinking) until the simulation stops.
Monitors their own death in a separate thread (is_dead).


Actions (action):
Takes the left and right forks (mutexes).
Eats by updating the last meal time and sleeping for time_to_eat.
Releases the forks.
Sleeps and then thinks.


Death Monitoring (is_dead):
Waits for time_to_die milliseconds.
Checks if the philosopher has not eaten within this time.
If so, prints the death message and signals the simulation to stop.


Simulation Management (stop):
Waits until the stop flag is set.
Joins all philosopher threads to ensure they have finished.
Destroys all mutexes and frees allocated memory.

check: valgrind --tool=helgrind -s
valgrind -s --leak-check=full


one philo
-fsanitize=thread’