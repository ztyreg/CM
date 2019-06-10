# Grammar

## Grammars and Semantics

1. program $\rightarrow$ declaration-list
2. declaration-list $\rightarrow$ declaration-list declaration | declaration
3. declaration $\rightarrow$ var-declaration | fun-declaration
4. var-declaration $\rightarrow$ type-specifier `ID` `;` | type-specifier `ID` `[` `NUM` `]` `;`
5. type-specifier $\rightarrow$ `int` | `void`
6. fun-declaration $\rightarrow$ type-specifier `ID` `(` params `)` compound-stmt
7. params $\rightarrow$ param-list | `void`
8. param-list $\rightarrow$ param-list `,` param | param
9. param $\rightarrow$ type-specifier `ID` | type-specifier `ID` `[` `]`
   1. Integer parameters are passed by value
   2. Array parameters are passed by reference
10. compound-stmt $\rightarrow$ `{` local-declarations statement-list `}`
    1. Local declarations supersede any global declarations
11. local-declarations $\rightarrow$ local-declarations var-declaration | `ε`
12. statement-list $\rightarrow$ statement-list statement | `ε`
13. statement $\rightarrow$ expression-stmt | compound-stmt | selection-stmt | iteration-stmt | return-stmt
14. expression-stmt $\rightarrow$ expression `;` | `;`
15. selection-stmt $\rightarrow$ `if` `(` expression `)` statement | `if` `(` expression `)` statement `else` statement
    1. !0: first. 0: second
16. iteration-stmt $\rightarrow$ `while` `(` expression `)` statement
    1. !0: continue. 0: end
17. return-stmt $\rightarrow$ `return` `;` | `return` expression `;`
    1. Void functions must not return values
18. expression $\rightarrow$ var `=` expression | simple-expression
19. var $\rightarrow$ `ID` | `ID` `[` expression `]`
    1. Find, evaluate and store
    2. Reture expression value
    3. Negative subscript causes the program to halt
    4. No upper bounds checking
    5. This is the only l-values in C-
20. simple-expression $\rightarrow$ additive-expression relop additive-expression | additive-expression
21. relop $\rightarrow$ `<=` | `<` | `>` | `>=` | `==` | `!=`
    1. An unparenthesized expression can only have 1 relational operator
    2. Value. No relop: value of additive-expression. Relop: 1 or 0
22. additive-expression $\rightarrow$ additive-expression addop term | term
23. addop $\rightarrow$ `+` | `-`
24. term $\rightarrow$ term mulop factor | factor
25. mulop $\rightarrow$ `*` | `/`
    1. Only integer division
26. factor $\rightarrow$ `(` expression `)` | var | call `NUM`
27. call $\rightarrow$ `ID` `(` args `)`
28. args $\rightarrow$ arg-list | `ε`
29. arg-list $\rightarrow$ arg-list `,` expression | expression
    1. Function must be declared before they are called
    2. The number of parameters in the declaration must equal the number of arguments in the call






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



Symbol table
 Set of symbol table items
z searchable by name + scope
 Data stored for each entry:
z name
z attributes
 type
(int, bool, array, ptr, function)
 address
(block, offset)
 declared or not,
used or not
 ...
 Operations
z lookup ( name )
z insert ( name )
z put ( name, attribute, value )
z get ( name, attribute)
z enterscope ()
z exitscope()