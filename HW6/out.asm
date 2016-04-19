.global main
j main_impl #jumping into main
simpleProcedure: #proc/func
# adding vars in function!
	li $s6, 4 #array type size
	li $s5, 2 #array starting index
	li $s4, 2 #loading expr to register
	sub $s5, $s5, $s4 #calculate index
	mul $s6, $s5, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $fp #adding fp offset and fp
	lw $s7, 0($s6) #loading array elem into register
	li $v0, 1
	move $a0, $s7
	syscall #print
	jr $ra #jump out of function
main_impl:
	li $s7, 6 #loading expr to register
	li $s4, 4 #array type size
	li $s6, 2 #array starting index
	li $s5, 2 #loading expr to register
	sub $s6, $s6, $s5 #calculate index
	mul $s4, $s6, $s4 #offset from base of array
	addi $s4, $s4, 0 #offset from pointer (f/s/g)
	add $s4, $s4, $gp
	sw $s7, 0($s4) #Storing t
	addi $s5, $gp, 0
	addi $sp, $sp, -12 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	sw $s5, 8($sp)
	addi $sp, $sp, -44 #args
	sw $s5, 0($sp)
	move $fp, $sp
	jal simpleProcedure #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	lw $s5, 8($sp)
	addi $sp, $sp, 12 #restored registers
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
