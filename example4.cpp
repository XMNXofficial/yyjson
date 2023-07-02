#include <yyjson.h>
#include <iostream>
using namespace std;
void こんにちは()
{
    printf("hello world\nこんにちは\n");
}
int main()
{
    int i = 1, num = 0;
    while (i < 3)
    {
        num += i++;
        i++;
    }
    // こんにちは();
    // char SendBuff[6666]={0};
    // string userName("haohaoa159");
    // string userPwd("hihihi");
    // yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
    // yyjson_mut_val *root = yyjson_mut_obj(doc);
    // yyjson_mut_doc_set_root(doc, root);
    // yyjson_mut_val *key_stateID = yyjson_mut_str(doc, "stateID");
    // yyjson_mut_val *val_stateID = yyjson_mut_int(doc, 1);
    // yyjson_mut_val *key_loginName = yyjson_mut_str(doc, "loginName");
    // yyjson_mut_val *val_loginName = yyjson_mut_str(doc, userName.c_str());
    // yyjson_mut_val *key_loginPwd = yyjson_mut_str(doc, "loginPwd");
    // yyjson_mut_val *val_loginPwd = yyjson_mut_str(doc, userPwd.c_str());
    // yyjson_mut_obj_add(root, key_stateID, val_stateID);
    // yyjson_mut_obj_add(root, key_loginName, val_loginName);
    // yyjson_mut_obj_add(root, key_loginPwd, val_loginPwd);
    // strcpy(SendBuff, yyjson_mut_write(doc, 0, nullptr));
    // yyjson_mut_doc_free(doc);
    // cout<<SendBuff;
    return 0;
}