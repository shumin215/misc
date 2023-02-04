#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

#define CYCLE_TITLE "CYCLE"
#define VAL_TITLE   "VALUE"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unistd.h>
#include <assert.h>

template <typename T>
class Histogram
{
    struct Hist_Info 
    {
        T val;
        unsigned cycle;
    };
    public:
        Histogram(unsigned *cycle, std::string fname):
            _cycle(cycle), _fname_txt(fname+".txt"), _fname_csv(fname+".csv")
        {
            if (access((_fname_txt).c_str(), F_OK) == 0) {
                auto exist = remove((_fname_txt).c_str());

                if (exist == -1)
                    assert(false);
            }
            if (access((_fname_csv).c_str(), F_OK) == 0) {
                auto exist = remove((_fname_csv).c_str());

                if (exist == -1)
                    assert(false);
            }

        }
        Histogram()
        {
            _cycle = NULL;
            _fname_txt = "";
            _fname_csv = "";
        }
        ~Histogram() {}

        void setVal(T val);
        void printHistogram(void);
        void makeCSV (void);
        void setCycle (unsigned *cycle) { this->_cycle = cycle; }
        void setFname (std::string fname);

    private:
        unsigned *_cycle;
        std::vector<Hist_Info> _list;
        std::string _fname_txt;
        std::string _fname_csv;
};
template <typename T>
void Histogram<T>::setFname (std::string fname)
{
    assert(_fname_txt == "");
    assert(_fname_csv == "");

    _fname_txt = fname + ".txt";
    _fname_csv = fname + ".csv";

    if (access((_fname_txt).c_str(), F_OK) == 0) {
        auto exist = remove((_fname_txt).c_str());

        if (exist == -1)
            assert(false);
    }
    if (access((_fname_csv).c_str(), F_OK) == 0) {
        auto exist = remove((_fname_csv).c_str());

        if (exist == -1)
            assert(false);
    }
}

template <typename T>
void Histogram<T>::setVal (T val)
{
    std::ofstream fout;
    Hist_Info hi;
    hi.cycle = *_cycle;
    hi.val = val;

    fout.open(_fname_txt, std::ios_base::out | std::ios_base::app);
    fout << "[" << hi.cycle << "] Value=" << hi.val << "\n";
    fout.close();
    if (_list.empty()) {
        _list.push_back(hi);

        return;
    }

    // Check the data is same with previous data
    Hist_Info latestInfo = _list.front();
    if (latestInfo.val != val) {
        _list.push_back(hi);
    }
}

template <typename T>
void Histogram<T>::printHistogram (void)
{
    for (auto iter=_list.begin(); iter<_list.end(); iter++) {
        std::cout << "[" << iter->cycle << "] Value=" << iter->val << std::endl;
    }
}

template <typename T>
void Histogram<T>::makeCSV (void)
{
    std::ofstream fout;
    fout.open(_fname_csv, std::ios_base::out | std::ios_base::app);
    fout << CYCLE_TITLE << "," << VAL_TITLE << "\n";

    for (auto iter=_list.begin(); iter<_list.end(); iter++) {
        fout << iter->cycle << "," << iter->val << "\n";
    }
}

#endif /* _HISTOGRAM_H_*/
