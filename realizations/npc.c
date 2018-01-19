//*****************************************************************************
// Class: npc
// File Name: npc.c
//
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/conversations.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfNpc()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    remove_action(1);
    add_action("talk", "repeat");
    add_action("talk", "talk");
}

/////////////////////////////////////////////////////////////////////////////
public int talk(string who)
{
    int ret = 0;
    if (!who || id(who))
    {
        object conversations = getService("conversations");
        if (objectp(conversations))
        {
            ret = conversations->beginConversation(this_player());
        }
    }
    return ret;
}