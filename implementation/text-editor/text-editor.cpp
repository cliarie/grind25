#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

void display_lines(const vector<string> &lines){
    for (auto &s : lines){
        cout << s << endl;
    }
}

class TextEditor {
public:
    TextEditor(const vector<string> &lines) : lines(lines){
        map_braces();
    }

    void toggle(int visual_line){
        int line = visual_to_actual.find(visual_line) != visual_to_actual.end() ? visual_to_actual[visual_line] : visual_line;
        if (braces.find(line) != braces.end()){
            if (collapsed.find(line) == collapsed.end())
                collapsed.insert(line);
            else{
                collapsed.erase(line);
            }
        }
    }

    void display(){
        int n = lines.size();
        visual_to_actual.clear();

        int visual_line = 0;
        for (int i = 0; i < n; ++i){
            if (braces.find(i) == braces.end()){
                cout << lines[i] << endl;
                visual_to_actual[visual_line] = i;
                visual_line++;
                continue;
            }
            if (collapsed.find(i) != collapsed.end()){
                cout << lines[i].substr(0, lines[i].find('{') + 1) << " ... }" << endl;
                visual_to_actual[visual_line] = i;
                visual_line++;
                i = braces[i];
            }
            else { // brace but not collapsed
                cout << lines[i] << endl;
                visual_to_actual[visual_line] = i;
                visual_line++;
            }

        }
    }

private:
    vector<string> lines;
    unordered_map<int, int> braces;
    unordered_set<int> collapsed;
    unordered_map<int, int> visual_to_actual;

    void map_braces(){
        stack<int> s;
        int n = lines.size();
        for (int i = 0; i < n; ++i){
            for (auto c : lines[i]){
                if (c == '{') s.push(i);
                else if (c == '}'){
                    braces[s.top()] = i;
                    s.pop();
                }
            }
        }
    }
};

int main(){
    vector<string> lines = {
        "int main(int n) {",
        "  for (int i = 0; i < n; i++) {",
        "      cout << \"hello\" << endl;",
        "    }",
        "  }",
        "int foo(int a) {",
        "    return a + 1;",
        "  }"
    };

    TextEditor editor(lines);

    // for (auto [k, v] : editor.braces) cout << k << " " << v << endl;
    editor.display();

    editor.toggle(1);
    editor.display();

    editor.toggle(0);
    editor.display();

    editor.toggle(1);
    editor.display();
}
