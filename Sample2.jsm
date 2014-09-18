	;	Sample2.jsm
	.bytecode	50.0
	.source	Sample2.java
	.class public	Sample2
	.super	java/lang/Object
	.method public <init>()V	
	.limit stack 1	
	.limit locals 1	
	aload_0
	invokespecial	java/lang/Object/<init>()V
	return
	.end method	
	.method static	count(I)I
	.limit stack	25
	.limit locals	3
	iconst_0
	istore	1
	iconst_0
	istore	2
	iconst_1
	istore	2
	iconst_0
	istore	1
	again0:
	iload	2
	iload	0
	if_icmpgt	whileEnd1
	iload	1
	iload	2
	iadd
	istore	1
	iload	2
	iconst_1
	iadd
	istore	2
	goto	again0
	whileEnd1:
	iload	1
	ireturn
	.end	method
	.method public static	main([Ljava/lang/String;)V
	.limit stack	25
	.limit locals	3
	iconst_0
	istore	1
	iconst_0
	istore	2
	invokestatic	SimpleIO/readInt()I
	istore	2
	iload	2
	invokestatic	Sample2/count(I)I
	istore	1
	iload	1
	invokestatic	SimpleIO/printInt(I)V
	invokestatic	SimpleIO/println()V
	return
	.end	method
