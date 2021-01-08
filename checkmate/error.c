#include "checkmate.h"

void	error(int error)
{
	//names errors
	if (error == 0)
	{
		printf("\nError: Name too long\n\n");
		scanf("%*[^\n]");
	}
	if (error == 1)
		printf("\nError: Equal names\n\n");

	//memory error
	if (error == 2)
		printf("\nError: Not enough memory\n");
	
	//moving errors
	if (error == 3)
		printf("\nError: Invalid move\n\n");
	if (error == 4)
		printf("\nError: Square is blank\n\n");
}
