	;	Sample1.jsm
	.bytecode	50.0
	.source	Sample1.java
	.class public	Sample1
	.super	java/lang/Object
	.method public <init>()V	
	.limit stack 1	
	.limit locals 1	
	aload_0
	invokespecial	java/lang/Object/<init>()V
	return
	.end method	
	.method public static	main([Ljava/lang/String;)V
	.limit stack	25
	.limit locals	3
	iconst_0
	istore	1
	iconst_0
	istore	2
	invokestatic	SimpleIO/readInt()I
	istore	2
	ldc	9
	iload	2
	ldc	8
	imul
	iadd
	istore	1
	ldc	"Result is "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	iload	1
	invokestatic	SimpleIO/printInt(I)V
	invokestatic	SimpleIO/println()V
	return
	.end	method
