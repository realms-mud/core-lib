//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The Llenwych flocks range "
        "along the drove road in season. We send wool north and "
        "buy grain from the farms nearer the capital.'");
    addResponse("first conversation", "Is the road safe?",
        "@S@'The main track is used daily. Stray dogs and foxes "
        "trouble the lambs more often than brigands do.'");
}
