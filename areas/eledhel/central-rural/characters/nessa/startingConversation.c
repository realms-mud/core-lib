//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nessa finishes counting a "
        "delivery before resting her pencil beside the ledger. "
        "@S@'Produce for the road is at the counter. The marked "
        "gleaning beds are outside; the sacks here are accounted for.'");
    addTopic("winter stores", "@S@'Roots in cool storage, fruit "
        "checked for bruises, and grain kept dry. Pera and I "
        "trade what keeps as well as what has just been picked. "
        "A field does not give the same supper in every season.'");
    addTopic("common ground", "@D@She turns a notice toward you. "
        "@S@'East from the yard are public roots, south of them "
        "the bean rows. The gleaning strips are south of the yard. "
        "Take what those marked beds allow, not a whole farm's crop.'");
    addTopic("the households", "@S@'Idel minds the shared barn "
        "north of the yard. Torven's mill is across the stream "
        "to the southeast. Pera's counter is back by the road. "
        "You can reach them all without entering the deep coppice.'");
    addResponse("first conversation", "What can I buy?",
        "@S@'Use the shop counter for the current stock and prices. "
        "I do not ask you to harvest before you may buy a meal.'");
    addResponse("first conversation", "How do you keep food through winter?",
        "@S@'By inspecting it while it is still worth keeping.'");
    addResponseTopic("first conversation",
        "How do you keep food through winter?", "winter stores");
    addResponse("winter stores", "May I take food from the sacks?",
        "@D@Her palm settles on the ledger. @S@'They belong "
        "to households or the counter. Buy provisions, or gather "
        "from the public beds when the crop is ready.'");
    addResponse("first conversation", "Where are the public beds?",
        "@S@'I will show you the notice, not send you guessing.'");
    addResponseTopic("first conversation", "Where are the public beds?",
        "common ground");
    addResponse("common ground", "Are the berries public too?",
        "@S@'The common hedge is at the orchard edge. The "
        "raspberry canes are beside the spring farther north. "
        "They fruit in season; leave the managed timber alone.'");
    addResponse("first conversation", "Who should I speak to about the farms?",
        "@S@'It depends whether you need a measure, a meal, or "
        "someone who knows the pasture.'");
    addResponseTopic("first conversation",
        "Who should I speak to about the farms?", "the households");
    addResponse("the households", "Does this granary belong to a noble house?",
        "@S@'The neighboring households maintain these shared "
        "stores. Each delivery is entered against its owner's name.'");
}
