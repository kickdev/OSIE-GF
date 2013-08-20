#pragma once

struct L2Server
{
	//L2Server Protocol
	short srvProtocol;
	//Test Value
	int TestValue;
};

class CVars
{
public:
	CVars(void);
	~CVars(void);
	void Initialize(void);
	char* GetServerProtocol(void);
	int& GetTestValue(void);
protected:
	bool FileExists(const char* file_name);
private:
	char* config_file;
	void CreateIniFile(void);
	void LoadVars(void);
	L2Server* iServer;
};

