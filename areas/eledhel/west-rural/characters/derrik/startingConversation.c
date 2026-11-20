//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Derrik wipes a curl of "
        "wood from his palm. @S@'I mend tubs, make casks, and "
        "keep each household's staves separate. A cooper who "
        "cannot name his timber soon has no customers.'");
    addTopic("the cooperage", "@S@'The east stack is alder for "
        "small casks; the covered boards are oak, already promised. "
        "I sell finished work and paid-for offcuts, not unmarked "
        "wood from the lane.'");
    addTopic("the missing hives", "@D@He sets a hoop down. "
        "@S@'No cart came through with a load of skeps. The ruts "
        "here are narrow and regular. Vessa's trail is broad, "
        "broken, and runs toward the creek.'");
    addTopic("the household marks", "@S@'A blue slash is Vessa's. "
        "Meral uses a three-leaf mark. If a board has neither, "
        "it is not mine to sell.'");

    addResponse("first conversation", "What do you make here?",
        "@D@You look over the hoops and staves.");
    addResponseTopic("first conversation", "What do you make here?",
        "the cooperage");
    addResponse("the cooperage", "May I take a piece of scrap wood?",
        "@S@'Ask first. The offcuts are measured and sold; even "
        "a short stave has a use.'");
    addResponse("first conversation", "Did you see anyone move the hives?",
        "@D@You ask about the ruts along the lane.");
    addResponseTopic("first conversation",
        "Did you see anyone move the hives?", "the missing hives");
    addResponse("first conversation", "How do you mark your stock?",
        "@D@You point to the household marks.");
    addResponseTopic("first conversation", "How do you mark your stock?",
        "the household marks");
}
