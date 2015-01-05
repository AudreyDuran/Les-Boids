#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Population.h"


int main()
{
	srand(time(NULL));

	Agent test;
	Agent test2;
    printf("x=%lf y=%lf vx=%lf \n", test.getx(), test.gety(), test.getVx());

    Population pop;
    printf("nb pop : %d\n", pop.getNbPop());
    pop.add(test);
    printf("nb pop : %d\n", pop.getNbPop());
    

	
    pop.run();


    

    return 0;
}
