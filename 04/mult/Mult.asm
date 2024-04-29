// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.

//// Replace this comment with your code.

    //i=R1
    @R1
    D=M
    @i
    M=D
    //res=0
    @res 
    M=0
(LOOP)
    @i 
    D=M 
    @LAP
    D;JGT
    @STOP
    0;JMP

(LAP)
    @res
    D=M 
    @R0
    D=D+M
    @res
    M=D
    //i = i-1
    @i
    M=M-1
    @LOOP
    0;JMP
(STOP)
    @res
    D=M 
    @R2
    M=D
   
