#include "PlayScene.h"
#include "MenuSelectHandler.h"
#include "Animation.h"
#include "music.h"





CPlayScene::CPlayScene():
m_pMap(NULL)
{
}

void CPlayScene::onEnterScene(int i)
{
	mRootLayer->setAnchorPoint(CCPointZero);
	/*CCSprite* pBG = CCSprite::create("Pic/BG.png");
	pBG->setAnchorPoint(CCPointZero);
	mRootLayer->addChild(pBG,2);*/
	/**************����С����*****************/

	//CCAnimation* animation=CCAnimationCache::sharedAnimationCache()->animationByName("Pic/Role1.png0");//��ȡ����
	//CCAnimate* animate=CCAnimate::create(animation);//��������
	//CCSprite* sp=CCSprite::create();
	//sp->setPosition(ccp(FRAME_WIDTH/2,FRAME_HEIGHT*0.7));
	//mRootLayer->addChild(sp);
	//sp->runAction(animate);
	if (MAPTAG == 1)m_pMap = CMap::initTileMap("amap1.tmx",this);
	if (MAPTAG == 2)m_pMap = CMap::initTileMap("amap2.tmx", this);

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Snd/bg/Play.mp3", true);

	/*amap->addChild(hero.getSprite(),3);*/
	/**************����С����*****************/

	CCLabelTTF* back_label = CCLabelTTF::create(CStringTableMgr::getString("main_menu"),"Arial",24);
	back_label->setColor(ccc3(0, 255, 0));
	CCMenuItemLabel * back_labelItem = CCMenuItemLabel::create(back_label,CMenuSelectHandler::sharedHandler(),menu_selector(CMenuSelectHandler::onMenu_Back2Menu));
	back_labelItem->setPosition(ccp(710,25));
	CCMenu* pMenu = CCMenu::create(back_labelItem,NULL);
	pMenu->setPosition(CCPointZero);
	mRootLayer->addChild(pMenu,1);

	
}

void CPlayScene::onExitScene()
{
	m_pMap->m_pPlayer1->unschedule(schedule_selector(CPlayer::myUpdate, m_pMap->m_pPlayer1));
	m_pMap->m_pPlayer2->unschedule(schedule_selector(CPlayer::myUpdate, m_pMap->m_pPlayer2));
	m_pMap->m_pPlayer1->s_playerNum = 0;
	mRootLayer->removeAllChildrenWithCleanup(true);

	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void CPlayScene::handleInput(EControlType eCtrlType, EPressState ePrsState)
{
	
	if (m_pMap != NULL)m_pMap->handleInput(eCtrlType, ePrsState);
}