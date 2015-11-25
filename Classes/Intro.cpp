#include "Intro.h"

USING_NS_CC;

CCScene* Intro::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Intro *layer = Intro::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Intro::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //get instance of the director singleton
	director = CCDirector::sharedDirector();

	mp_oLinkSprite = CCSprite::create("link.png");
	//mp_oLinkSprite->setAnchorPoint(ccp(0.5,0.05));

	screenWidth = director->getWinSize().width;
	screenHeight = director->getWinSize().height;
	
	mp_oLinkSprite->setPositionX(screenWidth*0.5);
	mp_oLinkSprite->setPositionY(screenHeight*0.5);


	speedX = 20.1;
	speedY= 0.0;

	this->addChild(mp_oLinkSprite);

	this->scheduleUpdate();

	CCMoveTo* moveaction = CCMoveTo::create(3, ccp(screenWidth, screenHeight/2));
	mp_oLinkSprite->runAction(moveaction);

    return true;
}


void Intro::update(float delta){

	//update our game here
	
	//apply some speed to the link sprite
	//CCPoint previousPosition = mp_oLinkSprite->getPosition();
	//CCPoint newPosition( previousPosition.x+(speedX*delta), previousPosition.y+(speedY*delta));
	//mp_oLinkSprite->setPosition(newPosition);

	

	if(mp_oLinkSprite->getPositionX()+(mp_oLinkSprite->getContentSize().width*0.5) > screenWidth)
	{
		//collision with end of screen
		speedX*=-1;
		
		
		//CCFlipX3D* flipAction = CCFlipX3D::create(0.2);

		//mp_oLinkSprite->runAction(flipAction);

	}
	
}

