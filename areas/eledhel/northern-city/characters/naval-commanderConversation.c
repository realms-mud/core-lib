//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Narev checks the notes before "
        "looking up. @S@'The harbor watch keeps the guarded berths in "
        "order. Tell me which quay you need.'");
    addTopic("harbor watch", "@S@'We watch the approaches, record "
        "arrivals, and keep service routes clear. Cargo questions go "
        "to the quartermaster or dockmaster.'");
    addTopic("public quay", "@S@'Use the public pier for ordinary "
        "business. The guarded service quay is for assigned crews "
        "and authorized cargo.'");

    addResponse("first conversation", "What does the harbor watch do?",
        "@D@He taps the patrol notes.");
    addResponseTopic("first conversation",
        "What does the harbor watch do?", "harbor watch");
    addResponse("first conversation", "Can I go aboard a ship?",
        "@S@'Ask its crew. A berth is not permission to board, "
        "and the watch will not make that choice for a captain.'");
    addResponse("harbor watch", "Where should a visitor go?",
        "@S@'The public pier. Keep clear of the service quay unless "
        "a crew member has asked you to help.'");
    addResponseTopic("harbor watch", "Where should a visitor go?",
        "public quay");
}
