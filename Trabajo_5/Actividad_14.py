class Persona:
  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname
  #--------------------------
  def set_age(self,new_age):
    self.age = new_age
  #--------------------------
  def get_name(self):
    return(self.firstname + ' ' + self.lastname)

class Sede(Persona):
  def __init__(self, fname, lname, cat):
    super().__init__(fname, lname)
    self.categoria = cat
  #--------------------------
  def set_cat(self,new_cat):
    self.categoria = new_cat
  #--------------------------
  def get_sede(self):
    if self.categoria == 0:
      return('Casa Matriz')
    if self.categoria == 1:
      return('Fabrica')
    if self.categoria == 2:
      return('Oficina Providencia')
    if self.categoria == 3:
      return('Oficina Providencia')

class Categoria(Persona):
  def __init__(self, fname, lname, cat):
    super().__init__(fname, lname)
    self.categoria = cat
  #--------------------------
  def set_cat(self,new_cat):
    self.categoria = new_cat
  #--------------------------
  def get_cat(self):
    if self.categoria == 0:
      return('Gerente General')
    if self.categoria == 1:
      return('Gerente Producción')
    if self.categoria == 2:
      return('Gerente de Finanzas')
    if self.categoria == 3:
      return('Auditor')

class Ingresos(Categoria):
  def __init__(self, fname, lname, cat, ant):
    super().__init__(fname, lname, cat)
    self.antiguedad = ant
  #--------------------------
  def set_cat(self,new_cat):
    self.categoria = new_cat
  #--------------------------
  def get_ingreso(self):
    if self.categoria == 0:
      return(2000000+20000*int(self.antiguedad))
    if self.categoria == 1:
      return(1200000+20000*int(self.antiguedad))
    if self.categoria == 2:
      return(1400000+20000*int(self.antiguedad))
    if self.categoria == 3:
      return(900000+20000*int(self.antiguedad))


print('Ingrese nombre del empleado')
nombre = str(input())
print('Ingrese apellido del empleado')
apellido = str(input())
print('Ingrese categoria (0-3) del empleado')
cat = int(input())
print('Ingrese cantidad de años de antiguedad del empleado')
ant = int(input())
print('----------------------------------------')

c = Persona(nombre,apellido)
x = Categoria(nombre,apellido,cat)
s = Sede(nombre,apellido,cat)
i = Ingresos(nombre,apellido,cat,ant)

print('El funcionario ' + c.get_name() + ':')
print('desempeña funciones en la ' + s.get_sede() + ' como ' + x.get_cat())
print('con un ingreso mensual de $'+ str(i.get_ingreso()))
