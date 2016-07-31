all: printreg-shift.o

temp.o: temp.asm
	nasm -f elf32 -g temp.asm
	ld -melf_i386 -g temp.o -o temp.out 
	
printreg-shift.o: printreg-shift.asm
	nasm -f elf32 -g printreg-shift.asm
	ld -melf_i386 -g printreg-shift.o -o printreg-shift.out 


clean:
	rm printreg-shift.o printreg-shift.out
