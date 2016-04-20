.global main
j main_impl #jumping into main
printname: #proc/func
	li $s6, 4 #array type size
	li $s5, 1 #array starting index
	li $s4, 1 #loading expr to register
	sub $s5, $s4, $s5 #calculate index
	mul $s6, $s5, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $fp #adding fp offset and fp
	lw $s7, 0($s6) #loading array elem into register
	li $v0, 11
	move $a0, $s7
	syscall #print
	li $s4, 4 #array type size
	li $s6, 1 #array starting index
	li $s5, 2 #loading expr to register
	sub $s6, $s5, $s6 #calculate index
	mul $s4, $s6, $s4 #offset from base of array
	addi $s4, $s4, 0 #offset from pointer (f/s/g)
	add $s4, $s4, $fp #adding fp offset and fp
	lw $s7, 0($s4) #loading array elem into register
	li $v0, 11
	move $a0, $s7
	syscall #print
	li $s5, 4 #array type size
	li $s4, 1 #array starting index
	li $s6, 3 #loading expr to register
	sub $s4, $s6, $s4 #calculate index
	mul $s5, $s4, $s5 #offset from base of array
	addi $s5, $s5, 0 #offset from pointer (f/s/g)
	add $s5, $s5, $fp #adding fp offset and fp
	lw $s7, 0($s5) #loading array elem into register
	li $v0, 11
	move $a0, $s7
	syscall #print
	li $s6, 4 #array type size
	li $s5, 1 #array starting index
	li $s4, 4 #loading expr to register
	sub $s5, $s4, $s5 #calculate index
	mul $s6, $s5, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $fp #adding fp offset and fp
	lw $s7, 0($s6) #loading array elem into register
	li $v0, 11
	move $a0, $s7
	syscall #print
	li $s4, 4 #array type size
	li $s6, 1 #array starting index
	li $s5, 5 #loading expr to register
	sub $s6, $s5, $s6 #calculate index
	mul $s4, $s6, $s4 #offset from base of array
	addi $s4, $s4, 0 #offset from pointer (f/s/g)
	add $s4, $s4, $fp #adding fp offset and fp
	lw $s7, 0($s4) #loading array elem into register
	li $v0, 11
	move $a0, $s7
	syscall #print
	jr $ra #jump out of function
