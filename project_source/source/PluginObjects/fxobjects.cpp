#include <memory>
#include <math.h>
#include "fxobjects.h"

double GRUUnit::processAudioSample(double x)
{
	double f = sigmoid(W_f * x + U_f * yn_1 + b_f);
	double yn = (1.0 - f) * yn_1 + f * tanh(W_h * x + U_h * f * yn_1);
	yn_1 = yn;
	return yn;
}

double GRUBlock::processAudioSample(double x)
{
	double unit_out = unit.processAudioSample(x * input_gain_lin);
	if (params.dcf == dcfStatus::kON)
	{
		return dcf.processAudioSample(unit_out) * output_gain_lin;
	}
	return unit_out * output_gain_lin;
}