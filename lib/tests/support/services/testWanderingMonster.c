//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/wanderingMonster.c";

private int pathCompletedCalled = 0;

/////////////////////////////////////////////////////////////////////////////
protected void onPathCompleted()
{
    pathCompletedCalled = 1;
    wanderingMonster::onPathCompleted();
}

/////////////////////////////////////////////////////////////////////////////
public int wasPathCompleted()
{
    return pathCompletedCalled;
}
