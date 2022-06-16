#include  "RGB_LED.h"
 

#define	PINVAL(x) 	(type == COMMON_CATHOD ? (x) : (255 - (x)))



RGB_LED::RGB_LED(
	int _pinred, int _pingreen, int _pinblue , bool _type
) {
	pinred = _pinred;
	pinblue = _pinblue;
	pingreen = _pingreen;
	type = _type;
	index = 0;
	_params = NULL;
	pinMode(_pinred, OUTPUT);
	pinMode(_pingreen, OUTPUT);
	pinMode(_pinblue, OUTPUT);
	setRGB(0);
}

void RGB_LED::set (unsigned long *param, int _repeat) {
	if (!param && _params) {
		setRGB(0);
	}	
	_params = param;
	if (!_params)
		return;
	index = 0;	
	startTime = millis();
	repeat = _repeat;
	count = *param;
	setRGB(_params[1+index*2]);
}

int RGB_LED::tick(void) {
	int		i;
	unsigned long	t = 0;
	unsigned long	delta;

	if (!_params)
		return 0;

	delta = millis() - startTime;

	for (i=0; i<count; i++) {
		t += _params[2+i*2];
		

		if (delta > t)
			continue;

		break;
	}

	if (index == i)
		return 0;

	if (i >= count) {
		startTime = millis();
		if (repeat == 0) {
			i = 0;
		} else if (repeat == 1) {
			_params = NULL;
		} else {
			i = 0;
			repeat--;
		}
		if (!_params) {
			setRGB(0);
			return 0;
		} 
	} 

	index = i;
	setRGB(_params[1+index*2]);
	return 0;
} 

void RGB_LED::setColor(unsigned long colorRGB) {
	_params = NULL;
	setRGB(colorRGB);
}

void RGB_LED::gradient(unsigned long *array, int startIndex, int steps, unsigned long stepPeriod, unsigned long fromRGB, unsigned long toRGB) {
	int i;
	long fromR = (fromRGB >> 16) & 0xFFL;
	long fromG = (fromRGB >> 8) & 0xFFL;
	long fromB = fromRGB & 0xFFL;
	long toR = toRGB >> 16 & 0xFFL;
	long toG = toRGB >> 8 & 0xFFL;
	long toB = toRGB & 0xFFL;
	long stepR = (toR - fromR) / (steps-1);
	long stepG = (toG - fromG) / (steps-1);
	long stepB = (toB - fromB) / (steps-1);
	for (i=0; i<steps; i++) {
		unsigned long stepColor = ((fromR + stepR*i)<<16) | ((fromG + stepG*i)<<8) | (fromB + stepB*i);
		array[(i+startIndex)*2 - 1] = stepColor;
		array[(i+startIndex)*2] = stepPeriod;
	}
	array[(steps-1+startIndex)*2 - 1] = toRGB;
}

void RGB_LED::fadeToColor(unsigned long toRGB, unsigned long period) {
	fadeColors(currentColor, toRGB, period);
}

void RGB_LED::fadeColors(unsigned long fromRGB, unsigned long toRGB, unsigned long period) {
	fadeParams[0] = FADE_STEPS;
        unsigned long stepPeriod = period / (FADE_STEPS-1);
	gradient(fadeParams, 1, FADE_STEPS, stepPeriod, fromRGB, toRGB);
	fadeParams[FADE_STEPS*2] = 0xFFFFFFF0L-period;
	set(fadeParams, 1);
}

void RGB_LED::pulseColor(unsigned long toRGB, unsigned long period) {
	pulseColors(currentColor, toRGB, period);
}

void RGB_LED::pulseColors(unsigned long fromRGB, unsigned long toRGB, unsigned long period) {
	fadeParams[0] = FADE_STEPS;
	unsigned long stepPeriod = period / (FADE_STEPS-1);
	gradient(fadeParams, 1, FADE_STEPS/2, stepPeriod, fromRGB, toRGB);
	gradient(fadeParams, 1 + FADE_STEPS/2, FADE_STEPS/2, stepPeriod, toRGB, fromRGB);
	set(fadeParams, 0);
}

void RGB_LED::setRGB(unsigned long p) {
	currentColor = p;
	analogWrite(pinred, PINVAL(p >> 16 & 0xFF));	
	analogWrite(pingreen, PINVAL(p >> 8 & 0xFF));
	analogWrite(pinblue, PINVAL(p & 0xFF));
}

