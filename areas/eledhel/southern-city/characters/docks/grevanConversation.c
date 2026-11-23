//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Grevan checks a cargo mark "
        "against his slate. @S@'This crate belongs on the next cart.'");
    addTopic("cargo tally", "@S@'Every load is counted at the quay. "
        "Damaged goods are marked before they leave the dock.'");
    addResponse("first conversation", "How do you track the cargo?",
        "@D@He turns the slate so you can see the marks.");
    addResponseTopic("first conversation", "How do you track the cargo?",
        "cargo tally");
}
