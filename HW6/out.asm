.global main
j main_impl #jumping into main
# adding vars in function!
# adding vars in function!
	li $s7, 0 #loading expr to register
	sw $s7, -48($sp) #Storing n
getArray: #proc/func
ForStart1:
	lw $s7, -48($sp)
	li $s6, 10 #loading expr to register
	beq $s6, $s7, ForEnd1
	lw $s6, -48($sp)
	lw $s7, -48($sp)
	li $s4, 2 #loading expr to register
	mul $s5, $s7, $s4
	li $s7, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s6, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, -44 #offset from pointer (f/s/g)
	add $s7, $s7, $sp
	sw $s5, 0($s7) #Storing returnarray
	lw $s6, -48($sp)
	addi $s6, $s6, 1 #increment
	sw $s6, -48($sp) #Storing n
	j ForStart1
ForEnd1:
	addi $s6, $sp, -44
	lw $s5, 0($s6) #memberwise clone
	sw $s5, -44($fp)
	lw $s5, 4($s6) #memberwise clone
	sw $s5, -40($fp)
	lw $s5, 8($s6) #memberwise clone
	sw $s5, -36($fp)
	lw $s5, 12($s6) #memberwise clone
	sw $s5, -32($fp)
	lw $s5, 16($s6) #memberwise clone
	sw $s5, -28($fp)
	lw $s5, 20($s6) #memberwise clone
	sw $s5, -24($fp)
	lw $s5, 24($s6) #memberwise clone
	sw $s5, -20($fp)
	lw $s5, 28($s6) #memberwise clone
	sw $s5, -16($fp)
	lw $s5, 32($s6) #memberwise clone
	sw $s5, -12($fp)
	lw $s5, 36($s6) #memberwise clone
	sw $s5, -8($fp)
	lw $s5, 40($s6) #memberwise clone
	sw $s5, -4($fp)
	jr $ra #jump out of function
	jr $ra #jump out of function
main_impl:
	li $s6, 0 #loading expr to register
	sw $s6, 88($gp) #Storing n
ForStart2:
	lw $s6, 88($gp) #n
	li $s5, 10 #loading expr to register
	beq $s5, $s6, ForEnd2
	la $s5, stringVal0
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 88($gp) #n
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal1
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 88($gp) #n
	lw $s6, 88($gp) #n
	li $s4, 5 #loading expr to register
	mul $s7, $s6, $s4
	li $s6, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s5, $s4 #calculate index
	mul $s6, $s4, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $gp
	sw $s7, 0($s6) #Storing a
	lw $s5, 88($gp) #n
	lw $s7, 88($gp) #n
	li $s4, 3 #loading expr to register
	mul $s6, $s7, $s4
	li $s7, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s5, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, 44 #offset from pointer (f/s/g)
	add $s7, $s7, $gp
	sw $s6, 0($s7) #Storing b
	lw $s5, 88($gp) #n
	addi $s5, $s5, 1 #increment
	sw $s5, 88($gp) #Storing n
	j ForStart2
ForEnd2:
	li $s5, 0 #loading expr to register
	sw $s5, 92($gp) #Storing n
ForStart3:
	lw $s5, 92($gp) #n
	li $s6, 10 #loading expr to register
	beq $s6, $s5, ForEnd3
	la $s6, stringVal2
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 92($gp) #n
	li $v0, 1
	move $a0, $s6
	syscall #print
	la $s6, stringVal3
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 92($gp) #n
	li $s7, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s6, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp #adding gp offset and gp
	lw $s5, 0($s7) #loading array elem into register
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal4
	li $v0, 4
	move $a0, $s5
	syscall #print
	la $s5, stringVal5
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 92($gp) #n
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal6
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 92($gp) #n
	li $s7, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s5, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, 44 #offset from pointer (f/s/g)
	add $s7, $s7, $gp #adding gp offset and gp
	lw $s6, 0($s7) #loading array elem into register
	li $v0, 1
	move $a0, $s6
	syscall #print
	la $s6, stringVal7
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 92($gp) #n
	addi $s6, $s6, 1 #increment
	sw $s6, 92($gp) #Storing n
	j ForStart3
ForEnd3:
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal getArray #function call
	addi $s6, $fp, -44
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	lw $s5, 0($s6) #memberwise clone
	sw $s5, 0($gp)
	lw $s5, 4($s6) #memberwise clone
	sw $s5, 4($gp)
	lw $s5, 8($s6) #memberwise clone
	sw $s5, 8($gp)
	lw $s5, 12($s6) #memberwise clone
	sw $s5, 12($gp)
	lw $s5, 16($s6) #memberwise clone
	sw $s5, 16($gp)
	lw $s5, 20($s6) #memberwise clone
	sw $s5, 20($gp)
	lw $s5, 24($s6) #memberwise clone
	sw $s5, 24($gp)
	lw $s5, 28($s6) #memberwise clone
	sw $s5, 28($gp)
	lw $s5, 32($s6) #memberwise clone
	sw $s5, 32($gp)
	lw $s5, 36($s6) #memberwise clone
	sw $s5, 36($gp)
	lw $s5, 40($s6) #memberwise clone
	sw $s5, 40($gp)
	li $s6, 0 #loading expr to register
	sw $s6, 96($gp) #Storing n
ForStart4:
	lw $s6, 96($gp) #n
	li $s5, 10 #loading expr to register
	beq $s5, $s6, ForEnd4
	la $s5, stringVal8
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 96($gp) #n
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal9
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 96($gp) #n
	li $s7, 4 #array type size
	li $s4, 0 #array starting index
	sub $s4, $s5, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp #adding gp offset and gp
	lw $s6, 0($s7) #loading array elem into register
	li $v0, 1
	move $a0, $s6
	syscall #print
	la $s6, stringVal10
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 96($gp) #n
	addi $s6, $s6, 1 #increment
	sw $s6, 96($gp) #Storing n
	j ForStart4
ForEnd4:
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal10: .asciiz "\n"
	stringVal0: .asciiz "n:"
	stringVal4: .asciiz "\n"
	stringVal1: .asciiz "\n"
	stringVal8: .asciiz "a["
	stringVal2: .asciiz "a["
	stringVal3: .asciiz "]:"
	stringVal9: .asciiz "]:"
	stringVal5: .asciiz "b["
	stringVal6: .asciiz "]:"
	stringVal7: .asciiz "\n\n"
