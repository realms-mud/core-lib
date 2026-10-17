//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";
virtual inherit "/lib/tests/support/services/databaseExperienceOwner.c";

private string lastCatch = 0;
private string *catchList = ({ });
private string *gmcpFrames = ({ });

/////////////////////////////////////////////////////////////////////////////
protected int experienceOwnerId()
{
    return databaseExperienceOwner::experienceOwnerId();
}

/////////////////////////////////////////////////////////////////////////////
public void agePlayer(int amount)
{
    this_object().materialAttributesHeartBeat(amount);
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
    lastCatch = 0;
}

/////////////////////////////////////////////////////////////////////////////
public int playerExists(string name)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
// Test seam: capture the raw bytes the GMCP module would write to the socket
// instead of calling binary_message() (which requires a real interactive
// connection). Store the decoded string so tests can assert on package/body.
/////////////////////////////////////////////////////////////////////////////
protected int writeBytesToConnection(int *data)
{
    if (pointerp(data) && sizeof(data))
    {
        gmcpFrames += ({ to_string(data) });
    }
    return sizeof(data);
}

/////////////////////////////////////////////////////////////////////////////
// Test helper: enable GMCP on the mock without triggering the full telnet
// negotiation lifecycle (subscriber clone + initial pushes). Tests that need
// the subscriber must set it up themselves via gmcpEventSubscriber directly.
/////////////////////////////////////////////////////////////////////////////
public void enableGmcp()
{
    setGmcpEnabled(1);
}



/////////////////////////////////////////////////////////////////////////////
public string caughtGmcp()
{
    return sizeof(gmcpFrames) ? gmcpFrames[<1] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public string *caughtGmcpFrames()
{
    return gmcpFrames + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public void clearCaughtGmcp()
{
    gmcpFrames = ({ });
}
