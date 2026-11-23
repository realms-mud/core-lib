//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Selen finishes an entry in "
        "the ship log. @S@'Every arrival and departure matters. "
        "A name written clearly can save a search later.'");
    addTopic("ship log", "@S@'The log records when a vessel takes "
        "a berth and who reports it. It is not a forecast and "
        "cannot promise what the sea will do.'");
    addTopic("watch duty", "@S@'We compare the pier with the record "
        "and pass unusual changes to Narev. We do not invent a danger "
        "because a ship is late.'");

    addResponse("first conversation", "What do you write in the log?",
        "@D@You indicate the open page.");
    addResponseTopic("first conversation", "What do you write in the log?",
        "ship log");
    addResponse("first conversation", "Is a ship overdue?",
        "@S@'I can tell you what has berthed. The log cannot say "
        "why another vessel has not arrived.'");
    addResponse("ship log", "Who checks the entries?",
        "@S@'The harbor watch compares them with the berths. "
        "I report a mismatch to Narev.'");
    addResponseTopic("ship log", "Who checks the entries?", "watch duty");
}
