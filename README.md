# Philosophers

![Intro](images/intro.png)

## Table of Contents

- [Description](#description)
- [Bonus Part](#bonus-part)
- [Usage](#usage)
- [Learning Resources](#learning-resources)
- [related projects](#related-projects)
- [Contact Information](#contact-information)


## Description

This project is about writing a program that simulates a group of philosophers dining at a round table. The philosophers take turns eating, thinking, and sleeping. There is a bowl of spaghetti in the middle of the table, and each philosopher needs two forks to eat. The philosophers must follow certain rules, such as not talking to each other and not knowing when another philosopher is about to die. The goal of the program is to avoid deadlocks and ensure that all philosophers eat.

## Bonus Part

The bonus part of this project involves adding support for philosophers with processes and semaphores. In this part, all the forks are put in the middle of the table and they have no states in memory. Instead, the number of available forks is represented by a semaphore. Each philosopher should be a process, but the main process should not be a philosopher.

## Usage

To build the project, run the following command in the project directory:

```
make
```

This will create the `philo or philo_bonus` executable.

To run the program, run the following command in the project directory:

```
./philo_bonus or ./philo number_of_philosopher  time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Learning Resources

- [The C Programming Language](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)
- [Advanced Programming in the UNIX Environment](https://www.amazon.com/Advanced-Programming-UNIX-Environment-3rd/dp/0134277599)
- [Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

## Related Projects

- [Minishell](https://github.com/Ziko909/minishell-42-cursus): This project is about creating a feature-rich shell program.
- [Webserv](https://github.com/Ziko909/Webserv): This project is aimed to create a feature-rich webserver.

## Contact Information

- GitHub: [Ziko909](https://github.com/Ziko909)
- LinkedIn: [Zakaria Aabou](https://www.linkedin.com/in/zakaria-aabou-868487240/)
- Gmail: aabou.zakaria909@gmail.com
