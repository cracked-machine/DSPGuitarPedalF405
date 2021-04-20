/*
 * Reverb.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */

#include <Reverb.hpp>

BasicReverb::BasicReverb()
{
	combfilter1 = new IIRCombFilter(3460 * 2, 0.805);
	combfilter2 = new IIRCombFilter(2988 * 2, 0.827);
	combfilter3 = new IIRCombFilter(3882 * 2, 0.783);
	combfilter4 = new IIRCombFilter(4312 * 2, 0.764);
	allpass1 = new UniCombFilter(	480  * 2, 0.7);
	allpass2 = new UniCombFilter(	161  * 2, 0.7);
	allpass3 = new UniCombFilter(	46   * 2, 0.7);
}
