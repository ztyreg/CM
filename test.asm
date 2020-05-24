# C Minus Compilation to TM Code
# Standard prelude:
0: LD 6,0(0)# load maxaddress from location 0
1: ST 0,0(0)# clear location 0
# End of standard prelude.
# -> comp
# -> assign
# -> Const
2: LDC 0,7(0)# load const
# <- Const
3: ST 0,0(5)# assign: store value
# <- assign
# -> if
# -> Op
# -> Id
4: LD 0,0(5)# load id value
# <- Id
5: ST 0,0(6)# op: push left
# -> Const
6: LDC 0,6(0)# load const
# <- Const
7: LD 1,0(6)# op: load left
8: SUB 0,1,0# op >
9: JGT 0,2(7)# br if true
10: LDC 0,0(0)# false case
11: LDA 7,1(7)# unconditional jmp
12: LDC 0,1(0)# true case
# <- Op
# if: jump to else belongs here
# -> comp
# -> Id
14: LD 0,0(5)# load id value
# <- Id
15: OUT 0,0,0# write ac
# <- comp
# if: jump to end belongs here
13: JEQ 0,3(7)# if: jmp to else
16: LDA 7,0(7)# jmp to end
# <- if
# -> if
# -> Op
# -> Id
17: LD 0,0(5)# load id value
# <- Id
18: ST 0,0(6)# op: push left
# -> Const
19: LDC 0,6(0)# load const
# <- Const
20: LD 1,0(6)# op: load left
21: SUB 0,1,0# op >
22: JGT 0,2(7)# br if true
23: LDC 0,0(0)# false case
24: LDA 7,1(7)# unconditional jmp
25: LDC 0,1(0)# true case
# <- Op
# if: jump to else belongs here
# -> comp
# -> assign
# -> Const
27: LDC 0,10(0)# load const
# <- Const
28: ST 0,9(5)# assign: store value
# <- assign
# -> Id
29: LD 0,9(5)# load id value
# <- Id
30: OUT 0,0,0# write ac
# <- comp
# if: jump to end belongs here
26: JEQ 0,5(7)# if: jmp to else
31: LDA 7,0(7)# jmp to end
# <- if
# -> while
# while: test start
# -> Op
# -> Id
32: LD 0,0(5)# load id value
# <- Id
33: ST 0,0(6)# op: push left
# -> Const
34: LDC 0,3(0)# load const
# <- Const
35: LD 1,0(6)# op: load left
36: SUB 0,1,0# op >=
37: JGE 0,2(7)# br if true
38: LDC 0,0(0)# false case
39: LDA 7,1(7)# unconditional jmp
40: LDC 0,1(0)# true case
# <- Op
# while: body start
# -> comp
# -> assign
# -> Op
# -> Id
42: LD 0,0(5)# load id value
# <- Id
43: ST 0,0(6)# op: push left
# -> Const
44: LDC 0,1(0)# load const
# <- Const
45: LD 1,0(6)# op: load left
46: SUB 0,1,0# op -
# <- Op
47: ST 0,0(5)# assign: store value
# <- assign
# <- comp
41: JEQ 0,7(7)# while: to end
48: LDA 7,-17(7)# jmp to end
# <- while
# -> Id
49: LD 0,0(5)# load id value
# <- Id
50: OUT 0,0,0# write ac
# -> assign
# -> Const
51: LDC 0,0(0)# load const
# <- Const
52: ST 0,7(5)# assign: store value
# <- assign
# -> while
# while: test start
# -> Op
# -> Id
53: LD 0,7(5)# load id value
# <- Id
54: ST 0,0(6)# op: push left
# -> Const
55: LDC 0,6(0)# load const
# <- Const
56: LD 1,0(6)# op: load left
57: SUB 0,1,0# op <
58: JLT 0,2(7)# br if true
59: LDC 0,0(0)# false case
60: LDA 7,1(7)# unconditional jmp
61: LDC 0,1(0)# true case
# <- Op
# while: body start
# -> comp
# -> assign
# -> Id
63: LD 0,7(5)# load id value
# <- Id
64: ST 0,1(5)# assign: store value
# <- assign
# -> assign
# -> Op
# -> Id
65: LD 0,7(5)# load id value
# <- Id
66: ST 0,0(6)# op: push left
# -> Const
67: LDC 0,1(0)# load const
# <- Const
68: LD 1,0(6)# op: load left
69: ADD 0,1,0# op +
# <- Op
70: ST 0,7(5)# assign: store value
# <- assign
# <- comp
62: JEQ 0,9(7)# while: to end
71: LDA 7,-19(7)# jmp to end
# <- while
# -> Id
72: LD 0,1(5)# load id value
# <- Id
# -> Const
73: LDC 0,5(0)# load const
# <- Const
74: OUT 0,0,0# write ac
# <- comp
# End of execution.
75: HALT 0,0,0# 
