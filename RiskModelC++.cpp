#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

int main()
{
	int NumberOfClaims;
	int NumberOfYears;
	double ClaimAmount[100];
	double TotalClaimAmount[50];
	double HighestClaimAmount[50];
	double AverageClaimAmount[50];
	double avClaim;

	std::default_random_engine generator;
	std::lognormal_distribution<double> distribution(9.0, 1.5);

	for (NumberOfYears = 1; NumberOfYears <= 20; NumberOfYears++)
	{


		AverageClaimAmount[NumberOfYears - 1] = 0;
		HighestClaimAmount[NumberOfYears - 1] = 0;
		TotalClaimAmount[NumberOfYears - 1] = 0;
		for (int index = 0; index < 100; index++)
		{
			ClaimAmount[index] = distribution(generator);
			AverageClaimAmount[NumberOfYears - 1] += ClaimAmount[index];
			TotalClaimAmount[NumberOfYears - 1] += ClaimAmount[index];
			if (HighestClaimAmount[NumberOfYears - 1] < ClaimAmount[index])
			{
				HighestClaimAmount[NumberOfYears - 1] = ClaimAmount[index];
			}
		}
		AverageClaimAmount[NumberOfYears - 1] /= 100;

	}
	
	for (int index = 0; index < 20; index++)
	{
		std::cout << "-Year "  <<index + 1 << "-\nAverage Claim Amount = " << std::setprecision(10) << AverageClaimAmount[index] << "\nHighest Claim Amount = " << std::setprecision(10) << HighestClaimAmount[index] << std::endl;
		std::cout << "Total Claim Amount = " << std::setprecision(10) << TotalClaimAmount[index] << std::endl;
	}
}
