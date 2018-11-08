#pragma once
class InputObserver
{
public:
	virtual void updateMouse(double X, double Y) = 0;
	virtual void updateKey(int key, int action) = 0;

};

