def_contar_caracteres(string):
contagem = {}

for char in string:
contagem[char] = contagem.get(char, 0)+1

        caracteres_ordenados = sorted(contagem.items(), key = lambda x: x[1], reverse = true)
                return caracteres_ordenados