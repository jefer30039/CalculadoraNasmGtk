;archivo con las operaciones a usar en la calculadora

section .text
    global calcularSuma
    global calcularResta
    global calcularMultiplicacion
    global calcularDivision

calcularSuma:
    ;Sumar números
    mov eax, edi
    mov ebx, esi
    ADD eax, ebx
    ret

calcularResta:
    ;Restar números
    mov eax, edi
    mov ebx, esi
    SUB eax, ebx
    ret

calcularMultiplicacion:
    ;Multiplicar números
    mov eax, edi
    mov ebx, esi
    IMUL eax, ebx
    ret

calcularDivision:
    MOV eax, edi ; Dividendo
    MOV ebx, esi ; Divisor

    ; Verificar si el divisor es 0
    CMP ebx, 0
    JE divisionPorCero

    ; Casos negativos
    CMP eax, 0
    JL  dividendoNegativo ; Si el dividendo es negativo
    CMP ebx, 0
    JL  divisorNegativo   ; Si el divisor es negativo

    ; División
    CWD ; Extender el signo de rax a dx:rax
    DIV ebx
    ret 

divisionPorCero:
    mov eax, 0
    ret

dividendoNegativo:
    NEG eax
    jmp continuarDivision

divisorNegativo:

    NEG ebx
    jmp continuarDivision

continuarDivision:
    CWD
    DIV ebx
    NEG eax ; Negar el resultado si el divisor era negativo
    ret

