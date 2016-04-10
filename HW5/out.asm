.global main
j main_impl
simpleProcedure: #proc/func
	la $s7, stringVal0
	li $v0, 4
	move $a0, $s7
	syscall #print
main_impl:
	jal simpleProcedure #function call
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal0: .asciiz "Simple Procedure Test\n"
