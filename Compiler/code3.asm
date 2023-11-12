printNodes(Node*):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        cmp     QWORD PTR [rbp-8], 0
        je      .L3
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     rax, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rax+8]
        mov     rdi, rax
        call    printNodes(Node*)
.L3:
        nop
        leave
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-8], 0
        mov     QWORD PTR [rbp-16], 0
        mov     QWORD PTR [rbp-24], 0
        mov     edi, 16
        call    operator new(unsigned long)
        mov     DWORD PTR [rax], 0
        mov     QWORD PTR [rax+8], 0
        mov     QWORD PTR [rbp-8], rax
        mov     edi, 16
        call    operator new(unsigned long)
        mov     DWORD PTR [rax], 0
        mov     QWORD PTR [rax+8], 0
        mov     QWORD PTR [rbp-16], rax
        mov     edi, 16
        call    operator new(unsigned long)
        mov     DWORD PTR [rax], 0
        mov     QWORD PTR [rax+8], 0
        mov     QWORD PTR [rbp-24], rax
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], 1
        mov     rax, QWORD PTR [rbp-16]
        mov     DWORD PTR [rax], 2
        mov     rax, QWORD PTR [rbp-24]
        mov     DWORD PTR [rax], 3
        mov     rax, QWORD PTR [rbp-8]
        mov     rdx, QWORD PTR [rbp-16]
        mov     QWORD PTR [rax+8], rdx
        mov     rax, QWORD PTR [rbp-16]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], rdx
        mov     rax, QWORD PTR [rbp-24]
        mov     QWORD PTR [rax+8], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    printNodes(Node*)
        mov     eax, 0
        leave
        ret