# Calculator DSL

A simple domain-specific language (DSL) and interpreter for parsing math expressions, variable assignments, if-statements, and loops.

## Technical Details

* **Input Formats:** The program reads and executes scripts from `.faf` files.
* **Variable Naming:** Variables can only be named using letters (no numbers or special characters).
* **Statements:** Each statement must begin on a new line.
* **Supported Operators:** Math expressions are built using `+`, `-`, `/`, `*`.
* **Data Types:** Supports `integers` and `float` numbers, including variables.
    * Features implicit conversion from float values to int.
* **Syntax Specifics:**
    * Each element/token inside a math expression must be separated by a space.
    * Comments begin with `#`. Free/empty lines are ignored and acceptable.
    * The equal sign `=` serves dual purposes:
        * Assignment for new or existing variables.
        * Equality checking inside `if` statements.

## Language Instructions

The following syntaxes are valid in this DSL:

* Variable Assignment:
    * `<int/float> <varname> = <math expression>`
    * `<varname> = <math expression>`
* Printing values:
    * `show <math expression>`
* Control Flow (If-Statements):
  ```text
  if <varname> = <math expression> then
      ...
  endif
  ```
  *(Note: If statements are not allowed inside loops)*
* Control Flow (Loops):
  ```text
  repeat <math expression> times
      ...
  endrepeat
  ```

## Possible Errors Captured

* Syntax Error: Open if statements (missing `endif`).
* Syntax Error: Open loops (missing `endrepeat`).
* Syntax Error: Too many `endif` or `endrepeat` statements.
* Syntax Error: Line number mismatch/Parsing issues.
* Syntax Error: `if` statements used inside loops.
* Division Error: Division by zero.
* Initialization Error: Initializing a variable twice.
* Initialization Error: Using an uninitialized variable.

## Usage & Execution

The project's structure has been moved directly under `src/`.

**Building the project:**
```bash
make build
```

**Running the interpreter on sample tests:**
An entry correctly maps the input tests path dynamically:
```bash
make run
```
This automatically compiles and executes `./test inputTests/basic.faf`. You can also manually provide a different input:
```bash
./test inputTests/loop.faf
```

## Clean
```bash
make clean
```
