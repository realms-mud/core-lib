//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Jalen shifts the cloth bundle "
        "away from a passing cart. @S@'A careful stitch should hold.'");
    addTopic("tailoring", "@S@'The tailor mends work clothes as often "
        "as fine coats. A sound seam matters more than a bright color.'");
    addResponse("first conversation", "What is in the bundle?",
        "@D@He checks the parcel tie.");
    addResponseTopic("first conversation", "What is in the bundle?",
        "tailoring");
}
