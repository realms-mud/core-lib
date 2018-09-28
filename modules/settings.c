//*****************************************************************************
// Class: parties
// File Name: parties.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/settings.h"
#include "/lib/include/settings.h"

/////////////////////////////////////////////////////////////////////////////
public int blocked(object target)
{
    return objectp(target) && member(blocks, target->RealName());
}

/////////////////////////////////////////////////////////////////////////////
public int block(string name)
{
    int ret = 0;

    if (name && stringp(name) && this_object()->playerExists(name))
    {
        ret = 1;
        blocks[name] = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void unblock(string name)
{
    if (member(blocks, name))
    {
        m_delete(blocks, name);
    }
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
public nomask varargs int receiveMessage(string message, object initiator)
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
        if (initiator)
        {
            ReplyTo = initiator;
        }
        tell_object(this_object(), message);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object ReplyToUser()
{
    return ReplyTo;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int pageSize(int newSize)
{
    if (newSize)
    {
        PageSize = newSize;
    }
    return PageSize;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string colorConfiguration(string newColorSetting)
{
    if(member(({ "none", "3-bit", "8-bit", "24-bit" }), newColorSetting) > -1)
    {
        colorSetting = newColorSetting;
    }
    return colorSetting;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string charsetConfiguration(string newCharSet)
{
    if (member(({ "ascii", "unicode" }), newCharSet) > -1)
    {
        characterSet = newCharSet;
    }
    return characterSet;
}
