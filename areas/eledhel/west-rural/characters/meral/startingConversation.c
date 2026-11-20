//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Meral sets down her chalk "
        "before she answers. @S@'Boughcross is the name folk use "
        "for this bend in the lane. The rows have their keepers; "
        "the road belongs to everyone.'");
    addTopic("the orchard rows", "@S@'The cultivated fruit is "
        "counted by household. Ask me before you gather it. The "
        "marked baskets are weighed for sale, and the trees are "
        "not firewood for passing carts.'");
    addTopic("the missing hives", "@D@She points toward the apiary. "
        "@S@'Three stands went quiet. Vessa found a broken skep "
        "and wax dragged toward the ravine. No one saw a cart.'");
    addTopic("the lane", "@S@'North goes past the bee yard. South "
        "reaches the cooper's shed. The ravine brook is west; "
        "keep to the path when the water is high.'");

    addResponse("first conversation", "May I take fruit from the trees?",
        "@D@You ask about the rows beyond the board.");
    addResponseTopic("first conversation",
        "May I take fruit from the trees?", "the orchard rows");
    addResponse("the orchard rows", "Can I cut a branch for a walking stick?",
        "@S@'No. The trees are tended, and the wood is accounted for. "
        "Ask Derrik about offcuts he has already been paid to sell.'");
    addResponse("first conversation", "What happened to the hives?",
        "@D@You ask about the empty stands.");
    addResponseTopic("first conversation",
        "What happened to the hives?", "the missing hives");
    addResponse("the missing hives", "Was someone stealing them?",
        "@S@'There are no wheel ruts or cut bindings. Look at the "
        "splintered skep before you accuse anyone.'");
    addResponse("first conversation", "Where does this lane go?",
        "@D@You follow the path with your eyes.");
    addResponseTopic("first conversation", "Where does this lane go?",
        "the lane");
}