printrec: #proc/func
	addi $s7, $fp, 0
	addi $sp, $sp, -12 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	sw $s7, 8($sp)
	addi $sp, $sp, -140 #args
	lw $s5, 0($s7) #memberwise clone
	sw $s5, 0($sp)
	lw $s5, 4($s7) #memberwise clone
	sw $s5, 4($sp)
	lw $s5, 8($s7) #memberwise clone
	sw $s5, 8($sp)
	lw $s5, 12($s7) #memberwise clone
	sw $s5, 12($sp)
	lw $s5, 16($s7) #memberwise clone
	sw $s5, 16($sp)
	lw $s5, 20($s7) #memberwise clone
	sw $s5, 20($sp)
	lw $s5, 24($s7) #memberwise clone
	sw $s5, 24($sp)
	lw $s5, 28($s7) #memberwise clone
	sw $s5, 28($sp)
	lw $s5, 32($s7) #memberwise clone
	sw $s5, 32($sp)
	lw $s5, 36($s7) #memberwise clone
	sw $s5, 36($sp)
	lw $s5, 40($s7) #memberwise clone
	sw $s5, 40($sp)
	lw $s5, 44($s7) #memberwise clone
	sw $s5, 44($sp)
	lw $s5, 48($s7) #memberwise clone
	sw $s5, 48($sp)
	lw $s5, 52($s7) #memberwise clone
	sw $s5, 52($sp)
	lw $s5, 56($s7) #memberwise clone
	sw $s5, 56($sp)
	lw $s5, 60($s7) #memberwise clone
	sw $s5, 60($sp)
	lw $s5, 64($s7) #memberwise clone
	sw $s5, 64($sp)
	lw $s5, 68($s7) #memberwise clone
	sw $s5, 68($sp)
	lw $s5, 72($s7) #memberwise clone
	sw $s5, 72($sp)
	lw $s5, 76($s7) #memberwise clone
	sw $s5, 76($sp)
	lw $s5, 80($s7) #memberwise clone
	sw $s5, 80($sp)
	lw $s5, 84($s7) #memberwise clone
	sw $s5, 84($sp)
	lw $s5, 88($s7) #memberwise clone
	sw $s5, 88($sp)
	lw $s5, 92($s7) #memberwise clone
	sw $s5, 92($sp)
	lw $s5, 96($s7) #memberwise clone
	sw $s5, 96($sp)
	lw $s5, 100($s7) #memberwise clone
	sw $s5, 100($sp)
	lw $s5, 104($s7) #memberwise clone
	sw $s5, 104($sp)
	lw $s5, 108($s7) #memberwise clone
	sw $s5, 108($sp)
	lw $s5, 112($s7) #memberwise clone
	sw $s5, 112($sp)
	lw $s5, 116($s7) #memberwise clone
	sw $s5, 116($sp)
	lw $s5, 120($s7) #memberwise clone
	sw $s5, 120($sp)
	lw $s5, 124($s7) #memberwise clone
	sw $s5, 124($sp)
	lw $s5, 128($s7) #memberwise clone
	sw $s5, 128($sp)
	lw $s5, 132($s7) #memberwise clone
	sw $s5, 132($sp)
	lw $s5, 136($s7) #memberwise clone
	sw $s5, 136($sp)
	move $fp, $sp
	jal printname #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	lw $s7, 8($sp)
	addi $sp, $sp, 12 #restored registers
	la $s7, stringVal0
	li $v0, 4
	move $a0, $s7
	syscall #print
	lw $s7, 140($fp)
	li $v0, 1
	move $a0, $s7
	syscall #print
	li $v0, 11
	li $s7, 10 #loading expr to register
	move $a0, $s7
	syscall #print
	jr $ra #jump out of function
