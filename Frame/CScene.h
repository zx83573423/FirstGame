#pragma once
class CScene
{
public:
	virtual void Init() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
	virtual void Quit() = 0;
};

