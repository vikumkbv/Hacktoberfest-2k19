#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int TemperatureConverter();
int EarthquakeEffect();
int WindSpeed();
int WeatherBalloon();
double Celsius(int);
double Fahrenheit(int);
double Kelvin(int);
double knot(int);
float alt(float);
float vel(float);
void toHour(int, int&, int&);

int main()
{ 
START:
  system("CLS");

  int choice;
  cout << "THE EARTH" << endl;
  cout << "---------" << endl;

  cout << endl
       << "1. Temperature Converter" << endl
       << "2. Earthquake Effect" << endl
       << "3. Wind Speed" << endl
       << "4. Weather Balloon" << endl
       << endl
       << "Press 0 to exit." << endl;

  cout << "Choose an option: ";
  cin >> choice;

  switch (choice) {
    case 1: {
      if (!TemperatureConverter()) goto START;
    } break;
    case 2: {
      if (!EarthquakeEffect()) goto START;
    } break;
    case 3: {
      if (!WindSpeed()) goto START;
    } break;
    case 4: {
      if (!WeatherBalloon()) goto START;
    } break;
    case 0: {
      exit(0);
    } break;
    default: { goto START; }
  }
}

int TemperatureConverter() { 
  system("CLS");
  cout << "Temperature Converter" << endl << endl;

  cout << "\n\nCelsius" << "\tFahrenheit" << "\tKelvin"<<endl;

  for (int i = 0; i <= 100;i+=5){
    cout << Celsius(i) << "\t" << Fahrenheit(i) << "\t\t" << Kelvin(i) << endl;
  }

  cout << endl;
  system("PAUSE");
  return 0;
}

int EarthquakeEffect() {
  system("CLS");
  double N;
  cout << "Earthquake Effect" << endl << endl;

  cout << "Enter the Richter value: ";
  cin >> N;

  cout << "\n\nThe earthquake effect is: ";
  if (N < 5.0) {
    cout << "Little or no damage." << endl;
  } else if (N >= 5.0 && N < 5.5) {
    cout << "Moderate damage." << endl;
  } else if (N >= 5.5 && N < 6.5) {
    cout << "Serious damage." << endl;
  } else if (N >= 6.5 && N < 7.5) {
    cout << "Disaster." << endl;
  } else {
    cout << "Catastrophic damage." << endl;
  }

  cout << endl;
  system("PAUSE");
  return 0;
}

