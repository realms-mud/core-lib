//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping dictionaries = ([]);

/////////////////////////////////////////////////////////////////////////////
object getDictionary(string dictionary)
{
    object ret = 0;

    if (member(dictionaries, dictionary) && objectp(dictionaries[dictionary]))
    {
        ret = dictionaries[dictionary];
    }
    else
    {
        string dictionaryPath = stringp(dictionary) ?
            sprintf("/lib/dictionaries/%sDictionary.c", dictionary) : 0;

        if (stringp(dictionaryPath) && (file_size(dictionaryPath) > 0))
        {
            ret = load_object(dictionaryPath);
        }
        dictionaries[dictionary] = ret;
    }
    return ret;
}
