//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Lorian turns a metal plate so "
        "the light catches its marks. @S@'The lines are clean.'");
    addTopic("engraving", "@S@'A steady hand matters more than speed. "
        "The plate is checked before it leaves the workshop.'");
    addResponse("first conversation", "What are you engraving?",
        "@D@He wraps the finished plate.");
    addResponseTopic("first conversation", "What are you engraving?",
        "engraving");
}
