
#include <string>
#include <iostream>

#include <cppexpose/Object.h>
#include <cppexpose/JSON.h>

#include <cppexpose-js/Engine.h>

#include "TreeNode.h"
#include "MyObject.h"
#include "linenoise-ng/linenoise.h"


using namespace cppexpose;


int main(int, char * [])
{
    cppexpose_js::Engine engine;

    // Create scripting environment
    Object script;
    engine.addGlobalObject("script", &script);

    MyObject obj;
    script.addProperty("obj", &obj);

    TreeNode tree;
    script.addProperty("tree", &tree);

    Array array;
    array.push(Variant(10));
    array.push(Variant(11));
    array.push(Variant(12));
    script.addProperty("array", &array);

    Object json;
    json = Variant("{\"a\": 1, \"b\": 2, \"c\": 3 }");
    script.addProperty("json", &json);

    Array arr;
    arr = Variant("[123, 124, 125]");
    script.addProperty("arr", &arr);

    // Start interactive command console
    while (char * line = linenoise("> ")) {
        // Get command
        std::string cmd = line;
        free(line);

        // Check command
        if (cmd[0] != '\0') {
            // Process command
            if (cmd == "exit") {
                // Exit command line
                break;
            } else {
                // Execute javascript code
                Variant result = engine.evaluate(cmd);
                std::cout << result.toString() << std::endl;

                // Add line to history
                linenoiseHistoryAdd(cmd.c_str());
            }
        }
    }

    // Exit application
    return 0;
}
