/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
double mag(double x, double y, double z){
		double power = pow(x,2.0)+pow(y,2.0)+pow(z,2.0);
		return sqrt(power);

}
int close_to(double tolerance, double point, double value){
		double temp1=point-tolerance;
		double temp2=point+tolerance;
	
		if( value == temp1 || value == temp2){
				return 1;
		}else{
			return 0;
		}
		
}
double calculate_fall(double t){
	double distance = 0.5*9.8*(t*t);
	return distance;	
}
double seconds(double time){
	return time/1000;
}

int main(void) {
    double t,ax, ay, az,time,temptime1,temptime2;
	const double gravity = 0.8;
	int count = 0;
	bool running = true;
	const int point = 10;
	bool fallingdetected = false;
	bool check2 = false;
	bool run = true;
	printf("Matthew Estes\n");
	printf("184531401\n");
	
	
	
	
	
	
    while (running) {
		scanf("%lf, %lf, %lf, %lf", &t, &ax, &ay, &az);
		count++;
		if(count ==1){
			printf("Ok, I'm now recieving data\n");
			fflush(stdout);
			printf("I'm waiting");
			
			
		}
		if(count%point==0 && mag(ax,ay,az)>gravity){
			printf(" .");
			fflush(stdout);
		}
		if(mag(ax,ay,az)<gravity){
			
			
			if(!fallingdetected){
				
				printf("\n");
				printf("	Help me! I'm falling");
				fflush(stdout);
				//setting a temp time to find the difference between when the controller starts free fall and when it ends 
				temptime1=t;
				fallingdetected=true;
				
			} else if(count % point == 0){
				printf(" !");
				fflush(stdout);
			}
			
		}else if(fallingdetected){
			
			if(mag(ax,ay,az)>gravity){
				temptime2=t;
				time = temptime2-temptime1;
				printf("\n");
				printf("		Ouch! I fell %.3lf meters in %.3lf seconds.", calculate_fall(seconds(time)),seconds(time));
				fflush(stdout);
				
				check2==true;
				running = false;
				run=false;
			}
		}	
			
		
		
		
			
		
		
		
		
		
    }

    return 0;
}

/* Put your functions here */
