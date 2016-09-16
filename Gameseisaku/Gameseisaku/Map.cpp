#include "stdafx.h"
#include "Map.h"
#include "MapChip.h"

using namespace std;
	//�}�b�v�`�b�v�̔z�u���̃e�[�u���B
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
	//�z�u��񂩂�}�b�v���\�z
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);
	for (int i = 0; i < tableSize; i++){
		//�}�b�v�`�b�v��0��.		
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
