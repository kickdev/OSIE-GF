#include "stdafx.h"
#include "Vars.h"


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
}

void CVars::LoadVars(void)
{
	if (CIniFile::SectionExists("L2Server", this->config_file)) 
	{
		if (CIniFile::RecordExists("Protocol", "L2Server", this->config_file))
			this->iServer->srvProtocol = CIniFile::GetIntValue("Protocol", "L2Server", this->config_file);
		else
			this->iServer->srvProtocol = 746;
	}
	else
	{
		this->iServer->srvProtocol = 746;
	}
}

string CVars::GetServerProtocol(void)
{
	char buff[20];
	ZeroMemory(buff, 20);
	_itoa_s(this->iServer->srvProtocol, buff, 20, 10);
	this->ServerProtocol = string("$Revision: ") + string(buff) + string(" $");
	return this->ServerProtocol;
}