/************************************************************************/
/* ���ߣ���Ǭ
 *���ڣ�2017-5-24 19:00
 *˵�������ļ��ṩ�ܽ����ж��������Ƽ����붯���صĽӿ�loadAni
 */
/************************************************************************/

#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include"cocos2d.h"
#include<fstream>
#include<string>
#include<memory>
#include<vector>
#include<map>
using namespace cocos2d;
using namespace std;

//��¼�������ݵĽṹ��
struct SngPic
{
	char filename[50];
	float picWidth;
	float picHeight;
	int divideWidth;
	int divideHeight;
	int order;
};

extern SngPic AniSettingDate;
extern fstream inFile;

//�������������붯���أ������ֶ�����
void load(SngPic& sp, char ,string);

//�������Զ��������Ŷ���ǰ�����ã���ֻ�����һ��
void loadAni();


#endif // !_ANIMATION_H_



