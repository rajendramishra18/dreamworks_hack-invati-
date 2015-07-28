#include "headers.h"

class point
{
	private:
		float px;
		float py;

	public:
		point()
		{
			px=0.0;
			py=0.0;
		}

		float getX()
		{
			return px;
		}

		float getY()
		{
			return py;
		}
	
		void setPoint(float x,float y)
		{
			px=x;
			py=y;
		}

		void drawPoint()
		{
			glVertex2f(px,py);
		}
};
