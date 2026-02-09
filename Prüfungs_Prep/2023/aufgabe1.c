

double mySqrt(double x){

	double y = 1.0;
	double eps = 0.0000000001;
	
	while(y*y - x > eps || y*y - x < -eps){

		double y_next;
		y_next = y/2 + x/(2*y);
		y = y_next;
 			
	}

  return y;
	
}
