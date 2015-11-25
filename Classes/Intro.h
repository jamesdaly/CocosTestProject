#ifndef _INTRO_H_
#define _INTRO_H_

#include "GameDefines.h"


class Intro : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
	//update function
	void update(float);

    // implement the "static node()" method manually
    CREATE_FUNC(Intro);

private:
	float screenWidth;
	float screenHeight;
	cocos2d::CCDirector* director;
	cocos2d::CCSprite* mp_oLinkSprite;
	float speedX;
	float speedY;

};

#endif