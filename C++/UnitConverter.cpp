#include <iostream>
#include <cmath>

using namespace std;

int main() {

  // Initialize some variables pre-hand
  float floatA = 0.0, floatB = 0.0, floatC = 0.0, floatD = 0.0,
         floatE = 0.0;
  int a = 0, b = 0, c = 0, d = 0, e = 0;

START:
  system("CLS"); // Clears the console
  a = 0; // Sets integer a to 0

  // Outputs choosable options to the user
  cout << "1. TEMPERATURE" << endl
       << "2. TIME" << endl
       << "3. AREA" << endl
       << "4. MASS" << endl
       << "5. VOLUME" << endl
       << "6. LENGTH" << endl
       << endl
       << "0. Exit Program" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;

  cout << endl;
  system("CLS");

  switch (a) {
    case 0:
      exit(0);
      break;
    case 1: {
      goto TEMPERATURE;
    } break;
    case 2: {
      goto TIME;
    } break;
    case 3: {
      goto AREA;
    } break;
    case 4: {
      goto MASS;
    } break;
    case 5: {
      goto VOLUME;
    } break;
    case 6: {
      goto LENGTH;
    } break;
  }

// Below are self explanatory
TEMPERATURE:
  system("CLS");
  a = 0;

  cout << "TEMPERATURE CONVERSION" << endl << endl;
  cout << "1. Fahrenheit to Celsius" << endl
       << "2. Celsius to Fahrenheit" << endl 
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) { 
  case 0: {
      goto START;
  } break;
  case 1: {
    cout << "Converting Fahrenheit to Celsius." << endl
         << "Enter the temperature: ";
    cin >> floatA;

    floatB = (floatA - 32) * 5 / 9;
    floatB = roundf(floatB * 100) / 100;
    cout << endl << endl << floatA << "F in Celsius is " << floatB << "C" << endl;
    system("PAUSE");
    goto TEMPERATURE;
  } break;
  case 2: {
    cout << "Converting Fahrenheit to Celsius." << endl
         << "Enter the temperature: ";
    cin >> floatA;
    floatB = (floatA * 9 / 5) + 32;
    floatB = roundf(floatB * 100) / 100;
    cout << endl << endl << floatA <<"C in Fahrenheit is " << floatB << "F" << endl;
    system("PAUSE");
    goto TEMPERATURE;
  } break;
  }

TIME:
  system("CLS");
  a = 0;

  cout << "TIME CONVERSION" << endl << endl;
  cout << "1. Second to Minutes" << endl
       << "2. Minute to Seconds" << endl
       << "3. Minute to Hour" << endl
       << "4. Hour to Minute" << endl
       << "5. Hour to Day" << endl
       << "6. Day to Hour" << endl
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) {
    case 0: {
      goto START;
    } break;
    case 1: {
      cout << "Converting Second to Minutes." << endl
           << "Enter seconds: ";
      cin >> floatA;

      floatB = floatA / 60;
      cout << endl
           << endl
           << floatA << " seconds is " << floatB << " minutes" << endl;
      system("PAUSE");
      goto TIME;
    } break;
    case 2: {
      cout << "Converting Minute to Seconds." << endl
           << "Enter minutes: ";
      cin >> floatA;

      floatB = floatA * 60;
      cout << endl
           << endl
           << floatA << " minutes is " << floatB << " seconds" << endl;
      system("PAUSE");
      goto TIME;
    } break;
    case 3: {
      cout << "Converting Minute to Hour." << endl
           << "Enter minutes: ";
      cin >> floatA;

      floatB = floatA / 60;
      cout << endl
           << endl
           << floatA << " minutes is " << floatB << " hours" << endl;
      system("PAUSE");
      goto TIME;
    } break;
    case 4: {
      cout << "Converting Hour to Minute." << endl << "Enter hours: ";
      cin >> floatA;

      floatB = floatA * 60;
      cout << endl
           << endl
           << floatA << " hours is " << floatB << " minutes" << endl;
      system("PAUSE");
      goto TIME;
    } break;
    case 5: {
      cout << "Converting Hour to Day." << endl << "Enter hours: ";
      cin >> floatA;

      floatB = floatA / 24;
      cout << endl
           << endl
           << floatA << " hours is " << floatB << " days" << endl;
      system("PAUSE");
      goto TIME;
    } break;
    case 6: {
      cout << "Converting Day to Hour." << endl << "Enter days: ";
      cin >> floatA;

      floatB = floatA * 24;
      cout << endl
           << endl
           << floatA << " days is " << floatB << " hours" << endl;
      system("PAUSE");
      goto TIME;
    } break;
  }

