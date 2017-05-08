//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useQuests = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockQuests()
{
    useQuests = !useQuests;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int questIsCompleted(string quest)
{
    return useQuests;
}

