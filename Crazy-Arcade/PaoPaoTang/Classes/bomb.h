/******************************/
/*�ļ�˵���������������
*���ߣ���Ǭ
*���ڣ�2017-6-10
*/
/******************************/

#ifndef _BOMB_H_
#define _BOMB_H_

#include "cocos2d.h"
#include "player.h"

class CPlayer;
class CMap;
class CBomb :public cocos2d::CCNode
{
public:
	CBomb(cocos2d::CCPoint pos, CMap* layer,CPlayer*);
	static CBomb* create(cocos2d::CCPoint pos, CMap* layer,CPlayer*);//��ʼ��������
	void erase();//��������Ͷ���
	void explode(float);//���ݱ�ը
	int expoldeBlock();//����ˮ���赲�ж�
	~CBomb();

private:
	bool isInBorder(cocos2d::CCPoint);//�ж�����ˮ����Χ�Ƿ��ڵ�ͼ��
	void deleteTile(cocos2d::CCPoint pos);//ը���谭��ɾ����Ƭ
	cocos2d::CCPoint toTiledPos(cocos2d::CCPoint&);//������λ�÷�����Ƭ����
	cocos2d::CCSprite* m_sprite;//���ݼ���ը���ľ���
	cocos2d::CCAnimate* m_ani;//���ݶ���
	cocos2d::CCAction* m_act;//���ݶ���
	CMap* m_pCurMap;//�������ڵ�ͼ
	cocos2d::CCSprite* up;//����ˮ������
	cocos2d::CCSprite* down;//...
	cocos2d::CCSprite* left;
	cocos2d::CCSprite* right;
	cocos2d::CCSprite* centre;
	CPlayer* m_pHero;//����������ɫ
	cocos2d::CCPoint m_settedPos;//��������ʱ��ɫ������
	int iUp;
	int iDown;
	int iLeft;
	int iRight;
	
};

#endif // !_BOMB_H_

