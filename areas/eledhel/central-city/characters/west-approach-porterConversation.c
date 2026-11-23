//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Deren shifts a sack from one "
        "shoulder to the other. @S@'The road is behind you now. Keep "
        "to the paving and the cart will find its way.'");
    addTopic("western road", "@S@'Most loads come in by cart. The "
        "drivers stop here to settle straps before the street narrows.'");
    addResponse("first conversation", "What do you do here?",
        "@D@He sets the sack down beside the road.");
    addResponseTopic("first conversation", "What do you do here?",
        "western road");
}
