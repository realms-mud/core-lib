//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useConversations = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockConversations()
{
    useConversations = !useConversations;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int userHasHadConversation(string playerName, string topic)
{
    return useConversations;
}
