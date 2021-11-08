.data
str:	.word 	32	#string input
loc:	.byte	32	#array of substring
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
    	move	$a0,$s0
    	la	$a0, str    	
   	jal 	delim
   	
   	#print string input
    	li	$v0,	4	
    	la	$a0,	str	
    	syscall
   	
   	
    
    	#return
    	li	$v0,	10
    	syscall
    
 
#delim function to get substrings
delim:
	li $t0, -1	#counter j    
	move $t0, $s2	#s2 = j
	la $a0, str	#argument 1 string array
	jal strlen	
	move $t1, $v0	#length of string array ($t1)
	li $a1, 32	#argument 2 ' ' token
	
	#create loc[j]
	move $a0, $s1	#$s1 = str
	la $s0, loc	#$s0 = loc
	mul $t0, $s2, $s0	
	add $t0, $s1, $t0	
	sw $s2, 0($t0)	#loc[j]
	
	#loc[j] = str and j++
	li $t2, 1	#counter i
	move $t2, $s3	#s3 = i
	la $s4, str	#$s4 = str
	add $t0, $s3, $s4	#str + i
	sw $0, 0($t0)	#str + i = next space
	
	addi $s2, $s2, 1	#j++	
	
	#loop to start making substring	
	bge $s3, $t1 search
search:	la $t0, str	#$t0 = str
	add $t4, $t0, $3	#str + i
	beq $t4, $a1, broken
	#broken = make new substring
	broken: addi $t4, $t4, 1	#str+ i + 1
		sw $s2, 4($t4)	#str + i = next space
		sw $0, 8($t0)	#str + i = next space
		addi $s2, $s2, 1	#j++	
		addi $s3, $s3, 1	#i++
	blt	$s3, $t1 loop
		
	
	
	
	
	
	
	
	
	

    	jr	$ra
    
    

#find length of string   
strlen:
	li $t0, -1	#pointer
    	#move $s0, $a0	#string
    	
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
        	

	
	


