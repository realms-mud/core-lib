//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Mellen holds the padded crate "
        "level. @S@'Nothing in here should rattle.'");
    addTopic("glass handling", "@S@'Glass travels in straw and cloth. "
        "The maker packs it, then the buyer checks it before carrying it.'");
    addResponse("first conversation", "Is the crate fragile?",
        "@D@She tests the padding at one corner.");
    addResponseTopic("first conversation", "Is the crate fragile?",
        "glass handling");
}
