#include <iostream>
#include <yyjson.h>
using namespace std;
int main()
{
    yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL); // 创建内存管理器
    yyjson_mut_val *root = yyjson_mut_obj(doc);     // 创建一个对象
    yyjson_mut_doc_set_root(doc, root);             // 将此对象设置为根

    // 创建userName
    yyjson_mut_val *key_arr_userName = yyjson_mut_str(doc, "userName");
    yyjson_mut_val *val_arr_userName = yyjson_mut_arr(doc);
    yyjson_mut_val *val_arr_userName_member1 = yyjson_mut_str(doc, "奕岚");
    yyjson_mut_val *val_arr_userName_member2 = yyjson_mut_str(doc, "嘉俊");
    yyjson_mut_val *val_arr_userName_member3 = yyjson_mut_str(doc, "子豪");
    yyjson_mut_arr_append(val_arr_userName, val_arr_userName_member1);
    yyjson_mut_arr_append(val_arr_userName, val_arr_userName_member2);
    yyjson_mut_arr_append(val_arr_userName, val_arr_userName_member3);
    yyjson_mut_obj_add(root, key_arr_userName, val_arr_userName);

    // 创建message
    yyjson_mut_val *key_obj_message = yyjson_mut_str(doc, "message");
    yyjson_mut_val *val_obj_message=yyjson_mut_obj(doc);
    yyjson_mut_val *val_obj_message_key_sender=yyjson_mut_str(doc,"sender");
    yyjson_mut_val *val_obj_message_val_sender=yyjson_mut_str(doc,"");
    yyjson_mut_val *val_obj_message_key_msg=yyjson_mut_str(doc,"msg");
    yyjson_mut_val *val_obj_message_val_msg=yyjson_mut_str(doc,"");
    yyjson_mut_obj_add(val_obj_message,val_obj_message_key_sender,val_obj_message_val_sender);
    yyjson_mut_obj_add(val_obj_message,val_obj_message_key_msg,val_obj_message_val_msg);
    yyjson_mut_obj_add(root,key_obj_message,val_obj_message);

    //打印测试
    cout<<yyjson_mut_write(doc,YYJSON_WRITE_PRETTY,0)<<endl;
    return 0;
}