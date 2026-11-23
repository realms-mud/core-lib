//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Ossen checks a cloth bundle for "
        "loose dye. @S@'This lot is ready for delivery.'");
    addTopic("dye lots", "@S@'Each vat is recorded by color and batch. "
        "That way a later order can match the first.'");
    addResponse("first conversation", "How do you keep the color even?",
        "@D@He folds the cloth to show its edge.");
    addResponseTopic("first conversation", "How do you keep the color even?",
        "dye lots");
}
