//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Carn draws his cart to the side "
        "for pedestrians. @S@'There is room to pass now.'");
    addTopic("cart traffic", "@S@'Drivers keep to the marked lane near "
        "the shops. A stopped cart can hold up the whole street.'");
    addResponse("first conversation", "Is cart traffic heavy?",
        "@D@He glances toward the crossing.");
    addResponseTopic("first conversation", "Is cart traffic heavy?",
        "cart traffic");
}
