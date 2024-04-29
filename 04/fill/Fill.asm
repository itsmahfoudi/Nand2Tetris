// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

//// Replace this comment with your code.
    // Set off = 8191
    @8191
    D=A 
    @off
    M=D
(MAIN)
    @KBD
    D=M
    @SET_VAL
    D;JEQ
    D=-1
    0;JMP

(SET_VAL)
    @val 
    M=D
    @FILL 
    0;JMP 

(FILL)
    @off
    D=M 
    @SCREEN 
    D=D+A 
    @val 
    M=D // Set M to point to @screen + offset
    D=A // Set D to Val
    M=D // Set M = val
    @off
    D=M 
    D=D-1
    M=D
    @MAIN
    D;JLT
    @FILL
    0;JMP
    
    
