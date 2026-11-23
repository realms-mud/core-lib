//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@The king turns from the "
        "council table with a tired, welcoming smile. @S@'Come in. "
        "A good question is no interruption.'");
    addTopic("the court", "@S@'A council is useful only when "
        "people can speak plainly. Courtesy should make that easier, "
        "not harder.'");
    addTopic("the royal family", "@S@'My family is dear to me, "
        "though each of my children has found a different way to "
        "keep me occupied.'");
    addResponse("first conversation", "What is a council for?",
        "@D@Ardenel gestures toward the table.");
    addResponseTopic("first conversation", "What is a council for?",
        "the court");
    addResponse("the court", "Do you have time for family?",
        "@D@His expression becomes briefly less formal.");
    addResponseTopic("the court", "Do you have time for family?",
        "the royal family");
}
