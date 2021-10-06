	.data
prompt:		.asciiz "Enter a number less than or equal to 100 to convert to binary: \n"		#prompt
attempt:	.asciiz "Try again: "		#test prompt
convert:	.asciiz "Converting... \n"		#convert
bin:		.asciiz " in binary is: "	#user numb to bin
	.text

main:

	#print prompt 
	li	$v0,	4	#loading address of string
	la	$a0,	prompt	#call prompt 1
	syscall
	
	#read int
	li 	$v0,	5	#read int
	syscall
	
	add	$t0,	$v0,	$0	#user int input
	addi	$t1,	$t1,	100	#num check
	
	
	#loop to num check
	ble	$t0,	$t1,	end	#start loop
	#user input <= 100	pass = out of loop
	
loop:	#print string prompt 
	li	$v0,	4	#loading address of string
	la	$a0,	attempt	#call attempt
	syscall
	
	#read int
	li 	$v0,	5	#read int
	syscall
	
	add	$t0,	$v0,	$0	
	
end:	bgt	$t0,	$t1,	loop	#end loop
	#user input > 100	pass = back into loop
	
	#print convert 
	li	$v0,	4	#loading address of string
	la	$a0,	convert	#call convert
	syscall
	
	#print int 
	li	$v0,	1	#print int
	move 	$a0, 	$t0
	syscall
	
	#print bin 
	li	$v0,	4	#loading address of string
	la	$a0,	bin	#call bin
	syscall
	
	addi	$t2,	$t2,	9	#8 digit binary
	
	
	#loop to convert to binary
	ble	$t2,	$0,	end2	#start loop
loop2:	

	#calc remainders
	div	$t0,	$2
	mfhi	$t1
	

	li	$v0,	1	#print remainder
	move 	$a0, 	$t1
	syscall
	
	addi	$t2,	$t2,	-1	#decrease counter
	
end2:	bgt	$t2,	0,	loop2	#end loop
	
	#return
	li	$v0,	10	
	syscall
