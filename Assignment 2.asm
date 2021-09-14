	.data
str1:	.asciiz "Enter a string of no more than 32 characters\n"		#prompt 1
str2:	.asciiz "Enter how many times to repeat this\n"				#prompt 2
buff:	.byte	32		#32 byte for string
	.text
	
main:
	#print string prompt 1
	li	$v0,	4	#loading address of string
	la	$a0,	str1	#call prompt 1
	syscall
	
	#read string from user
	li	$v0,	8	#syscall 8 = read string
	la	$a0,	buff	#read string and put in string buffer (blank space in memory)
	li	$a1,	32	#gets length
	syscall
	
	#print string prompt 2
	li	$v0,	4	#loading address of string
	la	$a0,	str2	#call address
	syscall
	
	#read int
	li 	$v0,	5	#read int
	syscall
	add	$t0,	$v0,	$0
	
	
	#loop
	ble	$t0,	$0,	end
loop:	li	$v0,	4		# print string
	la	$a0,	buff
	syscall
	
	addi	$t0,	$t0,	-1	#decrease counter
	
end:	bgt	$t0,	0,	loop

	
		
	#return
	li	$v0,	10	
	syscall
