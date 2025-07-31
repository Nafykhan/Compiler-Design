#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

const string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "class", "public",
    "private", "protected", "template", "typename", "using", "namespace"
};
const int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

const string operators[] = {
    "+", "-", "*", "/", "%", "++", "--", "==", "!=", ">", "<", ">=", "<=",
    "=", "+=", "-=", "*=", "/=", "%=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"
};
const int operatorCount = sizeof(operators) / sizeof(operators[0]);

const char punctuation[] = {
    '(', ')', '{', '}', '[', ']', ';', ',', '.', ':'
};
const int punctuationCount = sizeof(punctuation) / sizeof(punctuation[0]);

bool isKeyword(const string& token) {
    for (int i = 0; i < keywordCount; ++i) {
        if (keywords[i] == token)
            return true;
    }
    return false;
}

bool isOperator(const string& token) {
    for (int i = 0; i < operatorCount; ++i) {
        if (operators[i] == token)
            return true;
    }
    return false;
}

bool isPunctuation(char ch) {
    for (int i = 0; i < punctuationCount; ++i) {
        if (punctuation[i] == ch)
            return true;
    }
    return false;
}

bool isConstant(const string& token) {
    int dotCount = 0;
    for (char ch : token) {
        if (isdigit(ch)) continue;
        if (ch == '.' && ++dotCount <= 1) continue;
        return false;
    }
    return !token.empty();
}

bool isValidIdentifier(const string& token) {
    if (token.empty()) return false;
    if (!(isalpha(token[0]) || token[0] == '_')) return false;

    for (char ch : token) {
        if (!(isalnum(ch) || ch == '_')) return false;
    }
    return true;
}

void classifyToken(const string& token) {
    if (token.empty()) return;

    if (isKeyword(token)) {
        cout << "[Keyword]           : " << token << endl;
    } else if (isOperator(token)) {
        cout << "[Operator]          : " << token << endl;
    } else if (token.length() == 1 && isPunctuation(token[0])) {
        cout << "[Punctuation]       : " << token << endl;
    } else if (isConstant(token)) {
        cout << "[Constant]          : " << token << endl;
    } else if (isValidIdentifier(token)) {
        cout << "[Valid Identifier]  : " << token << endl;
    } else {
        cout << "[Invalid Identifier]: " << token << endl;
    }
}

void tokenizeLine(const string& line) {
    string token;
    for (size_t i = 0; i < line.length(); ++i) {
        char ch = line[i];

        if (ispunct(ch) && !isspace(ch)) {
            if (!token.empty()) {
                classifyToken(token);
                token.clear();
            }

            string op(1, ch);
            if (i + 1 < line.length()) {
                string twoCharOp = op + line[i + 1];
                if (isOperator(twoCharOp)) {
                    classifyToken(twoCharOp);
                    ++i;
                    continue;
                }
            }

            if (isOperator(op)) {
                classifyToken(op);
            } else if (isPunctuation(ch)) {
                classifyToken(op);
            }
        } else if (isspace(ch)) {
            if (!token.empty()) {
                classifyToken(token);
                token.clear();
            }
        } else {
            token += ch;
        }
    }

    if (!token.empty()) {
        classifyToken(token);
    }
}

int main() {
    ifstream file("/Users/macbookpro/Documents/Labtask3/program.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    cout << "Tokenizing...\n\n";
    string line;
    while (getline(file, line)) {
        tokenizeLine(line);
    }

    file.close();
    return 0;
}
