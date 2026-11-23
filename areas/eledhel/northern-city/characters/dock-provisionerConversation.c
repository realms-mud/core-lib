//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Taviel arranges a basket "
        "beside the stacked provisions. @S@'I stock what a crew "
        "can carry without holding up the pier.'");
    addTopic("provisions", "@S@'There is fresh food when the boats "
        "bring it in, and stored goods when they do not. Ask before "
        "you plan a long voyage around one basket.'");
    addTopic("loading", "@S@'Keep the fish crates separate from "
        "dry stores. A little care at the quay keeps a whole hold "
        "from smelling like yesterday's catch.'");

    addResponse("first conversation", "What can I buy here?",
        "@D@She points to the goods set out for sale.");
    addResponseTopic("first conversation", "What can I buy here?",
        "provisions");
    addResponse("first conversation", "Do you supply the ships?",
        "@S@'I sell to sailors and travelers. The naval stores "
        "are counted separately by Calven.'");
    addResponse("provisions", "Is the fish always fresh?",
        "@S@'Only when the catch is in. I will tell you what came "
        "off a boat today and what was stored.'");
    addResponseTopic("provisions", "Is the fish always fresh?",
        "loading");
}
