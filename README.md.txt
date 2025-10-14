# 🃏 Super Trunfo em C - Comparação Multi-Atributos

Este projeto é a versão avançada do desafio **Super Trunfo** em linguagem C, onde o jogador compara duas cartas de países com **dois atributos diferentes**. O sistema calcula a **soma dos atributos** (com exceções de regras) e define o vencedor da rodada.

## ✅ Funcionalidades

- Cadastro de 3 cartas: Brasil, Estados Unidos e Espanha
- Escolha de duas cartas para comparar
- Menus dinâmicos com `switch` e tratamento de entradas inválidas
- Escolha de **dois atributos distintos**
- Regra especial para **Densidade Demográfica** (quanto menor, melhor)
- Soma dos atributos determina o vencedor
- Tratamento de **empates**
- Interface clara via terminal

## 🌍 Cartas disponíveis

| País           | População (milhões) | Área (km²) | Densidade (hab/km²) | PIB (bilhões USD) |
|----------------|----------------------|------------|----------------------|--------------------|
| Estados Unidos | 10                   | 500        | 10                   | 5                  |
| Espanha        | 5                    | 400        | 10                   | 6                  |
| Brasil         | 15                   | 900        | 50                   | 11                 |

## 📊 Atributos disponíveis

1. População (milhões) - quanto maior, melhor  
2. Área (km²) - quanto maior, melhor  
3. Densidade Demográfica (hab/km²) - quanto menor, melhor  
4. PIB (bilhões USD) - quanto maior, melhor  

## 🛠️ Como compilar e executar

### Compilando

```bash
gcc super_trunfo.c -o super_trunfo
