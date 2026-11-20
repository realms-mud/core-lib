//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the Aegis unit", "@D@Halgaladh studies the faces "
        "around him before answering. @S@'A squad is not made strong "
        "by having one person carry every burden. We each take the "
        "lead when our skill is needed, and we all answer for the "
        "choices we make together.'");
    addTopic("the oath in practice", "@S@'The oath asks us to "
        "protect the realm and those who serve it. It does not ask "
        "us to hide a mistake or let pride put another life at risk.'");
    addTopic("learning from failure", "@D@He lowers his voice. "
        "@S@'We must correct mistakes without turning a comrade "
        "into a scapegoat. Shame alone teaches nothing.'");

    addResponse("the Aegis unit", "Does the leader decide everything?",
        "@S@'No. The leader coordinates, but the person best suited "
        "to a task must speak up and take responsibility for it.'");
    addResponseTopic("the Aegis unit",
        "Does the leader decide everything?", "the oath in practice");
    addResponse("the Aegis unit", "What if the squad fails?",
        "@S@'We examine what went wrong together and make sure "
        "the same failure does not cost another life.'");
    addResponseTopic("the Aegis unit", "What if the squad fails?",
        "learning from failure");

    addResponse("the oath in practice", "Can an order be wrong?",
        "@S@'Yes. An Aegis must use judgment and speak when an "
        "order would betray the purpose of the oath.'");
    addResponseTopic("the oath in practice", "Can an order be wrong?",
        "the Aegis unit");
    addResponse("the oath in practice", "Should we report every mistake?",
        "@S@'We report the truth. We correct a comrade privately "
        "when that is enough, but never conceal danger from the "
        "people responsible for the mission.'");
    addResponseTopic("the oath in practice",
        "Should we report every mistake?", "learning from failure");

    addResponse("learning from failure", "How do we begin?",
        "@S@'Listen to the person who made the choice. Learn what "
        "they knew, what they missed, and what the rest of us can "
        "do differently.'");
    addResponse("learning from failure", "What if it happens again?",
        "@S@'Then we address it again, more firmly if need be. "
        "Protecting one another does not mean ignoring a pattern.'");
    addResponseTopic("learning from failure", "What if it happens again?",
        "the oath in practice");
}
