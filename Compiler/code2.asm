count_no_digits(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-20]
        movsx   rdx, eax
        imul    rdx, rdx, 1717986919
        shr     rdx, 32
        mov     ecx, edx
        sar     ecx, 2
        cdq
        mov     eax, ecx
        sub     eax, edx
        mov     DWORD PTR [rbp-20], eax
        add     DWORD PTR [rbp-4], 1
.L2:
        cmp     DWORD PTR [rbp-20], 0
        jg      .L3
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 783
        mov     eax, DWORD PTR [rbp-4]
        mov     edi, eax
        call    count_no_digits(int)
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     eax, 0
        leave
        ret