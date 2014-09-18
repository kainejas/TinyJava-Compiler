	;	Sample1R.jsm
	.bytecode	50.0
	.source	Sample1R.java
	.class public	Sample1R
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
	.limit locals	4
	iconst_0
	istore	1
	ldc	0.0f
	fstore	2
	ldc	0.0f
	fstore	3
	invokestatic	SimpleIO/readFloat()F
	fstore	3
	ldc	9
	i2f
	fload	3
	ldc	8
	i2f
	fmul
	fadd
	fstore	2
	ldc	9
	i2f
	fload	3
	ldc	8
	i2f
	fmul
	fadd
	f2i
	istore	1
	ldc	"Result (int) is "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	iload	1
	invokestatic	SimpleIO/printInt(I)V
	invokestatic	SimpleIO/println()V
	ldc	"Result (float) is "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	fload	2
	invokestatic	SimpleIO/printFloat(F)V
	invokestatic	SimpleIO/println()V
	return
	.end	method