swap: #proc/func
# adding vars in function!
	lw $s7, 0($fp)
	addi $s5, $gp, 0
	lw $s7, 0($s5) #memberwise clone
	sw $s7, -144($sp)
	lw $s7, 4($s5) #memberwise clone
	sw $s7, -140($sp)
	lw $s7, 8($s5) #memberwise clone
	sw $s7, -136($sp)
	lw $s7, 12($s5) #memberwise clone
	sw $s7, -132($sp)
	lw $s7, 16($s5) #memberwise clone
	sw $s7, -128($sp)
	lw $s7, 20($s5) #memberwise clone
	sw $s7, -124($sp)
	lw $s7, 24($s5) #memberwise clone
	sw $s7, -120($sp)
	lw $s7, 28($s5) #memberwise clone
	sw $s7, -116($sp)
	lw $s7, 32($s5) #memberwise clone
	sw $s7, -112($sp)
	lw $s7, 36($s5) #memberwise clone
	sw $s7, -108($sp)
	lw $s7, 40($s5) #memberwise clone
	sw $s7, -104($sp)
	lw $s7, 44($s5) #memberwise clone
	sw $s7, -100($sp)
	lw $s7, 48($s5) #memberwise clone
	sw $s7, -96($sp)
	lw $s7, 52($s5) #memberwise clone
	sw $s7, -92($sp)
	lw $s7, 56($s5) #memberwise clone
	sw $s7, -88($sp)
	lw $s7, 60($s5) #memberwise clone
	sw $s7, -84($sp)
	lw $s7, 64($s5) #memberwise clone
	sw $s7, -80($sp)
	lw $s7, 68($s5) #memberwise clone
	sw $s7, -76($sp)
	lw $s7, 72($s5) #memberwise clone
	sw $s7, -72($sp)
	lw $s7, 76($s5) #memberwise clone
	sw $s7, -68($sp)
	lw $s7, 80($s5) #memberwise clone
	sw $s7, -64($sp)
	lw $s7, 84($s5) #memberwise clone
	sw $s7, -60($sp)
	lw $s7, 88($s5) #memberwise clone
	sw $s7, -56($sp)
	lw $s7, 92($s5) #memberwise clone
	sw $s7, -52($sp)
	lw $s7, 96($s5) #memberwise clone
	sw $s7, -48($sp)
	lw $s7, 100($s5) #memberwise clone
	sw $s7, -44($sp)
	lw $s7, 104($s5) #memberwise clone
	sw $s7, -40($sp)
	lw $s7, 108($s5) #memberwise clone
	sw $s7, -36($sp)
	lw $s7, 112($s5) #memberwise clone
	sw $s7, -32($sp)
	lw $s7, 116($s5) #memberwise clone
	sw $s7, -28($sp)
	lw $s7, 120($s5) #memberwise clone
	sw $s7, -24($sp)
	lw $s7, 124($s5) #memberwise clone
	sw $s7, -20($sp)
	lw $s7, 128($s5) #memberwise clone
	sw $s7, -16($sp)
	lw $s7, 132($s5) #memberwise clone
	sw $s7, -12($sp)
	lw $s7, 136($s5) #memberwise clone
	sw $s7, -8($sp)
	lw $s7, 140($s5) #memberwise clone
	sw $s7, -4($sp)
	lw $s5, 0($fp)
	lw $s7, 4($fp)
	addi $s4, $gp, 0
	li $s7, 144 #array type size
	li $s6, 1 #array starting index
	sub $s6, $s5, $s6 #calculate index
	mul $s7, $s6, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp
	sw $s4, 0($s7) #Storing table
	lw $s5, 4($fp)
	addi $s4, $sp, -144
	li $s7, 144 #array type size
	li $s6, 1 #array starting index
	sub $s6, $s5, $s6 #calculate index
	mul $s7, $s6, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp
	sw $s4, 0($s7) #Storing table
	jr $ra #jump out of function
# adding vars in function!
# adding vars in function!
	li $s5, 1 #loading expr to register
	sw $s5, -2248($sp) #Storing i
ForStart1:
	lw $s5, -2248($sp)
	li $s4, 35 #loading expr to register
	blt $s4, $s5, ForEnd1
	lw $s4, -2248($sp)
	li $s7, 1 #loading expr to register
	add $s5, $s4, $s7
# adding vars in function!
	sw $s5, -2252($sp) #Storing j
sortage: #proc/func
ForStart2:
	lw $s5, -2252($sp)
	li $s4, 35 #loading expr to register
	blt $s4, $s5, ForEnd2
	lw $s4, -2248($sp)
	lw $s4, 140($gp) #table.age
	lw $s5, -2252($sp)
	lw $s5, 140($gp) #table.age
	slt $s7, $s4, $s5
	 beq $zero, $s7, ElseLabel1_3 #if/else jump
	lw $s7, -2248($sp)
	lw $s4, -2252($sp)
	addi $sp, $sp, -16 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	sw $s4, 8($sp)
	sw $s7, 12($sp)
	addi $sp, $sp, -8 #args
	sw $s7, 0($sp)
	sw $s4, 4($sp)
	move $fp, $sp
	jal swap #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	lw $s4, 8($sp)
	lw $s7, 12($sp)
	addi $sp, $sp, 16 #restored registers
j ElseLabelEnd_3 #jump to after else
ElseLabel1_3: #else label
ElseLabelEnd_3:
	lw $s4, -2252($sp)
	addi $s4, $s4, 1 #increment
	sw $s4, -2252($sp) #Storing j
	j ForStart2
ForEnd2:
	lw $s4, -2248($sp)
	addi $s4, $s4, 1 #increment
	sw $s4, -2248($sp) #Storing i
	j ForStart1
ForEnd1:
	jr $ra #jump out of function
# adding vars in function!
# adding vars in function!
	li $s4, 1 #loading expr to register
	sw $s4, -2400($sp) #Storing i
