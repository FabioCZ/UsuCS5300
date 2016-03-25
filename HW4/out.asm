.global main
main:
	li $s7, 0
	sw $s7, 0($gp) #Storing i
	li $s5, 20
	li $s7, 32
	lw $s7, 0($gp) #i
	slt $s6, $s7, $s5
	lw $s7, 0($gp) #i
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	move $a0, $s7
	syscall #print
	lw $s7, 0($gp) #i
	addi $s7, $s7, 1 #increment
	sw $s7, 0($gp) #Storing i
	li $s5, 20
	li $s6, 32
	lw $s6, 0($gp) #i
	slt $s7, $s6, $s5
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
	li $s7, 10
	li $v0, 11
	move $a0, $s7
	syscall #print
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
