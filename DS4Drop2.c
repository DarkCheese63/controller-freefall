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

double distance_air(double t,double v,double xi){
	
	double x = xi + (v * t);
	return x-10;
}

double calculate_percentage(double initial, double final){
	return ((initial-final)/initial)*100;
}

double velocity_change(double v1,double time, double acceleration){
	
	return ( v1 + (9.8*(1-acceleration)*(time)));
}


int main(void) {
    double t,ax, ay, az,time,temptime1,temptime2,velocity,temptime3,time2;
	const double gravity = 0.8;
	int count = 0;
	bool running = true;
	const int point = 10;
	bool fallingdetected = false;
	bool check2 = false;
	bool run = true;
	velocity=0;
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
				time2 =temptime1-temptime2;
				double fall = calculate_fall(seconds(time));
				velocity = velocity_change(calculate_fall(seconds(time2)),seconds(time),mag(ax,ay,az));
				
			
				printf("\n");
				printf("		Ouch! I fell %.3lf meters in %.3lf seconds.\n",fall,seconds(time));
				printf("Compensating for air resistance , the fall was %.3lf meters.\n", distance_air(seconds(time),fall/seconds(time),calculate_fall(seconds(time))));
				printf("this is %.0lf",calculate_percentage(calculate_fall(seconds(time)),distance_air(seconds(time),fall/seconds(time),calculate_fall(seconds(time)))));
				printf("%% less than computed before\n");
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
