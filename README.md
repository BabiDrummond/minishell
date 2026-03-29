# 🐺 Wolfshell

*This project was created as part of the 42 curriculum by Barbara Drummond and Bruno Costa Borges.*

## Description

Minishell is a simplified implementation of a Unix shell written in C.  
The goal of this project is to reproduce essential Bash behaviors, allowing command execution, process management, pipes, redirections, and environment variables.

This project focuses on learning:

- Process creation and management (`fork`, `execve`)
- File descriptor manipulation
- Inter-process communication (pipes)
- Command parsing
- Signal handling

---

## Instructions

### Compilation

```bash
make
````

### Execution

```bash
./minishell
```

### Cleaning

```bash
make clean
make fclean
make re
```

---

## Resources

### References

* Bash Documentation: [https://www.gnu.org/software/bash/manual/](https://www.gnu.org/software/bash/manual/)
* `fork` manual: [https://man7.org/linux/man-pages/man2/fork.2.html](https://man7.org/linux/man-pages/man2/fork.2.html)
* `execve` manual: [https://man7.org/linux/man-pages/man2/execve.2.html](https://man7.org/linux/man-pages/man2/execve.2.html)
* `pipe` manual: [https://man7.org/linux/man-pages/man2/pipe.2.html](https://man7.org/linux/man-pages/man2/pipe.2.html)
* Readline Documentation: [https://tiswww.case.edu/php/chet/readline/rltop.html](https://tiswww.case.edu/php/chet/readline/rltop.html)

### AI Usage

AI was used as a support tool during the development of this project, mainly for:

* Clarifying theoretical concepts (pipes, signals, processes)
* Assisting in understanding parsing strategies
* Reviewing ideas and identifying potential edge cases

No code was used without full understanding. All generated content was carefully analyzed, tested, and validated before being integrated into the project.

