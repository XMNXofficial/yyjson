#include<yyjson.h>
#include<iostream>
using namespace std;
int main()
{
    auto doc=yyjson_mut_doc_new(nullptr);
    auto root=yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc,root);
    auto str1=yyjson_mut_str(doc,"hello");
    char str_[100]="world";
    auto str2=yyjson_mut_strcpy(doc,str_);
    strcpy(str_,"opwgtrkgop");
    yyjson_mut_obj_add(root,str1,str2);
    cout<<yyjson_mut_write(doc,YYJSON_WRITE_PRETTY,0);
    
    return 0;
}