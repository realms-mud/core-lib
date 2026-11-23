//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Kaelin lowers one pail to rest "
        "his shoulder. @S@'The houses will need fresh water soon.'");
    addTopic("water delivery", "@S@'I keep the lids closed in the "
        "street. The well is busy when the market crowd comes through.'");
    addResponse("first conversation", "Where are you taking the water?",
        "@D@He lifts the pail back into place.");
    addResponseTopic("first conversation", "Where are you taking the water?",
        "water delivery");
}
