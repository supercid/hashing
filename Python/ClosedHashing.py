#!/usr/bin/env python
# -*- coding: utf-8 -*-

class ClosedHashing(object):
	global TH
	TH=0
	def __init__(self, tam, tent):
		TH = tam
		tentativa = tent
		Hashing = []
		for i in range(1,tam):
			Hashing[i] = None
	
	def __del__(self): #destrutor
		for x in range(1,TH):
			Hashing[x] = None

	def vazia():
		vazia = True
		for x in range(1,TH):
			if Hashing[x] != None:
				vazia = False
		return vazia

	def getTH():
		return TH

	def getTentativa():
		if tentativa == LINEAR:
			print "Linear"
		elif tentativa == QUADRATICO:
			print "Quadrático"
		elif tentativa == DUPLO_HASHING:
			print "Duplo Hashing"

	def primo(valor):
		j=1
		if valor == 1:
			return False
		for x in range(1,sqrt(valor)):
			if valor%i == 0:
				j += 1
		if j>2 or j==1:
			return False
		else:
			return True
	
	def proxPrimo(th):
			for x in range(th-1,1, -1):
				if primo(x):
					return x

			return 2;
	
	def inserir(valor):
		th=TH
		for x in range(1,TH):
			if tentativa==LINEAR:
				indice = (valor + x)%TH
			elif tentativa == QUADRATICO:
				indice = (valor+ x*x)%TH
			elif tentativa == DUPLO_HASHING:
				indice = valor%th
				th = proxPrimo(th)

			if Hashing[indice] == None:
				Hashing[indice] = valor
				return

		print "Esse número não pode ser inserido"



	def deletar(valor):
		if (vazia==False):
			th=TH
			for x in range(1,TH):
				if tentativa==LINEAR:
					indice = (valor + x)%TH
				elif tentativa == QUADRATICO:
					indice = (valor+ x*x)%TH
				elif tentativa == DUPLO_HASHING:
					indice = valor%th
					th = proxPrimo(th)

				if Hashing[indice] == valor:
					Hashing[indice] = None
					print "Este número não está na hashing"
					return


	def exibir():
		print "\n\t\t Hashing\n"
		for x in range(1,TH):
			print Hashing[x]
			if x < TH-1:
				print ", "

		print " ] }\n"



print "\t\t\t CLOSED HASHING"
tam = (raw_input('Tamanho da Hashing: '))
tent = int(raw_input("\nTentativas\n1-Linear\n2-Quadratica\n3-Duplo Hashing\n: "))
hashing = ClosedHashing (tam,tent)


while True:
	print "Tamanho da Hashing = "
	print hashing.getTH()
	print "\nTipo de tentativa: "
	print hashing.getTentativa()

	hashing.exibir()


















