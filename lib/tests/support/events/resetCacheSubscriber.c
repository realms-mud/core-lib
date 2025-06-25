//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled = 0;

/////////////////////////////////////////////////////////////////////////////
public int TimesResetCacheEventReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void onRecalculating(object caller)
{
    NumTimesCalled++;
}
