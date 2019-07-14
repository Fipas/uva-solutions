#include <bits/stdc++.h>

using namespace std;


double roundToTenths(double x)
{
    x *= 10;
    return floor(x + 0.5) / 10;
}


struct student {
	char grade;
	char adjGrade;
	int bonusPoints;
	int abstinence;
	double average;
	double adjAverage;
	vector<double> testScores;
};

int main() {
	cout << "MAKING THE GRADE OUTPUT\n";

	int n;
	cin >> n;

	while (n--) {
		int numStudents, numTests;
		double mean = 0, variance = 0, deviation = 0, avgGrdPnt = 0;
		cin >> numStudents >> numTests;
		vector<student> students(numStudents);

		for (int i = 0; i < numStudents; i++) {
			int bonusPoints, abstinence;
			for (int j = 0; j < numTests; j++) {
				int score;
				cin >> score;
				students[i].testScores.push_back(score);
			}
			if (numTests > 2)
				students[i].testScores.erase(min_element(students[i].testScores.begin(), 
											 students[i].testScores.end()));
			cin >> bonusPoints >> abstinence;
			students[i].bonusPoints = bonusPoints;
			students[i].abstinence = abstinence;
		}

		for (int i = 0; i < numStudents; i++) {
			double sum = 0;
			for (int j = 0; j < students[i].testScores.size(); j++)
				sum += students[i].testScores[j];
			students[i].average = roundToTenths(sum / students[i].testScores.size());
			//cout << "average student " << i << ": " << students[i].average << endl;
			mean += students[i].average;
		}

		mean /= numStudents;
		mean = roundToTenths(mean);
		//cout << "mean: " << mean << endl;

		for (int i = 0; i < numStudents; i++) {
			variance += pow(mean - students[i].average, 2);
		}

		variance /= numStudents;
		variance = roundToTenths(variance);
		deviation = sqrt(variance);
		deviation = roundToTenths(deviation);

		//cout << deviation << endl;

		for (int i = 0; i < numStudents; i++) {
			students[i].average += (students[i].bonusPoints / 2) * 3;
		}

		for (int i = 0; i < numStudents; i++) {
			if (students[i].average >= mean + deviation) {
				students[i].grade = 'A';
			} else if (students[i].average >= mean && students[i].average < mean + deviation) {
				students[i].grade = 'B';
			} else if (students[i].average >= mean - deviation && students[i].average < mean) {
				students[i].grade = 'C';
			} else if (students[i].average < mean - deviation) {
				students[i].grade = 'D';
			}
		}

		for (int i = 0; i < numStudents; i++) {
			if (students[i].abstinence == 0 && students[i].grade != 'A')
				students[i].grade--;

			students[i].grade += students[i].abstinence / 4;
			students[i].grade = min(students[i].grade, 'F');

			if (students[i].grade == 'A')
				avgGrdPnt += 4;
			else if (students[i].grade == 'B')
				avgGrdPnt += 3;
			else if (students[i].grade == 'C')
				avgGrdPnt += 2;
			else if (students[i].grade == 'D')
				avgGrdPnt++;
		}

		avgGrdPnt /= numStudents;
		avgGrdPnt = roundToTenths(avgGrdPnt);

		cout << setprecision(1) << fixed << avgGrdPnt << endl;
	}

	cout << "END OF OUTPUT\n";

	return 0;
}