ForStart4:
	lw $s4, -2400($sp)
	li $s7, 35 #loading expr to register
	blt $s7, $s4, ForEnd4
	lw $s7, -2400($sp)
	li $s5, 1 #loading expr to register
	add $s4, $s7, $s5
# adding vars in function!
	sw $s4, -2404($sp) #Storing j
rsortage: #proc/func
ForStart5:
	lw $s4, -2404($sp)
	li $s7, 35 #loading expr to register
	blt $s7, $s4, ForEnd5
	lw $s7, -2400($sp)
	lw $s7, 140($gp) #table.age
	lw $s4, -2404($sp)
	lw $s4, 140($gp) #table.age
	slt $s5, $s4, $s7
	 beq $zero, $s5, ElseLabel1_6 #if/else jump
	lw $s5, -2400($sp)
	addi $s7, $gp, 0
	lw $s5, 0($s7) #memberwise clone
	sw $s5, -2396($sp)
	lw $s5, 4($s7) #memberwise clone
	sw $s5, -2392($sp)
	lw $s5, 8($s7) #memberwise clone
	sw $s5, -2388($sp)
	lw $s5, 12($s7) #memberwise clone
	sw $s5, -2384($sp)
	lw $s5, 16($s7) #memberwise clone
	sw $s5, -2380($sp)
	lw $s5, 20($s7) #memberwise clone
	sw $s5, -2376($sp)
	lw $s5, 24($s7) #memberwise clone
	sw $s5, -2372($sp)
	lw $s5, 28($s7) #memberwise clone
	sw $s5, -2368($sp)
	lw $s5, 32($s7) #memberwise clone
	sw $s5, -2364($sp)
	lw $s5, 36($s7) #memberwise clone
	sw $s5, -2360($sp)
	lw $s5, 40($s7) #memberwise clone
	sw $s5, -2356($sp)
	lw $s5, 44($s7) #memberwise clone
	sw $s5, -2352($sp)
	lw $s5, 48($s7) #memberwise clone
	sw $s5, -2348($sp)
	lw $s5, 52($s7) #memberwise clone
	sw $s5, -2344($sp)
	lw $s5, 56($s7) #memberwise clone
	sw $s5, -2340($sp)
	lw $s5, 60($s7) #memberwise clone
	sw $s5, -2336($sp)
	lw $s5, 64($s7) #memberwise clone
	sw $s5, -2332($sp)
	lw $s5, 68($s7) #memberwise clone
	sw $s5, -2328($sp)
	lw $s5, 72($s7) #memberwise clone
	sw $s5, -2324($sp)
	lw $s5, 76($s7) #memberwise clone
	sw $s5, -2320($sp)
	lw $s5, 80($s7) #memberwise clone
	sw $s5, -2316($sp)
	lw $s5, 84($s7) #memberwise clone
	sw $s5, -2312($sp)
	lw $s5, 88($s7) #memberwise clone
	sw $s5, -2308($sp)
	lw $s5, 92($s7) #memberwise clone
	sw $s5, -2304($sp)
	lw $s5, 96($s7) #memberwise clone
	sw $s5, -2300($sp)
	lw $s5, 100($s7) #memberwise clone
	sw $s5, -2296($sp)
	lw $s5, 104($s7) #memberwise clone
	sw $s5, -2292($sp)
	lw $s5, 108($s7) #memberwise clone
	sw $s5, -2288($sp)
	lw $s5, 112($s7) #memberwise clone
	sw $s5, -2284($sp)
	lw $s5, 116($s7) #memberwise clone
	sw $s5, -2280($sp)
	lw $s5, 120($s7) #memberwise clone
	sw $s5, -2276($sp)
	lw $s5, 124($s7) #memberwise clone
	sw $s5, -2272($sp)
	lw $s5, 128($s7) #memberwise clone
	sw $s5, -2268($sp)
	lw $s5, 132($s7) #memberwise clone
	sw $s5, -2264($sp)
	lw $s5, 136($s7) #memberwise clone
	sw $s5, -2260($sp)
	lw $s5, 140($s7) #memberwise clone
	sw $s5, -2256($sp)
	lw $s7, -2400($sp)
	lw $s5, -2404($sp)
	addi $s4, $gp, 0
	li $s5, 144 #array type size
	li $s6, 1 #array starting index
	sub $s6, $s7, $s6 #calculate index
	mul $s5, $s6, $s5 #offset from base of array
	addi $s5, $s5, 0 #offset from pointer (f/s/g)
	add $s5, $s5, $gp
	sw $s4, 0($s5) #Storing table
	lw $s7, -2404($sp)
	addi $s4, $sp, -2396
	li $s5, 144 #array type size
	li $s6, 1 #array starting index
	sub $s6, $s7, $s6 #calculate index
	mul $s5, $s6, $s5 #offset from base of array
	addi $s5, $s5, 0 #offset from pointer (f/s/g)
	add $s5, $s5, $gp
	sw $s4, 0($s5) #Storing table
