.global main
main:
	li $s7, 1
	sw $s7, 12($gp) #Storing z
	li $s7, 3
	sw $s7, 4($gp) #Storing a
	lw $s7, 0($gp) #x
	addi $s7, $s7, 1 #increment
	sw $s7, 4($gp) #Storing a
	lw $s7, 8($gp) #b
	addi $s7, $s7, -1 #decrement
	sw $s7, 8($gp) #Storing b
	li $v0, 11
	li $s7, 116
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	li $v0, 1
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	not $s7, $s7
	sw $s7, 12($gp) #Storing z
	li $v0, 11
	li $s7, 102
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	li $v0, 1
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	not $s7, $s7
	sw $s7, 12($gp) #Storing z
	li $v0, 11
	li $s7, 116
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 10
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 10
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 97
	move $a0, $s7
	syscall #print
	lw $s7, 4($gp) #a
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 98
	move $a0, $s7
	syscall #print
	lw $s7, 8($gp) #b
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 122
	move $a0, $s7
	syscall #print
	lw $s7, 12($gp) #z
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 10
	move $a0, $s7
	syscall #print
	lw $s7, 4($gp) #a
	lw $s6, 8($gp) #b
	add $s5, $s7, $s6
	sw $s5, 4($gp) #Storing a
	lw $s5, 4($gp) #a
	lw $s7, 8($gp) #b
	add $s6, $s5, $s7
	sw $s6, 8($gp) #Storing b
	lw $s6, 4($gp) #a
	li $v0, 1
	move $a0, $s6
	syscall #print
	lw $s6, 8($gp) #b
	li $v0, 1
	move $a0, $s6
	syscall #print
	lw $s6, 4($gp) #a
	lw $s5, 8($gp) #b
	mul $s7, $s6, $s5
	sw $s7, 4($gp) #Storing a
	lw $s7, 4($gp) #a
	lw $s6, 8($gp) #b
	mul $s5, $s7, $s6
	sw $s5, 8($gp) #Storing b
	lw $s5, 4($gp) #a
	li $v0, 1
	move $a0, $s5
	syscall #print
	lw $s5, 8($gp) #b
	li $v0, 1
	move $a0, $s5
	syscall #print
	lw $s5, 4($gp) #a
	lw $s7, 8($gp) #b
	add $s6, $s5, $s7
	sw $s6, 4($gp) #Storing a
#Finished writing maing, now writing data sector
.data:
	y: .asciiz "test"
	x: .word 12
