#include "yyjson.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
class statEdit
{
private:
	yyjson_mut_doc *json_doc = nullptr;
	yyjson_mut_val *json_root = nullptr;
	yyjson_mut_val *json_arr1 = nullptr;

public:
	typedef struct stats
	{
		std::string stat;
		long value;
	} stat;
	struct statScript
	{
		std::string ScriptName;
		std::vector<stat> stats;
	};
	std::fstream *file = nullptr;
	statEdit();
	~statEdit();
	void add_Script_FromBuffer(std::string ScriptName, std::string Buffer);
	void add_Script(struct statScript *Script);
	void delete_Script();
	void edit_Script();
	void save_Script();
};
statEdit::statEdit()
{
	file = new std::fstream("statEdit.json");
	file->seekg(0, std::ios::end);	 // 设置读取位置到末尾
	size_t fileSize = file->tellg(); // 获取当前读取位置

	file->seekg(0, std::ios::beg); // 恢复读取位置
	if (fileSize != 0)
	{
		// 存在文件
		char *Buffer = new char[fileSize]; // 分配缓冲区
		file->read(Buffer, fileSize);	   // 读取文件到缓冲区
		file->close();
		auto temp = yyjson_read(Buffer, strlen(Buffer), 0); // 创建不可变doc
		json_doc = yyjson_doc_mut_copy(temp, NULL);
		if (yyjson_mut_is_obj(yyjson_mut_doc_get_root(json_doc)))
		{
			// json有效
			json_root = yyjson_mut_doc_get_root(json_doc);		   // 读取root
			json_arr1 = yyjson_mut_obj_get(json_root, "StatEdit"); // 读取数组
		}
		else
		{
			// json无效
			json_root = yyjson_mut_obj(json_doc);
			json_arr1 = yyjson_mut_arr(json_doc);
			yyjson_mut_doc_set_root(json_doc, json_root);
			yyjson_mut_obj_add(json_root, yyjson_mut_str(json_doc, "StatEdit"), json_arr1);
		}
	}
	else
	{
		// 不存在文件
		file->close();
		json_doc = yyjson_mut_doc_new(nullptr);
		json_root = yyjson_mut_obj(json_doc);
		json_arr1 = yyjson_mut_arr(json_doc);
		yyjson_mut_doc_set_root(json_doc, json_root);
		yyjson_mut_obj_add(json_root, yyjson_mut_str(json_doc, "StatEdit"), json_arr1);
	}
}

statEdit::~statEdit()
{
}

void statEdit::add_Script_FromBuffer(std::string ScriptName, std::string Buffer)
{
	std::vector<std::string> str = {"INT32\n", "$"};
	for (auto &i : str) // 批量替换
	{
		size_t pos = 0; // 每次循环重置读取位置
		while ((pos = Buffer.find(i, pos)) != std::string::npos)
			Buffer.replace(pos, i.length(), "");
	}
	struct statScript *Script = new struct statScript;
	std::vector<struct stats> stats;
	std::istringstream in(Buffer);
	std::string temp1, temp2;
	while (std::getline(in, temp1)) // 循环读取
	{
		std::getline(in, temp2);
		stats.push_back({temp1, std::stoi(temp2)});
	}
	Script->ScriptName = ScriptName;
	Script->stats = stats;
	add_Script(Script);
	delete Script;

}

void statEdit::add_Script(struct statScript *Script)
{
	auto obj1 = yyjson_mut_arr_add_obj(json_doc, json_arr1);															// 在StatEdit数组中加入一个对象成员
	yyjson_mut_obj_add(obj1, yyjson_mut_str(json_doc, "Script"), yyjson_mut_str(json_doc, Script->ScriptName.c_str())); // 在对象中加入一个键值对(脚本名)
	auto arr1 = yyjson_mut_arr(json_doc);																				// 创建一个数组
	auto obj2 = yyjson_mut_obj_add(obj1, yyjson_mut_str(json_doc, "Stats"), arr1);										// 在对象中加入一个键值对

	for (int i1 = 0; i1 < Script->stats.size(); i1++)
	{
		auto obj3 = yyjson_mut_arr_add_obj(json_doc, arr1);																	  // 在新的数组中加入一个对象成员
		yyjson_mut_obj_add(obj3, yyjson_mut_str(json_doc, "Stat"), yyjson_mut_str(json_doc, Script->stats[i1].stat.c_str())); // 在对象中加入一个键值对
		yyjson_mut_obj_add(obj3, yyjson_mut_str(json_doc, "Value"), yyjson_mut_int(json_doc, Script->stats[i1].value));		  // 在对象中加入一个键值对
	}
}

void statEdit::delete_Script()
{
}

void statEdit::edit_Script()
{
}

void statEdit::save_Script()
{
	// std::remove("statEdit.json");
	// std::ofstream out("statEdit.json", std::ios::out);
	// std::cout<<yyjson_mut_write(json_doc, YYJSON_WRITE_PRETTY, 0);
	// out.write(Buffer, strlen(Buffer));
	// out.close();
}
int main()
{
	statEdit qwq;
	for (int i1 = 0; i1 < 1; i1++)
		qwq.add_Script_FromBuffer("test", "QWQ\n123");
	qwq.save_Script();
	return 0;
}