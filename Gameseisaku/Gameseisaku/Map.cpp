#include "stdafx.h"
#include "Map.h"
#include "MapChip.h"

using namespace std;
	//マップチップの配置情報のテーブル。
	SMapChipLocInfo mapChipLocInfoTable[] = {
#include "locationInfo.h"
	};
Map::Map()
{

}

Map::~Map()
{
	for (auto& mapchip : mapChipList){
		delete mapchip;
	}
}
void Map::Start()
{
	//配置情報からマップを構築
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);
	for (int i = 0; i < tableSize; i++){
		//マップチップを生0成.		
		MapChip* mapChip = new MapChip;
		mapChip->Init(mapChipLocInfoTable[i].modelName);
		mapChipList.push_back(mapChip);
		//delete mapchipList.second;
	}
}
void Map::Update()
{
	for (auto& mapChip : mapChipList){
		mapChip->Update();
	}
}
void Map::Render()
{
	for (auto& mapChip : mapChipList){
		mapChip->Render();
	}
}
