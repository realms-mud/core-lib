//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Telya closes the sample case "
        "against her coat. @S@'The clasp is sound.'");
    addTopic("jewelry work", "@S@'The jeweler records each stone and "
        "metal before setting it. Small pieces are easy to misplace.'");
    addResponse("first conversation", "What is in the case?",
        "@D@She checks the clasp again.");
    addResponseTopic("first conversation", "What is in the case?",
        "jewelry work");
}
