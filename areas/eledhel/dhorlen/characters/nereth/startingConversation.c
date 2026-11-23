//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nereth sets a grain measure "
        "on the bench before turning from the wheel. @S@'Keep clear "
        "of the stones while they are turning.'");
    addTopic("the mill", "@S@'The stream drives the wheel. I grind "
        "oats and rye for the nearby farms, then send the sacks "
        "back by cart.'");
    addTopic("the bridge", "@S@'The old bridge is the sure crossing "
        "when the river rises. In a hard flood, wait for the water "
        "to fall rather than risk a cart on the stones.'");
    addTopic("the road", "@S@'The King's Road leads north toward "
        "Tirwen and Rhaedhen. Southbound drovers use this green "
        "before they cross the river.'");
    addResponse("first conversation", "What does the mill grind?",
        "@S@'Oats and rye from the farms along the road.'");
    addResponseTopic("first conversation", "What does the mill grind?",
        "the mill");
    addResponse("first conversation", "Can I cross the river?",
        "@S@'Use the bridge. Leave the ford to the animals and "
        "wait out a flood.'");
    addResponseTopic("first conversation", "Can I cross the river?",
        "the bridge");
    addResponse("first conversation", "Where does the King's Road go?",
        "@S@'North to the orchard farms, then Rhaedhen and Eledhel.'");
    addResponseTopic("first conversation",
        "Where does the King's Road go?", "the road");
}
