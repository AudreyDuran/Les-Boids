#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Population.h"


int main()
{
	srand(time(NULL));

    //Test for Agent's default constructor
	Agent test;
    printf("x=%lf y=%lf vx=%lf \n", test.getx(), test.gety(), test.getVx());

    //Test for Agent's constructor with 4 parameters
    Agent test2 = Agent(0,1,100,100);
    printf("x=%lf y=%lf vx=%lf \n", test2.getx(), test2.gety(), test2.getVx());



    // Test for Population's default constructor
    Population pop;
    printf("nb pop : %d\n", pop.getNbPop());

    //Test add Population's method
    pop.add(test);
    pop.add(test2);
    printf("nb pop : %d\n", pop.getNbPop());
    
    //Test of isClosedTo
   printf("test2.isClosedTo(test,5) = %d \n",test2.isClosedTo(test, 0.2));

	//Test run Population's method
    pop.run();


    

    return 0;
}
