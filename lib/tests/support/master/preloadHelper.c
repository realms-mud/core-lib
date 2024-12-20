//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/secure/master/preload.c";

/////////////////////////////////////////////////////////////////////////////
public void SwapInitFile(string newFile)
{
    initFile = newFile;
}

/////////////////////////////////////////////////////////////////////////////
public void AutoLoadCoreLib(int value)
{
    ShouldAutoLoadCoreLib = value;
}
