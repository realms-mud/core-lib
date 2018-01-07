//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";

private string lastCatch = 0;
private string *catchList = ({ });

private int BlockPlayer = 0;

/////////////////////////////////////////////////////////////////////////////
public int agePlayer(int amount)
{
    this_object()->materialAttributesHeartBeat(amount);
}

/////////////////////////////////////////////////////////////////////////////
public void catch_tell(string message)
{
    lastCatch = message;
    catchList += ({ message });
}

/////////////////////////////////////////////////////////////////////////////
public string caughtMessage()
{
    return lastCatch;
}

/////////////////////////////////////////////////////////////////////////////
public string *caughtMessages()
{
    return catchList + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public void resetCatchList()
{
    catchList = ({ });
}

/////////////////////////////////////////////////////////////////////////////
public int blocked(object target)
{
    return BlockPlayer;
}

/////////////////////////////////////////////////////////////////////////////
public void toggleBlockPlayer()
{
    BlockPlayer = !BlockPlayer;
}
