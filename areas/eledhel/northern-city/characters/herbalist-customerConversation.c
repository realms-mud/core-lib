//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tirren flexes his reddened hands "
        "while he waits. @S@'The lines have rubbed them raw. Morleth "
        "is making a salve before I go back to the quay.'");
    addTopic("salve", "@S@'It is a small thing, but hauling is easier "
        "when the skin has had a chance to mend. I will follow Morleth's "
        "directions and keep the jars aboard ship.'");

    addResponse("first conversation", "Do you work at the harbor?",
        "@S@'I haul lines and crates when a ship needs hands. "
        "The northern quay is busy enough without rushing the knots.'");
    addResponse("first conversation", "What is Morleth preparing?",
        "@D@He turns his hands over carefully.");
    addResponseTopic("first conversation", "What is Morleth preparing?",
        "salve");
    addResponse("salve", "Will it heal every injury?",
        "@S@'No. It is for rubbed skin, not a deep cut or a sickness. "
        "For those, I would ask a healer.'");
}
