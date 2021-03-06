/* Copyright (c) 2005, Regents of Massachusetts Institute of Technology, 
 * Brandeis University, Brown University, and University of Massachusetts 
 * Boston. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in the 
 *     documentation and/or other materials provided with the distribution.
 *   - Neither the name of Massachusetts Institute of Technology, 
 *     Brandeis University, Brown University, or University of 
 *     Massachusetts Boston nor the names of its contributors may be used 
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// Decodes Int pages

#ifndef _BITSPARSEDECODER_H_
#define _BITSPARSEDECODER_H_

#include "Decoder.h"
#include "../Util/StringReader.h"
#include "../Util/ByteReader.h"
#include "../SparseBlock.h"
#include "../PosArrayBlock.h"
#include "../../common/Constants.h"
#include "../PosType2Block.h"

class BitSparseDecoder : public Decoder
{
public:
	BitSparseDecoder(bool valSorted_, unsigned short type_, int fieldSize_);
	BitSparseDecoder(byte* buffer_, bool valSorted_, unsigned short type_, int fieldSize_);
	BitSparseDecoder(BitSparseDecoder& decoder_); 
	virtual ~BitSparseDecoder();
	
	virtual void setBuffer(byte* buffer_);
	virtual int getValueSize();
	virtual int getPageLengthBits();
	
	virtual bool hasNextBlock();
	virtual Block* peekNextBlock();
	virtual Block* getNextBlock();
	virtual Block* getNextBlockSingle();
	virtual bool skipToPos(unsigned int blockLoc_);

	virtual bool skipToBlockOnValue(int value_);



	virtual ValPos* getStartVal();
	virtual unsigned int getStartPos();
	virtual ValPos* getEndVal();
	virtual unsigned int getEndPos();
	
	virtual unsigned int getSize() { return *numValsPtr; }
protected:
	unsigned int* numValsPtr;
	unsigned int* startPosPtr;
	unsigned int* endPosPtr;
	StringReader reader;
	SparseBlock* outBlock;
	PosType2Block* outPosBlock;
	Type2Block* posBlockBaseBlock;
	PosBlockIter* currIter;
	Type2Header* t2header;
	ValPos* outPair;
	unsigned int currPos;
	int fieldSize;
};

#endif //_BITSPARSEDECODER_H_
