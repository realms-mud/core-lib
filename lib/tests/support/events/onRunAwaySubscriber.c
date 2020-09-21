//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled;

/////////////////////////////////////////////////////////////////////////////
public int TimesRunAwayEventReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void onRunAway(object caller)
{
    NumTimesCalled++;
}
