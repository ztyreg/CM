# Symbol Table

Semantic analysis ensures that the program satisfies a set of additional rules regarding the usage of programming constructs (variables, objects, expressions, statements).

Examples of semantic rules:

* Variables must be declared before being used
* A variable should not be declared multiple times in the same scope
* In an assignment statement, the variable and the assigned expression must have the same type
* The condition of an if-statement must have type Boolean

Some categories of rules:

* Semantic rules regarding **types**
* Semantic rules regarding **scopes**





Main rules regarding scopes:

Rule 1: Use an identifier only if defined in enclosing scope 

Rule 2: Do not declare identifiers of the same kind with identical names more than once in the same scope 



| NAME | KIND | TYPE             | OTHER |
| ---- | ---- | ---------------- | ----- |
| foo  | fun  | int x int → bool |       |
| m    | par  | int              |       |
| n    | par  | int              |       |
| tmp  | var  | bool             |       |

 

​        

 Supported kinds:



Supported types:



Use a hierarchy of symbol tables to represent the hierarchy of scopes.



To find the declaration of an identifier that is active at a program point: 

* Start from the current scope 

* Go up in the hierarchy until you find an identifier with the same name, or fail 