#ifndef FM_SAMPLE_H_
#define FM_SAMPLE_H_

#include <string>
#include <vector>
#include <iostream>

class fm_sample
{
public:
    double w = 1.0;
    int y;
    std::vector<std::pair<std::string, double>> x;
    fm_sample(const std::string& line);
private:
    static const char* spliter;
    static const char* innerSpliter;
};

const char* fm_sample::spliter = " ";
const char* fm_sample::innerSpliter = ":";

fm_sample::fm_sample(const std::string& line)
{
    this->x.clear();

    size_t posb = line.find_first_not_of(spliter, 0);
    size_t pose = line.find_first_of(spliter, posb);
    this->w = std::stod(line.substr(posb, pose - posb));

    posb = line.find_first_not_of(spliter, pose);
    pose = line.find_first_of(spliter, posb);
    int label = atoi(line.substr(posb, pose-posb).c_str());
    this->y = label > 0 ? 1 : -1;

    std::string key;
    double value;
    const size_t linesz = line.size();
    while(pose < linesz)
    {
        posb = line.find_first_not_of(spliter, pose);
        if(posb == std::string::npos)
        {
            break;
        }
        pose = line.find_first_of(innerSpliter, posb);
        if(pose == std::string::npos)
        {
            cerr << "wrong line of sample input\n" << line << endl;
            exit(1);
        }
        key = line.substr(posb, pose-posb);
        posb = pose + 1;
        if(posb >= line.size())
        {
            cerr << "wrong line of sample input\n" << line << endl;
            exit(1);
        }
        pose = line.find_first_of(spliter, posb);
        value = stod(line.substr(posb, pose-posb));
        if(value != 0)
        {
            this->x.emplace_back(key, value);
        }
    }
}

#endif /*FM_SAMPLE_H_*/
