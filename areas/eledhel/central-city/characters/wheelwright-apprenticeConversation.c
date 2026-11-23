//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Rovan turns a spoke gauge "
        "between his fingers. @S@'A wheel tells you plenty if you "
        "watch it roll.'");
    addTopic("cart wheels", "@S@'The wheelwright teaches me to listen "
        "for a loose hub. A driver who waits for a break on the road "
        "pays for it twice.'");
    addResponse("first conversation", "What are you learning?",
        "@D@He points toward a cart moving down the street.");
    addResponseTopic("first conversation", "What are you learning?",
        "cart wheels");
}
