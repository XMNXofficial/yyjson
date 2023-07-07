#include "yyjson.h"
#include "iostream"
using namespace std;
int main()
{
    string str = R"({"arr":[{"test":1},{"test":2},{"test":3},{"test":4},{"test":5}]})";
    auto doc = yyjson_read(str.c_str(), str.length(), 0);
    auto root = yyjson_doc_get_root(doc);
    auto obj1 = yyjson_obj_get(root, "arr");
    for (int i1 = 0; i1 < yyjson_arr_size(obj1); i1++)
    {
        auto arr1 = yyjson_arr_get(obj1, i1);
        auto arr1_obj = yyjson_obj_get(arr1, "test");
        auto int1 = yyjson_get_int(arr1_obj);
        cout << int1<<endl;
    }

    return 0;
}