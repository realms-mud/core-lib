//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int NumTimesCalled;

/////////////////////////////////////////////////////////////////////////////
public int TimesUsedResearchEventReceived()
{
    return NumTimesCalled;
}

/////////////////////////////////////////////////////////////////////////////
public void usedResearchEvent(object caller)
{
    NumTimesCalled++;
}


