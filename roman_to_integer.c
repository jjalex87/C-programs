

int romanToInt(char * s){
    int romToIntLut[26];
    char roman[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int integer[7] = {1, 5, 10, 50, 100, 500, 1000};
    int idx;
    int len = strlen(s);
    int val = 0;
    int isSubtract = 0;
    
    for (idx = 0; idx < 7; idx++)
    {
        romToIntLut[roman[idx] - 'A'] = integer[idx];
    }
    
    for (idx = 0; idx < len; idx++)
    {
        isSubtract = 0;
        switch(s[idx])
        {
            case 'I':
                if (s[idx + 1] == 'V' || s[idx + 1] == 'X')
                {
                    isSubtract = 1;
                }
                break;
            case 'X':
                if (s[idx + 1] == 'L' || s[idx + 1] == 'C')
                {
                    isSubtract = 1;
                }
                break;
            case 'C':
                if (s[idx + 1] == 'D' || s[idx + 1] == 'M')
                {
                    isSubtract = 1;
                }
                break;
            default:
                break;
        }
        if (isSubtract)
        {
            val += romToIntLut[s[idx + 1] - 'A'] - romToIntLut[s[idx] - 'A'];
            idx++;
        }
        else
        {
            val += romToIntLut[s[idx] - 'A'];
        }
    }
    return (val);
}
