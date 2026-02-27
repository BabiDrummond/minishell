# Lexer Module for Minishell

## Overview
This module implements a lexer (tokenizer) for shell command lines, designed to be integrated as a static library into the 42 minishell project. It parses input strings into tokens, handling operators, words, and quoted strings, and provides a flexible API for use in larger shell projects.

## Features
- Tokenizes shell input lines into words and operators
- Handles quoted and unquoted words
- Handles words concatenation
- Recognizes operators based on list
- identify expandable words
- Designed for modular integration (static library)

## Build Instructions

### 1. Build as a library (for integration)
```
make
```
- Produces `lexer.a` (static library) in the project root
- All object files are placed in the `obj/` directory
- Does **not** compile the sample main

### 2. Clean build files
```
make clean   # Removes object files
make fclean  # Removes object files and binaries
make re      # Full rebuild
```

## Usage Example


### Integration
Include `lexer.h` in your project and link with `lexer.a`.


#### Example usage

```c
char **operators = initialize_operators();
char *line = readline("prompt> ");
t_head *tokens = tokenize(line, operators);
print_tokens(tokens);
```

For a complete and practical usage example, see the implementation in `main.c` provided in this repository. It demonstrates how to initialize operators, read input, tokenize, and print tokens interactively.

## Example Output


#### Exemplo de uso e saída

```
prompt> echo "hello world" | cat -e
Token: {type: 'WORD', parts: [{ value: 'echo', expandable: true }]}
Token: {type: 'WORD', parts: [{ value: 'hello world', expandable: true }]}
Token: {type: 'OPERATOR', symbol: '|' }
Token: {type: 'WORD', parts: [{ value: 'cat', expandable: true }]}
Token: {type: 'WORD', parts: [{ value: '-e', expandable: true }]}
```

- The prompt accepts input and prints the list of tokens parsed from the line.
- Operators and words are recognized and separated.

## Operators Supported
Operators are not hardcoded. You must provide a list of operators as a `char **operators` array when using the lexer functions. This allows you to fully customize which operators are recognized by the lexer.

For example, to use the default set:
```c
char **operators = initialize_operators();
```
You can also create your own list of operators as needed.

**Default operators:**
- `||`, `&&`, `|`, `<<`, `>>`, `<`, `>`

## API
See `lexer.h` for all available functions and data structures.

## License
42 School project — for educational use.
