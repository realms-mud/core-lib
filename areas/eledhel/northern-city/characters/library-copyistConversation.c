//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Saelis sets down her pen and "
        "watches the fresh ink dry. @S@'The public shelves are open to "
        "readers. I copy the records and mend what time has worn.'");
    addTopic("public shelves", "@S@'The histories and family records "
        "are arranged by subject. Ask the librarian if you need a volume "
        "that is not on the shelves.'");
    addTopic("copying records", "@S@'A copy is only as reliable as its "
        "source. I mark damaged passages rather than guess at words "
        "that have been lost.'");

    addResponse("first conversation", "What can I read here?",
        "@D@You glance toward the shelves behind her.");
    addResponseTopic("first conversation", "What can I read here?",
        "public shelves");
    addResponse("first conversation", "Can you copy a family record?",
        "@S@'I can make a careful copy from a surviving volume. "
        "I will not invent what the page no longer says.'");
    addResponseTopic("first conversation", "Can you copy a family record?",
        "copying records");
    addResponse("public shelves", "What if the record is damaged?",
        "@S@'Then I note the damage and leave the uncertain words "
        "uncertain. A clean false copy is worse than a torn truth.'");
    addResponseTopic("public shelves", "What if the record is damaged?",
        "copying records");
}
