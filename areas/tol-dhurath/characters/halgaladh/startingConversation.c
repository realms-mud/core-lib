//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("seilyndria", "@S@'Seilyndria? This cannot be - she was cast "
        "into the void a long time ago. What can this mean?' @D@says "
        "Halgaladh, brow furrowed in thought, fear apparent on his face.");
}
