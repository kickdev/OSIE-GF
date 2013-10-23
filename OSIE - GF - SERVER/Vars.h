#pragma once

struct L2Server
{
	//L2Server Protocol
	int srvProtocol;
};

class CVars
{
public:
	CVars(void);
	~CVars(void);
	void Initialize(void);
	string GetServerProtocol(void);
protected:
	bool FileExists(const char* file_name);
private:
	char* config_file;
	void CreateIniFile(void);
	void LoadVars(void);
	L2Server* iServer;
	string ServerProtocol;
};

