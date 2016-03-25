.global main
main:
	li $s7, 0 #loading expr to register
	sw $s7, 0($gp) #Storing i
	whileBegin:
	li $s5, 20 #loading expr to register
	lw $s7, 0($gp) #i
	slt $s6, $s7, $s5
	beq $zero,$s6, whileEnd
	li $s6, 32 #loading expr to register
	lw $s6, 0($gp) #i
	li $v0, 1
	move $a0, $s6
	syscall #print
	li $v0, 11
	move $a0, $s6
	syscall #print
	lw $s6, 0($gp) #i
	addi $s6, $s6, 1 #increment
	sw $s6, 0($gp) #Storing i
	j whileBegin
	whileEnd:
	li $s6, 10 #loading expr to register
	li $v0, 11
	move $a0, $s6
	syscall #print
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