int WindSpeed() {
  system("CLS");
  int N, knots;
  cout << "Wind Speed" << endl << endl;

  cout << "Enter wind speed (mph): ";
  cin >> N;
  knots = knot(N);

  if (knots >= 1 && knots <= 3) {
    cout << "\n\nWind Force: " << 1 << endl;
    cout << "Classification: "
         << "Light Air" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Scaly ripples, no foam crests" << endl;
    cout << "On Land: Smoke drift indicates wind direction, still wind vanes" << endl;
  } else if(knots >= 4 && knots <= 6) {
    cout << "\n\nWind Force: " << 2 << endl;
    cout << "Classification: "
         << "Light Breeze" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Small wavelets, crests glassy, no breaking" << endl;
    cout << "On Land: Wind felt on face, leaves rustle, vanes begin to move" << endl;
  } else if (knots >= 7 && knots <= 10) {
    cout << "\n\nWind Force: " << 3 << endl;
    cout << "Classification: "
         << "Gentle Breeze" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Large wavelets, crests begin to break, scattered whitecaps" << endl;
    cout << "On Land: Leaves and small twigs constantly moving, light flags extended" << endl;
  } else if (knots >= 11 && knots <= 16) {
    cout << "\n\nWind Force: " << 4 << endl;
    cout << "Classification: "
         << "Moderate Breeze" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Small waves 1-4 ft. becoming longer, numerous whitecaps" << endl;
    cout << "On Land: Dust, leaves, and loose paper lifted, small tree branches move"
         << endl;
  } else if (knots >= 17 && knots <= 21) {
    cout << "\n\nWind Force: " << 5 << endl;
    cout << "Classification: "
         << "Fresh Breeze" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Moderate waves 4-8 ft taking longer form, many whitecaps, some spray"
         << endl;
    cout << "On Land: Small trees in leaf begin to sway"
         << endl;
  } else if (knots >= 22 && knots <= 27) {
    cout << "\n\nWind Force: " << 6 << endl;
    cout << "Classification: "
         << "Strong Breeze" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Larger waves 8-13 ft, whitecaps common, more spray"
         << endl;
    cout << "On Land: Larger tree branches moving, whistling in wires" << endl;
  } else if (knots >= 28 && knots <= 33) {
    cout << "\n\nWind Force: " << 7 << endl;
    cout << "Classification: "
         << "Near Gale" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Sea heaps up, waves 13-19 ft, white foam streaks off breakers"
         << endl;
    cout << "On Land: Whole trees moving, resistance felt walking against wind" << endl;
  } else if (knots >= 34 && knots <= 40) {
    cout << "\n\nWind Force: " << 8 << endl;
    cout << "Classification: "
         << "Gale" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Moderately high (18-25 ft) waves of greater length, edges of crests begin to break into spindrift, foam blown in streaks"
         << endl;
    cout << "On Land: Twigs breaking off trees, generally impedes progress"
         << endl;
  } else if (knots >= 41 && knots <= 47) {
    cout << "\n\nWind Force: " << 9 << endl;
    cout << "Classification: "
         << "Strong Gale" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: High waves (23-32 ft), sea begins to roll, dense streaks of foam, spray may reduce visibility"
         << endl;
    cout << "On Land: Slight structural damage occurs, slate blows off roofs"
         << endl;
  } else if (knots >= 48 && knots <= 55) {
    cout << "\n\nWind Force: " << 10 << endl;
    cout << "Classification: "
         << "Storm" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Very high waves (29-41 ft) with overhanging crests, sea white with densely blown foam, heavy rolling, lowered visibility"
         << endl;
    cout << "On Land: Seldom experienced on land, trees broken or uprooted, \" considerable structural damage \""
         << endl;
  } else if (knots >= 56 && knots <= 63) {
    cout << "\n\nWind Force: " << 11 << endl;
    cout << "Classification: "
         << "Violent Storm" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Exceptionally high (37-52 ft) waves, foam patches cover sea, visibility more reduced"
         << endl;
    cout << "On Land: No Data"
         << endl;
  } else if (knots > 64) {
    cout << "\n\nWind Force: " << 12 << endl;
    cout << "Classification: "
         << "Hurricane" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Air filled with foam, waves over 45 ft, sea completely white with driving spray, visibility greatly reduced"
         << endl;
    cout << "On Land: No Data" << endl;
  } else {
    cout << "\n\nWind Force: " << 0 << endl;
    cout << "Classification: "
         << "Calm" << endl;

    cout << "Appearance of Wind Effects" << endl;
    cout << "On Sea: Sea surface smooth and mirror-like"
         << endl;
    cout << "On Land: Calm, smoke rises vertically" << endl;
  }

  cout << endl;
  system("PAUSE");
  return 0;
}

int WeatherBalloon() {
  system("CLS");
  int startTime, interval, endTime, timeDifference;
  cout << "Weather Balloon" << endl << endl;

  do {
    cout << "Enter start time (24hr format): ";
    cin >> startTime;
  } while (startTime < 0 || startTime > 48);

  do {
    cout << "Enter end time (24hr format, maximum 48 hrs advance): ";
    cin >> endTime;
  } while (endTime < 0 || endTime > 48 || endTime < startTime);
  
  cout << "Enter time interval between data: ";
  cin >> interval;

  cout << "\n\nTime (hh:mm)\t\tAltitude\t\tVelocity" << endl;

  for (int i = (startTime * 60); i <= (endTime * 60); i += interval) {
    float t = (float)i / 60;
    int min, hour;
    toHour(i + interval, min, hour);

    cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2)
         << min;
    cout << fixed << setprecision(2) << "\t\t\t" << alt(t) << " m\t\t" << vel(t)
         << "m/s" << endl;
  }

  cout << endl;
  system("PAUSE");
  return 0;
}

double Celsius(int value) { return value; }
double Fahrenheit(int value) { return ((value * (9 / 5)) + 32); }
double Kelvin(int value) { return value + 273.15; }
double knot(int value) { return value / 0.868976242; }

float alt(float time) { 
  float alt = 0;
  alt = -0.12 * pow(time, 4) + 12 * pow(time, 3) - 380.0 * pow(time, 2) +
        4100 * (time) + 220;
  return roundf(alt * 100) / 100;
}

float vel(float time) { 
  float vel = 0;
  vel = -0.48 * pow(time, 3) + 36.0 * pow(time, 2) - 760 * (time) + 4100;
  return roundf(vel * 100) / 100;
}

void toHour(int minute, int& min, int& hour) {
  min = minute % 60;
  hour = minute / 60;
}
