/* 
 * File:  ConsoleArgs.cpp
 * Author: zhangwei
 *
 * Created on September 6, 2016, 1:26 PM
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	for (int i = 0; i < argc ; i++) {
		cout <<  i << " : " << argv[i]<< endl;
	}
}
