//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/organizations.c";

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = 0;

    object dictionary = load_object("/lib/dictionaries/partyDictionary.c");
    if (dictionary)
    {
        ret = dictionary->getParty(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    string ret = 0;

    object party = getParty();
    if (party)
    {
        ret = party->partyName();
    }
    return ret;
}
