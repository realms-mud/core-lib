//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string eventReceived;
private mixed dataReceived;

/////////////////////////////////////////////////////////////////////////////
public void create() 
{
    eventReceived = "none";
    dataReceived = 0;
}

/////////////////////////////////////////////////////////////////////////////
public string lastEvent()
{
    return eventReceived;
}

/////////////////////////////////////////////////////////////////////////////
public string lastData()
{
    return dataReceived;
}

/////////////////////////////////////////////////////////////////////////////
public void receiveEvent(object caller, string event, mixed data)
{
    eventReceived = event;
    dataReceived = data;
}
