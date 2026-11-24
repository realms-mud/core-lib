//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("camp investigation", "@D@Halgaladh studies the empty "
        "ground where the robed figure fell. @S@'The bodies stopped "
        "moving when one of their handlers fell. That is a weakness "
        "we must understand before we meet them again.'");
    addTopicInterjection("camp investigation",
        "/areas/argalen-keep/characters/galadhel/galadhel.c",
        "camp aftermath", 1);
    addTopic("our dead", "@D@He lowers his gaze. @S@'These were "
        "our comrades. We should search for their personal effects "
        "and give Berenar what we find.'");
    addTopic("the hunt", "@S@'The enemy has withdrawn, not vanished. "
        "If we pursue, we do so as a unit and leave someone to "
        "carry word of what happened.'");

    addResponse("camp investigation", "What did you learn?",
        "@S@'The dead fell when the robed ones were struck. That "
        "suggests their control depends on the living.'");
    addResponseTopic("camp investigation",
        "What did you learn?", "the hunt");
    addResponse("camp investigation", "Can we save our comrades?",
        "@S@'Not those who have already fallen. We can still "
        "ensure they are treated with respect.'");
    addResponseTopic("camp investigation",
        "Can we save our comrades?", "our dead");

    addResponse("our dead", "Should we delay the pursuit?",
        "@S@'We should not delay longer than we must. Berenar "
        "can tend the fallen while the rest of us follow the trail.'");
    addResponseTopic("our dead", "Should we delay the pursuit?",
        "the hunt");
    addResponse("the hunt", "Who should report to Aredec?",
        "@S@'Berenar. He knows what happened here and can give "
        "the lord a clear account.'");
}
