//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/monsterWithAI.c";

private int pathCompletedCalled = 0;

/////////////////////////////////////////////////////////////////////////////
protected void onPathCompleted()
{
    pathCompletedCalled = 1;
    monsterWithAI::onPathCompleted();
}

/////////////////////////////////////////////////////////////////////////////
public int wasPathCompleted()
{
    return pathCompletedCalled;
}
