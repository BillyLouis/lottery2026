// #ifndef EIGENPREDICTOR_H
// #define EIGENPREDICTOR_H

// #ifdef __cplusplus
// #include <Eigen/Dense>
// #include <string>

// // ------------------------------------------------------------
// // Define struct for predictor input
// // ------------------------------------------------------------
// // struct PredictorInput {
// //     Eigen::MatrixXf matrix;
// //     float myDate;
// //     std::string dateLabel;
// // };
// //==================
// struct PredictorSet {
//     Eigen::MatrixXf matrix;
//     float myDate;
//     std::string dateLabel;
//     int constants[6];
//     Node* head = nullptr;
// };

// struct PredictorInput {
//     std::vector<PredictorSet> sets;
// };

// // Returns a hardcoded test input (can be extended later)
// PredictorInput getPredictorInput();

// extern "C" {
// #endif

// // Main predictor entry point callable from Go
// void run_predictor();

// #ifdef __cplusplus
// }
// #endif

// #endif // EIGENPREDICTOR_H
//==================================================
// #ifndef EIGENPREDICTOR_H
// #define EIGENPREDICTOR_H

// #ifdef __cplusplus
// #include <Eigen/Dense>
// #include <string>
// #include <vector>      // Required for std::vector
// #include <cstring>     // Required for memcpy

// // ------------------------------------------------------------
// // Forward declarations
// // ------------------------------------------------------------
// struct Node;

// // ------------------------------------------------------------
// // Define struct for predictor input
// // ------------------------------------------------------------
// struct PredictorInput;  // Forward declare since PredictorSet refers to it

// struct PredictorSet {
//     Eigen::MatrixXf matrix;
//     float myDate = 0.0f;
//     std::string dateLabel;
//     int constants[6];       // e.g., {11,17,24,35,38,5}
//     Node* head = nullptr;   // each matrix gets its own linked list
// };

// struct PredictorInput {
//     std::vector<PredictorSet> sets;  // multi-matrix support
// };

// // ------------------------------------------------------------
// // Define Node structure for linked list
// // ------------------------------------------------------------
// struct Node {
//     std::string idx;
//     float value;
//     int trunc;
//     int minus1;
//     int plus1;
//     std::string op_mode;
//     std::string position;
//     Node* next;

//     Node() : value(0), trunc(0), minus1(0), plus1(0), next(nullptr) {}  // default constructor
//     Node(const std::string& i, float v, int t, int m1, int p1,
//          const std::string& op, const std::string& pos)
//         : idx(i), value(v), trunc(t), minus1(m1), plus1(p1),
//           op_mode(op), position(pos), next(nullptr) {}
// };

// // Returns a hardcoded test input (can be extended later)
// PredictorInput getPredictorInput();

// // Main predictor entry point callable from Go
// extern "C" {
// void run_predictor();
// }

// #endif // __cplusplus
// #endif // EIGENPREDICTOR_H

//==============================================================
// #ifndef EIGENPREDICTOR_H
// #define EIGENPREDICTOR_H

// #ifdef __cplusplus
// // C++-only includes go here
// #include <Eigen/Dense>
// #include <string>
// #include <vector>
// #include <cstring>
// #endif

// // Forward declarations (safe in both C and C++)
// #ifdef __cplusplus
// struct Node;
// struct PredictorInput;  // forward declare
// struct PredictorSet {
//     Eigen::MatrixXf matrix;
//     float myDate = 0.0f;
//     std::string dateLabel;
//     int constants[6];
//     Node* head = nullptr;
// };
// struct PredictorInput {
//     std::vector<PredictorSet> sets;
// };
// struct Node {
//     std::string idx;
//     float value;
//     int trunc;
//     int minus1;
//     int plus1;
//     std::string op_mode;
//     std::string position;
//     Node* next;
//     Node() : value(0), trunc(0), minus1(0), plus1(0), next(nullptr) {}
//     Node(const std::string& i, float v, int t, int m1, int p1,
//          const std::string& op, const std::string& pos)
//       : idx(i), value(v), trunc(t), minus1(m1), plus1(p1),
//         op_mode(op), position(pos), next(nullptr) {}
// };
// PredictorInput getPredictorInput();
// #endif

// // Always declare the C-callable function for both C and C++
// #ifdef __cplusplus
// extern "C" {
// #endif

// void run_predictor(void);

// #ifdef __cplusplus
// } // extern "C"
// #endif

// #endif // EIGENPREDICTOR_H
//==============================================================
#ifndef EIGENPREDICTOR_H
#define EIGENPREDICTOR_H

#ifdef __cplusplus
// C++-only includes go here
#include <Eigen/Dense>
#include <string>
#include <vector>
#include <cstring>
#include <streambuf>
#include <ostream>

// Forward declarations (safe in both C and C++)
struct Node;
struct PredictorInput;  // forward declare

struct PredictorSet {
    Eigen::MatrixXf matrix;
    float myDate = 0.0f;
    std::string dateLabel;
    std::string setId;     // optional identifier from JSON (or fallback to index)
    int constants[6];
    Node* head = nullptr;
};

struct PredictorInput {
    std::vector<PredictorSet> sets;
};

struct Node {
    std::string idx;
    float value;
    int trunc;
    int minus1;
    int plus1;
        int count;            // line/count number in traversal
    std::string op_mode;
    std::string position;
    Node* next;
        Node() : value(0), trunc(0), minus1(0), plus1(0), count(0), next(nullptr) {}
        Node(const std::string& i, float v, int t, int m1, int p1, int cnt,
                 const std::string& op, const std::string& pos)
            : idx(i), value(v), trunc(t), minus1(m1), plus1(p1), count(cnt),
                op_mode(op), position(pos), next(nullptr) {}
};

PredictorInput getPredictorInput();

// ------------------------------------------------------------
// TeeBuf class: duplicates output to console and file
// ------------------------------------------------------------
class TeeBuf : public std::streambuf {
    std::streambuf* sb1;
    std::streambuf* sb2;
public:
    TeeBuf(std::streambuf* buf1, std::streambuf* buf2)
        : sb1(buf1), sb2(buf2) {}

protected:
    virtual int overflow(int c) {
        if (c == EOF) return !EOF;
        if (sb1->sputc(c) == EOF || sb2->sputc(c) == EOF) return EOF;
        return c;
    }
    virtual int sync() {
        return (sb1->pubsync() == 0 && sb2->pubsync() == 0) ? 0 : -1;
    }
};

#endif // __cplusplus

// Always declare the C-callable function for both C and C++
#ifdef __cplusplus
extern "C" {
#endif

void run_predictor(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // EIGENPREDICTOR_H