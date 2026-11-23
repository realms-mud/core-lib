//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Hareth checks a saddle strap "
        "and tests its buckle. @S@'A horse should leave the yard "
        "sound, watered, and properly fitted.'");
    addTopic("horses", "@S@'The palace horses have different tempers "
        "and different work. Do not take one without the rider's "
        "or household's permission.'");
    addTopic("tack", "@S@'A worn strap can fail at the worst moment. "
        "Check the stitching, buckle, and fit before a long ride.'");

    addResponse("first conversation", "Can I borrow a horse?",
        "@S@'Not without permission. The household keeps these "
        "mounts for its own riders and errands.'");
    addResponse("first conversation", "What do you check before a ride?",
        "@D@He gives the strap one last careful pull.");
    addResponseTopic("first conversation",
        "What do you check before a ride?", "tack");
    addResponse("tack", "How do I choose a mount?",
        "@S@'Ask the rider who knows the horse. A steady mount "
        "is worth more than a fine coat.'");
}
