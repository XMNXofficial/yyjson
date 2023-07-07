#include "yyjson.h"
#include "iostream"
using namespace std;
int main()
{
    string str = R"({})";
    auto doc = yyjson_read(str.c_str(), str.length(), 0);
    auto isObj = yyjson_is_obj(yyjson_doc_get_root(doc));
    // cout << yyjson_write(doc, 0, 0);
    cout <<isObj;

    return 0;
}