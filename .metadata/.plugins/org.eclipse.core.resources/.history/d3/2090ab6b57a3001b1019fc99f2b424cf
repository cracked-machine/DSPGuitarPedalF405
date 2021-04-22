/*
 * DSPManager.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */


#include <AbstractFx.hpp>

//#include <Reverb.hpp>
#include <BoundedVector.hpp>

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
		BLOCK_SAMPLE_MODE,
		SINGLE_SAMPLE_MODE
	};
	SampleMode sampleMode = BLOCK_SAMPLE_MODE;


	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > rxBuf{};
	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > txBuf{};
	//AudioBlockU16<8> rxBuf{};
	//AudioBlockU16<8> txBuf{};
	//uint16_t txBuf[8];


	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< DSPManager >(size))
				return malloc(size);
			else
				return nullptr;
	}

private:
	AbstractFx* theFx;


};


