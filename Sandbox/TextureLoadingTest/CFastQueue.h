#pragma once
#ifndef CFastQueue_H
#define CFastQueue_H

#include "CSem.h"


//high performance no-mutex pipe object.
//Limitation: ONLY 1 THREAD FOR EACH SIDE OF THE PIPE. This works and has high performance, only if each function (push, pop) is called from a single thread.
template<class ContainedObj,int kQueueSize>
class CFastQueue
{
	gmcu::CSem		mFreeCount;
	gmcu::CSem		mSize;
	int				mBegin;//index of first element of queue
	int				mEnd;//index of first element out of queue
	ContainedObj	mSlots[kQueueSize];
public:
	CFastQueue()
		:mBegin(0)
		,mEnd(0)
	{
		mFreeCount.Init(kQueueSize);
		mSize.Init(0);
	}
	bool Pop(ContainedObj& outObj, int inTimeout = 0)
	{
		if( mSize.Wait(inTimeout) )//decrease size, we take 1 obj
		{
			outObj = mSlots[mBegin];
			mBegin= (mBegin+1) % kQueueSize;
			mFreeCount.Post();// free 1 slot for further loading
			return true;
		}
		else
			return false;
	}
	bool Push(const ContainedObj& inObj, int inTimeout = 0 )
	{
		if( BeginPush(inTimeout) )
		PushItem() = inObj;
		EndPush();
	}
	ContainedObj& operator[](size_t inIndex) { return mSlots[inIndex]; }//use with care.
	bool BeginPush(int inTimeout =0)
	{
		if ( mFreeCount.Wait(inTimeout) )//need 1 slot for loading
		{
			mEnd = (mEnd+1)%kQueueSize;
			return true;
		}
		else
			return false;
	}
	void EndPush()
	{
		mSize.Post();
	}

	bool BeginPop(int inTimeout = 0)
	{
		if ( inTimeout == 1?mSize.TryWait():mSize.Wait(inTimeout) )//need 1 slot for loading
		{
			mBegin = (mBegin+1)%kQueueSize;
			return true;
		}
		else
			return false;
	}
	void EndPop()
	{
		mFreeCount.Post();
	}
	ContainedObj& PushItem() { return (*this)[(mEnd + kQueueSize-1)%kQueueSize]; }
	ContainedObj& PopItem() { return (*this)[(mBegin + kQueueSize-1)%kQueueSize]; }

	struct StPush
	{
		StPush(CFastQueue& inQueue, int inTimeout = 0)
			:mQueue(&inQueue)
		{
			if(!mQueue->BeginPush())
				mQueue = NULL;
		}
		~StPush()
		{
			if (mQueue)
			{
				mQueue->EndPush();
			}
		}
		ContainedObj& operator * () { return mQueue?mQueue->PushItem():*NULL; }
		ContainedObj* operator ->() { return mQueue?&mQueue->PushItem():NULL; }
	private:
		CFastQueue* mQueue;
	};
	struct StPop
	{
		StPop(CFastQueue& inQueue, int inTimeout = 0)
			:mQueue(&inQueue)
		{
			if(!mQueue->BeginPop())
				mQueue = NULL;
		}
		~StPop()
		{
			if (mQueue)
			{
				mQueue->EndPop();
			}
		}
		ContainedObj& operator * () { return mQueue?mQueue->PopItem():*NULL; }
		ContainedObj* operator ->() { return mQueue?&mQueue->PopItem():NULL; }
		operator ContainedObj*() {return &**this; }
	private:
		CFastQueue* mQueue;
	};

};

#endif