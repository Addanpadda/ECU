#ifndef RPM_H
#define RPM_H

#include <Arduino.h>
#define RPM_PIN 2

class RPM {
private:
  static const byte PulsesPerRevolution = 2;  // Set how many pulses there are on each revolution. Default: 2.
  static const unsigned long ZeroTimeout = 100000;  // For high response time, a good value would be 100000.
  static const byte numReadings = 2;  // Number of samples for smoothing. The higher, the more smoothing, but it's going to
  /////////////
  // Variables:
  /////////////
  
  static volatile unsigned long LastTimeWeMeasured;  // Stores the last time we measured a pulse so we can calculate the period.
  static volatile unsigned long PeriodBetweenPulses;  // Stores the period between pulses in microseconds.
  static volatile unsigned long PeriodAverage;  // Stores the period between pulses in microseconds in total, if we are taking multiple pulses.
  static unsigned long FrequencyRaw;  // Calculated frequency, based on the period. This has a lot of extra decimals without the decimal point.
  static unsigned long FrequencyReal;  // Frequency without decimals.
  static unsigned long rpm;  // Raw RPM without any processing.
  static unsigned int PulseCounter;  // Counts the amount of pulse readings we took so we can average multiple pulses before calculating the period.
  static unsigned long PeriodSum; // Stores the summation of all the periods to do the average.
  static unsigned long LastTimeCycleMeasure;  // Stores the last time we measure a pulse in that cycle.
  static volatile unsigned long CurrentMicros;  // Stores the micros in that cycle.
  static unsigned int AmountOfReadings;
  static unsigned int ZeroDebouncingExtra;  // Stores the extra value added to the ZeroTimeout to debounce it.
  
  // Variables for smoothing tachometer:
  static unsigned long readings[numReadings];  // The input.
  static unsigned long readIndex;  // The index of the current reading.
  static unsigned long total;  // The running total.

  static void RPM_Pulse();
public:
  static unsigned long average;  // The RPM value after applying the smoothing.

  RPM();
  static void calcRPM();
};

#endif
