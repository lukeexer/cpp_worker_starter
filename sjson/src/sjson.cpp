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

string SJson::from_json(json src_json) {
    string converted_str = "";

    try {
        converted_str = src_json.dump();
    } catch (...) {
        throw ConvertFromJsonToStringException();
    }

    return converted_str;
}

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

    try {
        json src_json_obj;
        src_json_obj["happy"] = true;
        src_json_obj["pi"] = 3.141;
        string converted_string = SJson::from_json(src_json_obj);
        cout << "The converted JSON string is: " << converted_string << endl;
    } catch (ConvertFromJsonToStringException exp) {
        cout << "Failed to convert the specifed json object to string" << endl;
        cout << exp.what() << endl;
    }

    return 0;
}