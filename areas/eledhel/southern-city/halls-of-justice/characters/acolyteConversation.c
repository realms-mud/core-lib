//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Ilyen finishes setting bowls "
        "at the long table, then greets you with a small bow.");
    addTopic("acolytes", "@S@'We keep the hall ready and learn the "
        "law through study and service. No petitioner's station "
        "changes the courtesy they are owed.'");
    addTopic("the dining hall", "@S@'Judges and visitors eat here "
        "when the day's hearings allow. The table is long, but no "
        "one is expected to sit alone.'");

    addResponse("first conversation", "What do the acolytes do?",
        "@S@'We serve the hall, its records, and those who come "
        "seeking a hearing.'");
    addResponseTopic("first conversation", "What do the acolytes do?",
        "acolytes");
    addResponse("first conversation", "Who eats at this table?",
        "@S@'Anyone whose business brings them here, when the "
        "judges have time to share a meal.'");
    addResponseTopic("first conversation",
        "Who eats at this table?", "the dining hall");
}
