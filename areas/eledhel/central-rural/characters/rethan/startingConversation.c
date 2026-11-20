//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Rethan turns his slate so "
        "you can read the road marks before he answers. @S@'The "
        "west track is passable. The gate is busy, not closed.'");
    addTopic("the Common Measure", "@S@'The miller's flour, the "
        "orchard's fruit, and a traveler's honest coin all have "
        "their place here. I keep one table clear for people "
        "waiting on carts or weather.'");
    addTopic("the road slate", "@D@He taps a line of small wheel "
        "marks. @S@'One mark for a cart seen, two for a cart "
        "delayed, and a cross only when the watch confirms trouble. "
        "It saves the farms from chasing rumors.'");
    addTopic("the farm households", "@S@'Pera sells what is fresh. "
        "Nessa keeps the stores, Torven weighs at the mill, and "
        "Idel minds the pasture. Ask them about their own work; "
        "I will not speak for another household.'");
    addTopic("the wooded road", "@D@Rethan lowers his voice, but "
        "not his eyes. @S@'Idel has seen people take supplies "
        "from the old track. That is a warning to be careful, "
        "not proof against every traveler.'");
    addTopic("the yard", "@S@'Othyl knows every loose shoe and "
        "crooked wheel in that yard. Water the horses at the "
        "trough, and leave the hand-cart where the next carrier "
        "can find it.'");

    addResponse("first conversation", "What is the Common Measure?",
        "@D@You ask about the painted sign outside.");
    addResponseTopic("first conversation", "What is the Common Measure?",
        "the Common Measure");
    addResponse("the Common Measure", "Do you buy grain here?",
        "@S@'No. The mill and the granary keep their own accounts. "
        "This is a place to wait, eat, and learn what the road is doing.'");
    addResponse("first conversation", "What do the marks on your slate mean?",
        "@D@You point to the marks beside the door.");
    addResponseTopic("first conversation",
        "What do the marks on your slate mean?", "the road slate");
    addResponse("the road slate", "Who decides when a road is unsafe?",
        "@S@'The watch confirms danger. A wheel stuck in mud is "
        "not an outlaw, and a late cart is not a missing person.'");
    addResponse("first conversation", "Who can tell me about these farms?",
        "@D@You ask about the names on the delivery marks.");
    addResponseTopic("first conversation",
        "Who can tell me about these farms?", "the farm households");
    addResponse("the farm households", "Where can I buy fresh food?",
        "@S@'Pera has the counter beside the crossing. Nessa's "
        "stores are for sale too, even when the fields are bare.'");
    addResponseTopic("the farm households", "Where can I buy fresh food?",
        "the Common Measure");
    addResponse("first conversation", "Is it safe to take the old track?",
        "@D@You ask about the marks at the bottom of the slate.");
    addResponseTopic("first conversation",
        "Is it safe to take the old track?", "the wooded road");
    addResponse("the wooded road", "Should I go after the people there?",
        "@S@'No. Tell the watch what you saw and where. Do not "
        "turn a warning into a hunt.'");
    addResponse("first conversation", "Who looks after the horses?",
        "@D@You glance toward the yard.");
    addResponseTopic("first conversation",
        "Who looks after the horses?", "the yard");
}
