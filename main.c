#include "func.c"

int main(int argc, char* argv[])
{
	if (argc <=1)
	{
		printf("entered too few arguments. Try again.");
		printf("\n");
	}
	if (strcmp(argv[1], "start") == 0)
	{
        printf(strcat("Starting ", argv[2]));
        run_service(argv[2]);
    }
    if (strcmp(argv[1], "stop") == 0)
	{
        printf(strcat("Stopping ", argv[2]));
        stop_service(argv[2]);
    }
}