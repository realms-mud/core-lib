//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The knight watches the road "
        "before turning to you. @S@'I am on patrol for the Werric "
        "Knighthood. If you need directions, ask; if you have news "
        "from the road, I will hear it.'");
    addTopic("the patrol", "@S@'We keep to the roads and marked "
        "tracks. A patrol can discourage trouble, but it cannot "
        "watch every path at once.'");
    addTopic("the Werric", "@S@'The Werric serve as knights and "
        "guardians. We answer to our order and take our duties "
        "seriously, whether we are riding in a company or alone.'");
    addTopic("patrol limits", "@S@'One rider cannot watch every "
        "track. We follow the roads where people are most likely "
        "to need us, and we rely on travelers to report what they see.'");
    addTopic("road reports", "@S@'Tell the constable where you "
        "found the sign and when. If it is urgent, find the nearest "
        "patrol and do not follow the trail yourself.'");

    addResponse("first conversation", "Is the road safe?",
        "@S@'The road to town is clear at present. Beyond it, travel "
        "with care and do not leave the marked track.'");
    addResponseTopic("first conversation", "Is the road safe?",
        "the patrol");
    addResponse("first conversation", "What is the Werric?",
        "@S@'An order of knights with responsibilities across "
        "Eledhel. Our service is not limited to one town.'");
    addResponseTopic("first conversation", "What is the Werric?",
        "the Werric");
    addResponse("the patrol", "Have you seen anything unusual?",
        "@S@'Nothing I can confirm. If you have seen something "
        "yourself, tell the constable in town so the report is "
        "recorded.'");
    addResponse("the Werric", "Can I join the order?",
        "@S@'Speak with a Werric officer in person. Service asks "
        "for more than skill with a weapon; it asks for discipline "
        "and judgment.'");
    addResponse("the patrol", "Why are there no knights on every road?",
        "@S@'We have a limited number of riders. We patrol the "
        "routes that carry the most people and return where help "
        "is most likely needed.'");
    addResponseTopic("the patrol",
        "Why are there no knights on every road?", "patrol limits");
    addResponse("patrol limits", "What should I do if I find tracks?",
        "@S@'Keep your distance, remember the place, and report "
        "what you saw. Do not risk yourself trying to identify them.'");
    addResponseTopic("patrol limits",
        "What should I do if I find tracks?", "road reports");
    addResponse("road reports", "Should I tell the town watch too?",
        "@S@'Yes. The constable can record the report and warn "
        "the townsfolk while we check the road.'");
    addResponseTopic("road reports",
        "Should I tell the town watch too?", "the patrol");
    addResponseTopic("the Werric", "Can I join the order?",
        "patrol limits");
}
