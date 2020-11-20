#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
int main()
{
	FILE* pf = fopen("1.txt", "wb"); // ������д
	if (NULL == pf)
	{
		exit(0);
	}

	// �����Ƹ�ʽ��д�ļ�
	//int a = 12345678;
	//fwrite(&a, sizeof(a), 1, pf); // �����Ʒ�ʽд��ȥ
	//char ch = -1;
	//fwrite(&ch, 1, 1, pf);

	// �ı���ʽд�ļ�
	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10); // ����ת�ַ����������������Ƕ��ٽ���
	fwrite(sz, 1, strlen(sz), pf);

	char ch = -1;
	memset(sz, 0, 32);
	_itoa(ch, sz, 10);
	fwrite(sz, 1, strlen(sz), pf);
	
	fclose(pf);
	return 0;
}
#endif




#if 0
#include <fstream>

// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	void WriteBin(const ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ��д
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

	void WriteText(const ServerInfo& info)
	{
		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��ȶ��ַ�������atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // �����ļ�
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;

	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;

	// �ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
#endif




#if 0
int main()
{
	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10);// ����ת�ַ���

	memset(sz, 0, 32);
	sprintf(sz, "%d", a);// ��ʽ��
	return 0;
}
#endif




#include <sstream>

#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;

	string str;
	ss >> str;
	string ret = ss.str();
	cout << ret << endl;

	ss.clear(); // ���ֻ�޸�״̬
	ss.str(""); // ���ÿյ��ַ���
	double d = 12.34;
	ss << d;
	ss >> str;

	ret = ss.str();
	cout << ret << endl;
	return 0;
}
#endif




#if 0
int main()
{
	stringstream ss; // �ַ���ƴ��
	ss << "hello";
	ss << "   ";
	ss << "world!!!";

	string s;
	s = ss.str();
	cout << s << endl;
	return 0;
}
#endif




#if 0
int main()
{
	unsigned long long a = 0xffffffffffffffff;
	cout << a << endl;
	return 0;
}
#endif




#if 0
int main()
{
	stringstream sstream;
	// ������ַ������� sstream ��
	sstream << "first" << " " << "string,";
	sstream << " second string";
	cout << "strResult is: " << sstream.str() << endl;

	// ��� sstream
	sstream.str(""); // ���ײ�string��������Ϊ" "���ַ���
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
	return 0;
}
#endif

