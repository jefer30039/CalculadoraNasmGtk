;archivo con las operaciones a usar en la calculadora

section .data
    num1 dd 0
    num2 dd 0
    resultado dd 0

section .text
    global suma
    global resta
    global multiplicacion
    global division

suma:
    ;Sumar números
    mov eax, [num1]
    mov ebx, [num2]
    ADD eax, ebx
    mov [resultado], eax
    ret

resta:
    ;Restar números
    mov eax, [num1]
    mov ebx, [num2]
    SUB eax, ebx
    mov [resultado], eax
    ret

multiplicacion:
    ;Multiplicar números
    mov eax, [num1]
    mov ebx, [num2]
    IMUL eax, ebx
    mov [resultado], eax
    ret

division:
    MOV eax, [num1] ; Dividendo
    MOV ebx, [num2] ; Divisor

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
    MOV [resultado], eax

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
    MOV [resultado], eax
    ret

