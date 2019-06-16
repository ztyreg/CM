# C Minus Compilation to TM Code
# Standard prelude:
0: LD 6,0(0)# load maxaddress from location 0
1: ST 0,0(0)# clear location 0
# End of standard prelude.
# -> comp
# -> if
# -> Op
# -> Id
2: LD 0,1(5)# load id value
# <- Id
3: ST 0,0(6)# op: push left
# -> Id
4: LD 0,2(5)# load id value
# <- Id
5: LD 1,0(6)# op: load left
6: SUB 0,1,0# op <
7: JLT 0,2(7)# br if true
8: LDC 0,0(0)# false case
9: LDA 7,1(7)# unconditional jmp
10: LDC 0,1(0)# true case
# <- Op
# if: jump to else belongs here
# if: jump to end belongs here
11: JEQ 0,1(7)# if: jmp to else
12: LDA 7,0(7)# jmp to end
# <- if
# <- comp
# -> comp
# -> assign
# -> Const
13: LDC 0,1(0)# load const
# <- Const
14: ST 0,3(5)# assign: store value
# <- assign
# -> assign
# -> Op
# -> Const
15: LDC 0,1(0)# load const
# <- Const
16: ST 0,0(6)# op: push left
# -> Const
17: LDC 0,2(0)# load const
# <- Const
18: LD 1,0(6)# op: load left
19: ADD 0,1,0# op +
# <- Op
20: ST 0,4(5)# assign: store value
# <- assign
# -> assign
# -> Const
21: LDC 0,4(0)# load const
# <- Const
22: ST 0,7(5)# assign: store value
# <- assign
# -> if
# -> Op
# -> Id
23: LD 0,3(5)# load id value
# <- Id
24: ST 0,0(6)# op: push left
# -> Const
25: LDC 0,3(0)# load const
# <- Const
26: LD 1,0(6)# op: load left
27: SUB 0,1,0# op <
28: JLT 0,2(7)# br if true
29: LDC 0,0(0)# false case
30: LDA 7,1(7)# unconditional jmp
31: LDC 0,1(0)# true case
# <- Op
# if: jump to else belongs here
# -> comp
# -> while
# while: test start
# -> Op
# -> Id
33: LD 0,4(5)# load id value
# <- Id
34: ST 0,0(6)# op: push left
# -> Const
35: LDC 0,0(0)# load const
# <- Const
36: LD 1,0(6)# op: load left
37: SUB 0,1,0# op >
38: JGT 0,2(7)# br if true
39: LDC 0,0(0)# false case
40: LDA 7,1(7)# unconditional jmp
41: LDC 0,1(0)# true case
# <- Op
# while: body start
# -> comp
# -> assign
# -> Op
# -> Id
43: LD 0,4(5)# load id value
# <- Id
44: ST 0,0(6)# op: push left
# -> Const
45: LDC 0,1(0)# load const
# <- Const
46: LD 1,0(6)# op: load left
47: SUB 0,1,0# op -
# <- Op
48: ST 0,4(5)# assign: store value
# <- assign
# <- comp
42: JEQ 0,7(7)# while: to end
49: LDA 7,-17(7)# jmp to end
# <- while
# <- comp
# if: jump to end belongs here
32: JEQ 0,18(7)# if: jmp to else
50: LDA 7,0(7)# jmp to end
# <- if
# -> assign
51: ST 0,3(5)# assign: store value
# <- assign
# -> Id
52: LD 0,3(5)# load id value
# <- Id
53: OUT 0,0,0# write ac
# -> Id
54: LD 0,4(5)# load id value
# <- Id
55: OUT 0,0,0# write ac
# <- comp
# End of execution.
56: HALT 0,0,0# 
