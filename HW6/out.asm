.global main
j main_impl #jumping into main
main_impl:
	li $s7, 6 #loading expr to register
	li $s6, 4 #array type size
	li $s5, 2 #loading expr to register
	mul $s6, $s5, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $gp
	sw $s7, 0($s6) #Storing t
	li $v0, 5
	syscall #read
	sw $v0, 0($gp) #store read value to x
	la $s5, stringVal0
	li $v0, 4
	move $a0, $s5
	syscall #print
	lw $s5, 0($gp) #x
	li $s6, 4 #array type size
	mul $s6, $s5, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $gp #adding gp offset and gp
	lw $s7, 0($s6) #loading array elem into register
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal0: .asciiz "array access: "
	Test: .asciiz "assadfg"
