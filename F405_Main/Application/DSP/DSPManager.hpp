/*
 * DSPManager.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */


#include <AbstractFx.hpp>

//#include <Reverb.hpp>
//#include <BoundedVector.hpp>


class DSPManager
{

public:
	DSPManager();
	DSPManager(AbstractFx* pFx);
	virtual ~DSPManager();

	void setFx(AbstractFx* pFx);
	AbstractFx* getFx();

	enum SampleMode
	{
		MUTE_MODE = 0,
		BLOCK_SAMPLE_MODE,
		SINGLE_SAMPLE_MODE
	};

	void bringUp();
	void tearDown();



	void setSampleMode(DSPManager::SampleMode pMode);
	DSPManager::SampleMode getSampleMode();

	// use in DSPManager::BLOCK_SAMPLE_MODE
	AudioBlockU16< AbstractFx::STEREO_DOUBLE_BLK_SIZE_U16 > rxBufBlock{};
	AudioBlockU16< AbstractFx::STEREO_DOUBLE_BLK_SIZE_U16 > txBufBlock{};

	// use in DSPManager::SINGLE_SAMPLE_MODE
	AudioBlockU16< AbstractFx::STEREO_DOUBLE_CH_SIZE_U16 >  rxBufSingle{};
	AudioBlockU16< AbstractFx::STEREO_DOUBLE_CH_SIZE_U16 >  txBufSingle{};


	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< DSPManager >(size))
				return malloc(size);
			else
				return nullptr;
	}

	static void mute();
	static void unmute();
	void enable();
	void disable();

	static SampleMode theSampleMode;
	static SampleMode theSavedMode;

private:
	AbstractFx* theFx;

};


