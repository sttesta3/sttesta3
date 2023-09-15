#include "gtest/gtest.h"
#include "Vector.hpp"

class VectorTests : public ::testing::Test {
protected:
    Vector vector{};
    Item* dato{};
    Item* dato1 = new Item("1", "");
    Item* dato2 = new Item("2", "");
    Item* dato3 = new Item("3", "");

    void liberar();
};

void VectorTests::liberar() {
    delete dato1;
    delete dato2;
    delete dato3;
}

TEST_F(VectorTests, Alta) {
    vector.alta(dato1);
    EXPECT_TRUE(*vector[0] == "1");

    vector.alta(dato2);
    EXPECT_TRUE(*vector[1] == "2");

    liberar();
}

TEST_F(VectorTests, AltaIndice) {
    vector.alta(dato1, 0);
    EXPECT_TRUE(*vector[0] == "1");

    vector.alta(dato2, 0);
    EXPECT_TRUE(*vector[0] == "2");

    liberar();
}

TEST_F(VectorTests, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(dato1, 1), VectorException);

    liberar();
}


TEST_F(VectorTests, Baja) {
    vector.alta(dato1);

    dato = vector.baja();
    EXPECT_TRUE(*dato == "1");

    liberar();
}

TEST_F(VectorTests, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), VectorException);

    liberar();
}

TEST_F(VectorTests, BajaIndice) {
    vector.alta(dato1);
    vector.alta(dato2);

    dato = vector.baja(0);
    EXPECT_TRUE(*dato == "1");

    dato = vector.baja(0);
    EXPECT_TRUE(*dato == "2");

    liberar();
}

TEST_F(VectorTests, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), VectorException);

    liberar();
}

TEST_F(VectorTests, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(dato1);

    EXPECT_THROW(vector.baja(1), VectorException);

    liberar();
}

TEST_F(VectorTests, Vacio) {
    EXPECT_TRUE(vector.vacio());

    vector.alta(dato1);
    EXPECT_FALSE(vector.vacio());

    vector.baja();
    EXPECT_TRUE(vector.vacio());

    liberar();
}

TEST_F(VectorTests, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0);

    vector.alta(dato1);
    vector.alta(dato2);
    vector.alta(dato3);
    EXPECT_EQ(vector.tamanio(), 3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2);

    liberar();
}

TEST_F(VectorTests, OperadorAcceso) {
    vector.alta(dato1);
    vector.alta(dato2, 0);
    vector.alta(dato3);
    dato = vector.baja(0);

    EXPECT_TRUE(*vector[1] == "3");
    EXPECT_TRUE(*dato == "2");

    liberar();
}

TEST_F(VectorTests, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], VectorException);

    liberar();
}

TEST_F(VectorTests, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(dato1);

    EXPECT_THROW(vector[1], VectorException);

    liberar();
}