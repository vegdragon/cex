#include "Utils.h"

char Utils::bin_str[] = { '0', '0', '0', '0', '0', '0', '0', '0', '\0' };

Utils::Utils()
{

}

Utils::~Utils()
{

}

const char * Utils::HexToBin(int hex)
{
    int div = hex;
    int reminder = 0;
    int sizeOfBuffer = 0;
    int pos = sizeOfBuffer = sizeof(Utils::bin_str) / sizeof(char) - 1;

    for (int i=0;i<pos;i++) Utils::bin_str[i] = '0';

    bin_str[pos--] = '\0';
    do
    {
        reminder = div%2;
        div = div>>1;
        Utils::bin_str[pos--] = '0' + reminder;
    } while (div>0 && pos>=0);

    return &Utils::bin_str[0];
}
