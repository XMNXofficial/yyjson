#include <yyjson.h>
#include <iostream>
using namespace std;
int main()
{
    // 生成部分
    yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *root = yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc, root);
    yyjson_mut_val *key_userName = yyjson_mut_str(doc, "userName");
    yyjson_mut_val *val_userName = yyjson_mut_str(doc, "test");
    yyjson_mut_obj_add(root, key_userName, val_userName);
    char *json = yyjson_mut_write(doc, 0, 0);
    char json_backup[2048]={0};
    strcpy(json_backup,json);//备份一下
    // cout<<"生成的json"<<json_backup<<endl;

    // 读取试试
    yyjson_mut_val* read_root=yyjson_mut_doc_get_root(doc);
    yyjson_mut_val* read_obj=yyjson_mut_obj_get(read_root,"userName");
    // cout<<"读取userName:"<<yyjson_mut_get_str(read_obj)<<endl;
    yyjson_mut_doc_free(doc);//备注:此处浅free掉了,但是不会把原来的内存清零.


    //通过字符串读取试试
    char* ss=R"({"userName":"test"})";
    yyjson_doc* imut_doc=yyjson_read(ss,strlen(ss),0);
    //踩坑:yyjson_read读取长度,只能是字符串里中止的位置,如果超出一点,即使有\0也会异常!
    //也就是说,这里要填写的是json实际长度,而不是字符串数组长度.
    yyjson_val* imut_root=yyjson_doc_get_root(imut_doc);
    yyjson_val* imut_obj=yyjson_obj_get(imut_root,"userName");
    // cout<<"读取userName:"<<yyjson_get_str(imut_obj)<<endl;
    yyjson_doc_free(imut_doc);


    //不可变转为可变
    char* str=R"({"userName":"test"})";
    yyjson_doc* temp=yyjson_read(str,strlen(str),0);
    yyjson_mut_doc* temp_mut= yyjson_doc_mut_copy(temp,nullptr);

    yyjson_mut_val* temp_mut_root=yyjson_mut_doc_get_root(temp_mut);
    yyjson_mut_obj_add(temp_mut_root,yyjson_mut_str(temp_mut,"你好"),yyjson_mut_str(temp_mut,"世界"));
    cout<<yyjson_mut_write(temp_mut,0,0);
    return 0;
}