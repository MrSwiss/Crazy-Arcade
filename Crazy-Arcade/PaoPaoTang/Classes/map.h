/**********************/
/*
*�ļ�˵�������ļ�������Ϸ����Ƭ��ͼ��������������غ���������
*���ߣ���Ǭ
*ʱ�䣺2017-6-2
*//**********************/
#define TILEDWIDTH 17
#define TILEDHEIGHT 15

#ifndef _MAP_H_
#define _MAP_H_

#include "cocos2d.h"
#include "item.h"
#include "BeginScene.h"
#include "player.h"
#include "bomb.h"
#include "MenuSelectHandler.h"

class CBomb;
class CPlayer;
class CMap :public cocos2d::CCTMXTiledMap
{
public:
	static CMap* initTileMap(const char* tmxFile, CBaseScene* curScene);
	CMap(CBaseScene* curScene);
	//ͨ��ָ������ת��Ϊ��ͼ������
	cocos2d::CCPoint tilePosFromLocation(cocos2d::CCPoint pos);
	//�ж���Ƭ�Ƿ�Ϊ�ϰ�
	bool isTilePosBlocked(cocos2d::CCPoint pos);
	bool isTilePosBlocked(cocos2d::CCPoint pos, CPlayer*);
	bool bombBlock[TILEDWIDTH][TILEDHEIGHT];
	bool bombAttack[TILEDWIDTH][TILEDHEIGHT];
	int itemPos[TILEDWIDTH][TILEDHEIGHT];
	CCSprite* itemPointerPos[TILEDWIDTH][TILEDHEIGHT];
	CBomb* bombPointerPos[TILEDWIDTH][TILEDHEIGHT];
	void setBombBlock(int x, int y,bool z);
	void setItem(cocos2d::CCPoint);
	void handleInput(EControlType eCtrlType, EPressState ePrsState);
	void judge(float dt);
	void win(int ID);
	cocos2d::CCPoint toTiledPos(cocos2d::CCPoint&);
	CPlayer* m_pPlayer1;
	CPlayer* m_pPlayer2;
	CBaseScene* m_pBelongedScene;
	int judgeTime ;

};


#endif // !_MAP_H_
