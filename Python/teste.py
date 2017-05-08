#!/usr/bin/env python
# -*- coding: utf-8 -*-

class No:
   esquerda, direita, valor = None, None, 0
 
   def __init__(self, valor):
     # construtor dos valores
     self.esquerda = None
     self.direita = None
     self.valor = valor
 
class Ordenacao:
   def __init__(self):
     # inicializa a raiz da árvore
     self.root = None
 
   def AdicionaNo(self, valor):
     return No(valor)
 
   def Inserir(self, raiz, valor):
     # inserir novo valor
     if raiz == None:
         # não há nenhum valor
         return self.AdicionaNo(valor)
     else:
         # já está na árvore
         if valor <= raiz.valor:
            # se os dados forem menores do que os armazenados
            # entra na sub-árvore do lado esquerdo
            raiz.esquerda = self.Inserir (raiz.esquerda, valor)
         else:
            # entra na sub-árvore do lado direito
            raiz.direita = self.Inserir (raiz.direita, valor)
         return raiz

