# -*- coding: latin1 -*-

print('''  \n \n   
                       ____ 
                      / * *)
                     /    / 
          .__^^^^^__/    /
      ___/              /
      ___              /
          | | ______| |
          |_|       |_| \n \n''')

#!/usr/bin/env python
# -*- coding: utf-8 -*-

linha = '-' * 50
titulo = 'Sequencia de Fibonacci'

print(linha)
print(titulo.center(50))
print(linha, "\n")



print("-"*50, "\n",'''Na matemática, a Sucessão de Fibonacci (também Sequência de Fibonacci), é uma sequência de números inteiros, começando normalmente por 0 e 1, na qual, cada termo subsequente corresponde à soma dos dois anteriores. A sequência recebeu o nome do matemático italiano Leonardo de Pisa, mais conhecido por Fibonacci, que descreveu, no ano de 1202, o crescimento de uma população de coelhos, a partir desta. Esta sequência já era, no entanto, conhecida na antiguidade.

Os números de Fibonacci são, portanto, os números que compõem a seguinte sequência (sequência A000045 na OEIS):

0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, ... .[nota 1][2].
Em termos matemáticos, a sequência é definida recursivamente pela fórmula abaixo, sendo o primeiro termo F1= 1:

Fn=Fn-1+Fn-2

e valores iniciais

F1=1; F2=1

A sequência de Fibonacci tem aplicações na análise de mercados financeiros, na ciência da computação e na teoria dos jogos. Também aparece em configurações biológicas, como, por exemplo, na disposição dos galhos das árvores ou das folhas em uma haste,[3] no arranjo do cone da alcachofra, do abacaxi,[4] ou no desenrolar da samambaia.[5]''',"\n","\n","     -https://pt.wikipedia.org/wiki/Sequ%C3%AAncia_de_Fibonacci","\n", "-"*50, "\n")


x=int(input(" 1 - repetir até n . 2 - repetir x vezes . 3 - repetir infinitamente . escolha um número:".replace(".", "\n")))
a= 0
b= 1
c=0
print("/\  "*10)
print("  \/"*10)

if x == 1:
  n=int(input("digite o valor maximo da sequencia fibonacci:"))
  print("/\  "*10)
  print("  \/"*10)
  print(a)
  print(b)
  while(1):
    c = a + b
    if c > n:
      break
    a = b
    b = c
    print (c) 
elif x == 2:
  n=int(input("Digite a quantidade de numeros da sequencia fibonacci desejados:"))
  i=3
  print("/\  "*10)
  print("  \/"*10)
  print("1 -",a)
  print("2 -",b)
  for l in range(n-2):
    c = a + b
    a = b
    b = c
    print (i, "-", c)
    i=i+1
elif x == 3:
    print("/\  "*10)
    print("  \/"*10)
    print (a)
    print(b)
    for l in range(n):
     c = a + b
     a = b
     b = c
     print (c)
     n=n+1