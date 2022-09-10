#include <sjson/sjson.h>

#include <iostream>

json SJson::to_json(string src_str) {
    json converted_json = NULL;

    try {
        converted_json = json::parse(src_str);
    } catch (...) {
        throw ConvertFromStringToJsonException();
    }
    
    return converted_json;
}

// string SJson::from_json(json &src_json) {

// }

using namespace std;

int main(int, char*[])
{
    try {
        string src_json_str = R"({"happy": true, "pi": 3.141})";
        //string src_json_str = R"({"happy": true, "pi": 3.141)"; // Test invalid json string format
        json j = SJson::to_json(src_json_str);
        cout << "happy: " << j["happy"] << endl;
        cout << "pi: " << j["pi"] << endl;
    } catch (ConvertFromStringToJsonException exp) {
        cout << "Failed to convert the specified string to json object" << endl;
        cout << exp.what() << endl;
    }

    return 0;
}