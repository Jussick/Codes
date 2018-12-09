	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	__Z12traverseListP8ListNode ## -- Begin function _Z12traverseListP8ListNode
	.p2align	4, 0x90
__Z12traverseListP8ListNode:            ## @_Z12traverseListP8ListNode
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jne	LBB0_2
## %bb.1:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rsi
	movq	%rax, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rdi
	callq	*-32(%rbp)
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	jmp	LBB0_7
LBB0_2:
	movq	-40(%rbp), %rax
	movq	%rax, -48(%rbp)
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -48(%rbp)
	je	LBB0_6
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=1
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movq	-48(%rbp), %rax
	movl	(%rax), %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	L_.str.1(%rip), %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	%rax, -64(%rbp)         ## 8-byte Spill
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=1
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	jmp	LBB0_3
LBB0_6:
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rax
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	*-16(%rbp)
	movq	%rax, -72(%rbp)         ## 8-byte Spill
LBB0_7:
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc ## -- Begin function _ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.weak_definition	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.p2align	4, 0x90
__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc: ## @_ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movq	-16(%rbp), %rax
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE6lengthEPKc
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	movq	-32(%rbp), %rsi         ## 8-byte Reload
	movq	%rax, %rdx
	callq	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_ ## -- Begin function _ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.globl	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.weak_definition	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
	.p2align	4, 0x90
