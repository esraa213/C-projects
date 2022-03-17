//Esraa Sayed Abd el azeem
//id:1809957
//section :1
#include<iostream>
#include<math.h>
#include <limits>
#include<stdio.h>
using namespace std;
int determinant( int first[3][3], int n) {
   int det = 0;
   int submatrix[3][3];
   if (n == 2)
   return ((first[0][0] * first[1][1]) - (first[1][0] * first[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int c = 1; c < n; c++) {
            int subj = 0;
            for (int d = 0; d < n; d++) {
               if (d == x)
               continue;
               submatrix[subi][subj] = first[c][d];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * first[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}
main()
{
   int  n, c, d,f, first[3][3], second[3][3], sum[3][3],
	   minus[3][3], times[3][3] ,ar[2][2];
   char ans;


   cout << "\n\t\t\tWelcome! :)\n";
   cout << "\n\tThis is my Matrix calculator Program\n";
   cout	<< endl;

   cout << "\n\nEnter the size of the matrix (2x2) or (3x3) : \n";
   cout << "[ enter 2 if your matrix is (2x2) or 3 if  your matrix  is (3x3): ";
   cin >> n;
   cout << endl;
   cout << " how many matrices would you input ? ";
   cout << " enter 1 for 1 matrix or 2 for two matrix ";
   cin >> f;
   if (f==2) {
   cout << "Enter the elements of first matrix: \n";
   cout << endl;

   for (  c = 0 ; c < n ; c++ )
      for ( d = 0 ; d < n ; d++ )
         cin >> first[c][d];
		cout << endl;

   cout << "Enter the elements of second matrix: \n";
   cout << endl;

   for ( c = 0 ; c < n ;c++ )
      for ( d = 0 ; d < n ; d++ )
            cin >> second[c][d];
	  cout << endl;
	  int choice = 0;
 cout << "\n** choose from the following **\n\n"
            << "1 - Addition\n"
            << "2 - Subtraction\n"
            << "3 - multiplication\n"
            << "4 - Quit\n\n"
            << "enter your choice: ";
while(!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nERROR: Please enter valid input!\n"
				 << "Enter your choice again: ";
		}

        cout << endl;

        switch(choice) {

        case 1 :
            for ( c = 0 ; c < n ; c++ )
      for ( d = 0 ; d < n ; d++ )
         sum[c][d] = first[c][d] + second[c][d];

   cout << "Sum of entered matrices: \n";
   cout << endl;

   for ( c = 0 ; c < n ; c++ )
   {
      for ( d = 0 ; d < n ; d++ )
         cout << sum[c][d] << "\t";

      cout << endl;
   }
break;
        case 2 :
      for ( c = 0 ; c < n ; c++ )
      for ( d = 0 ; d < n ; d++ )
         minus[c][d] = first[c][d] - second[c][d];

   cout << "subtraction of Entered Matrices: \n";
   cout << endl;

   for ( c = 0 ; c < n ; c++ )
   {
      for ( d = 0 ; d < n ; d++ )
         cout << minus[c][d] << "\t";

      cout << endl;
   }
            break;
   case 3 :
       for ( c = 0 ; c < n ; c++ )
      for ( d = 0 ; d < n ; d++ )
         times[c][d] = first[c][d] * second[c][d];

   cout << "multiplication of Entered Matrices: \n";
   cout << endl;

   for ( c = 0 ; c < n ; c++ )
   {
      for ( d = 0 ; d < n ; d++ )
         cout << times[c][d] << "\t";
      cout << endl;
   }
    break ;
        case 4 :
			cout << "Thank you for using this software! :D\n";
            break;

        default :
            cout << "That's not a choice.\n";
        }

        cout << "\npress any key...\n";

		// clears input buffer and wait for input:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("CLS");
   cout << "\nDo you want to solve another matrix?\n";
   cout << "[Y] or [N]: ";
   cin  >> ans;
   cout << endl;
   if (ans== 'Y')

	   return main ();


   else (ans == 'N');

	   return 0;
   }
else
{
    cout << "Enter the elements of first matrix: \n";
   cout << endl;

   for (  c = 0 ; c < n ; c++ )
      for ( d = 0 ; d < n ; d++ )
         cin >> first[c][d];
		cout << endl;
   int choice = 0;
   cout << "\n** You choose from the following **\n\n"
            << "1 - determinant\n"
            << "2 - inverse of the matrix\n"
            << "3 - Quit\n\n"
            << "enter your choice: ";
while(!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nERROR: Please enter valid input!\n"
				 << "Enter your choice again: ";
		}

        cout << endl;

        switch(choice) {

        case 1 :
          cout<<"Determinant of the matrix is "<< determinant(first, n);
   return 0;
      cout << endl;
      break;
      case 2 :
          if (n==3) {
	cout<<("\nInverse of matrix is: \n");
	for(c= 0; c < 3; c++){
		for(d = 0; d < 3; d++)
			cout<<(((first[(d+1)%3][(c+1)%3] * first[(d+2)%3][(c+2)%3]) - (first[(d+1)%3][(c+2)%3] * first[(d+2)%3][(c+1)%3]))/ determinant(first, n))<<"\t";

	 cout << endl;
	}

	}
            else if (n==2) {
double ar[2][2]= {{first[1][1]   , -first[0][1] } ,{-first[1][0]  , first[0][0] } };
// output each array element's value
   for ( int c = 0; c < 2; c++ )
      for ( int d = 0; d < 2; d++ ) {

         cout << "ar[" << c << "][" << d << "]: ";
         cout << ar[c][d]/(determinant(first, n))<< endl;
      }
   return 0;
}
		// clears input buffer and wait for input:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("CLS");
        cout << "\nDo you want to solve another matrix?\n";
   cout << "[Y] or [N]: ";
   cin  >> ans;
   cout << endl;
   if (ans== 'Y')

	   return main ();


   else (ans == 'N');

	   return 0;
        }
   }
}


