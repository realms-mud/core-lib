//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";

private string lastCatch = 0;

/////////////////////////////////////////////////////////////////////////////
public int agePlayer(int amount)
{
    this_object()->materialAttributesHeartBeat(amount);
}

/////////////////////////////////////////////////////////////////////////////
public void catch_tell(string message)
{
    lastCatch = message;
}

/////////////////////////////////////////////////////////////////////////////
public string caughtMessage()
{
    return lastCatch;
}
