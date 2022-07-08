int getDecimalFromRoman(char roman)
{
    switch(roman)
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

int romanToInt(char * s){
    int len = strlen(s);
    int i;
    int val1, val2;
    int decimal = 0;
    
    for (i = 0; i < len; i++)
    {
        val2 = 0;
        val1 = getDecimalFromRoman(s[i]);
        if ((i + 1) < len)
        {
            val2 = getDecimalFromRoman(s[i + 1]);
        }
        if (val1 >= val2)
        {
            decimal += val1;
        }
        else
        {
            decimal = decimal + val2 - val1;
            i++;
        }
    }
    return (decimal);
}
