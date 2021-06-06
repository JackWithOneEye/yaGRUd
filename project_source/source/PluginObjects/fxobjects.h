#pragma once

#include <memory>
#include <math.h>
#include "guiconstants.h"

constexpr auto CH_LEFT = 0;
constexpr auto CH_RIGHT = 1;

const double kSmallestPositiveFloatValue = 1.175494351e-38;         /* min positive value */
const double kSmallestNegativeFloatValue = -1.175494351e-38;         /* min negative value */

inline bool checkFloatUnderflow(double& value)
{
	bool retValue = false;
	if (value > 0.0 && value < kSmallestPositiveFloatValue)
	{
		value = 0;
		retValue = true;
	}
	else if (value < 0.0 && value > kSmallestNegativeFloatValue)
	{
		value = 0;
		retValue = true;
	}
	return retValue;
}

inline double sigmoid(double x)
{
	return 1.0 / (1.0 + exp(-x));
}

enum class dcfStatus { kOFF, kON };

struct GRUParameters
{
	GRUParameters() {};

	GRUParameters& operator=(const GRUParameters& params)
	{
		if (this == &params)
			return *this;
		input_gain_dB = params.input_gain_dB;
		W_f = params.W_f;
		W_h = params.W_h;
		U_f = params.U_f;
		U_h = params.U_h;
		b_f = params.b_f;
		dcf = params.dcf;
		output_gain_dB = params.output_gain_dB;
		return *this;
	}

	double input_gain_dB = 0.0;
	double W_f = 0.5;
	double W_h = 0.5;
	double U_f = 0.5;
	double U_h = 0.5;
	double b_f = 0.5;
	dcfStatus dcf = dcfStatus::kOFF;
	double output_gain_dB = 0.0;
};

class GRUUnit
{
public:
	GRUUnit() {};
	~GRUUnit() {};

	double processAudioSample(double x);

	void setCoeffs(const GRUParameters& _params) { 
		W_f = _params.W_f;
		W_h = _params.W_h;
		U_f = _params.U_f;
		U_h = _params.U_h;
		b_f = _params.b_f;
	}

	void reset()
	{
		yn_1 = 0.0;
	}

private:
	double W_f = 0.5;
	double W_h = 0.5;
	double U_f = 0.5;
	double U_h = 0.5;
	double b_f = 0.5;

	double yn_1 = 0.0;
};

class DCFilter
{
public:
	DCFilter() {};
	~DCFilter() {};

	double processAudioSample(double x)
	{
		double y = x - xn1 + dcf_coeff * yn1;
		checkFloatUnderflow(y);
		xn1 = x;
		yn1 = y;
		return y;
	}

	void reset()
	{
		xn1 = 0.0;
		yn1 = 0.0;
	}

private:
	const double dcf_coeff = 0.995;

	double xn1 = 0.0;
	double yn1 = 0.0;
};

class GRUBlock
{
public:
	GRUBlock() {};
	~GRUBlock() {};

	GRUParameters getParameters() { return params; }

	double processAudioSample(double x);

	void reset()
	{
		dcf.reset();
		unit.reset();
	}

	void setParameters(const GRUParameters& _params) 
	{
		if (params.input_gain_dB != _params.input_gain_dB)
		{
			input_gain_lin = pow(10.0, _params.input_gain_dB / 20.0);
		}
		if (params.output_gain_dB != _params.output_gain_dB)
		{
			output_gain_lin = pow(10.0, _params.output_gain_dB / 20.0);
		}
		unit.setCoeffs(_params);
		params = _params;
    }

private:
	DCFilter dcf;
	double input_gain_lin = 1.0;
	double output_gain_lin = 1.0;
	GRUParameters params;
	GRUUnit unit;

};