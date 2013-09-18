#include <stdio.h>
unsigned int get_sp(void){
        __asm__("movl %esp, %eax");
}
int main(){
        printf("Current ESP value is 0x%x." " Can you overwrite it?\n", get_sp());
}

/*
Repeating Return Addresses
The most important element of the exploit is the return address, which must be aligned
perfectly and repeated until it overflows the saved eip value on the stack. Although it is
possible to point directly to the beginning of the shellcode, it is often much easier to be
a little sloppy and point to somewhere in the middle of the NOP sled. To do that, the
first thing you need to know is the current esp value, which points to the top of the
stack. The gcc compiler allows you to use assembly code inline and to compile pro-
grams as follows:

                   "DISABLE ASLR" += echo "0" > /proc/sys/kernel/randomize_va_space
                   "ENABLE ASLR"  += echo "2" > /proc/sys/kernel/randomize_va_space
                   
                   root@t0xin:/home/fwewe32/src/grey-hat-hacking/chapter 10/c# ./aslr_check 
                   Stack pointer (ESP): 0xbffff6e8
                   
                   Ref: http://www.amazon.com/Hacking-Ethical-Hackers-Handbook-Edition/dp/0071742557
 */