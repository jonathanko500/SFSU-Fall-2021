.data
str:	.word 	32	#string input
loc:	.word	32	#array of substring
.text


main:   
	#read string input
	li $v0, 8
	la $a0, str
    	li $a1, 32
    	syscall
    
    	#print string input
    	li	$v0,	4	
    	la	$a0,	str	
    	syscall
    
    	#call delim function/method
    	la	$a0, str
   	#jal delim
   	jal strlen
   	
   	
   	
    
    #return
    li	$v0,	10
    syscall
    
 
#delim function to get substrings
#delim:
	


    	#jr	$ra
    
    

#find length of string   
strlen:
	li $t0, -1	#pointer
    	move $s0, $a0	#string
    	
    	#loop through string and start counting
    	loop:
    		lb $t1, 0($s0)	
    		beq $t1, $t6,maxLen
    	
    		#increment counter / pointer
    		addi $t0, $t0, 1
        	addi $s0, $s0, 1
	
		j loop
	maxLen:
		move $v0, $t0
        	jr $ra
        	

	
	


