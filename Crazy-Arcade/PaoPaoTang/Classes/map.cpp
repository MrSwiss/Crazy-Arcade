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
CMap* CMap::initTileMap(const char *tmxfile)
{
	CMap *map = new CMap;
	memset(map->bombBlock, 0, sizeof(map->bombBlock));
	if (map->initWithTMXFile(tmxfile))
	{
		CCTMXLayer *clayer = map->layerNamed("collision");       //ͨ�������ֻ�øò����  
		//clayer->setVisible(false);
		map->autorelease();
		return map;
	}

	CC_SAFE_DELETE(map);
	return NULL;
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


