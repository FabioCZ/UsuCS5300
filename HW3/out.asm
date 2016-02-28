	li $s7, 1 # Expression to register load
	sw $s7, 0($gp) #Storing a
	li $s7, 2 # Expression to register load
	sw $s7, 4($gp) #Storing b
	lw $s7, 0($gp) #a
	li $v0, 1
	move $a0, $s7
	syscall #print
	lw $s7, 4($gp) #b
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 5
	lsyscall #read
	sw $v0, 0($gp) #store read value to a
	lw $s7, 0($gp) #a
	lw $s6, 4($gp) #b
	add $s5, $s7, $s6
	sw $s5, 0($gp) #Storing a
	lw $s5, 0($gp) #a
	lw $s7, 4($gp) #b
	add $s6, $s5, $s7
	sw $s6, 4($gp) #Storing b
	lw $s6, 0($gp) #a
	li $v0, 1
	move $a0, $s6
	syscall #print
	lw $s6, 4($gp) #b
	li $v0, 1
	move $a0, $s6
	syscall #print
	lw $s6, 0($gp) #a
	lw $s5, 4($gp) #b
	mul $s7, $s6, $s5
	sw $s7, 0($gp) #Storing a
	lw $s7, 0($gp) #a
	lw $s6, 4($gp) #b
	mul $s5, $s7, $s6
	sw $s5, 4($gp) #Storing b
	lw $s5, 0($gp) #a
	li $v0, 1
	move $a0, $s5
	syscall #print
	lw $s5, 4($gp) #b
	li $v0, 1
	move $a0, $s5
	syscall #print
Test code.data:
