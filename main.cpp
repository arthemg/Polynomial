/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 4
 * 10 October 2016
 */

#include "polynomial.h"
#include <iostream>

int main() {
    Polynomial p1, p2;

    char option;
    int polynum, selDegree, newCoef;
    double scalar;
    cout<<"Setting 2 polynomials"<<endl;
    cout<<"Setting 1st Polynomial"<<endl;
    p1 = p1.setUpPoly();
    cout<<"Your 1st polynomials is: "<< p1<< endl;
    cout<<"Setting 2nd Polynomial"<<endl;
    p2 = p2.setUpPoly();
    cout<<"Your 2nd polynomials is: "<< p2<< endl;

    cout<<"You have following operations you can perform with your polynomials:"<<endl;
    cout<<"O - print polynomial."<<endl;
    cout<<"D - divide by a scalar ( p1/2.5)"<<endl;
    cout<<"N - negate the polynomial"<<endl;
    cout<<"A - to add both polynomials"<<endl;
    cout<<"S - set coefficient"<<endl;
    cout<<"Q - to quit the program"<<endl;

    do
    {
        cout<<"Enter the option: ";
        cin>> option;
        option = tolower(option);

        switch (option)
        {
            case 'o':
                cout<<"which polynomial would you like to print, 1 or 2?";
                cin>>polynum;
                if(polynum == 1)
                {
                    cout<<p1<<endl;
                }
                else if(polynum ==2 )
                {
                    cout<<p2<<endl;
                }
                else
                {
                    cout<<"Please select either 1 or 2"<<endl;
                }
                break;
            case 'd':
                cout<<"Which polynomial would you like to divide? Please choose 1 or 2 ";
                cin>>polynum;
                cout<<"Please enter the scalar: ";
                cin>>scalar;
                if(polynum == 1)
                {

                    cout<<(p1/scalar)<<endl;
                }
                else if(polynum ==2 )
                {
                    cout<<(p2/scalar)<<endl;
                }
                else
                {
                    cout<<"Please select either 1 or 2"<<endl;
                }
                break;
            case 'n':
                cout<<"Which polynomial would you like to negate? Please choose 1 or 2 ";
                cin>>polynum;
                if(polynum == 1)
                {

                    cout<<-p1<<endl;
                }
                else if(polynum ==2 )
                {
                    cout<<-p2<<endl;
                }
                else
                {
                    cout<<"Please select either 1 or 2"<<endl;
                }
                break;
            case'a':
                cout<<"Adding Polynomial 1 and 2: "<<endl;
                cout<<"There resulting Polynomial is: "<< (p1+p2)<<endl;
                break;
            case's':
                cout<<"Coefficient of which polynomial would you like to change, 1 or 2? ";
                cin>>polynum;
                if(polynum == 1) {

                        cout << "Please enter the degree: ";
                        cin >> selDegree;
                        if ((selDegree > p1.getDegree()-1) || (selDegree < 0))
                        {
                            cout << "The max degree allowed is: " << p1.getDegree()-1 << endl;
                            break;

                        }
                        cout << "Please enter new coefficient: ";
                        cin >> newCoef;
                        p1.setCoeff(selDegree, newCoef);
                        cout << "New polynomials is: " << p1 << endl;
                    }
                else if(polynum ==2 )
                {
                    cout<<"Please enter the degree: ";
                    cin>>selDegree;
                    if ((selDegree > p1.getDegree()-1) || (selDegree < 0))
                    {
                        cout << "The max degree allowed is: " << p2.getDegree()-1 << endl;
                        break;
                    }
                    cout<<"Please enter new coefficient: ";
                    cin>>newCoef;
                    p2.setCoeff(selDegree, newCoef);
                    cout<<"New polynomials is: "<< p2<< endl;
                }
                else
                {
                    cout<<"Please select either 1 or 2"<<endl;
                }
                break;
            case'q':
                cout<<"Thank you for using polynomial program! Good Bye.";
                break;
            default:
                cout<<"Please select collect right option.";

        }
    }while(option != 'q');

    return 0;
}