.data
str: .asciiz "Hello World!\n"
.text

main:
li	$v0,4	#PRINT string
la	$a0, str
syscall

li	$v0,10
syscall
