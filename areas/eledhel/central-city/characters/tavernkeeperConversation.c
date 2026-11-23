//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Dalen sets a bowl on the "
        "counter and nods toward a clear table. @S@'Sit down before "
        "the stew gets cold.'");
    addTopic("the tavern", "@S@'This room is for the people who "
        "work nearby. We keep the food simple and the door open "
        "when the street is safe.'");
    addTopic("gate street", "@S@'The carts start early on Gate "
        "Street. If you want quiet, come after the market wagons "
        "have gone through.'");

    addResponse("first conversation", "Who comes here?",
        "@D@He points to the benches along the wall.");
    addResponseTopic("first conversation", "Who comes here?",
        "the tavern");
    addResponse("first conversation", "Is the street busy?",
        "@D@Dalen listens to the wheels passing outside.");
    addResponseTopic("first conversation", "Is the street busy?",
        "gate street");
}
