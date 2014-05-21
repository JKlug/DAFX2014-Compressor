/*------------------------------------------------------------------*\
 Interface to a Delay Plugin for mono audio signals with an static
 delay time of 80 samples.
 public domain
 Author: Nils Schreiber, Philip Luedtke , Stephanus Volke (TGM) (Jade-Hochschule)
 \*------------------------------------------------------------------*/

#ifndef _DELAY_H_TGM_
#define _DELAY_H_TGM_

#include <math.h>
#include <iostream>

class CDelay
{
public:
	CDelay(void);
	~CDelay(void);
	void reset(void);
	int processSamples(double *In, double *Out, int nSamples);
	inline double processOneSample(double In)
    {
        double Out = m_buffer[79];
        memmove(&m_buffer[1], &m_buffer[0], sizeof(m_buffer) - sizeof(*m_buffer));
        m_buffer[0] = In;
        return Out;
    };
    
protected:
	double m_buffer[80];
};



#endif
