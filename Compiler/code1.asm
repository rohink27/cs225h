main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16 ; this is the stack set up
        mov     DWORD PTR [rbp-4], 10
        mov     eax, DWORD PTR [rbp-4] ; put 10 into an accumulator register
        imul    eax, eax, 23 ; perform multipiction
        mov     DWORD PTR [rbp-8], eax ; push it on the stack
        mov     eax, DWORD PTR [rbp-8] ; 
        add     eax, 5
        mov     DWORD PTR [rbp-12], eax ; push new value on stack
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax ; move into a source register
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int) ; print on iostream
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     eax, DWORD PTR [rbp-12]
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout ; loads value into esi and prints it amd moves to rdi
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     eax, DWORD PTR [rbp-8]
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(std::basic_ostream<char, std::char_traits<char> >& (*)(std::basic_ostream<char, std::char_traits<char> >&))
        mov     eax, 0
        leave
        ret