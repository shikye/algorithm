#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>



unsigned long *ini_rbp;
 //Compile with -fno-omit-frame-pointer
void print_stack_trace_fp_chain() {
     printf("=== Stack trace from fp chain ===\n");
        
     unsigned long *rbp;
     unsigned long return_addr;
     asm("movq (%%rbp), %0" : "=r"(rbp) : : );
     asm("movq 8(%1), %0" : "=r"(return_addr) : "r"(rbp):);
    
     unsigned long rbp_comp = (unsigned long) rbp;

     // When should this stop?
     while ( rbp <= ini_rbp && rbp_comp > 0x700000000000) {

        printf("stack frame pointer: 0x%016" PRIxPTR "\n", rbp_comp);

        printf("Return address: 0x%016" PRIxPTR "\n", return_addr);

        printf("\n");


    
        asm("movq (%1), %0" : "=r"(rbp) : "r"(rbp): );
        asm("movq 8(%1), %0" : "=r"(return_addr) : "r"(rbp):);


        rbp_comp = (unsigned long) rbp;
      }
      printf("=== End ===\n\n");
}

void bar(){
    print_stack_trace_fp_chain();
    printf("this is bar\n");
}

void foo(){
    print_stack_trace_fp_chain();
    bar();
}



int main(){
 
    asm("movq %%rbp , %0" : "=m"(ini_rbp) : : );

    print_stack_trace_fp_chain();

    foo();

    return 0;

}
