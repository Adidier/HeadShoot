#ifndef BITVECTOR_H 
#define BITVECTOR_H


class Bitvector
{
protected:
	unsigned long int* m_array;
	int m_size;

public:
	Bitvector();
	Bitvector(int p_size);
	~Bitvector();
	void Resize(int p_size);
	bool operator[] (int p_index);
	void Set(int p_index, bool p_value);
};

#endif 