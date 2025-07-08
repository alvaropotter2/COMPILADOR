# Test para strings con condicional
nombre = "Ana"
mensaje = "Hola, " + nombre

if nombre == "Ana"
    mensaje = mensaje + "!"
else
    mensaje = mensaje + ", quien eres?"
end

puts mensaje
