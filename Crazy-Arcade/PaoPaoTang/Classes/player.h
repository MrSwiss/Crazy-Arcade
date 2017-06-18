/**********************/
/*
*�ļ�˵�������ļ�������Ϸ�����Ƕ��������
*���ߣ���Ǭ
*ʱ�䣺2017-5-29 
*/
/**********************/
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include"cocos2d.h"
#include "BaseDef.h"
#include <string>
#include "map.h"
#include "bomb.h"
#include "BaseScene.h"
#include "music.h"
class CBaseScene;
class CBomb;
class CPlayer :public cocos2d::CCNode
{
	friend class CBomb;
public:
	//��ʼ����ɫ
	CPlayer(CMap* curMap);
	static CPlayer* create(CMap* curMap);
	//��ȡ����
	cocos2d::CCSprite* getSprite();
	//�߶�����
	void move(EControlType);
	//ͣ��
	void stop(EControlType);
	//����ը��
	void setBomb();
	//��ɫ�����ݰ�Χ
	void trapped();
	//��ɫ����
	void dead();
	bool isDead();
	void win(int ID);

	//��õ���
	void getItem();
	//���̿���
	void handleInput(EControlType,EPressState);
	//���º���
	void myUpdate(float dt);
	//��ײ��⺯��
	cocos2d::CCPoint posFlag();
	bool morePosJadge();
	//���ó�����
	void setBornPosition();
	//����retain����
	EControlType getMoveDirection();
	~CPlayer();

	static int s_playerNum;

private:

	//handleInput�ڵ���,���ڽ��ܰ��µĲ���
	void handleDown(EControlType);
	//handleInput�ڵ���,���ڽ��ܷſ��Ĳ���
	void handleUp(EControlType);
	//�ı�����״̬
	bool changeState(EPlayerLogicState);
	//��ײ�����
	void backPos();
	//�߽���
	bool isInBorder();
	


	int m_iMaxBombNum;//���ը��������
	int m_iSettledBobNum;//�ѷ���ը����
	int m_iBombScale;//ը����Χ
	int m_iSpeed;//�ƶ��ٶ�
	int playerID;
	
	/****״̬�����******/
	EPlayerLogicState m_currentState;//��ǰ״̬
	EControlType m_moveDirection;//��¼�ƶ�ʱ�ķ���
	bool m_rgStateTable[EPLS_NUM][EPLS_NUM];//״̬��
	/*************/


	cocos2d::CCSprite* m_pHero;//���Ǿ���ָ��
	cocos2d::CCAnimate* m_pAnimate;//��ǰ����
	cocos2d::CCMoveBy* m_pMoveBy;//��ǰ�ƶ�����
	CMap* m_pCurrentMap;//��ǰ���ص�ͼ
	
	

};





#endif // !_PLAYER_H_
