#include "headers.h"

class object
{
	private:
		float ltx,lty,lbx,lby,rbx,rby,rtx,rty;

	public:
		object()
		{
			ltx=0.5f;
			lty=0.5f;
			lbx=0.5f;
			lby=-0.5f;
			rbx=0.75f;
			rby=-0.5f;
			rtx=0.75f;
			rty=0.5f;
		}
		
		float getlbx()
		{	return lbx;	}

		float getlby()
		{	return lby;	}

		float getltx()
		{	return ltx;	}
		
		float getlty()
		{	return lty;	}
	
		float getrbx()
		{	return rbx;	}

		float getrby()
		{	return rby;	}

		float getrtx()
		{	return rtx;	}

		float getrty()
		{	return rty;	}

		void drawObj(double ** rot)
		{
			calcPos(rot);
			glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    			  glColor3f(1.0f, 0.0f, 0.0f); // Red
    			  glVertex2f( ltx, lty );    // x, y
   		 	  glVertex2f( lbx, lby);
    	 		 glVertex2f( rbx, rby);
    			 glVertex2f( rtx, rty);
   			glEnd();
		}

		void mult(float &x,float &y,double ** rot)
		{
			x=x*(float)rot[0][0]+y*(float)rot[1][0];
			y=x*(float)rot[0][1]+y*(float)rot[1][1];
		}

		void calcPos(double ** rot)
		{
			mult(ltx,lty,rot);
			mult(lbx,lby,rot);
			mult(rtx,rty,rot);
			mult(rbx,rby,rot);
		}
};
