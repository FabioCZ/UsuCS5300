.global main
main:
	li $s7, 0 #loading expr to register
	sw $s7, 0($gp) #Storing i
	lw $s7, 0($gp) #i
	li $s5, 0 #loading expr to register
	slt $s6, $s5, $s7
	 beq $zero, $s6, ElseLabel1_1 #if/else jump
	la $s6, stringVal0
	li $v0, 4
	move $a0, $s6
	syscall #print
j ElseLabelEnd_1 #jump to after else
ElseLabel1_1: #else label
	li $s6, 0 #loading expr to register
	sw $s6, 4($gp) #Storing j
WhileBegin2:
	lw $s6, 4($gp) #j
	li $s5, 4 #loading expr to register
	slt $s7, $s6, $s5
	beq $zero,$s7, WhileEnd2
	lw $s7, 4($gp) #j
	sw $s7, 12($gp) #Storing a
ForStart3:
	lw $s7, 12($gp) #a
	li $s6, 4 #loading expr to register
	beq $s6, $s7, ForEnd3
	li $s6, 0 #loading expr to register
	sw $s6, 8($gp) #Storing k
RepeatBegin4:
	lw $s6, 8($gp) #k
	li $s5, 0 #loading expr to register
	seq $s7, $s6, $s5
	 beq $zero, $s7, ElseLabel1_5 #if/else jump
	la $s7, stringVal1
	li $v0, 4
	move $a0, $s7
	syscall #print
	lw $s7, 8($gp) #k
	li $v0, 1
	move $a0, $s7
	syscall #print
	la $s7, stringVal2
	li $v0, 4
	move $a0, $s7
	syscall #print
j ElseLabelEnd_5 #jump to after else
ElseLabel1_5: #else label
	lw $s7, 8($gp) #k
	li $s5, 1 #loading expr to register
	seq $s6, $s5, $s7
	 beq $zero, $s6, ElseLabel2_5 #if/else jump
	la $s6, stringVal3
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 8($gp) #k
	li $v0, 1
	move $a0, $s6
	syscall #print
	la $s6, stringVal4
	li $v0, 4
	move $a0, $s6
	syscall #print
j ElseLabelEnd_5 #jump to after else
ElseLabel2_5: #else label
	lw $s6, 8($gp) #k
	li $s7, 3 #loading expr to register
	sne $s5, $s6, $s7
	 beq $zero, $s5, ElseLabel3_5 #if/else jump
	la $s5, stringVal5
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 8($gp) #k
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal6
	li $v0, 4
	move $a0, $s5
	syscall #print
j ElseLabelEnd_5 #jump to after else
ElseLabel3_5: #else label
	la $s5, stringVal7
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 8($gp) #k
	li $v0, 1
	move $a0, $s5
	syscall #print
	la $s5, stringVal8
	li $v0, 4
	move $a0, $s5
	syscall #print
ElseLabelEnd_5:
	lw $s5, 8($gp) #k
	addi $s5, $s5, 1 #increment
	sw $s5, 8($gp) #Storing k
	lw $s5, 8($gp) #k
	li $s7, 3 #loading expr to register
	slt $s6, $s7, $s5
	beq $zero,$s6, RepeatBegin4
	la $s6, stringVal9
	li $v0, 4
	move $a0, $s6
	syscall #print
	lw $s6, 12($gp) #a
	li $v0, 1
	move $a0, $s6
	syscall #print
	li $v0, 11
	li $s6, 10 #loading expr to register
	move $a0, $s6
	syscall #print
	lw $s6, 12($gp) #a
	addi $s6, $s6, 1 #increment
	sw $s6, 12($gp) #Storing a
	j ForStart3
ForEnd3:
	lw $s6, 4($gp) #j
	addi $s6, $s6, 1 #increment
	sw $s6, 4($gp) #Storing j
	j WhileBegin2
	WhileEnd2:
ElseLabelEnd_1:
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal7: .asciiz "else="
	stringVal6: .asciiz ", "
	stringVal5: .asciiz "2="
	stringVal9: .asciiz "a="
	stringVal3: .asciiz "1="
	stringVal2: .asciiz ", "
	stringVal8: .asciiz ", "
	stringVal1: .asciiz "0="
	stringVal4: .asciiz ", "
	stringVal0: .asciiz "err"
