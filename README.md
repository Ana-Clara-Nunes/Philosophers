*This project has been created as part of the 42 curriculum by anunes-o.*

# Philosophers

## Description

This project implements the 42 "Philosophers" subject using C, POSIX threads, and mutexes. It simulates philosophers who alternate between thinking, eating, and sleeping while sharing forks between neighbors. The goal is to keep the simulation alive until either a philosopher dies or all philosophers have eaten the required number of times.

## Instructions

### Build

From the `philo/` directory:

```bash
make
```

This produces the executable `philo`.

### Run

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200 10
```

### Output

The program prints timestamped actions in milliseconds, for example:

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

where `X` is the philosopher number.

## Requirements

- Each philosopher runs as a separate thread.
- There is one fork between each pair of philosophers and each fork is protected by a mutex.
- The program uses only permitted functions: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, and `pthread_mutex_unlock`.
- The program must not leak heap memory, crash unexpectedly, or have data races.

## Project Structure

- `main.c` — program entry point and simulation start/stop logic
- `src/init.c` — initialization of data, forks, and philosophers
- `src/parsing.c` — argument validation and parsing
- `src/routines.c` — philosopher thread routine and state functions
- `src/bon_appetit.c` — fork acquisition and eating logic
- `src/monitor.c` — death monitoring and simulation termination
- `src/time_utils.c` — timing helper functions
- `src/cleanup.c` — resource cleanup
- `philo.h` — shared data structures and function declarations

## Resources

- POSIX threads (`pthread_create`, `pthread_join`, `pthread_mutex_*`)
- `gettimeofday` for millisecond timestamps
- 42 subject documentation and peer guidance
- AI was used to review code behavior and help draft the README content
