#pragma once
class Point
{
private:
	//Posicion X de Point
	int m_pos_x;
	//Posicion Y de Point
	int m_pos_y;
public:
	//Default contructor
	Point();
	//Point constructor taking pos x and pos y
	Point(int t_pos_x, int t_pos_y);
	//Returns x pos of Point
	void set_pos_x(const int t_pos_x);
	//Returns y pos of Point
	void set_pos_y(const int t_pos_y);
	//Returns pos x of Point
	const int get_pos_x(); 
	//Returns pos y of Point
	const int get_pos_y(); 


};

