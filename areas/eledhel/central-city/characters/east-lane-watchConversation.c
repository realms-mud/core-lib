//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Siven moves a handcart "
        "away from a doorway. @S@'The lane is wide enough if "
        "the work stays inside the yards.'");
    addTopic("street watch", "@S@'I help keep the crossings "
        "open and ask people to lower their voices before the "
        "whole block hears an argument.'");
    addResponse("first conversation", "Is there much trouble?",
        "@D@He watches the cart continue down the street.");
    addResponseTopic("first conversation", "Is there much trouble?",
        "street watch");
}
