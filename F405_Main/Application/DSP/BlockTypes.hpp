/*
 * BlockTypes.hpp
 *
 *  Created on: 18 Apr 2021
 *      Author: chris
 */

#ifndef DSP_BLOCKTYPES_HPP_
#define DSP_BLOCKTYPES_HPP_


	// define alias template to std::array<uint16_t, S> for parameter use
	template <size_t S>
	using StereoBlockU16 = std::array<uint16_t, S>;

	template <size_t S>
	using MonoBlockF32 = std::array<float, S>;

	template <size_t S>
	using IIRState = std::array<float, S>;

	template <size_t S>
	using IIRCoeffSet = std::array<float, S>;



#endif /* DSP_BLOCKTYPES_HPP_ */
