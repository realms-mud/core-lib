//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private nosave string BaseConversation = "lib/modules/conversations/baseConversation.c";
private nosave mapping topics = ([]);
private nosave object CurrentTopic = 0;

private mapping opinions = ([]);
private mapping spokenTopics = ([]);

/////////////////////////////////////////////////////////////////////////////
static nomask void loadConversationData(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendConversation()
{
    return ([
    ]);
}
