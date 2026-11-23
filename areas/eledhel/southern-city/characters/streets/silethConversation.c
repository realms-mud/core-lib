//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Sileth shields the oil flask "
        "from the crowd. @S@'The lamps in the temple must stay lit.'");
    addTopic("temple lamps", "@S@'We replace the wicks after the last "
        "service and store the oil away from the brazier.'");
    addResponse("first conversation", "What is the oil for?",
        "@D@She checks the stopper.");
    addResponseTopic("first conversation", "What is the oil for?",
        "temple lamps");
}
