#include "app.h"
 
#include "lib.h"
 
int app_run()
{
    printf("Call app_run()\n");
	do_work();

    printf("arr[0]=%d\n", arr[0]);
    printf("arr=%p\n", arr);

    return 0;
}
