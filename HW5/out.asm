.global main
j main_impl
	jr $ra #jump out of function
	jr $ra #jump out of function
simpleFunction: #proc/func
	li $s7, 12 #loading expr to register
	sw $s7, 0($gp) #Storing x
	lw $s7, 0($gp) #x
	li $s5, 15 #loading expr to register
	slt $s6, $s7, $s5
	 beq $zero, $s6, ElseLabel1_1 #if/else jump
	la $s6, stringVal0
	li $v0, 4
	move $a0, $s6
	syscall #print
j ElseLabelEnd_1 #jump to after else
ElseLabel1_1: #else label
ElseLabelEnd_1:
	lw $s6, 0($gp) #x
	li $v0, 1
	move $a0, $s6
	syscall #print
	li $v0, 11
	li $s6, 10 #loading expr to register
	move $a0, $s6
	syscall #print
	la $s6, stringVal1
	li $v0, 4
	move $a0, $s6
	syscall #print
	li $s6, 5 #loading expr to register
	sw $s6, -4($fp) #Storing _return
	jr $ra #jump out of function
main_impl:
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	addi $sp, $sp, -8 #args
	li $s6, 1 #loading expr to register
	sw $s6, 0($sp)
	li $s7, 101 #loading expr to register
	sw $s7, 4($sp)
	move $fp, $sp
	jal simpleFunction #function call
	lw $t0, -4($fp)
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	li $v0, 1
	move $a0, $t0
	syscall #print
	li $v0, 11
	li $t0, 10 #loading expr to register
	move $a0, $t0
	syscall #print
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal1: .asciiz "Entered Function. Returning 5.\n"
	stringVal0: .asciiz "in if"
