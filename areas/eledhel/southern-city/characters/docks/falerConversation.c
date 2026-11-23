//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Faler checks two berth marks on "
        "the slate. @S@'The next boat has room to come alongside.'");
    addTopic("berth records", "@S@'We note each arrival and departure. "
        "The quay crew needs to know which berth is free.'");
    addResponse("first conversation", "How do you track the boats?",
        "@D@He points to the marks beside each berth.");
    addResponseTopic("first conversation", "How do you track the boats?",
        "berth records");
}
