#include "stdafx.h"
#include "Vars.h"

extern CVars g_Vars;
CVars g_Vars;

CVars::CVars(void)
{
	ZeroMemory(this->ServerProtocol, 11);
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
	CIniFile::SetSectionComments("# Settings L2Server", "L2Server", this->config_file);
	CIniFile::SetRecordComments("# Protocol L2Server\n","Protocol","L2Server", this->config_file);
}

void CVars::LoadVars(void)
{
	if (CIniFile::SectionExists("L2Server", this->config_file)) 
	{
		if (CIniFile::RecordExists("Protocol", "L2Server", this->config_file))
			this->iServer->srvProtocol = (short)CIniFile::GetIntValue("Protocol", "L2Server", this->config_file);
		else
			this->iServer->srvProtocol = 746;
	}
	else
	{
		this->iServer->srvProtocol = 746;
	}
}

const char* CVars::GetServerProtocol(void)
{
	sprintf_s(this->ServerProtocol, 0x11, "$Revision: %d $", (this->iServer->srvProtocol ? this->iServer->srvProtocol : 746));
	return this->ServerProtocol;
}