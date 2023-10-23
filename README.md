# Simple UNIX Command Line Interpreter (Shell)

This is a basic UNIX command line interpreter (shell) implemented in C. It provides a simple command line interface for executing commands.

## Usage

To use this shell, follow these steps:

1. **Compile the code:**

   ```bash
   gcc -o simple_shell simple_shell.c
   ```

2. **Run the shell:**

   ```bash
   ./simple_shell
   ```

3. You will see the shell prompt, `simple_shell>`. Enter a command and press Enter. For example:

   ```bash
   simple_shell> ls
   ```

4. The shell will execute the command and display the output.

5. To exit the shell, press Ctrl+D or use the `exit` command:

   ```bash
   simple_shell> exit
   ```

## Features

- This shell can execute simple, single-word commands.
- It handles the "end of file" condition (Ctrl+D) for graceful termination.
- It uses the `execve` system call to execute commands and inherits the environment variables from the parent process.
- It displays an error message if a command is not found.

## Limitations

- The shell does not support complex commands with multiple words, special characters, arguments, built-in commands, or advanced features.
- It does not include a PATH variable lookup, so you need to provide the full path to executable commands.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Author

Mawoda Ekabua

## Acknowledgments

This simple shell is a basic example for educational purposes and can be extended to add more features and functionality.

Feel free to modify and use it as a starting point for your own shell project.

If you have any questions or need further assistance, please [contact the author](onemawoda@gmail.com).
```
