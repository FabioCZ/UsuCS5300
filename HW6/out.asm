.global main
	li $s7, 12 #loading expr to register
	sw $s7, 0($gp) #Storing NUMS_LENGTH
	j main_impl #jumping into main
main_impl:
	la $s7, Test
	li $v0, 4
	move $a0, $s7
	syscall #print
	lw $s7, 0($gp) #NUMS_LENGTH
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $s7, 10 #loading expr to register
	sw $s7, 4($gp) #Storing x
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	Test: .asciiz "assadfg"
