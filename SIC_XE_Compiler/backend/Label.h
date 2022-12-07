#ifndef LABEL_H_
#define LABEL_H_

#include <sstream>
#include <iomanip>
#include <string>

namespace backend {

using namespace std;

class Label {
private:
    static int index;
    string label;

public:
    Label() {
        stringstream ss;
        ss << setw(6) << setfill('0') << ++index;
        label = "L" + ss.str();
    }

    string getString() const { return label; }

    friend ostream& operator << (ostream& ofs, const Label *label);
};

inline ostream& operator << (ostream& ofs, const Label *label) {
    ofs << label->getString();
    return ofs;
}

}

#endif
