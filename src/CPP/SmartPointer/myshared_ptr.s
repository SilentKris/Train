	.file	"myshared_ptr.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	":"
	.section	.text._ZN4Demo6prnmsgEv,"axG",@progbits,_ZN4Demo6prnmsgEv,comdat
	.align 2
	.weak	_ZN4Demo6prnmsgEv
	.type	_ZN4Demo6prnmsgEv, @function
_ZN4Demo6prnmsgEv:
.LFB968:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEPKv
	movl	$.LC0, 4(%esp)
	movl	%eax, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZZN4Demo6prnmsgEvE8__func__, 4(%esp)
	movl	%eax, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$.LC0, 4(%esp)
	movl	%eax, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$27, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE968:
	.size	_ZN4Demo6prnmsgEv, .-_ZN4Demo6prnmsgEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB974:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA974
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$48, %esp
	movl	$1, (%esp)
.LEHB0:
	call	_Znwj
	movl	%eax, 4(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoEC1EPS0_
.LEHE0:
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
.LEHB1:
	call	_ZN12myshared_ptrI4DemoEC1ERKS1_
.LEHE1:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoEptEv
	movl	%eax, (%esp)
.LEHB2:
	call	_ZN4Demo6prnmsgEv
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoEptEv
	movl	%eax, (%esp)
	call	_ZN4Demo6prnmsgEv
	leal	-25(%ebp), %eax
	leal	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoEdeEv
	subl	$4, %esp
	leal	-10(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4Demo6prnmsgEv
	leal	-25(%ebp), %eax
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoEdeEv
	subl	$4, %esp
	leal	-9(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4Demo6prnmsgEv
.LEHE2:
	movl	$0, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
.LEHB3:
	call	_ZN12myshared_ptrI4DemoED1Ev
.LEHE3:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
.LEHB4:
	call	_ZN12myshared_ptrI4DemoED1Ev
.LEHE4:
	movl	%ebx, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_remember_state
	.cfi_def_cfa 1, 0
	.cfi_restore 1
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
.L6:
	.cfi_restore_state
	movl	%eax, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoED1Ev
	jmp	.L4
.L5:
	movl	%eax, %ebx
.L4:
	leal	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN12myshared_ptrI4DemoED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
.LEHB5:
	call	_Unwind_Resume
.LEHE5:
	.cfi_endproc
.LFE974:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA974:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE974-.LLSDACSB974
.LLSDACSB974:
	.uleb128 .LEHB0-.LFB974
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB974
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L5-.LFB974
	.uleb128 0
	.uleb128 .LEHB2-.LFB974
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L6-.LFB974
	.uleb128 0
	.uleb128 .LEHB3-.LFB974
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L5-.LFB974
	.uleb128 0
	.uleb128 .LEHB4-.LFB974
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB974
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE974:
	.text
	.size	main, .-main
	.section	.text._ZN12myshared_ptrI4DemoEC2EPS0_,"axG",@progbits,_ZN12myshared_ptrI4DemoEC5EPS0_,comdat
	.align 2
	.weak	_ZN12myshared_ptrI4DemoEC2EPS0_
	.type	_ZN12myshared_ptrI4DemoEC2EPS0_, @function
_ZN12myshared_ptrI4DemoEC2EPS0_:
.LFB980:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	_ZN12myshared_ptrI4DemoE3AddEv
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE980:
	.size	_ZN12myshared_ptrI4DemoEC2EPS0_, .-_ZN12myshared_ptrI4DemoEC2EPS0_
	.section	.rodata
.LC1:
	.string	"Memory is released\357\274\201"
	.section	.text._ZN12myshared_ptrI4DemoED2Ev,"axG",@progbits,_ZN12myshared_ptrI4DemoED5Ev,comdat
	.align 2
	.weak	_ZN12myshared_ptrI4DemoED2Ev
	.type	_ZN12myshared_ptrI4DemoED2Ev, @function
_ZN12myshared_ptrI4DemoED2Ev:
.LFB983:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	_ZN12myshared_ptrI4DemoE5MinusEv
	movl	_ZN12myshared_ptrI4DemoE5countE, %eax
	testl	%eax, %eax
	jne	.L8
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_ZdlPv
	movl	$.LC1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
.L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE983:
	.size	_ZN12myshared_ptrI4DemoED2Ev, .-_ZN12myshared_ptrI4DemoED2Ev
	.section	.text._ZN12myshared_ptrI4DemoEC2ERKS1_,"axG",@progbits,_ZN12myshared_ptrI4DemoEC5ERKS1_,comdat
	.align 2
	.weak	_ZN12myshared_ptrI4DemoEC2ERKS1_
	.type	_ZN12myshared_ptrI4DemoEC2ERKS1_, @function
_ZN12myshared_ptrI4DemoEC2ERKS1_:
.LFB986:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	_ZN12myshared_ptrI4DemoE3AddEv
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE986:
	.size	_ZN12myshared_ptrI4DemoEC2ERKS1_, .-_ZN12myshared_ptrI4DemoEC2ERKS1_
	.section	.text._ZN12myshared_ptrI4DemoEptEv,"axG",@progbits,_ZN12myshared_ptrI4DemoEptEv,comdat
	.align 2
	.weak	_ZN12myshared_ptrI4DemoEptEv
	.type	_ZN12myshared_ptrI4DemoEptEv, @function
_ZN12myshared_ptrI4DemoEptEv:
.LFB988:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE988:
	.size	_ZN12myshared_ptrI4DemoEptEv, .-_ZN12myshared_ptrI4DemoEptEv
	.section	.text._ZN12myshared_ptrI4DemoEdeEv,"axG",@progbits,_ZN12myshared_ptrI4DemoEdeEv,comdat
	.align 2
	.weak	_ZN12myshared_ptrI4DemoEdeEv
	.type	_ZN12myshared_ptrI4DemoEdeEv, @function
_ZN12myshared_ptrI4DemoEdeEv:
.LFB989:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret	$4
	.cfi_endproc
.LFE989:
	.size	_ZN12myshared_ptrI4DemoEdeEv, .-_ZN12myshared_ptrI4DemoEdeEv
	.section	.text._ZN12myshared_ptrI4DemoE3AddEv,"axG",@progbits,_ZN12myshared_ptrI4DemoE3AddEv,comdat
	.weak	_ZN12myshared_ptrI4DemoE3AddEv
	.type	_ZN12myshared_ptrI4DemoE3AddEv, @function
_ZN12myshared_ptrI4DemoE3AddEv:
.LFB993:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_ZN12myshared_ptrI4DemoE5countE, %eax
	addl	$1, %eax
	movl	%eax, _ZN12myshared_ptrI4DemoE5countE
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE993:
	.size	_ZN12myshared_ptrI4DemoE3AddEv, .-_ZN12myshared_ptrI4DemoE3AddEv
	.section	.text._ZN12myshared_ptrI4DemoE5MinusEv,"axG",@progbits,_ZN12myshared_ptrI4DemoE5MinusEv,comdat
	.weak	_ZN12myshared_ptrI4DemoE5MinusEv
	.type	_ZN12myshared_ptrI4DemoE5MinusEv, @function
_ZN12myshared_ptrI4DemoE5MinusEv:
.LFB994:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	_ZN12myshared_ptrI4DemoE5countE, %eax
	subl	$1, %eax
	movl	%eax, _ZN12myshared_ptrI4DemoE5countE
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE994:
	.size	_ZN12myshared_ptrI4DemoE5MinusEv, .-_ZN12myshared_ptrI4DemoE5MinusEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB997:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	.L15
	cmpl	$65535, 12(%ebp)
	jne	.L15
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %eax
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	%eax, (%esp)
	call	__cxa_atexit
.L15:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE997:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.weak	_ZN12myshared_ptrI4DemoE5countE
	.section	.bss._ZN12myshared_ptrI4DemoE5countE,"awG",@nobits,_ZN12myshared_ptrI4DemoE5countE,comdat
	.align 4
	.type	_ZN12myshared_ptrI4DemoE5countE, @gnu_unique_object
	.size	_ZN12myshared_ptrI4DemoE5countE, 4
_ZN12myshared_ptrI4DemoE5countE:
	.zero	4
	.text
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB998:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE998:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__sub_I_main
	.section	.rodata
	.type	_ZZN4Demo6prnmsgEvE8__func__, @object
	.size	_ZZN4Demo6prnmsgEvE8__func__, 7
_ZZN4Demo6prnmsgEvE8__func__:
	.string	"prnmsg"
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.weak	_ZN12myshared_ptrI4DemoEC1EPS0_
	.set	_ZN12myshared_ptrI4DemoEC1EPS0_,_ZN12myshared_ptrI4DemoEC2EPS0_
	.weak	_ZN12myshared_ptrI4DemoED1Ev
	.set	_ZN12myshared_ptrI4DemoED1Ev,_ZN12myshared_ptrI4DemoED2Ev
	.weak	_ZN12myshared_ptrI4DemoEC1ERKS1_
	.set	_ZN12myshared_ptrI4DemoEC1ERKS1_,_ZN12myshared_ptrI4DemoEC2ERKS1_
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