j ElseLabelEnd_6 #jump to after else
ElseLabel1_6: #else label
ElseLabelEnd_6:
	lw $s7, -2404($sp)
	addi $s7, $s7, 1 #increment
	sw $s7, -2404($sp) #Storing j
	j ForStart5
ForEnd5:
	lw $s7, -2400($sp)
	addi $s7, $s7, 1 #increment
	sw $s7, -2400($sp) #Storing i
	j ForStart4
ForEnd4:
	jr $ra #jump out of function
# adding vars in function!
	li $s7, 1 #loading expr to register
	sw $s7, -2408($sp) #Storing i
printtable: #proc/func
ForStart7:
	lw $s7, -2408($sp)
	li $s4, 35 #loading expr to register
	blt $s4, $s7, ForEnd7
	lw $s4, -2408($sp)
	addi $s7, $gp, 0
	addi $sp, $sp, -12 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	sw $s7, 8($sp)
	addi $sp, $sp, -144 #args
	lw $s4, 0($s7) #memberwise clone
	sw $s4, 0($sp)
	lw $s4, 4($s7) #memberwise clone
	sw $s4, 4($sp)
	lw $s4, 8($s7) #memberwise clone
	sw $s4, 8($sp)
	lw $s4, 12($s7) #memberwise clone
	sw $s4, 12($sp)
	lw $s4, 16($s7) #memberwise clone
	sw $s4, 16($sp)
	lw $s4, 20($s7) #memberwise clone
	sw $s4, 20($sp)
	lw $s4, 24($s7) #memberwise clone
	sw $s4, 24($sp)
	lw $s4, 28($s7) #memberwise clone
	sw $s4, 28($sp)
	lw $s4, 32($s7) #memberwise clone
	sw $s4, 32($sp)
	lw $s4, 36($s7) #memberwise clone
	sw $s4, 36($sp)
	lw $s4, 40($s7) #memberwise clone
	sw $s4, 40($sp)
	lw $s4, 44($s7) #memberwise clone
	sw $s4, 44($sp)
	lw $s4, 48($s7) #memberwise clone
	sw $s4, 48($sp)
	lw $s4, 52($s7) #memberwise clone
	sw $s4, 52($sp)
	lw $s4, 56($s7) #memberwise clone
	sw $s4, 56($sp)
	lw $s4, 60($s7) #memberwise clone
	sw $s4, 60($sp)
	lw $s4, 64($s7) #memberwise clone
	sw $s4, 64($sp)
	lw $s4, 68($s7) #memberwise clone
	sw $s4, 68($sp)
	lw $s4, 72($s7) #memberwise clone
	sw $s4, 72($sp)
	lw $s4, 76($s7) #memberwise clone
	sw $s4, 76($sp)
	lw $s4, 80($s7) #memberwise clone
	sw $s4, 80($sp)
	lw $s4, 84($s7) #memberwise clone
	sw $s4, 84($sp)
	lw $s4, 88($s7) #memberwise clone
	sw $s4, 88($sp)
	lw $s4, 92($s7) #memberwise clone
	sw $s4, 92($sp)
	lw $s4, 96($s7) #memberwise clone
	sw $s4, 96($sp)
	lw $s4, 100($s7) #memberwise clone
	sw $s4, 100($sp)
	lw $s4, 104($s7) #memberwise clone
	sw $s4, 104($sp)
	lw $s4, 108($s7) #memberwise clone
	sw $s4, 108($sp)
	lw $s4, 112($s7) #memberwise clone
	sw $s4, 112($sp)
	lw $s4, 116($s7) #memberwise clone
	sw $s4, 116($sp)
	lw $s4, 120($s7) #memberwise clone
	sw $s4, 120($sp)
	lw $s4, 124($s7) #memberwise clone
	sw $s4, 124($sp)
	lw $s4, 128($s7) #memberwise clone
	sw $s4, 128($sp)
	lw $s4, 132($s7) #memberwise clone
	sw $s4, 132($sp)
	lw $s4, 136($s7) #memberwise clone
	sw $s4, 136($sp)
	lw $s4, 140($s7) #memberwise clone
	sw $s4, 140($sp)
	move $fp, $sp
	jal printrec #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	lw $s7, 8($sp)
	addi $sp, $sp, 12 #restored registers
	lw $s7, -2408($sp)
	addi $s7, $s7, 1 #increment
	sw $s7, -2408($sp) #Storing i
	j ForStart7
