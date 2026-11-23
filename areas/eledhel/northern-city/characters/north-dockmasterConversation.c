//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Iveren pulls a mooring line "
        "tight and checks the knot. @S@'A ship gets a berth when "
        "the harbor can take it safely.'");
    addTopic("berths", "@S@'The inner berths are guarded and assigned. "
        "Visitors should keep to the public pier and leave working "
        "lines alone.'");
    addTopic("mooring", "@S@'A loose line can damage a hull or a hand. "
        "If you see one dragging in the water, tell the nearest crew.'");

    addResponse("first conversation", "Who assigns the berths?",
        "@D@He glances toward the headquarters.");
    addResponseTopic("first conversation", "Who assigns the berths?",
        "berths");
    addResponse("first conversation", "Can I help with a loose line?",
        "@S@'Only if the crew asks. Tell them what you saw and let "
        "the trained hands secure it.'");
    addResponseTopic("first conversation", "Can I help with a loose line?",
        "mooring");
    addResponse("berths", "Where can I wait for a sailor?",
        "@S@'Use the public pier, away from the loading path. "
        "The crew will find you there.'");
}
