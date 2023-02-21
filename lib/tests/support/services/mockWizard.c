//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/wizard.c";

private string lastCatch = 0;
private string *catchList = ({});

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
    return catchList + ({});
}

/////////////////////////////////////////////////////////////////////////////
public void resetCatchList()
{
    catchList = ({});
}
