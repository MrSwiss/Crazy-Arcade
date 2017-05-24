#include "cocos2d.h"
#include "BeginScene.h"
#include "BaseDef.h"
#include "MenuSelectHandler.h"
#include "GameUtils.h"
#include "Animation.h"
void CBeginScene::onEnterScene()
{
	CCMenuItemImage* image = CCMenuItemImage::create("play.png","play.png",CMenuSelectHandler::sharedHandler(),menu_selector(CMenuSelectHandler::beginScene_PlayItem));
	image->setPosition(FRAME_WIDTH/2,FRAME_HEIGHT/2);
	wstring exit = L"�˳���Ϸ";
	string exit2;
	GameUitls::WStrToUTF8(exit2,exit);
	CCLabelTTF* label = CCLabelTTF::create(exit2.c_str(),"Arial",24);
	CCMenuItemLabel* labelItem = CCMenuItemLabel::create(label,CMenuSelectHandler::sharedHandler(),menu_selector(CMenuSelectHandler::beginScene_PlayItem));
	labelItem->setPosition(FRAME_WIDTH/2,FRAME_HEIGHT/2-140);

	CCMenu* pMenu = CCMenu::create(image,labelItem, NULL);
	pMenu->setPosition(CCPointZero);
	mRootLayer->addChild(pMenu,1);
/**************����С����*****************/
	loadAni();//���ض���
	
	CCAnimation* animation=CCAnimationCache::sharedAnimationCache()->animationByName("Pic/Role2.png3");//��ȡ����
	CCAnimate* animate=CCAnimate::create(animation);//��������
	CCSprite* sp=CCSprite::create();
	sp->setPosition(ccp(FRAME_WIDTH/6,FRAME_HEIGHT/6));
	mRootLayer->addChild(sp);
	sp->runAction(animate);
/**************����С����*****************/
}
