#include "stdafx.h"

bool read_file(const char* fn, unsigned char** out, size_t* sz)
{
	std::ifstream ifs(fn, std::ios_base::binary);
	if(!ifs.is_open())
		return false;

	ifs.seekg(0,std::ios_base::end);
	size_t size = size_t(ifs.tellg());
	ifs.seekg(std::ios_base::beg);
	if(sz==0 || size>1<<20)
		return false;

	*out = new unsigned char[size+1];
	(*out)[size] = '\0';
	*sz = size;
	ifs.read(reinterpret_cast<char*>(*out), size);
	return true;
}

bool parse_resource_h(std::unordered_map<std::string,int>* ids, const char* rc)
{
	const char* p = rc;

	auto laSkipWs = [](const char** pp){
		auto p = *pp;
		while(*p && (*p==' ' || *p=='\t' || *p=='\r'))
			p++;
		*pp = p;
	};

	auto laSkipLine = [](const char** pp){
		auto p = *pp;
		while(*p && *p!='\n')
			p++;
		if(*p=='\n')
			p++;
		*pp = p;
	};

	auto laReadString = [](std::string* str, const char** pp){
		std::vector<char> s;
		auto p = *pp;
		while(*p && *p!=' ' && *p!='\t' && *p!='\r' && *p!='\n'){
			s.push_back(*p);
			p++;
		}
		if(s.size())
			*str = std::string(reinterpret_cast<char*>(&s[0]), s.size()); // Is move-assign used?
		*pp = p;
	};

	auto laReadInteger = [](int* pi, const char** pp){
		auto p = *pp;
		int i = 0;
		while(*p>='0' && *p<='9'){
			i = i*10 + (*p-'0');
			p++;
		}

		*pi = i;
		*pp = p;
	};

	for(;;){
		std::string key;
		int value;

		if(!*p) break;

		laSkipWs(&p);
		if(!*p) goto _exit_for;
		if(p[0]=='/' && p[1]=='/'){
			laSkipLine(&p);
			continue;
		}
		if(p[0]=='#'){
			if(strncmp(&p[1], "define", 6)==0){
				p += 7;
				laSkipWs(&p);
				laReadString(&key, &p);
				laSkipWs(&p);
				if(*p == '\n'){
					laSkipLine(&p);
					continue;
				}
				laReadInteger(&value, &p);

				(*ids)[key] = value;

				laSkipLine(&p);
				continue;
			}
			else{
				laSkipLine(&p);
				continue;
			}
		}
		else{
			laSkipLine(&p);
			continue;
		}
	}
_exit_for:
	;
	return true;
}

class CIdXml
{
public:
	CIdXml(tinyxml2::XMLDocument& doc, std::unordered_map<std::string,int>* ids)
		: m_doc(doc)
		, m_ids(*ids)
	{
	}
	
	void SetNodes()
	{
		SetNodes(m_doc.FirstChild());
	}

private:
	int GetID(const char* key)
	{
		if(m_ids.count(key))
			return m_ids[key];
		else
			return -1;
	}

	void SetElement(tinyxml2::XMLElement* pElem)
	{
		auto a = pElem->FirstAttribute();
		if(a){
			do{
				if(strcmp(a->Name(),"id")==0){
					int i = GetID(a->Value());
					if(i != -1)
						pElem->SetAttribute("id",GetID(a->Value()));
				}
			}while(a = a->Next());
		}
	}

	void SetNodes(tinyxml2::XMLNode* pNode)
	{
		if(!pNode) return;
		do{
			tinyxml2::XMLElement* pElem = pNode->ToElement();
			if(!pElem) continue;

			SetElement(pElem);
			SetNodes(pElem->FirstChild());
		}while(pNode = pNode->NextSibling());
	}

private:
	tinyxml2::XMLDocument& m_doc;
	std::unordered_map<std::string,int>& m_ids;
};

bool idxml(const char* xml, std::unordered_map<std::string,int>* ids, const char* out_xml)
{
	tinyxml2::XMLDocument doc;
	if(doc.LoadFile(xml) != tinyxml2::XML_SUCCESS)
		return false;

	CIdXml ix(doc, ids);
	ix.SetNodes();
	return doc.SaveFile(out_xml) == tinyxml2::XML_NO_ERROR;
}

void usage()
{
	const char* msg = 
		"idxml - 将SdkLayout程序中的xml文件中的字符串ID转换为数值ID\n"
		"参数:\n"
		"\tidxml <in_xml> <resource.h> [out_xml]\n"
		"\n";
	std::cout << msg;
}

int main(int argc, char* argv[])
{
	if(argc!=3 && argc!=4){
		usage();
		return !(argc==3||argc==4);
	}

	const char* in_xml = argv[1];
	const char* rsrc_h = argv[2];
	const char* out_xml = argc==4 ? argv[3] : in_xml;

	unsigned char* data;
	size_t sz;
	if(!read_file(rsrc_h, &data, &sz)){
		std::cout << "无法读取文件: " << rsrc_h << std::endl;
		return 1;
	}

	std::unordered_map<std::string,int> ids;
	parse_resource_h(&ids, reinterpret_cast<char*>(data));
	delete[] data;
	
	if(!idxml(in_xml, &ids, out_xml)){
		std::cout << "失败!" << std::endl;
		return 1;
	}
	return 0;
}

