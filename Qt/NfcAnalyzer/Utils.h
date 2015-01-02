#ifndef UTILS_H
#define UTILS_H


class Utils
{
private:
    static char bin_str[9];

public:
    Utils();
    ~Utils();

    static const char * HexToBin(int hex);
};

#endif // UTILS_H
