//*****************************************************************************
// Class: parties
// File Name: parties.c
//
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/settings.h"
#include "/lib/include/settings.h"

/////////////////////////////////////////////////////////////////////////////
public int blocked(object target)
{
    return member(blockedUsers, target->RealName());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isBusy()
{
    return IsBusy;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isEarmuffed()
{
    return Earmuffs;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void toggleBusy()
{
    IsBusy = !IsBusy;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void toggleEarmuffs()
{
    Earmuffs = !Earmuffs;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void clearReplyTo()
{
    ReplyTo = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int receiveMessage(object initiator, string message)
{
    int ret = MessageSent;
    if (blocked(initiator))
    {
        ret = Blocked;
    }
    // TODO: 47 - Need to allow higher level wizards to bypass busy flag
    else if (isBusy())
    {
        ret = Busy;
    }
    else
    {
        ReplyTo = initiator;
        tell_object(this_object(), message);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object ReplyToUser()
{
    return ReplyTo;
}
