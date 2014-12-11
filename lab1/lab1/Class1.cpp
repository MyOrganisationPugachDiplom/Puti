static class Vector
{
	double x;
	double y;
	static double ScalMul(Vector _x, Vector _y)
	{
		return _x.x*_y.x+_x.y*_y.y;
	}
	static bool Colliniarn(Vector _x, Vector _y)
	{
		if(_x.y !=0 && _y.y!=0)
		{
			if(_x.x/_x.y != _y.x/_y.y) 
				return false;
			else 
				return true;
		}
		else
		{
			if(_x.y!=0 || _y.y!=0)
				return false;
			else
				return true;
		}
	}
	static Vector Add(Vector _x, Vector _y)
	{
		Vector res;
		res.x = _x.x + _y.y;
		res.y = _x.y + _y.y;
		return res;
	}

};

class Shape
{

};


class Circle : Shape
{
	Vector center;
	Vector radius;
};

class Square
{
	Vector  corners[4];
};

class Section
{
public:
	Vector begin;
	Vector end;
};

class Intersections
{
	Vector Intersect(Square sq, Section sc)
	{

	}

	Vector Intersect(Section sc1 , Section sc2)
	{
		if(Vector::Colliniarn(sc1,sc2))
			return 
	}
}