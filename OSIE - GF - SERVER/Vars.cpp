#include "stdafx.h"
#include "Vars.h"

extern CVars g_Vars;
CVars g_Vars;

CVars::CVars(void)
{
	this->config_file = "l2config.ini";
}

CVars::~CVars(void)
{
	delete this->iServer;
	delete[] this->config_file;
}

bool CVars::FileExists(const char* file_name)
{
	return std::ifstream(file_name) != NULL;
}

void CVars::Initialize(void)
{
	this->iServer = new L2Server;
	if (!this->FileExists(this->config_file))
		this->CreateIniFile();
	this->LoadVars();
}

void CVars::CreateIniFile(void)
{
	CIniFile::Create(this->config_file);
	CIniFile::SetValue("Protocol", "746", "L2Server", this->config_file);
	CIniFile::SetSectionComments("# This section is responsible for connecting to the server cached", "L2Server", this->config_file);
	CIniFile::SetRecordComments("# L2Server Protocol\n","Protocol","L2Server", this->config_file);
	CIniFile::SetValue("TestValue", "1", "L2Server", this->config_file);
	CIniFile::SetRecordComments("# Test Value\n","TestValue","L2Server", this->config_file);
}

void CVars::LoadVars(void)
{
	if (CIniFile::SectionExists("L2Server", this->config_file)) 
	{
		if (CIniFile::RecordExists("Protocol", "L2Server", this->config_file))
			this->iServer->srvProtocol = CIniFile::GetIntValue("Protocol", "L2Server", this->config_file);
		else
			this->iServer->srvProtocol = 746;
		if (CIniFile::RecordExists("TestValue","L2Server",this->config_file))
			this->iServer->TestValue = CIniFile::GetIntValue("TestValue","L2Server",this->config_file);
		else
			this->iServer->TestValue = 1;
	}
	else
	{
		this->iServer->srvProtocol = 746;
		this->iServer->TestValue = 1;
	}
}

char* CVars::GetServerProtocol(void)
{
	char* buff = new char[0x11];
	sprintf_s(buff, 0x11, "$Revision: %d $", (this->iServer->srvProtocol ? this->iServer->srvProtocol : 746));
	return buff;
}

int& CVars::GetTestValue(void)
{
	int& buff = this->iServer->TestValue;
	//
	return buff;
}