.data
	newline: .asciiz        "\n"
.text
.globl main

main: 

loop: 	
	li $v0, 5 		# syscall value for reading in an integer
	syscall   		# get input string from user
	add $a0, $v0, $0	# put input into $a0
	jal fibonacci		# value = finbonacci 
	add $a0, $v0, $0	# add returned fibonacci number to $a0
	li $v0, 1 		# syscall value for printing an integer
	syscall   		# get input string from user
	beq $a0, $0, end	# if the returned value is 0, get out!!
	li $v0, 4               # system call code 4 for printing a string
        la $a0, newline         # load the address of the string containing the '\n' character
        syscall                 # print the newline character
	j loop
	
fibonacci: 
	addi $sp, $sp, -8	# allocate memory in the stack frame
	sw $ra, 4($sp)		# store the return adress on the stack
	sw $a0, 0($sp) 		# store the value on the stack
	beq $a0, $0, bc1	# if n == 0, go to base case 1
	addi $t0, $0, 1		# $t0 = 1
	beq $a0, $t0, bc2	# if n == 2, go to base case 2
	
	addi $a0, $a0, -1	# n-1
	jal fibonacci 		# 1st recursive call
	lw $a0, 0($sp) 		# loading the original n value
	addi $a0, $a0, -2	# n-2
	sw $v0, 0($sp)		# storing fibonacci (n-1) onto stack
	jal fibonacci 		# 2nd recurive 
	lw $v1, 0($sp)		# load fib (n-1) into $v1
	add $v0, $v0, $v1	# fib(n-1) + fib(n-2)
	
rtn:
	lw $ra, 4($sp) 		# get old $a0 from stack
	add $sp, $sp, 8 	# deallocate stack memory
	jr $ra			# return to main

bc1: 
	add $v0, $0, $0		# make the return value 0
	j rtn			# return to fibonacci method
bc2: 
	addi $v0, $0, 1		# make the return value 1
	j rtn			# return to fibonacci method

end: