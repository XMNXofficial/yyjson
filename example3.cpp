#include<yyjson.h>
#include<iostream>
using namespace std;
int main()
{
    yyjson_mut_doc* doc=yyjson_mut_doc_new(NULL);
    yyjson_mut_val* root=yyjson_mut_obj(doc);
    yyjson_mut_doc_set_root(doc,root);
    yyjson_mut_val *key_stateID = yyjson_mut_str(doc, "stateID");
    yyjson_mut_val *val_stateID = yyjson_mut_int(doc,1);
    yyjson_mut_obj_add(root, key_stateID, val_stateID);
    yyjson_mut_val *key_userName = yyjson_mut_str(doc, "userName");
    yyjson_mut_val *val_userName = yyjson_mut_str(doc, "test");
    yyjson_mut_obj_add(root, key_userName, val_userName);
    yyjson_mut_val *key_msg = yyjson_mut_str(doc, "msg");
    yyjson_mut_val *val_msg = yyjson_mut_str(doc, "test");
    yyjson_mut_obj_add(root, key_msg, val_msg);
    char json_backup[2048]={0};
    strcpy(json_backup,yyjson_mut_write(doc,0,0));
    yyjson_mut_doc_free(doc);
cout<<json_backup;


    // yyjson_doc* idoc=yyjson_read(json_backup,strlen(json_backup),0);
    // yyjson_val

    return 0;
}