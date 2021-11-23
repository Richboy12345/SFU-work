# Richard Zhang
# rza69
# 301402349
# simple functions for adding subtracting and multiplying, as well as a function to check if x < y
	.globl	lt
	.globl	plus
	.globl	minus
	.globl	mul

# x in edi, y in esi

lt: # returns if x is less than y
	xorl	%eax, %eax
	cmpl	%esi, %edi
	setl	%al
	ret

plus:  # performs integer addition
# Requirement:
# - you cannot use add* instruction
	xorl	%eax, %eax	#	zero the return register
	negl	%esi				# y = -y
	movl	%edi, %eax	# move x to return register
	subl	%esi, %eax	# x - (-y)
	ret


minus: # performs integer subtraction
# Requirement:
# - you cannot use sub* instruction
	xorl	%eax, %eax	#	zero the return register
	negl	%esi				# y = -y
	movl	%edi, %eax	# move x to return register
	addl	%esi, %eax	# x + (-y)
	ret

# algorithm:
#	multiplies using repeated addition, the function is called y times and each recursive call adds x to the return value
mul: # performs integer multiplication - when both operands are non-negative!
# x in edi, y in esi
# Requirements:
# - cannot use imul* instruction
# - you must use recursion (no loop) and the stack
  cmpl  $0, %edi    # compare x to 0
  je    zero        # if x = zero jump
  cmpl  $0, %esi    # compare y to 0
  je    zero        # if y = zero jump
  cmpl  $1, %esi    # compare y to 1
  je    base        # y = 1 is base case
  decl  %esi        # decrement y
  call  mul         # recursive call to mul with y - 1
  incl  %esi        # increment y after recursive call returns to preserve original value
  addl  %edi, %eax  # add x to return register
  jmp   return
zero:
  xorl	%eax, %eax	#	zero the return register
  jmp   return      # jump to return (to return 0 in the case that either x or y are 0)
base:
  movl  %edi, %eax  # base case (y = 1) move x to return value
  jmp   return
return:
	ret
