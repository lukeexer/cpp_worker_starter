#include <string>

#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class SJson {
    public:
        static json to_json(string src_str);
        //static string from_json(json &src_json);
};

class ConvertFromStringToJsonException: public std::exception {
    public:
        string what () {
            return "Failed to convert string to JSON.";
        }
};

class ConvertFromJsonToStringException: public std::exception {
    public:
        string what () {
            return "Failed to convert string to JSON.";
        }
};