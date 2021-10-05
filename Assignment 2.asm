	.data
prompt:		.asciiz "Enter a number less than or equal to 100 to convert to binary: \n"		#prompt
attempt:	.asciiz "Try again: \n"		#prompt
buff:	.byte	32	#32 byte for string
	.text

main:

	#print string prompt 
	li	$v0,	4	#loading address of string
	la	$a0,	prompt	#call prompt 1
	syscall
	
	#read int
	li 	$v0,	5	#read int
	syscall
	
	add	$t0,	$v0,	$0	#user int input
	addi	$t1,	$t1,	100	#num check
	
	
	#loop
	ble	$t0,	$t1,	end	#start loop
	
loop:	#print string prompt 
	li	$v0,	4	#loading address of string
	la	$a0,	attempt	#call prompt 1
	syscall
	
	#read int
	li 	$v0,	5	#read int
	syscall
	
	add	$t0,	$t0,	$0
		
	
end:	bgt	$t0,	$t1,	loop	#end loop
	
	
	#return
	li	$v0,	10	
	syscall