AREA:
  system("CLS");
  a = 0;

  cout << "AREA CONVERSION" << endl << endl;
  cout << "1. Square metre to Square kilometre" << endl
       << "2. Square kilometre to Square metre" << endl
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) {
    case 0: {
      goto START;
    } break;
    case 1: {
      cout << "Converting Square metre to Square kilometre." << endl << "Enter Square metre: ";
      cin >> floatA;

      floatB = floatA / 1000000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << " Square metre is " << floatB << " Square kilometre" << endl;
      system("PAUSE");
      goto AREA;
    } break;
    case 2: {
      cout << "Converting Square kilometre to Square metre." << endl << "Enter Square kilometre: ";
      cin >> floatA;

      floatB = floatA * 1000000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << " Square kilometre is " << floatB << " Square metre" << endl;
      system("PAUSE");
      goto AREA;
    } break;
  }

MASS:
  system("CLS");
  a = 0;

  cout << "MASS CONVERSION" << endl << endl;
  cout << "1. kg to g" << endl
       << "2. g to kg" << endl
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) {
    case 0: {
      goto START;
    } break;
    case 1: {
      cout << "Converting kg to g." << endl << "Enter kg: ";
      cin >> floatA;

      floatB = floatA * 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "kg is " << floatB << "g" << endl;
      system("PAUSE");
      goto MASS;
    } break;
    case 2: {
      cout << "Converting g to kg." << endl << "Enter g: ";
      cin >> floatA;

      floatB = floatA / 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "g is " << floatB << "kg" << endl;
      system("PAUSE");
      goto MASS;
    } break;
  }

VOLUME:
  system("CLS");
  a = 0;

  cout << "VOLUME CONVERSION" << endl << endl;
  cout << "1. ml to l" << endl
       << "2. l to ml" << endl
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) {
    case 0: {
      goto START;
    } break;
    case 1: {
      cout << "Converting ml to l." << endl << "Enter ml: ";
      cin >> floatA;

      floatB = floatA / 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "ml is " << floatB << "l" << endl;
      system("PAUSE");
      goto VOLUME;
    } break;
    case 2: {
      cout << "Converting l to ml." << endl << "Enter l: ";
      cin >> floatA;

      floatB = floatA * 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "l is " << floatB << "ml" << endl;
      system("PAUSE");
      goto VOLUME;
    } break;
  }

LENGTH:
  system("CLS");
  a = 0;

  cout << "LENGTH CONVERSION" << endl << endl;
  cout << "1. mm to cm" << endl
       << "2. cm to mm" << endl
       << "3. cm to m" << endl
       << "4. m to cm" << endl
       << "5. m to km" << endl
       << "6. km to m" << endl
       << endl
       << "0. Back" << endl
       << endl;

  cout << "Choose an option: ";
  cin >> a;
  switch (a) {
    case 0: {
      goto START;
    } break;
    case 1: {
      cout << "Converting mm to cm." << endl << "Enter mm: ";
      cin >> floatA;

      floatB = floatA / 10;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "mm is " << floatB << "cm" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
    case 2: {
      cout << "Converting cm to mm." << endl << "Enter cm: ";
      cin >> floatA;

      floatB = floatA * 10;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "cm is " << floatB << "mm" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
    case 3: {
      cout << "Converting cm to m." << endl << "Enter cm: ";
      cin >> floatA;

      floatB = floatA / 100;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "cm is " << floatB << "m" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
    case 4: {
      cout << "Converting m to cm." << endl << "Enter m: ";
      cin >> floatA;

      floatB = floatA * 100;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "m is " << floatB << "cm" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
    case 5: {
      cout << "Converting m to km." << endl << "Enter m: ";
      cin >> floatA;

      floatB = floatA / 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "m is " << floatB << "km" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
    case 6: {
      cout << "Converting km to m." << endl << "Enter km: ";
      cin >> floatA;

      floatB = floatA * 1000;
      floatB = roundf(floatB * 100) / 100;
      cout << endl
           << endl
           << floatA << "km is " << floatB << "m" << endl;
      system("PAUSE");
      goto LENGTH;
    } break;
  }
}
