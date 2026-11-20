//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The drove road is kept clear "
        "for the flocks. Keep to it after dark; the western track is "
        "rough country.'");
}
