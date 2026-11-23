//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Vardan steadies the bundle "
        "against his chest. @S@'I promised the archive I would bring "
        "these books back in good order.'");
    addTopic("Werric order", "@S@'The knights keep a place for "
        "study as well as instruction. I come here to return a "
        "volume and ask for another.'");
    addResponse("first conversation", "Do you study with the knights?",
        "@D@He nods toward the temple entrance.");
    addResponseTopic("first conversation", "Do you study with the "
        "knights?", "Werric order");
}
