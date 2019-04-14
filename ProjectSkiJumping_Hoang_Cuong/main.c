/*****************************************************************************
 *	APPLICATION:	ProjectSkiJumping_Hoang_Cuong
 *	MODULE:			main
 *	PURPOSE:
 *	AUTHOR(S):		Hoang Cuong
 *
 *	4/12/2019 4:47:06 PM	Created.
 *****************************************************************************/
#include <stdio.h>
/*****************************************************************************
 *	THE MAIN ENTRY POINT TO THE PROGRAM.
 *
 *	input:	argc	The number of arguments of the programme.
 *			argv	The vector of arguments of the programme.
 *	return:	The code of the reason the process was terminated for.
 *			The value defaults to zero.
 *****************************************************************************/
/** Declare the struct hill with 2 data: fixedPoint & distancePoint **/
struct hill
{
	float fixedPoint;		// fixedPoint is the point to start calculating (60 points for small hill, medium hill, normal hill, large hill & 120 points for ski flying hill).
	float distancePoint;	// distnacePoint is the point to bonus and minus from the fixedPoint to calculate the total point.
};

struct hill point(kPoint);			// Function to set up the fixedPoint & distancePoint bases on the K-point.

void printHillsTable();				// Function to print out types of hills table.

void printDistancePointsTable();	// Function to print out distance points table

float totalPointCalculation(int kPoint, float jumpingLength, float fixedPoint1, float distnacePoint1);

int main(int argc, char* argv[])
{
	int kPoint = 0;					// Declare variable integer for the K-Point.
	float jumpingLength = 0.0;		// Declare variable float for the length of ski jumping.
	float totalPoint = 0.0;			// Declare variable float for the total point of ski jumping.
	struct hill calcPoints;			// Declare calcPoints (calculation points & distance points) of type hill.

	printHillsTable();				// Calling function printHillsTable to print out the types of hills table.
	printDistancePointsTable();		// Calling function printDistancePointsTable to print out the distance points table.
	
	/** Input the data of K-point **/
	printf("Please input K-point (only number of meter): ");
	scanf("%d", &kPoint);

	/** Input the data of jumping length **/
	printf("Please input the jumping length: ");
	scanf("%f", &jumpingLength);

	calcPoints = point(kPoint);		// Calling function point to set data for calcPoints.

	totalPoint = totalPointCalculation(kPoint, jumpingLength, calcPoints.fixedPoint, calcPoints.distancePoint);		// Calling function totalPointCalculation to calculate the total point of ski jumping.
	 
	printf("Total point of jumping: %.1f \n", totalPoint);		// Print out the result of total point of ski jumping.

	return 0;
}

/** Function to print out types of hills table **/
void printHillsTable() {
	printf("==========================================================================	\n");
	printf("Class\t\t\t Construction point\t\t\t Hill size								\n");
	printf("==========================================================================	\n");
	printf("1.Small hill\t\t < 45\t\t\t\t\t < 50										\n");
	printf("2.Medium hill\t\t 45 - 75\t\t\t\t 50 - 84									\n");
	printf("3.Normal hill\t\t 75 - 99\t\t\t\t 85 - 109									\n");
	printf("4.Large hill\t\t 100 - 169\t\t\t\t 110 - 184								\n");
	printf("5.Ski flying hill\t >= 170\t\t\t\t\t >= 185									\n");
	printf("\n");
}

/** Function to print out distance points table **/
void printDistancePointsTable() {
	printf("\n");
	printf("================================================	\n");
	printf("Calculation points\t\t Distance points				\n");
	printf("================================================	\n");
	printf("20 - 24\t\t\t\t 4.8									\n");
	printf("25 - 29\t\t\t\t 4.4									\n");
	printf("30 - 34\t\t\t\t 4.0									\n");
	printf("35 - 39\t\t\t\t 3.6									\n");
	printf("40 - 49\t\t\t\t 3.2									\n");
	printf("50 - 59\t\t\t\t 2.8									\n");
	printf("60 - 69\t\t\t\t 2.4									\n");
	printf("70 - 79\t\t\t\t 2.2									\n");
	printf("80 - 99\t\t\t\t 2.0									\n");
	printf("100 - 169\t\t\t 1.8									\n");
	printf("> 170\t\t\t\t 1.2									\n");
	printf("\n");
}

/** Function to set up the fixedPoint & distancePoint bases on the K-point **/
struct hill point(kPoint)
{
	struct hill calcPoint;
	if (kPoint < 20)
	{
		printf("Wrong K-point. \n");
	}
	else if (kPoint >= 170) 
	{
		calcPoint.fixedPoint = 120.0;
		calcPoint.distancePoint = 1.2;
	}
	else if (kPoint >= 20 && kPoint < 170)
	{
		calcPoint.fixedPoint = 60.0;
		if		(kPoint >= 20 && kPoint <= 24) calcPoint.distancePoint = 4.8;
		else if (kPoint >= 25 && kPoint <= 29) calcPoint.distancePoint = 4.4;
		else if (kPoint >= 30 && kPoint <= 34) calcPoint.distancePoint = 4.0;
		else if (kPoint >= 35 && kPoint <= 39) calcPoint.distancePoint = 3.6;
		else if (kPoint >= 40 && kPoint <= 49) calcPoint.distancePoint = 3.2;
		else if (kPoint >= 50 && kPoint <= 59) calcPoint.distancePoint = 2.8;
		else if (kPoint >= 60 && kPoint <= 69) calcPoint.distancePoint = 2.4;
		else if (kPoint >= 70 && kPoint <= 79) calcPoint.distancePoint = 2.2;
		else if (kPoint >= 80 && kPoint <= 99) calcPoint.distancePoint = 2.0;
		else if (kPoint >= 100 && kPoint <= 169) calcPoint.distancePoint = 1.8;
	}

	return calcPoint;
};

/** Function to calculate the total point **/
float totalPointCalculation(int kPoint,float jumpingLength, float fixedPoint, float distancePoint) {
	float totalPoint = 0.0;
	float distance = 0.0;

	if (kPoint < jumpingLength) {
		distance = jumpingLength - kPoint;
		totalPoint = fixedPoint + (distance * distancePoint);
	}
	else if (kPoint > jumpingLength)
	{
		distance = kPoint - jumpingLength;
		totalPoint = fixedPoint - (distance * distancePoint);
	}
	else
	{
		totalPoint = fixedPoint;
	}

	return totalPoint;
}
