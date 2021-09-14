	.data
str:	.asciiz	"Hello world!\n"	# set up a string in memory
buff:	.byte 	32
	
	.text
main:
	li	$v0,	8		# read string
	la	$a0,	buff
	li	$a1,	32
	syscall

	li	$v0,	4		# print string
	la	$a0,	buff
	syscall
	
	li	$v0,	10		# return;
	syscall
