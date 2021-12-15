#include "usuario.h"
#include "reserva.h"
#include "recursos.h"
//#include "maquinas.h"
#include "gtest/gtest.h"

#include <cstdlib>

TEST(Usuario, Correo){
    Usuario usuario("Pepee"," "," ",0);

    EXPECT_TRUE(usuario.setCorreo("pepe@uco.es"));
    EXPECT_FALSE(usuario.setCorreo("pepe12.es"));

}

TEST(Usuario, Contraseña){
    Usuario usuario("Pepee"," "," ",0);

    EXPECT_FALSE(usuario.setContrasena("1"));
    EXPECT_FALSE(usuario.setContrasena("12"));
    EXPECT_FALSE(usuario.setContrasena("123"));
    EXPECT_FALSE(usuario.setContrasena("1234"));
    EXPECT_FALSE(usuario.setContrasena("12345"));
    EXPECT_TRUE(usuario.setContrasena("123456"));
    EXPECT_TRUE(usuario.setContrasena("1234567"));
}

/*TEST(Reserva, recursos){
    Reserva r;
    
    EXPECT_TRUE(r.setElegirRecursos(5, 5));
    EXPECT_FALSE(r.setElegirRecursos(7, 5));
    EXPECT_EQ(1, r.getConfirmacion());
}*/

TEST(Reserva, fecha){
    Reserva r;

    EXPECT_TRUE(r.comprobacionHora("12.00"));
    EXPECT_FALSE(r.comprobacionHora("27.00"));
    EXPECT_TRUE(r.comprobacionFecha("15/12/2021"));
    EXPECT_FALSE(r.comprobacionFecha("15/12/1998"));
    EXPECT_TRUE(r.comprobarHoraDiaIgual("15/12/2021", "16.00", "15/12/2021","17.00"));
    EXPECT_FALSE(r.comprobarHoraDiaIgual("15/12/2021", "16.00", "15/12/2021","14.00"));

}