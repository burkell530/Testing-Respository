#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
  Temperature::Temperature()
    :kelvin_(0) {
  }

  // Sets kelvin to the supplied value
  Temperature::Temperature(double kelvin)
    :kelvin_(kelvin) {
  }

  // Converts the supplied temperature to kelvin and internally stores it.
  Temperature::Temperature(double temp, char unit) {
    unit = (toupper(unit));
    if (unit == 'F')
      kelvin_ = ((5.0 * (temp - 32) / 9) + 273.15);
    else if (unit == 'C')
      kelvin_ = temp + 273.15;
    else
      kelvin_ = temp;
  }

  // The temperature will come in as kelvin and this function will set the
  // internal temp to this value
  void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
  }

  // The temperature will come in as Fahrenheit and this function will set the
  // internal temp to this value, once converted to kelvin
  void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = celsius + 273.15;
  }

  // Gets the internal temperature in Kelvin.
  void Temperature::SetTempFromFahrenheit(double fahrenheit) {
    kelvin_ = ((5.0 * (fahrenheit - 32) / 9) + 273.15);
  }

  // The temperature will come in as Celsius and this function will set the
  // internal temp to this value, once converted to kelvin
  double Temperature::GetTempAsKelvin() const {
    return kelvin_;
  }

  // Returns the internal temp converted to celsius
  double Temperature::GetTempAsCelsius() const {
    return kelvin_ - 273.15;
  }

  // Returns the internal temp converted to fahrenheit
  double Temperature::GetTempAsFahrenheit() const {
    return (((kelvin_ - 273.15) * 9) / 5.0) + 32;
  }

  /*
  * Get a string representation of the temperature.
  * The string will be formatted as:
  * "TEMP UNIT"
  */
  string Temperature::ToString(char unit) const {
    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.setf(std::ios::showpoint);
    ss.precision(2);
    unit = (toupper(unit));
    switch (unit) {
      case 'F':
        ss << GetTempAsFahrenheit() << " " << "Fahrenheit";
        return ss.str();
        break;
      case 'C':
        ss << GetTempAsCelsius() << " " << "Celsius";
        return ss.str();
        break;
      case 'K':
        ss << GetTempAsKelvin() << " " << "Kelvin";
        return ss.str();
        break;
      default:
        return "Invalid Unit";
    }
  }