ForEnd7:
	jr $ra #jump out of function
main_impl:
	li $s7, 2 #loading expr to register
	sw $s7, 140($gp) #Storing table.age
	li $s7, 99 #loading expr to register
	li $s4, 4 #array type size
	li $s5, 1 #array starting index
	li $s6, 1 #loading expr to register
	sub $s5, $s6, $s5 #calculate index
	mul $s4, $s5, $s4 #offset from base of array
	addi $s4, $s4, 0 #offset from pointer (f/s/g)
	add $s4, $s4, $gp
	sw $s7, 0($s4) #Storing table.name
	li $s6, 104 #loading expr to register
	li $s7, 4 #array type size
	li $s4, 1 #array starting index
	li $s5, 2 #loading expr to register
	sub $s4, $s5, $s4 #calculate index
	mul $s7, $s4, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp
	sw $s6, 0($s7) #Storing table.name
	li $s5, 97 #loading expr to register
	li $s6, 4 #array type size
	li $s7, 1 #array starting index
	li $s4, 3 #loading expr to register
	sub $s7, $s4, $s7 #calculate index
	mul $s6, $s7, $s6 #offset from base of array
	addi $s6, $s6, 0 #offset from pointer (f/s/g)
	add $s6, $s6, $gp
	sw $s5, 0($s6) #Storing table.name
	li $s4, 100 #loading expr to register
	li $s5, 4 #array type size
	li $s6, 1 #array starting index
	li $s7, 4 #loading expr to register
	sub $s6, $s7, $s6 #calculate index
	mul $s5, $s6, $s5 #offset from base of array
	addi $s5, $s5, 0 #offset from pointer (f/s/g)
	add $s5, $s5, $gp
	sw $s4, 0($s5) #Storing table.name
	li $s7, 114 #loading expr to register
	li $s4, 4 #array type size
	li $s5, 1 #array starting index
	li $s6, 5 #loading expr to register
	sub $s5, $s6, $s5 #calculate index
	mul $s4, $s5, $s4 #offset from base of array
	addi $s4, $s4, 0 #offset from pointer (f/s/g)
	add $s4, $s4, $gp
	sw $s7, 0($s4) #Storing table.name
	li $s6, 2 #loading expr to register
	sw $s6, 5740($gp) #Storing j
ForStart8:
	lw $s6, 5740($gp) #j
	li $s7, 35 #loading expr to register
	blt $s7, $s6, ForEnd8
	li $s7, 1 #loading expr to register
	sw $s7, 5744($gp) #Storing i
