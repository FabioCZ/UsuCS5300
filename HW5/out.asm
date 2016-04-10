.global main
j main_impl
simpleProcedure: #proc/func
# adding vars in function!
	jr $ra #jump out of function
main_impl:
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal simpleProcedure #function call
	lw $fp, 0($sp) # saving frame pointer
	lw $ra, 4($sp) # saving return address
	addi $sp, $sp, 8 #restored registers
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