__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_: ## @_ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_
Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception0
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movq	%rdi, -72(%rbp)
	movq	-72(%rbp), %rdi
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	%rdi, %rcx
	addq	%rax, %rcx
	movq	%rcx, -32(%rbp)
	movb	$10, -33(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-48(%rbp), %rax
	movq	%rdi, -80(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	__ZNKSt3__18ios_base6getlocEv
	movq	-88(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp0:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp1:
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	jmp	LBB2_1
LBB2_1:
	movb	-33(%rbp), %al
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp2:
	movl	%edi, -100(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-100(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -112(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-112(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp3:
	movb	%al, -113(%rbp)         ## 1-byte Spill
	jmp	LBB2_5
LBB2_2:
Ltmp4:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
Ltmp5:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
Ltmp6:
	jmp	LBB2_3
LBB2_3:
	movq	-56(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
LBB2_4:
Ltmp7:
	movq	%rax, %rdi
	movq	%rdx, -128(%rbp)        ## 8-byte Spill
	callq	___clang_call_terminate
LBB2_5:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
	movq	-80(%rbp), %rdi         ## 8-byte Reload
	movb	-113(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE3putEc
	movq	-72(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
	movq	-72(%rbp), %rdi
	movq	%rax, -144(%rbp)        ## 8-byte Spill
	movq	%rdi, %rax
	addq	$144, %rsp
	popq	%rbp
	retq
Lfunc_end0:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table2:
Lexception0:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\274"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	52                      ## Call site table length
Lset0 = Lfunc_begin0-Lfunc_begin0       ## >> Call Site 1 <<
	.long	Lset0
Lset1 = Ltmp0-Lfunc_begin0              ##   Call between Lfunc_begin0 and Ltmp0
	.long	Lset1
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset2 = Ltmp0-Lfunc_begin0              ## >> Call Site 2 <<
	.long	Lset2
Lset3 = Ltmp3-Ltmp0                     ##   Call between Ltmp0 and Ltmp3
	.long	Lset3
Lset4 = Ltmp4-Lfunc_begin0              ##     jumps to Ltmp4
	.long	Lset4
	.byte	0                       ##   On action: cleanup
Lset5 = Ltmp5-Lfunc_begin0              ## >> Call Site 3 <<
	.long	Lset5
Lset6 = Ltmp6-Ltmp5                     ##   Call between Ltmp5 and Ltmp6
	.long	Lset6
Lset7 = Ltmp7-Lfunc_begin0              ##     jumps to Ltmp7
	.long	Lset7
	.byte	1                       ##   On action: 1
Lset8 = Ltmp6-Lfunc_begin0              ## >> Call Site 4 <<
	.long	Lset8
Lset9 = Lfunc_end0-Ltmp6                ##   Call between Ltmp6 and Lfunc_end0
	.long	Lset9
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z15createALinklistPii ## -- Begin function _Z15createALinklistPii
	.p2align	4, 0x90
__Z15createALinklistPii:                ## @_Z15createALinklistPii
Lfunc_begin1:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception1
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -16(%rbp)
	movl	%esi, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jg	LBB3_2
## %bb.1:
	movq	$0, -8(%rbp)
	jmp	LBB3_11
LBB3_2:
	movl	$16, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
	movq	-16(%rbp), %rdx
	movl	(%rdx), %esi
Ltmp8:
	movq	%rdi, -72(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -80(%rbp)         ## 8-byte Spill
	callq	__ZN8ListNodeC1Ei
Ltmp9:
	jmp	LBB3_3
LBB3_3:
	movq	-80(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -56(%rbp)
	movl	$1, -60(%rbp)
LBB3_4:                                 ## =>This Inner Loop Header: Depth=1
	movl	-60(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB3_10
## %bb.5:                               ##   in Loop: Header=BB3_4 Depth=1
	movl	$16, %eax
	movl	%eax, %edi
	callq	__Znwm
	movq	%rax, %rdi
	movq	%rax, %rcx
	movq	-16(%rbp), %rdx
	movslq	-60(%rbp), %rsi
	movl	(%rdx,%rsi,4), %esi
Ltmp11:
	movq	%rdi, -88(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rcx, -96(%rbp)         ## 8-byte Spill
	callq	__ZN8ListNodeC1Ei
Ltmp12:
	jmp	LBB3_6
LBB3_6:                                 ##   in Loop: Header=BB3_4 Depth=1
	movq	-56(%rbp), %rax
	movq	-96(%rbp), %rcx         ## 8-byte Reload
	movq	%rcx, 8(%rax)
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -56(%rbp)
## %bb.7:                               ##   in Loop: Header=BB3_4 Depth=1
	movl	-60(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -60(%rbp)
	jmp	LBB3_4
LBB3_8:
Ltmp10:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movq	-72(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB3_12
LBB3_9:
Ltmp13:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movq	-88(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB3_12
LBB3_10:
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB3_11:
	movq	-8(%rbp), %rax
	addq	$96, %rsp
	popq	%rbp
	retq
LBB3_12:
	movq	-40(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end1:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table3:
Lexception1:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\303\200"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	65                      ## Call site table length
Lset10 = Lfunc_begin1-Lfunc_begin1      ## >> Call Site 1 <<
	.long	Lset10
Lset11 = Ltmp8-Lfunc_begin1             ##   Call between Lfunc_begin1 and Ltmp8
	.long	Lset11
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset12 = Ltmp8-Lfunc_begin1             ## >> Call Site 2 <<
	.long	Lset12
Lset13 = Ltmp9-Ltmp8                    ##   Call between Ltmp8 and Ltmp9
	.long	Lset13
Lset14 = Ltmp10-Lfunc_begin1            ##     jumps to Ltmp10
	.long	Lset14
	.byte	0                       ##   On action: cleanup
Lset15 = Ltmp9-Lfunc_begin1             ## >> Call Site 3 <<
	.long	Lset15
Lset16 = Ltmp11-Ltmp9                   ##   Call between Ltmp9 and Ltmp11
	.long	Lset16
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset17 = Ltmp11-Lfunc_begin1            ## >> Call Site 4 <<
	.long	Lset17
Lset18 = Ltmp12-Ltmp11                  ##   Call between Ltmp11 and Ltmp12
	.long	Lset18
Lset19 = Ltmp13-Lfunc_begin1            ##     jumps to Ltmp13
	.long	Lset19
	.byte	0                       ##   On action: cleanup
Lset20 = Ltmp12-Lfunc_begin1            ## >> Call Site 5 <<
	.long	Lset20
Lset21 = Lfunc_end1-Ltmp12              ##   Call between Ltmp12 and Lfunc_end1
	.long	Lset21
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN8ListNodeC1Ei       ## -- Begin function _ZN8ListNodeC1Ei
	.weak_def_can_be_hidden	__ZN8ListNodeC1Ei
	.p2align	4, 0x90
__ZN8ListNodeC1Ei:                      ## @_ZN8ListNodeC1Ei
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	callq	__ZN8ListNodeC2Ei
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z16destoryALinklistP8ListNode ## -- Begin function _Z16destoryALinklistP8ListNode
	.p2align	4, 0x90
__Z16destoryALinklistP8ListNode:        ## @_Z16destoryALinklistP8ListNode
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	LBB5_2
## %bb.1:
	jmp	LBB5_8
LBB5_2:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
LBB5_3:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -16(%rbp)
	je	LBB5_7
## %bb.4:                               ##   in Loop: Header=BB5_3 Depth=1
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	cmpq	$0, %rax
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	je	LBB5_6
## %bb.5:                               ##   in Loop: Header=BB5_3 Depth=1
	movq	-32(%rbp), %rax         ## 8-byte Reload
	movq	%rax, %rdi
	callq	__ZdlPv
LBB5_6:                                 ##   in Loop: Header=BB5_3 Depth=1
	jmp	LBB5_3
LBB5_7:
	jmp	LBB5_8
LBB5_8:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z16addOneNodeToTailiPP8ListNode ## -- Begin function _Z16addOneNodeToTailiPP8ListNode
	.p2align	4, 0x90
__Z16addOneNodeToTailiPP8ListNode:      ## @_Z16addOneNodeToTailiPP8ListNode
Lfunc_begin2:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception2
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	(%rsi), %rsi
	movq	%rsi, -24(%rbp)
	movl	$16, %edi
                                        ## kill: def %rdi killed %edi
	callq	__Znwm
	movq	%rax, %rsi
	movq	%rax, %rdi
	movl	-8(%rbp), %ecx
Ltmp14:
	movq	%rdi, -56(%rbp)         ## 8-byte Spill
	movq	%rax, %rdi
	movq	%rsi, -64(%rbp)         ## 8-byte Spill
	movl	%ecx, %esi
	callq	__ZN8ListNodeC1Ei
Ltmp15:
	jmp	LBB6_1
LBB6_1:
	movq	-56(%rbp), %rax         ## 8-byte Reload
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB6_4
## %bb.2:
	movb	$0, -1(%rbp)
	jmp	LBB6_11
LBB6_3:
Ltmp16:
	movl	%edx, %ecx
	movq	%rax, -40(%rbp)
	movl	%ecx, -44(%rbp)
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	callq	__ZdlPv
	jmp	LBB6_12
LBB6_4:
	cmpq	$0, -24(%rbp)
	jne	LBB6_6
## %bb.5:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	%rax, (%rcx)
	jmp	LBB6_10
LBB6_6:
	jmp	LBB6_7
LBB6_7:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB6_9
## %bb.8:                               ##   in Loop: Header=BB6_7 Depth=1
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	LBB6_7
LBB6_9:
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, 8(%rcx)
LBB6_10:
	movb	$1, -1(%rbp)
LBB6_11:
	movb	-1(%rbp), %al
	andb	$1, %al
	movzbl	%al, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
LBB6_12:
	movq	-40(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
Lfunc_end2:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table6:
Lexception2:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.byte	41                      ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	39                      ## Call site table length
Lset22 = Lfunc_begin2-Lfunc_begin2      ## >> Call Site 1 <<
	.long	Lset22
Lset23 = Ltmp14-Lfunc_begin2            ##   Call between Lfunc_begin2 and Ltmp14
	.long	Lset23
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset24 = Ltmp14-Lfunc_begin2            ## >> Call Site 2 <<
	.long	Lset24
Lset25 = Ltmp15-Ltmp14                  ##   Call between Ltmp14 and Ltmp15
	.long	Lset25
Lset26 = Ltmp16-Lfunc_begin2            ##     jumps to Ltmp16
	.long	Lset26
	.byte	0                       ##   On action: cleanup
Lset27 = Ltmp15-Lfunc_begin2            ## >> Call Site 3 <<
	.long	Lset27
Lset28 = Lfunc_end2-Ltmp15              ##   Call between Ltmp15 and Lfunc_end2
	.long	Lset28
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z13mergeTwoListsP8ListNodeS0_ ## -- Begin function _Z13mergeTwoListsP8ListNodeS0_
	.p2align	4, 0x90
__Z13mergeTwoListsP8ListNodeS0_:        ## @_Z13mergeTwoListsP8ListNodeS0_
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movq	%rdi, -48(%rbp)
	movq	%rsi, -56(%rbp)
	movq	-48(%rbp), %rsi
	movq	%rsi, -64(%rbp)
	movq	-56(%rbp), %rsi
	movq	%rsi, -72(%rbp)
	movq	$0, -80(%rbp)
	cmpq	$0, -64(%rbp)
	jne	LBB7_3
## %bb.1:
	cmpq	$0, -72(%rbp)
	je	LBB7_3
## %bb.2:
	movq	-72(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB7_31
LBB7_3:
	cmpq	$0, -72(%rbp)
	jne	LBB7_6
## %bb.4:
	cmpq	$0, -64(%rbp)
	je	LBB7_6
## %bb.5:
	movq	-64(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB7_31
LBB7_6:
	cmpq	$0, -64(%rbp)
	jne	LBB7_9
## %bb.7:
	cmpq	$0, -72(%rbp)
	jne	LBB7_9
## %bb.8:
	movq	$0, -40(%rbp)
	jmp	LBB7_31
LBB7_9:
	jmp	LBB7_10
LBB7_10:                                ## =>This Inner Loop Header: Depth=1
	movb	$1, %al
	cmpq	$0, -64(%rbp)
	movb	%al, -81(%rbp)          ## 1-byte Spill
	jne	LBB7_12
## %bb.11:                              ##   in Loop: Header=BB7_10 Depth=1
	cmpq	$0, -72(%rbp)
	setne	%al
	movb	%al, -81(%rbp)          ## 1-byte Spill
LBB7_12:                                ##   in Loop: Header=BB7_10 Depth=1
	movb	-81(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB7_13
	jmp	LBB7_30
LBB7_13:                                ##   in Loop: Header=BB7_10 Depth=1
	cmpq	$0, -64(%rbp)
	jne	LBB7_19
## %bb.14:
	jmp	LBB7_15
LBB7_15:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -72(%rbp)
	je	LBB7_18
## %bb.16:                              ##   in Loop: Header=BB7_15 Depth=1
	leaq	-80(%rbp), %rsi
	movq	-72(%rbp), %rax
	movl	(%rax), %edi
	callq	__Z16addOneNodeToTailiPP8ListNode
	movb	%al, -82(%rbp)          ## 1-byte Spill
## %bb.17:                              ##   in Loop: Header=BB7_15 Depth=1
	movq	-72(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -72(%rbp)
	jmp	LBB7_15
LBB7_18:
	movq	-80(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB7_31
LBB7_19:                                ##   in Loop: Header=BB7_10 Depth=1
	cmpq	$0, -72(%rbp)
	jne	LBB7_25
## %bb.20:
	jmp	LBB7_21
LBB7_21:                                ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -64(%rbp)
	je	LBB7_24
## %bb.22:                              ##   in Loop: Header=BB7_21 Depth=1
	leaq	-80(%rbp), %rsi
	movq	-64(%rbp), %rax
	movl	(%rax), %edi
	callq	__Z16addOneNodeToTailiPP8ListNode
	movb	%al, -83(%rbp)          ## 1-byte Spill
## %bb.23:                              ##   in Loop: Header=BB7_21 Depth=1
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -64(%rbp)
	jmp	LBB7_21
LBB7_24:
	movq	-80(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB7_31
LBB7_25:                                ##   in Loop: Header=BB7_10 Depth=1
	jmp	LBB7_26
LBB7_26:                                ##   in Loop: Header=BB7_10 Depth=1
	movq	-64(%rbp), %rax
	movl	(%rax), %ecx
	movq	-72(%rbp), %rax
	cmpl	(%rax), %ecx
	jg	LBB7_28
## %bb.27:                              ##   in Loop: Header=BB7_10 Depth=1
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.2(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	-64(%rbp), %rsi
	movl	(%rsi), %esi
	movq	%rax, %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rdi
	movq	%rax, -24(%rbp)
	movq	%rdi, -32(%rbp)
	movq	-24(%rbp), %rdi
	callq	*-32(%rbp)
	leaq	-80(%rbp), %rsi
	movq	-64(%rbp), %rdi
	movl	(%rdi), %edi
	movq	%rax, -96(%rbp)         ## 8-byte Spill
	callq	__Z16addOneNodeToTailiPP8ListNode
	movq	-64(%rbp), %rsi
	movq	8(%rsi), %rsi
	movq	%rsi, -64(%rbp)
	movb	%al, -97(%rbp)          ## 1-byte Spill
	jmp	LBB7_29
LBB7_28:                                ##   in Loop: Header=BB7_10 Depth=1
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.3(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	-72(%rbp), %rsi
	movl	(%rsi), %esi
	movq	%rax, %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	leaq	__ZNSt3__14endlIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_(%rip), %rdi
	movq	%rax, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	-8(%rbp), %rdi
	callq	*-16(%rbp)
	leaq	-80(%rbp), %rsi
	movq	-72(%rbp), %rdi
	movl	(%rdi), %edi
	movq	%rax, -112(%rbp)        ## 8-byte Spill
	callq	__Z16addOneNodeToTailiPP8ListNode
	movq	-72(%rbp), %rsi
	movq	8(%rsi), %rsi
	movq	%rsi, -72(%rbp)
	movb	%al, -113(%rbp)         ## 1-byte Spill
LBB7_29:                                ##   in Loop: Header=BB7_10 Depth=1
	jmp	LBB7_10
LBB7_30:
	movq	-80(%rbp), %rax
	movq	%rax, -40(%rbp)
LBB7_31:
	movq	-40(%rbp), %rax
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$144, %rsp
	movl	$5, %esi
	leaq	-32(%rbp), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -68(%rbp)
	movq	l__ZZ4mainE4arr1(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	l__ZZ4mainE4arr1+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	l__ZZ4mainE4arr1+16(%rip), %ecx
	movl	%ecx, -16(%rbp)
	movq	l__ZZ4mainE4arr2(%rip), %rax
	movq	%rax, -64(%rbp)
	movq	l__ZZ4mainE4arr2+8(%rip), %rax
	movq	%rax, -56(%rbp)
	movl	l__ZZ4mainE4arr2+16(%rip), %ecx
	movl	%ecx, -48(%rbp)
	callq	__Z15createALinklistPii
	movl	$5, %esi
	leaq	-64(%rbp), %rdi
	movq	%rax, -80(%rbp)
	callq	__Z15createALinklistPii
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.4(%rip), %rsi
	movq	%rax, -88(%rbp)
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	-80(%rbp), %rdi
	movq	%rax, -120(%rbp)        ## 8-byte Spill
	callq	__Z12traverseListP8ListNode
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.5(%rip), %rsi
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	-88(%rbp), %rdi
	movq	%rax, -128(%rbp)        ## 8-byte Spill
	callq	__Z12traverseListP8ListNode
	movq	-80(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -104(%rbp)
	movq	-80(%rbp), %rdi
	movq	-88(%rbp), %rsi
	callq	__Z13mergeTwoListsP8ListNodeS0_
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	leaq	L_.str.6(%rip), %rsi
	movq	%rax, -112(%rbp)
	callq	__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc
	movq	-112(%rbp), %rdi
	movq	%rax, -136(%rbp)        ## 8-byte Spill
	callq	__Z12traverseListP8ListNode
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rsi
	cmpq	%rsi, %rax
	jne	LBB8_2
## %bb.1:
	xorl	%eax, %eax
	addq	$144, %rsp
	popq	%rbp
	retq
LBB8_2:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	__ZN8ListNodeC2Ei       ## -- Begin function _ZN8ListNodeC2Ei
	.weak_def_can_be_hidden	__ZN8ListNodeC2Ei
	.p2align	4, 0x90
__ZN8ListNodeC2Ei:                      ## @_ZN8ListNodeC2Ei
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	-12(%rbp), %esi
	movl	%esi, (%rdi)
	movq	$0, 8(%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m ## -- Begin function _ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.weak_definition	__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
	.p2align	4, 0x90
__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m: ## @_ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
Lfunc_begin3:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception3
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$416, %rsp              ## imm = 0x1A0
	movq	%rdi, -200(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%rdx, -216(%rbp)
	movq	-200(%rbp), %rsi
Ltmp17:
	leaq	-232(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
Ltmp18:
	jmp	LBB10_1
LBB10_1:
	leaq	-232(%rbp), %rax
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movb	(%rax), %cl
	movb	%cl, -265(%rbp)         ## 1-byte Spill
## %bb.2:
	movb	-265(%rbp), %al         ## 1-byte Reload
	testb	$1, %al
	jne	LBB10_3
	jmp	LBB10_26
LBB10_3:
	leaq	-256(%rbp), %rax
	movq	-200(%rbp), %rcx
	movq	%rax, -176(%rbp)
	movq	%rcx, -184(%rbp)
	movq	-176(%rbp), %rax
	movq	-184(%rbp), %rcx
	movq	%rax, -144(%rbp)
	movq	%rcx, -152(%rbp)
	movq	-144(%rbp), %rax
	movq	-152(%rbp), %rcx
	movq	(%rcx), %rdx
	movq	-24(%rdx), %rdx
	addq	%rdx, %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	40(%rcx), %rcx
	movq	%rcx, (%rax)
	movq	-208(%rbp), %rsi
	movq	-200(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movl	8(%rax), %edi
	movq	%rsi, -280(%rbp)        ## 8-byte Spill
	movl	%edi, -284(%rbp)        ## 4-byte Spill
## %bb.4:
	movl	-284(%rbp), %eax        ## 4-byte Reload
	andl	$176, %eax
	cmpl	$32, %eax
	jne	LBB10_6
## %bb.5:
	movq	-208(%rbp), %rax
	addq	-216(%rbp), %rax
	movq	%rax, -296(%rbp)        ## 8-byte Spill
	jmp	LBB10_7
LBB10_6:
	movq	-208(%rbp), %rax
	movq	%rax, -296(%rbp)        ## 8-byte Spill
LBB10_7:
	movq	-296(%rbp), %rax        ## 8-byte Reload
	movq	-208(%rbp), %rcx
	addq	-216(%rbp), %rcx
	movq	-200(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	-24(%rsi), %rsi
	addq	%rsi, %rdx
	movq	-200(%rbp), %rsi
	movq	(%rsi), %rdi
	movq	-24(%rdi), %rdi
	addq	%rdi, %rsi
	movq	%rsi, -72(%rbp)
	movq	-72(%rbp), %rsi
	movq	%rax, -304(%rbp)        ## 8-byte Spill
	movq	%rcx, -312(%rbp)        ## 8-byte Spill
	movq	%rdx, -320(%rbp)        ## 8-byte Spill
	movq	%rsi, -328(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__111char_traitsIcE3eofEv
	movq	-328(%rbp), %rcx        ## 8-byte Reload
	movl	144(%rcx), %esi
	movl	%eax, %edi
	callq	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	testb	$1, %al
	jne	LBB10_8
	jmp	LBB10_16
LBB10_8:
	movq	-328(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -32(%rbp)
	movb	$32, -33(%rbp)
	movq	-32(%rbp), %rsi
Ltmp19:
	leaq	-48(%rbp), %rdi
	callq	__ZNKSt3__18ios_base6getlocEv
Ltmp20:
	jmp	LBB10_9
LBB10_9:
	leaq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
Ltmp21:
	movq	__ZNSt3__15ctypeIcE2idE@GOTPCREL(%rip), %rsi
	callq	__ZNKSt3__16locale9use_facetERNS0_2idE
Ltmp22:
	movq	%rax, -336(%rbp)        ## 8-byte Spill
	jmp	LBB10_10
LBB10_10:
	movb	-33(%rbp), %al
	movq	-336(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -8(%rbp)
	movb	%al, -9(%rbp)
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rsi
	movq	56(%rsi), %rsi
	movsbl	-9(%rbp), %edi
Ltmp23:
	movl	%edi, -340(%rbp)        ## 4-byte Spill
	movq	%rdx, %rdi
	movl	-340(%rbp), %r8d        ## 4-byte Reload
	movq	%rsi, -352(%rbp)        ## 8-byte Spill
	movl	%r8d, %esi
	movq	-352(%rbp), %rdx        ## 8-byte Reload
	callq	*%rdx
Ltmp24:
	movb	%al, -353(%rbp)         ## 1-byte Spill
	jmp	LBB10_14
LBB10_11:
Ltmp25:
	movl	%edx, %ecx
	movq	%rax, -56(%rbp)
	movl	%ecx, -60(%rbp)
Ltmp26:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
Ltmp27:
	jmp	LBB10_12
LBB10_12:
	movq	-56(%rbp), %rax
	movl	-60(%rbp), %ecx
	movq	%rax, -368(%rbp)        ## 8-byte Spill
	movl	%ecx, -372(%rbp)        ## 4-byte Spill
	jmp	LBB10_24
LBB10_13:
Ltmp28:
	movq	%rax, %rdi
	movq	%rdx, -384(%rbp)        ## 8-byte Spill
	callq	___clang_call_terminate
LBB10_14:
Ltmp29:
	leaq	-48(%rbp), %rdi
	callq	__ZNSt3__16localeD1Ev
Ltmp30:
	jmp	LBB10_15
LBB10_15:
	movb	-353(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %ecx
	movq	-328(%rbp), %rdx        ## 8-byte Reload
	movl	%ecx, 144(%rdx)
LBB10_16:
	movq	-328(%rbp), %rax        ## 8-byte Reload
	movl	144(%rax), %ecx
	movb	%cl, %dl
	movb	%dl, -385(%rbp)         ## 1-byte Spill
## %bb.17:
	movq	-256(%rbp), %rdi
Ltmp31:
	movb	-385(%rbp), %al         ## 1-byte Reload
	movsbl	%al, %r9d
	movq	-280(%rbp), %rsi        ## 8-byte Reload
	movq	-304(%rbp), %rdx        ## 8-byte Reload
	movq	-312(%rbp), %rcx        ## 8-byte Reload
	movq	-320(%rbp), %r8         ## 8-byte Reload
	callq	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Ltmp32:
	movq	%rax, -400(%rbp)        ## 8-byte Spill
	jmp	LBB10_18
LBB10_18:
	leaq	-264(%rbp), %rax
	movq	-400(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -264(%rbp)
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB10_25
## %bb.19:
	movq	-200(%rbp), %rax
	movq	(%rax), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rax
	movq	%rax, -112(%rbp)
	movl	$5, -116(%rbp)
	movq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movq	%rax, -96(%rbp)
	movl	%edx, -100(%rbp)
	movq	-96(%rbp), %rax
	movl	32(%rax), %edx
	movl	-100(%rbp), %esi
	orl	%esi, %edx
Ltmp33:
	movq	%rax, %rdi
	movl	%edx, %esi
	callq	__ZNSt3__18ios_base5clearEj
Ltmp34:
	jmp	LBB10_20
LBB10_20:
	jmp	LBB10_21
LBB10_21:
	jmp	LBB10_25
LBB10_22:
Ltmp40:
	movl	%edx, %ecx
	movq	%rax, -240(%rbp)
	movl	%ecx, -244(%rbp)
	jmp	LBB10_29
LBB10_23:
Ltmp35:
	movl	%edx, %ecx
	movq	%rax, -368(%rbp)        ## 8-byte Spill
	movl	%ecx, -372(%rbp)        ## 4-byte Spill
	jmp	LBB10_24
LBB10_24:
	movl	-372(%rbp), %eax        ## 4-byte Reload
	movq	-368(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -240(%rbp)
	movl	%eax, -244(%rbp)
Ltmp36:
	leaq	-232(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp37:
	jmp	LBB10_28
LBB10_25:
	jmp	LBB10_26
LBB10_26:
Ltmp38:
	leaq	-232(%rbp), %rdi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
Ltmp39:
	jmp	LBB10_27
LBB10_27:
	jmp	LBB10_31
LBB10_28:
	jmp	LBB10_29
LBB10_29:
	movq	-240(%rbp), %rdi
	callq	___cxa_begin_catch
	movq	-200(%rbp), %rdi
	movq	(%rdi), %rcx
	movq	-24(%rcx), %rcx
	addq	%rcx, %rdi
Ltmp41:
	movq	%rax, -408(%rbp)        ## 8-byte Spill
	callq	__ZNSt3__18ios_base33__set_badbit_and_consider_rethrowEv
Ltmp42:
	jmp	LBB10_30
LBB10_30:
	callq	___cxa_end_catch
LBB10_31:
	movq	-200(%rbp), %rax
	addq	$416, %rsp              ## imm = 0x1A0
	popq	%rbp
	retq
LBB10_32:
Ltmp43:
	movl	%edx, %ecx
	movq	%rax, -240(%rbp)
	movl	%ecx, -244(%rbp)
Ltmp44:
	callq	___cxa_end_catch
Ltmp45:
	jmp	LBB10_33
LBB10_33:
	jmp	LBB10_34
LBB10_34:
	movq	-240(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
LBB10_35:
Ltmp46:
	movq	%rax, %rdi
	movq	%rdx, -416(%rbp)        ## 8-byte Spill
	callq	___clang_call_terminate
Lfunc_end3:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table10:
Lexception3:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\253\201"              ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.ascii	"\234\001"              ## Call site table length
Lset29 = Ltmp17-Lfunc_begin3            ## >> Call Site 1 <<
	.long	Lset29
Lset30 = Ltmp18-Ltmp17                  ##   Call between Ltmp17 and Ltmp18
	.long	Lset30
Lset31 = Ltmp40-Lfunc_begin3            ##     jumps to Ltmp40
	.long	Lset31
	.byte	5                       ##   On action: 3
Lset32 = Ltmp19-Lfunc_begin3            ## >> Call Site 2 <<
	.long	Lset32
Lset33 = Ltmp20-Ltmp19                  ##   Call between Ltmp19 and Ltmp20
	.long	Lset33
Lset34 = Ltmp35-Lfunc_begin3            ##     jumps to Ltmp35
	.long	Lset34
	.byte	5                       ##   On action: 3
Lset35 = Ltmp21-Lfunc_begin3            ## >> Call Site 3 <<
	.long	Lset35
Lset36 = Ltmp24-Ltmp21                  ##   Call between Ltmp21 and Ltmp24
	.long	Lset36
Lset37 = Ltmp25-Lfunc_begin3            ##     jumps to Ltmp25
	.long	Lset37
	.byte	3                       ##   On action: 2
Lset38 = Ltmp26-Lfunc_begin3            ## >> Call Site 4 <<
	.long	Lset38
Lset39 = Ltmp27-Ltmp26                  ##   Call between Ltmp26 and Ltmp27
	.long	Lset39
Lset40 = Ltmp28-Lfunc_begin3            ##     jumps to Ltmp28
	.long	Lset40
	.byte	7                       ##   On action: 4
Lset41 = Ltmp29-Lfunc_begin3            ## >> Call Site 5 <<
	.long	Lset41
Lset42 = Ltmp34-Ltmp29                  ##   Call between Ltmp29 and Ltmp34
	.long	Lset42
Lset43 = Ltmp35-Lfunc_begin3            ##     jumps to Ltmp35
	.long	Lset43
	.byte	5                       ##   On action: 3
Lset44 = Ltmp36-Lfunc_begin3            ## >> Call Site 6 <<
	.long	Lset44
Lset45 = Ltmp37-Ltmp36                  ##   Call between Ltmp36 and Ltmp37
	.long	Lset45
Lset46 = Ltmp46-Lfunc_begin3            ##     jumps to Ltmp46
	.long	Lset46
	.byte	5                       ##   On action: 3
Lset47 = Ltmp38-Lfunc_begin3            ## >> Call Site 7 <<
	.long	Lset47
Lset48 = Ltmp39-Ltmp38                  ##   Call between Ltmp38 and Ltmp39
	.long	Lset48
Lset49 = Ltmp40-Lfunc_begin3            ##     jumps to Ltmp40
	.long	Lset49
	.byte	5                       ##   On action: 3
Lset50 = Ltmp39-Lfunc_begin3            ## >> Call Site 8 <<
	.long	Lset50
Lset51 = Ltmp41-Ltmp39                  ##   Call between Ltmp39 and Ltmp41
	.long	Lset51
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset52 = Ltmp41-Lfunc_begin3            ## >> Call Site 9 <<
	.long	Lset52
Lset53 = Ltmp42-Ltmp41                  ##   Call between Ltmp41 and Ltmp42
	.long	Lset53
Lset54 = Ltmp43-Lfunc_begin3            ##     jumps to Ltmp43
	.long	Lset54
	.byte	0                       ##   On action: cleanup
Lset55 = Ltmp42-Lfunc_begin3            ## >> Call Site 10 <<
	.long	Lset55
Lset56 = Ltmp44-Ltmp42                  ##   Call between Ltmp42 and Ltmp44
	.long	Lset56
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset57 = Ltmp44-Lfunc_begin3            ## >> Call Site 11 <<
	.long	Lset57
Lset58 = Ltmp45-Ltmp44                  ##   Call between Ltmp44 and Ltmp45
	.long	Lset58
Lset59 = Ltmp46-Lfunc_begin3            ##     jumps to Ltmp46
	.long	Lset59
	.byte	5                       ##   On action: 3
Lset60 = Ltmp45-Lfunc_begin3            ## >> Call Site 12 <<
	.long	Lset60
Lset61 = Lfunc_end3-Ltmp45              ##   Call between Ltmp45 and Lfunc_end3
	.long	Lset61
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	0                       ## >> Action Record 1 <<
                                        ##   Cleanup
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 2 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 1
	.byte	1                       ## >> Action Record 3 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
	.byte	1                       ## >> Action Record 4 <<
                                        ##   Catch TypeInfo 1
	.byte	125                     ##   Continue to action 3
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZNSt3__111char_traitsIcE6lengthEPKc ## -- Begin function _ZNSt3__111char_traitsIcE6lengthEPKc
	.weak_definition	__ZNSt3__111char_traitsIcE6lengthEPKc
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE6lengthEPKc:  ## @_ZNSt3__111char_traitsIcE6lengthEPKc
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_strlen
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.private_extern	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_ ## -- Begin function _ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.globl	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.weak_definition	__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
	.p2align	4, 0x90
__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_: ## @_ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_
Lfunc_begin4:
	.cfi_startproc
	.cfi_personality 155, ___gxx_personality_v0
	.cfi_lsda 16, Lexception4
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$736, %rsp              ## imm = 0x2E0
	movb	%r9b, %al
	leaq	-560(%rbp), %r10
	leaq	-496(%rbp), %r11
	movq	%rdi, -512(%rbp)
	movq	%rsi, -520(%rbp)
	movq	%rdx, -528(%rbp)
	movq	%rcx, -536(%rbp)
	movq	%r8, -544(%rbp)
	movb	%al, -545(%rbp)
	movq	-512(%rbp), %rcx
	movq	%r11, -480(%rbp)
	movq	$-1, -488(%rbp)
	movq	-480(%rbp), %rdx
	movq	-488(%rbp), %rsi
	movq	%rdx, -464(%rbp)
	movq	%rsi, -472(%rbp)
	movq	-464(%rbp), %rdx
	movq	$0, (%rdx)
	movq	-496(%rbp), %rdx
	movq	%rdx, -560(%rbp)
	movq	%r10, -456(%rbp)
	cmpq	$0, %rcx
	jne	LBB12_2
## %bb.1:
	movq	-512(%rbp), %rax
	movq	%rax, -504(%rbp)
	jmp	LBB12_29
LBB12_2:
	movq	-536(%rbp), %rax
	movq	-520(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -568(%rbp)
	movq	-544(%rbp), %rax
	movq	%rax, -352(%rbp)
	movq	-352(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -576(%rbp)
	movq	-576(%rbp), %rax
	cmpq	-568(%rbp), %rax
	jle	LBB12_4
## %bb.3:
	movq	-568(%rbp), %rax
	movq	-576(%rbp), %rcx
	subq	%rax, %rcx
	movq	%rcx, -576(%rbp)
	jmp	LBB12_5
LBB12_4:
	movq	$0, -576(%rbp)
LBB12_5:
	movq	-528(%rbp), %rax
	movq	-520(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -584(%rbp)
	cmpq	$0, -584(%rbp)
	jle	LBB12_9
## %bb.6:
	movq	-512(%rbp), %rax
	movq	-520(%rbp), %rcx
	movq	-584(%rbp), %rdx
	movq	%rax, -256(%rbp)
	movq	%rcx, -264(%rbp)
	movq	%rdx, -272(%rbp)
	movq	-256(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-264(%rbp), %rsi
	movq	-272(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-584(%rbp), %rax
	je	LBB12_8
## %bb.7:
	leaq	-592(%rbp), %rax
	leaq	-248(%rbp), %rcx
	movq	%rcx, -232(%rbp)
	movq	$-1, -240(%rbp)
	movq	-232(%rbp), %rcx
	movq	-240(%rbp), %rdx
	movq	%rcx, -216(%rbp)
	movq	%rdx, -224(%rbp)
	movq	-216(%rbp), %rcx
	movq	$0, (%rcx)
	movq	-248(%rbp), %rcx
	movq	%rcx, -592(%rbp)
	movq	%rax, -8(%rbp)
	movq	$0, -512(%rbp)
	movq	-512(%rbp), %rax
	movq	%rax, -504(%rbp)
	jmp	LBB12_29
LBB12_8:
	jmp	LBB12_9
LBB12_9:
	cmpq	$0, -576(%rbp)
	jle	LBB12_24
## %bb.10:
	xorl	%esi, %esi
	movl	$24, %eax
	movl	%eax, %edx
	leaq	-616(%rbp), %rcx
	movq	-576(%rbp), %rdi
	movb	-545(%rbp), %r8b
	movq	%rcx, -80(%rbp)
	movq	%rdi, -88(%rbp)
	movb	%r8b, -89(%rbp)
	movq	-80(%rbp), %rcx
	movq	-88(%rbp), %rdi
	movb	-89(%rbp), %r8b
	movq	%rcx, -56(%rbp)
	movq	%rdi, -64(%rbp)
	movb	%r8b, -65(%rbp)
	movq	-56(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rdi
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	%rdi, %r9
	movq	%r9, -32(%rbp)
	movq	-32(%rbp), %r9
	movq	%rdi, -664(%rbp)        ## 8-byte Spill
	movq	%r9, %rdi
	movq	%rcx, -672(%rbp)        ## 8-byte Spill
	callq	_memset
	movq	-664(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	%rcx, -16(%rbp)
	movq	-64(%rbp), %rsi
	movq	-672(%rbp), %rdi        ## 8-byte Reload
	movsbl	-65(%rbp), %edx
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
	leaq	-616(%rbp), %rcx
	movq	-512(%rbp), %rsi
	movq	%rcx, -208(%rbp)
	movq	-208(%rbp), %rcx
	movq	%rcx, -200(%rbp)
	movq	-200(%rbp), %rcx
	movq	%rcx, -192(%rbp)
	movq	-192(%rbp), %rdi
	movq	%rdi, -184(%rbp)
	movq	-184(%rbp), %rdi
	movq	%rdi, -176(%rbp)
	movq	-176(%rbp), %rdi
	movzbl	(%rdi), %eax
	movl	%eax, %edi
	andq	$1, %rdi
	cmpq	$0, %rdi
	movq	%rsi, -680(%rbp)        ## 8-byte Spill
	movq	%rcx, -688(%rbp)        ## 8-byte Spill
	je	LBB12_12
## %bb.11:
	movq	-688(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -128(%rbp)
	movq	-128(%rbp), %rcx
	movq	%rcx, -120(%rbp)
	movq	-120(%rbp), %rcx
	movq	%rcx, -112(%rbp)
	movq	-112(%rbp), %rcx
	movq	16(%rcx), %rcx
	movq	%rcx, -696(%rbp)        ## 8-byte Spill
	jmp	LBB12_13
LBB12_12:
	movq	-688(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rcx
	movq	%rcx, -160(%rbp)
	movq	-160(%rbp), %rcx
	movq	%rcx, -152(%rbp)
	movq	-152(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -144(%rbp)
	movq	-144(%rbp), %rcx
	movq	%rcx, -136(%rbp)
	movq	-136(%rbp), %rcx
	movq	%rcx, -696(%rbp)        ## 8-byte Spill
LBB12_13:
	movq	-696(%rbp), %rax        ## 8-byte Reload
	movq	%rax, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	-576(%rbp), %rcx
	movq	-680(%rbp), %rdx        ## 8-byte Reload
	movq	%rdx, -280(%rbp)
	movq	%rax, -288(%rbp)
	movq	%rcx, -296(%rbp)
	movq	-280(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-288(%rbp), %rsi
	movq	-296(%rbp), %rdx
Ltmp47:
	movq	%rax, %rdi
	callq	*%rcx
Ltmp48:
	movq	%rax, -704(%rbp)        ## 8-byte Spill
	jmp	LBB12_14
LBB12_14:
	jmp	LBB12_15
LBB12_15:
	movq	-704(%rbp), %rax        ## 8-byte Reload
	cmpq	-576(%rbp), %rax
	je	LBB12_20
## %bb.16:
	leaq	-336(%rbp), %rax
	movq	%rax, -320(%rbp)
	movq	$-1, -328(%rbp)
	movq	-320(%rbp), %rax
	movq	-328(%rbp), %rcx
	movq	%rax, -304(%rbp)
	movq	%rcx, -312(%rbp)
	movq	-304(%rbp), %rax
	movq	$0, (%rax)
	movq	-336(%rbp), %rax
	movq	%rax, -712(%rbp)        ## 8-byte Spill
## %bb.17:
	leaq	-640(%rbp), %rax
	movq	-712(%rbp), %rcx        ## 8-byte Reload
	movq	%rcx, -640(%rbp)
	movq	%rax, -344(%rbp)
## %bb.18:
	movq	$0, -512(%rbp)
	movq	-512(%rbp), %rax
	movq	%rax, -504(%rbp)
	movl	$1, -644(%rbp)
	jmp	LBB12_21
LBB12_19:
Ltmp49:
	movl	%edx, %ecx
	movq	%rax, -624(%rbp)
	movl	%ecx, -628(%rbp)
Ltmp50:
	leaq	-616(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
Ltmp51:
	jmp	LBB12_23
LBB12_20:
	movl	$0, -644(%rbp)
LBB12_21:
	leaq	-616(%rbp), %rdi
	callq	__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
	movl	-644(%rbp), %eax
	testl	%eax, %eax
	movl	%eax, -716(%rbp)        ## 4-byte Spill
	je	LBB12_22
	jmp	LBB12_33
LBB12_33:
	movl	-716(%rbp), %eax        ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -720(%rbp)        ## 4-byte Spill
	je	LBB12_29
	jmp	LBB12_32
LBB12_22:
	jmp	LBB12_24
LBB12_23:
	jmp	LBB12_30
LBB12_24:
	movq	-536(%rbp), %rax
	movq	-528(%rbp), %rcx
	subq	%rcx, %rax
	movq	%rax, -584(%rbp)
	cmpq	$0, -584(%rbp)
	jle	LBB12_28
## %bb.25:
	movq	-512(%rbp), %rax
	movq	-528(%rbp), %rcx
	movq	-584(%rbp), %rdx
	movq	%rax, -360(%rbp)
	movq	%rcx, -368(%rbp)
	movq	%rdx, -376(%rbp)
	movq	-360(%rbp), %rax
	movq	(%rax), %rcx
	movq	96(%rcx), %rcx
	movq	-368(%rbp), %rsi
	movq	-376(%rbp), %rdx
	movq	%rax, %rdi
	callq	*%rcx
	cmpq	-584(%rbp), %rax
	je	LBB12_27
## %bb.26:
	leaq	-656(%rbp), %rax
	leaq	-416(%rbp), %rcx
	movq	%rcx, -400(%rbp)
	movq	$-1, -408(%rbp)
	movq	-400(%rbp), %rcx
	movq	-408(%rbp), %rdx
	movq	%rcx, -384(%rbp)
	movq	%rdx, -392(%rbp)
	movq	-384(%rbp), %rcx
	movq	$0, (%rcx)
	movq	-416(%rbp), %rcx
	movq	%rcx, -656(%rbp)
	movq	%rax, -424(%rbp)
	movq	$0, -512(%rbp)
	movq	-512(%rbp), %rax
	movq	%rax, -504(%rbp)
	jmp	LBB12_29
LBB12_27:
	jmp	LBB12_28
LBB12_28:
	movq	-544(%rbp), %rax
	movq	%rax, -432(%rbp)
	movq	$0, -440(%rbp)
	movq	-432(%rbp), %rax
	movq	24(%rax), %rcx
	movq	%rcx, -448(%rbp)
	movq	-440(%rbp), %rcx
	movq	%rcx, 24(%rax)
	movq	-512(%rbp), %rax
	movq	%rax, -504(%rbp)
LBB12_29:
	movq	-504(%rbp), %rax
	addq	$736, %rsp              ## imm = 0x2E0
	popq	%rbp
	retq
LBB12_30:
	movq	-624(%rbp), %rdi
	callq	__Unwind_Resume
	ud2
LBB12_31:
Ltmp52:
	movq	%rax, %rdi
	movq	%rdx, -728(%rbp)        ## 8-byte Spill
	callq	___clang_call_terminate
LBB12_32:
	ud2
Lfunc_end4:
	.cfi_endproc
	.section	__TEXT,__gcc_except_tab
	.p2align	2
GCC_except_table12:
Lexception4:
	.byte	255                     ## @LPStart Encoding = omit
	.byte	155                     ## @TType Encoding = indirect pcrel sdata4
	.asciz	"\274"                  ## @TType base offset
	.byte	3                       ## Call site Encoding = udata4
	.byte	52                      ## Call site table length
Lset62 = Lfunc_begin4-Lfunc_begin4      ## >> Call Site 1 <<
	.long	Lset62
Lset63 = Ltmp47-Lfunc_begin4            ##   Call between Lfunc_begin4 and Ltmp47
	.long	Lset63
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
Lset64 = Ltmp47-Lfunc_begin4            ## >> Call Site 2 <<
	.long	Lset64
Lset65 = Ltmp48-Ltmp47                  ##   Call between Ltmp47 and Ltmp48
	.long	Lset65
Lset66 = Ltmp49-Lfunc_begin4            ##     jumps to Ltmp49
	.long	Lset66
	.byte	0                       ##   On action: cleanup
Lset67 = Ltmp50-Lfunc_begin4            ## >> Call Site 3 <<
	.long	Lset67
Lset68 = Ltmp51-Ltmp50                  ##   Call between Ltmp50 and Ltmp51
	.long	Lset68
Lset69 = Ltmp52-Lfunc_begin4            ##     jumps to Ltmp52
	.long	Lset69
	.byte	1                       ##   On action: 1
Lset70 = Ltmp51-Lfunc_begin4            ## >> Call Site 4 <<
	.long	Lset70
Lset71 = Lfunc_end4-Ltmp51              ##   Call between Ltmp51 and Lfunc_end4
	.long	Lset71
	.long	0                       ##     has no landing pad
	.byte	0                       ##   On action: cleanup
	.byte	1                       ## >> Action Record 1 <<
                                        ##   Catch TypeInfo 1
	.byte	0                       ##   No further actions
                                        ## >> Catch TypeInfos <<
	.long	0                       ## TypeInfo 1
	.p2align	2
                                        ## -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.private_extern	___clang_call_terminate ## -- Begin function __clang_call_terminate
	.globl	___clang_call_terminate
	.weak_definition	___clang_call_terminate
	.p2align	4, 0x90
___clang_call_terminate:                ## @__clang_call_terminate
## %bb.0:
	pushq	%rax
	callq	___cxa_begin_catch
	movq	%rax, (%rsp)            ## 8-byte Spill
	callq	__ZSt9terminatev
                                        ## -- End function
	.globl	__ZNSt3__111char_traitsIcE11eq_int_typeEii ## -- Begin function _ZNSt3__111char_traitsIcE11eq_int_typeEii
	.weak_definition	__ZNSt3__111char_traitsIcE11eq_int_typeEii
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE11eq_int_typeEii: ## @_ZNSt3__111char_traitsIcE11eq_int_typeEii
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	sete	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__ZNSt3__111char_traitsIcE3eofEv ## -- Begin function _ZNSt3__111char_traitsIcE3eofEv
	.weak_definition	__ZNSt3__111char_traitsIcE3eofEv
	.p2align	4, 0x90
__ZNSt3__111char_traitsIcE3eofEv:       ## @_ZNSt3__111char_traitsIcE3eofEv
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$4294967295, %eax       ## imm = 0xFFFFFFFF
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"List is NULL!"

L_.str.1:                               ## @.str.1
	.asciz	" "

L_.str.2:                               ## @.str.2
	.asciz	"add one: "

L_.str.3:                               ## @.str.3
	.asciz	"add two: "

	.section	__TEXT,__const
	.p2align	4               ## @_ZZ4mainE4arr1
l__ZZ4mainE4arr1:
	.long	1                       ## 0x1
	.long	3                       ## 0x3
	.long	5                       ## 0x5
	.long	7                       ## 0x7
	.long	9                       ## 0x9

	.p2align	4               ## @_ZZ4mainE4arr2
l__ZZ4mainE4arr2:
	.long	2                       ## 0x2
	.long	4                       ## 0x4
	.long	6                       ## 0x6
	.long	8                       ## 0x8
	.long	10                      ## 0xa

	.section	__TEXT,__cstring,cstring_literals
L_.str.4:                               ## @.str.4
	.asciz	"list1: "

L_.str.5:                               ## @.str.5
	.asciz	"list2: "

L_.str.6:                               ## @.str.6
	.asciz	"merged: "


.subsections_via_symbols
