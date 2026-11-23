//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Marden checks a basket of "
        "apples before turning to you.");
    addTopic("market stores", "@S@'The market serves households and "
        "travelers. I keep produce separate from the dry stores, "
        "and mark every measure before it is sold.'");
    addTopic("fresh produce", "@S@'Buy what you can use while it is "
        "fresh. For a longer journey, take roots and dried food, "
        "and keep them away from damp.'");

    addResponse("first conversation", "What can I buy here?",
        "@S@'Fruit, roots, greens, and a few provisions that travel "
        "well. Tell me how long you expect to be on the road.'");
    addResponseTopic("first conversation", "What can I buy here?",
        "market stores");
    addResponse("market stores", "What keeps best on the road?",
        "@S@'Roots keep longer than greens. Wrap them dry and "
        "check your stores before you leave town.'");
    addResponseTopic("market stores", "What keeps best on the road?",
        "fresh produce");
}
