//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Halen rolls a cask clear of the "
        "gangplank. @S@'The next load can come ashore.'");
    addTopic("loading berth", "@S@'We keep the gangplank clear and "
        "move heavy casks first. Small parcels can wait.'");
    addResponse("first conversation", "What is being unloaded?",
        "@D@He points toward a stack of marked crates.");
    addResponseTopic("first conversation", "What is being unloaded?",
        "loading berth");
}
