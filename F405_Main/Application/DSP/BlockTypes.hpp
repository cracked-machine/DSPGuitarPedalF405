/*
 * BlockTypes.hpp
 *
 *  Created on: 18 Apr 2021
 *      Author: chris
 */

#ifndef DSP_BLOCKTYPES_HPP_
#define DSP_BLOCKTYPES_HPP_

namespace AudioBlockTypes
{

	// Generic U16 Audio block STL array
	template <size_t S>
	using AudioBlockU16 = std::array<uint16_t, S>;

	// Generic F32 Audio block STL array
	template <size_t S>
	using AudioBlockF32 = std::array<float, S>;
}

namespace FilterArrayTypes
{
	// Array of state variables for IIR filter
	template <size_t S>
	using IIRState = std::array<float, S>;

	// Array of coefficients for IIR filters
	template <size_t S>
	using IIRCoeffSet = std::array<float, S>;

}



#endif /* DSP_BLOCKTYPES_HPP_ */
