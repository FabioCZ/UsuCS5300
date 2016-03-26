.global main
main:
	li $s7, 0 #loading expr to register
	sw $s7, 0($gp) #Storing i
WhileBegin1:
	lw $s7, 0($gp) #i
	li $s5, 20 #loading expr to register
	slt $s6, $s7, $s5
	beq $zero,$s6, WhileEnd1
	li $v0, 11
	li $s6, 105 #loading expr to register
	move $a0, $s6
	syscall #print
	lw $s6, 0($gp) #i
	li $v0, 1
	move $a0, $s6
	syscall #print
	li $v0, 11
	li $s6, 32 #loading expr to register
	move $a0, $s6
	syscall #print
	lw $s6, 0($gp) #i
	addi $s6, $s6, 1 #increment
	sw $s6, 0($gp) #Storing i
	li $s6, 0 #loading expr to register
	sw $s6, 4($gp) #Storing j
WhileBegin2:
	lw $s6, 4($gp) #j
	li $s5, 2 #loading expr to register
	slt $s7, $s6, $s5
	beq $zero,$s7, WhileEnd2
	li $v0, 11
	li $s7, 106 #loading expr to register
	move $a0, $s7
	syscall #print
	lw $s7, 4($gp) #j
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 32 #loading expr to register
	move $a0, $s7
	syscall #print
	lw $s7, 4($gp) #j
	addi $s7, $s7, 1 #increment
	sw $s7, 4($gp) #Storing j
	j WhileBegin2
	WhileEnd2:
	li $v0, 11
	li $s7, 10 #loading expr to register
	move $a0, $s7
	syscall #print
	j WhileBegin1
	WhileEnd1:
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
