	;	FactorialRec.jsm
	.bytecode	50.0
	.source	FactorialRec.java
	.class public	FactorialRec
	.super	java/lang/Object
	.field static 	n I
	.field static 	fact I
	.method public <init>()V	
	.limit stack 1	
	.limit locals 1	
	aload_0
	invokespecial	java/lang/Object/<init>()V
	return
	.end method	
	.method static	factorial(I)I
	.limit stack	25
	.limit locals	2
	iconst_0
	istore	1
	iload	0
	iconst_1
	if_icmpgt	else0
	iconst_1
	istore	1
	goto	end1
	else0:
	iload	0
	iload	0
	iconst_1
	isub
	invokestatic	FactorialRec/factorial(I)I
	imul
	istore	1
	end1:
	iload	1
	ireturn
	.end	method
	.method public static	main([Ljava/lang/String;)V
	.limit stack	25
	.limit locals	1
	ldc	"Enter an integer: "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	invokestatic	SimpleIO/readInt()I
	putstatic	FactorialRec/n I
	getstatic	FactorialRec/n I
	invokestatic	FactorialRec/factorial(I)I
	putstatic	FactorialRec/fact I
	ldc	"Factorial of "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	getstatic	FactorialRec/n I
	invokestatic	SimpleIO/printInt(I)V
	ldc	" = "
	invokestatic	SimpleIO/printString(Ljava/lang/String;)V
	getstatic	FactorialRec/fact I
	invokestatic	SimpleIO/printInt(I)V
	invokestatic	SimpleIO/println()V
	return
	.end	method
	.method static <clinit>()V	
	.limit stack 1	
	.limit locals 0	
	iconst_0
	putstatic	FactorialRec/n I
	iconst_0
	putstatic	FactorialRec/fact I
	return
	.end method	