ForStart9:
	lw $s7, 5744($gp) #i
	li $s6, 35 #loading expr to register
	blt $s6, $s7, ForEnd9
	lw $s6, 5740($gp) #j
	lw $s6, 5744($gp) #i
	lw $s7, 5740($gp) #j
	li $s5, 1 #loading expr to register
	sub $s4, $s7, $s5
	lw $s4, 5740($gp) #j
	lw $s7, 5744($gp) #i
	li $s3, 35 #loading expr to register
	rem $s5, $s7, $s3
	add $s7, $s4, $s5
	li $s5, 1 #loading expr to register
	add $s4, $s7, $s5
	li $s5, 4 #array type size
	li $s3, 1 #array starting index
	sub $s3, $s4, $s3 #calculate index
	mul $s5, $s3, $s5 #offset from base of array
	addi $s5, $s5, 0 #offset from pointer (f/s/g)
	add $s5, $s5, $gp #adding gp offset and gp
	lw $s7, 0($s5) #loading array elem into register
	li $s5, 1 #loading expr to register
	add $s4, $s7, $s5
	li $s5, 20 #loading expr to register
	rem $s7, $s4, $s5
	li $s5, 97 #loading expr to register
	add $s4, $s7, $s5
	li $s7, 4 #array type size
	li $s5, 1 #array starting index
	sub $s5, $s6, $s5 #calculate index
	mul $s7, $s5, $s7 #offset from base of array
	addi $s7, $s7, 0 #offset from pointer (f/s/g)
	add $s7, $s7, $gp
	sw $s4, 0($s7) #Storing table.name
	lw $s6, 5744($gp) #i
	addi $s6, $s6, 1 #increment
	sw $s6, 5744($gp) #Storing i
	j ForStart9
ForEnd9:
	lw $s6, 5740($gp) #j
	lw $s6, 5740($gp) #j
	lw $s4, 5740($gp) #j
	mul $s7, $s6, $s4
	li $s4, 30 #loading expr to register
	rem $s6, $s7, $s4
	sw $s6, 140($gp) #Storing table.age
	lw $s6, 5740($gp) #j
	addi $s6, $s6, 1 #increment
	sw $s6, 5740($gp) #Storing j
	j ForStart8
ForEnd8:
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal printtable #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	la $s6, stringVal1
	li $v0, 4
	move $a0, $s6
	syscall #print
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal sortage #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal printtable #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	la $s6, stringVal2
	li $v0, 4
	move $a0, $s6
	syscall #print
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal rsortage #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	addi $sp, $sp, -8 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	move $fp, $sp
	jal printtable #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	addi $sp, $sp, 8 #restored registers
	li $s6, 1 #loading expr to register
	sw $s6, 5748($gp) #Storing i
