//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("scions of dhuras", "@S@'That seems like a reasonable secondary "
        "goal.' @D@notes Halgaladh. @S@'Returning them to the Scions of Dhuras "
        "would bring both us and the king quite a bit of goodwill from that "
        "order.'");
}
