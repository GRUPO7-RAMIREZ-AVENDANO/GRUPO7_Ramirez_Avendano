persona_1=int(input("Ingresar edad de la primera persona: "))
persona_2=int(input("Ingresar edad de la segunda persona: "))
if persona_1 > persona_2:
    print("Primera persona es mayor.")
elif persona_1 < persona_2:
    print("Segunda persona es mayor.")
else:
    print("Ambas personas son de la misma edad.")