ForStart10:
	lw $s6, 5748($gp) #i
	li $s7, 5 #loading expr to register
	blt $s7, $s6, ForEnd10
	lw $s7, 5748($gp) #i
	lw $s6, 5748($gp) #i
	addi $s6, $gp, 0
	li $s4, 140 #array type size
	li $s5, 1 #array starting index
	sub $s5, $s7, $s5 #calculate index
	mul $s4, $s5, $s4 #offset from base of array
	addi $s4, $s4, 5040 #offset from pointer (f/s/g)
	add $s4, $s4, $gp
	sw $s6, 0($s4) #Storing mat
	la $s7, stringVal3
	li $v0, 4
	move $a0, $s7
	syscall #print
	lw $s7, 5748($gp) #i
	li $v0, 1
	move $a0, $s7
	syscall #print
	la $s7, stringVal4
	li $v0, 4
	move $a0, $s7
	syscall #print
	lw $s7, 5748($gp) #i
	addi $s6, $gp, 5040
	addi $sp, $sp, -12 #spilling registers
	sw $fp, 0($sp) # saving frame pointer
	sw $ra, 4($sp) # saving return address
	sw $s6, 8($sp)
	addi $sp, $sp, -140 #args
	lw $s7, 0($s6) #memberwise clone
	sw $s7, 0($sp)
	lw $s7, 4($s6) #memberwise clone
	sw $s7, 4($sp)
	lw $s7, 8($s6) #memberwise clone
	sw $s7, 8($sp)
	lw $s7, 12($s6) #memberwise clone
	sw $s7, 12($sp)
	lw $s7, 16($s6) #memberwise clone
	sw $s7, 16($sp)
	lw $s7, 20($s6) #memberwise clone
	sw $s7, 20($sp)
	lw $s7, 24($s6) #memberwise clone
	sw $s7, 24($sp)
	lw $s7, 28($s6) #memberwise clone
	sw $s7, 28($sp)
	lw $s7, 32($s6) #memberwise clone
	sw $s7, 32($sp)
	lw $s7, 36($s6) #memberwise clone
	sw $s7, 36($sp)
	lw $s7, 40($s6) #memberwise clone
	sw $s7, 40($sp)
	lw $s7, 44($s6) #memberwise clone
	sw $s7, 44($sp)
	lw $s7, 48($s6) #memberwise clone
	sw $s7, 48($sp)
	lw $s7, 52($s6) #memberwise clone
	sw $s7, 52($sp)
	lw $s7, 56($s6) #memberwise clone
	sw $s7, 56($sp)
	lw $s7, 60($s6) #memberwise clone
	sw $s7, 60($sp)
	lw $s7, 64($s6) #memberwise clone
	sw $s7, 64($sp)
	lw $s7, 68($s6) #memberwise clone
	sw $s7, 68($sp)
	lw $s7, 72($s6) #memberwise clone
	sw $s7, 72($sp)
	lw $s7, 76($s6) #memberwise clone
	sw $s7, 76($sp)
	lw $s7, 80($s6) #memberwise clone
	sw $s7, 80($sp)
	lw $s7, 84($s6) #memberwise clone
	sw $s7, 84($sp)
	lw $s7, 88($s6) #memberwise clone
	sw $s7, 88($sp)
	lw $s7, 92($s6) #memberwise clone
	sw $s7, 92($sp)
	lw $s7, 96($s6) #memberwise clone
	sw $s7, 96($sp)
	lw $s7, 100($s6) #memberwise clone
	sw $s7, 100($sp)
	lw $s7, 104($s6) #memberwise clone
	sw $s7, 104($sp)
	lw $s7, 108($s6) #memberwise clone
	sw $s7, 108($sp)
	lw $s7, 112($s6) #memberwise clone
	sw $s7, 112($sp)
	lw $s7, 116($s6) #memberwise clone
	sw $s7, 116($sp)
	lw $s7, 120($s6) #memberwise clone
	sw $s7, 120($sp)
	lw $s7, 124($s6) #memberwise clone
	sw $s7, 124($sp)
	lw $s7, 128($s6) #memberwise clone
	sw $s7, 128($sp)
	lw $s7, 132($s6) #memberwise clone
	sw $s7, 132($sp)
	lw $s7, 136($s6) #memberwise clone
	sw $s7, 136($sp)
	move $fp, $sp
	jal printname #function call
	lw $fp, 0($sp) # restoring frame pointer
	lw $ra, 4($sp) # restoring return address
	lw $s6, 8($sp)
	addi $sp, $sp, 12 #restored registers
	li $v0, 11
	li $s6, 10 #loading expr to register
	move $a0, $s6
	syscall #print
	lw $s6, 5748($gp) #i
	addi $s6, $s6, 1 #increment
	sw $s6, 5748($gp) #Storing i
	j ForStart10
ForEnd10:
	li $v0, 10 #load stop instr
	syscall
#Finished writing maing, now writing data sector
.data:
	stringVal3: .asciiz "mat["
	stringVal2: .asciiz "reverse swapping!\n"
	stringVal1: .asciiz "sorting!\n"
	stringVal4: .asciiz "]="
	stringVal0: .asciiz " is age "
