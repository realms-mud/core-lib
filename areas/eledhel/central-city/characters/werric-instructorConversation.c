//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Sir Caldrin closes one of the "
        "blank books on the long table. @S@'The Temple of the "
        "Triumvirate serves as the Werric Knights' outpost here.'");
    addTopic("enrollment", "@S@'Those prepared to take the oath "
        "may use 'enroll with Caldrin'. The Werric path cannot be "
        "combined with every other guild.'");
    addTopic("lessons", "@S@'Use 'lessons from Caldrin' to see "
        "the available instruction. Requirements are part of "
        "the lesson, not obstacles to be ignored.'");
    addTopic("the books", "@S@'We keep these pages ready for "
        "instruction and record. The Werric tradition is carried "
        "by practice as well as by written counsel.'");

    addResponse("first conversation", "Is this a temple?",
        "@S@'It is the Werric Knights' outpost in Eledhel, with "
        "a great hall and rooms for their records and instruction.'");
    addResponseTopic("first conversation", "Is this a temple?",
        "the books");
    addResponse("first conversation", "How can I join the Werric Knights?",
        "@D@He gestures toward the table.");
    addResponseTopic("first conversation",
        "How can I join the Werric Knights?", "enrollment");
    addResponse("first conversation", "Can you teach me?",
        "@S@'I can show you the available instruction and its "
        "requirements.'");
    addResponseTopic("first conversation", "Can you teach me?", "lessons");
}
