#ifndef RGB_LED_h
#define RGB_LED_h

#include	<Arduino.h>

#define	COMMON_ANODE		1
#define	COMMON_CATHOD		0
#define FADE_STEPS		10

class RGB_LED {
  public:
	RGB_LED(
		int _pinred = 3, 
		int _pingreen = 5, 
		int _pinblue = 6, 
		bool _type = COMMON_ANODE 
	);
	void set(unsigned long *param, int repeat = 0);
	void setColor(unsigned long colorRGB);
	void fadeToColor(unsigned long toRGB, unsigned long period);
	void fadeColors(unsigned long fromRGB, unsigned long toRGB, unsigned long period);
	int tick(void);
	
private:
	unsigned long   startTime;	
	int	count;
	bool	type;
	int	index;
	int	repeat;
	int	pinred;
	int	pingreen;
	int	pinblue;
	unsigned long currentColor = 0;
	unsigned long *_params = NULL;
	unsigned long  fadeParams[FADE_STEPS*2+1];
	void setRGB(unsigned long p);
};

#endif

