#include "func.hpp"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <string>

namespace es
{
	int number()
	{
		std::ifstream fin;
		fin.open("C:\\Users\\student24\\Desktop\\laba1.1.1\\laba1.1.1\\time.txt");
		int counter = 0;
		if (fin.is_open())
		{
			std::string line;
			while (std::getline(fin, line))
			{
				counter++;
			}
		}
		fin.close();
		return counter;
	}

	void gtime()
	{
		time_t mytime = time(NULL);
		struct tm* now = localtime(&mytime);
		int year = now->tm_year + 1900;
		int month = now->tm_mon + 1;
		int day = now->tm_mday;
		int hour = now->tm_hour;
		int min = now->tm_min;
		int sec = now->tm_sec;
		std::cout << year << "-" << month << "-" << day << "-" << hour << "-" << min << "-" << sec << std::endl;

		std::ofstream fout;
		fout.open("C:\\Users\\student24\\Desktop\\laba1.1.1\\laba1.1.1\\time.txt", std::ofstream::app);
		if (fout.is_open())
		{
			fout << number() + 1 << "_" << year << "-" << month << "-" << day << "-" << hour << "-" << min << "-" << sec << std::endl;
		}
		fout.close();
	}
}