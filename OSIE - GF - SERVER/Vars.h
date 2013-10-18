#pragma once

struct L2Server
{
	//L2Server Protocol
	short srvProtocol;
};

class CVars
{
public:
	CVars(void);
	~CVars(void);
	void Initialize(void);
	const char* GetServerProtocol(void);
protected:
	bool FileExists(const char* file_name);
private:
	char* config_file;
	void CreateIniFile(void);
	void LoadVars(void);
	L2Server* iServer;
	char ServerProtocol[0x11];
};

