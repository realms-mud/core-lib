//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("you heard the man", "\n@D@Donald nods and looks at Halgaladh, "
        "@S@`Well you heard the man! Get yer arse moving!' @D@He nods "
        "at ##InitiatorName## and adds, @S@`Move out! Alberich, you're on "
        "point.'");

    addTopic("Does it matter", "@D@Donald grumbles, @S@`Does it matter? He's "
        "dead just the same.'");
    addResponse("Does it matter", "It matters", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@`It matters. What are we dealing "
        "with?'");
    addResponse("Does it matter", "I guess not", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@`I suppose you're right. What are "
        "we dealing with?'");

    addTopic("what are we dealing with", "@D@Donald looks at Haldor's corpse "
        "and grimly states, @S@`A dead Aegis.'");
    addResponseTopic("Does it matter", "It matters", "what are we dealing with");
    addResponseTopic("Does it matter", "I guess not", "what are we dealing with");

    addTopicInterjection("what are we dealing with",
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "look over there", 1);

    addTopic("how can he be dead", "\n@D@Donald looks at the corpse lying in "
        "his path, @S@`What the hell is going on? How can...' @D@he places "
        "emphasis on his next word, @S@`HE be dead?'");
    addTopicInterjection("how can he be dead",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "stinks too", 1);
}
