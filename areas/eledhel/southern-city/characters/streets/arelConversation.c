//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Arel secures a bundle of parcels "
        "against her side. @S@'Everything is wrapped for the walk.'");
    addTopic("market purchases", "@S@'I compare the marked measures "
        "before paying. It is easier to settle a mistake at the stall.'");
    addResponse("first conversation", "What did you buy?",
        "@D@She checks the parcel knots.");
    addResponseTopic("first conversation", "What did you buy?",
        "market purchases");
}
