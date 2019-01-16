#include "BitVector.h"

Bitvector::Bitvector()
{

}

Bitvector::~Bitvector()
{

}

Bitvector::Bitvector(int p_size) {
	m_array = 0;
	m_size = 0;
	Resize(p_size);
}

//Obtiene un bit especifico dentro del vector de bits

bool Bitvector::operator[] (int p_index)
{
	//Encuentra celda donde esta el bit
	int cell = p_index / 32;
	//Encuentra el bit de la celda que se necesita
	int bit = p_index % 32;
	//Obtiene el bit y lo recorre para que tenga un valor de 1 o 0
	return (m_array[cell] & (1 << bit)) >> bit;
}

//Activa o desactiva el valor en un vector:	

void Bitvector::Set(int p_index, bool p_value)
{
	int cell = p_index / 32;
	int bit = p_index % 32;
	//Posiciona un 1 en la misma posicion que el bit que se quiere modificar y se aplica or para hacerlo verdadero
	if (p_value == true)
		m_array[cell] = (m_array[cell] | (1 << bit));
	//Posiciona un 1 en la misma posicion que el bit que se quiere modificar y con '~' se se invierte todo el arreglo
	//Se aplica '&' con este vector para desactivar ese bit
	else
		m_array[cell] = (m_array[cell] & (~(1 << bit)));
}

//Cambia el tamaño del arreglo

void Bitvector::Resize(int p_size)
{
	unsigned long int* newvector = 0; //Se crea un nuevo apuntador en 0 hecho para almacenar booleanos
	//Comprueba si el numero de bits es divisible entre 32
	if (p_size % 32 == 0)
		p_size = p_size / 32;
	//Si el numero no es divisible entre 32 se agrega 1 para reservar una celda ya que la division resultaria en 0
	else
		p_size = (p_size / 32) + 1;

	//Se declara un nuevo arreglo contenido en el apuntador hecho previamente
	newvector = new unsigned long int[p_size];
	//Revisa si hay suficiente espacio en la memoria para el nuevo vector, si no, el vector conservara sus datos
	if (newvector == 0)
		return;
	//Se determina si el tamaño del nuevo arreglo es mayor o menor al viejo, si es menor, los datos que sobran se perderan
	//la variable min se asigna al arreglo que sea más pequeño 
	int min;
	if (p_size < m_size)
		min = p_size;
	else
		min = m_size;
	//Se hace un for loop para iterar sobre cada elemento del viejo arreglo y copiar el numero de valores determinado por min al nuevo arreglo
	int index;
	for (index = 0; index < min; index++)
		newvector[index] = m_array[index];
	//Se cambia el tamaño del arreglo viejo al tamaño del nuevo arreglo
	m_size = p_size;
	//Verifica si el arreglo viejo existe y si no, se borra
	if (m_array != 0)
		delete[] m_array;
	//El apuntador original apunta ahora al nuevo arreglo
	m_array = newvector;
}