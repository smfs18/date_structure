def build_program(target_stack):
    if not target_stack:
        return ""
    
    # Se o último elemento for 1, pode ter sido criado por '1'
    if target_stack[-1] == 1:
        return build_program(target_stack[:-1]) + "1"
    
    # Se os dois últimos elementos forem iguais, pode ter sido 'd'
    if len(target_stack) >= 2 and target_stack[-1] == target_stack[-2]:
        return build_program(target_stack[:-1]) + "d"
    
    # Verificar se pode ser resultado de '+'
    # Precisamos encontrar dois números que somados dão o último elemento
    # E considerar o decremento dos outros elementos
    for i in range(len(target_stack)-1):
        for j in range(i+1, len(target_stack)-1):
            if target_stack[i] + target_stack[j] == target_stack[-1]:
                # Reconstruir o estado anterior (antes do '+')
                new_stack = target_stack[:-1]
                # Remover os dois elementos que foram somados
                new_stack.pop(j)
                new_stack.pop(i)
                # Incrementar todos os outros elementos (operação inversa do decremento)
                new_stack = [x+1 for x in new_stack]
                # Verificar se todos são positivos
                if all(x > 0 for x in new_stack):
                    sub_program = build_program(new_stack)
                    if sub_program is not None:
                        return sub_program + "+"
    
    return None  # Não encontrou solução

pilha = [1, 2]
print(build_program(pilha))