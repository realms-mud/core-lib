//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'This estate lies north of "
        "Linwaeth. The road carries grain and wool toward town, "
        "and the coast road continues farther south.'");
    addResponse("first conversation", "Are there dangers?",
        "@S@'Foxes hunt near the hedges, and a traveler should keep "
        "to the road after dark. The household reports any serious "
        "trouble to Linwaeth.'");
}
