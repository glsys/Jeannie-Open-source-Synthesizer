// This optional setting causes Encoder to use more optimized code,
// It must be defined before Encoder.h is included.
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include <Bounce.h>

#define BassBoost 14
#define CS_HC595 36
#define PWM1     28
#define PWM2     29
#define PWM3     19
#define PWM4     18
#define PWM5     25
#define ENCODER_PINA 4
#define ENCODER_PINB 5
#define PAGE_SW 17
#define QUANTISE_FACTOR 15// Sets a tolerance of noise on the ADC. 15 is 4 bits
#define DEBOUNCE 30

static byte muxInput = 0;
static int mux1ValuesPrev[16] = {};
static int mux2ValuesPrev[16] = {};
static int mux3ValuesPrev[16] = {};
static int mux4ValuesPrev[16] = {};
static int mux5ValuesPrev[16] = {};
static int mux6ValuesPrev[16] = {};
static int muxVCFValuesPrev[16] = {};

static int mux1Read = 0;
static int mux2Read = 0;
static int mux3Read = 0;
static int mux4Read = 0;
static int mux5Read = 0;
static int mux6Read = 0;
static int volumeRead = 0;
static int volumePrevious = 0;
static long encPrevious = 0;

Encoder encoder(ENCODER_PINB, ENCODER_PINA);//This often needs the pins swapping depending on the encoder

FLASHMEM void setupHardware() {
  //Switches
  pinMode(PAGE_SW, INPUT_PULLUP);
  //LEDs
  pinMode(CS_HC595, OUTPUT);
  //Switches  
  pinMode(BassBoost, OUTPUT);
  digitalWrite(BassBoost,HIGH);  // Boost off
  // PWM Fx
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(PWM4, OUTPUT);
  pinMode(PWM5, OUTPUT);
}
