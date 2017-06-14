/**********************/
/*
*�ļ�˵�������ļ�������Ϸ����Ƭ��ͼ��������������غ����Ķ���
*���ߣ���Ǭ
*ʱ�䣺2017-6-2
*/
/**********************/
#include "map.h"
#include "bomb.h"
using namespace cocos2d;
class CBomb;
CMap* CMap::initTileMap(const char *tmxfile, CBaseScene* curScene)
{
	CMap *map = new CMap(curScene);
	if (map->initWithTMXFile(tmxfile))
	{
		map->autorelease();
		return map;
	}

	CC_SAFE_DELETE(map);
	return NULL;
}

CMap::CMap(CBaseScene* curScene):
	m_pBelongedScene(curScene),
	m_pPlayer1(NULL),
	m_pPlayer2(NULL)
{
	memset(bombBlock, 0, sizeof(bombBlock));
	memset(bombAttack, 0, sizeof(bombAttack));
	memset(itemPos, 0, sizeof(itemPos));
	memset(itemPointerPos, 0, sizeof(itemPointerPos));
	memset(bombPointerPos, 0, sizeof(bombPointerPos));

	for (int i = 0; i < TILEDHEIGHT; i++) 
	{
		bombBlock[0][i] = 1;
		bombBlock[TILEDWIDTH-1][i] = 1;
	}
	for (int i = 0; i < TILEDWIDTH; i++)
	{
		bombBlock[i][0] = 1;
		bombBlock[i][TILEDHEIGHT-1] = 1;
	}
	
	CCSprite* pBG = CCSprite::create("Pic/BG.png");
	pBG->setAnchorPoint(CCPointZero);
	addChild(pBG, 1); 
	setPosition(ccp(-20, 0));
	pBG->setPosition(ccp(20, 0));
	m_pBelongedScene->getRootLayer()->addChild(this,1);
	m_pPlayer1 = CPlayer::create(this);
	m_pPlayer2 = CPlayer::create(this);
}

//ͨ��ָ��������ת��Ϊ��ͼ������  
CCPoint CMap::tilePosFromLocation(CCPoint pos)
{
	int x = pos.x / this->getTileSize().width;
	int y = pos.y / this->getTileSize().height;

	y = this->getMapSize().height - y-1;
	return ccp(x, y);
}
//�жϸ���Ƭ�Ƿ�Ϊ�ϰ�  
bool CMap::isTilePosBlocked(CCPoint pos)
{
	//�жϵ�ǰ���Ƿ�Ϊ��ײ��  
	CCPoint tilpos = tilePosFromLocation(pos);                //�����������תΪ������  
	CCTMXLayer *clayer = this->layerNamed("collision");      //ͨ�������ֻ�øò���� 


	int tileGID = clayer->tileGIDAt(tilpos);             //��øÿ��GID��ʶ��  
	if (tileGID != 0)
	{
		CCDictionary* properties = this->propertiesForGID(tileGID);
		if (strcmp(properties->valueForKey("Collidable")->getCString(), "true") == 0)
			return true;
	}
	if (bombBlock[(int)tilpos.x][(int)tilpos.y])
		return true;

	return false;
}

void CMap::setBombBlock(int x, int y,bool z)
{
	bombBlock[x][y] = z;
}

void CMap::setItem(CCPoint tPos)
{
	CItem* item = CItem::create(tPos,this);
}

void CMap::handleInput(EControlType eCtrlType, EPressState ePrsState)
{
	if (m_pPlayer1 != NULL)m_pPlayer1->handleInput(eCtrlType, ePrsState);
	if (m_pPlayer2 != NULL)m_pPlayer2->handleInput(eCtrlType, ePrsState);
}


