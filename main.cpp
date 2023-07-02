#include <iostream>
#include "yyjson.h"
#include<vector>
using namespace std;
int main()
{
	// system("chcp 65001");
	vector<string> family {"奕岚","子豪","嘉俊"};
	yyjson_mut_doc* doc=yyjson_mut_doc_new(NULL);//新建一个空白文档(文档本质是一个内存管理)
	yyjson_mut_val* root=yyjson_mut_obj(doc);//(初始化json的根,以doc为文档)
	//根就是最外面的括号{}
	yyjson_mut_doc_set_root(doc,root);
	yyjson_mut_val* arr_key=yyjson_mut_str(doc,"family");
	yyjson_mut_val* arr_val=yyjson_mut_arr(doc);
	for(int i1=0;i1<family.size();i1++)
	{
		yyjson_mut_val* a=yyjson_mut_str(doc,family[i1].c_str());
		yyjson_mut_arr_append(arr_val,a);
	}
	yyjson_mut_obj_add(root,arr_key,arr_val);
	// yyjson_mut_doc_set_root(doc,root);
	cout<<yyjson_mut_write(doc,YYJSON_WRITE_PRETTY||YYJSON_WRITE_ESCAPE_SLASHES,NULL);
	yyjson_mut_doc_free(doc);
	return 0;
}
