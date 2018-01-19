//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

string Notification;

/////////////////////////////////////////////////////////////////////////////
public void receiveEvent(object caller, string event)
{
    Notification = event;
}

/////////////////////////////////////////////////////////////////////////////
public string checkNotification()
{
    return Notification;
}
