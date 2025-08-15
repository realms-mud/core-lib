//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = 0;

    object partyService = getService("party");
    if (partyService)
    {
        ret = partyService->getParty(this_object());
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
        ret = regreplace(party->partyName(), "(.*)#[^#]+", "\\1", 1);
    }
    return ret;
}
