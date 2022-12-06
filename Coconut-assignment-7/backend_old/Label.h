/**
 * <h1>Label</h1>
 *
 * <p>Jasmin instruction label.</p>
 *
 * <p>Copyright (c) 2020 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef LABEL_H_
#define LABEL_H_

#include <sstream>
#include <iomanip>
#include <string>

namespace backend {

using namespace std;

class Label {
private:
    static int index;  // index for generating label strings
    string label;      // the label string

public:
    Label() {
        stringstream ss;
        ss << setw(6) << setfill('0') << ++index;
        label = "L" + ss.str();
    }

    string getString() const { return label; }

    friend ostream& operator << (ostream& ofs, const Label *label);
};

inline ostream& operator << (ostream& ofs, const Label *label)
{
    ofs << label->getString();
    return ofs;
}

}

#endif /* LABEL_H_ */
