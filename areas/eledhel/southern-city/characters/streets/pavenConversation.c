//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Paven dusts grit from his tool "
        "roll. @S@'The repair should hold through the next rain.'");
    addTopic("masonry", "@S@'Loose stone is patched before carts run "
        "over it. A small repair is better than a broken wheel.'");
    addResponse("first conversation", "What were you repairing?",
        "@D@He gestures toward the paving.");
    addResponseTopic("first conversation", "What were you repairing?",
        "masonry");
}
