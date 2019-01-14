//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void Haldor()
{
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
}

/////////////////////////////////////////////////////////////////////////////
private void LetsGetTheseBastards()
{
    addTopic("how can he be dead", "\n@D@Donald looks at the corpse lying in "
        "his path, @S@`What the hell is going on? How can...' @D@he places "
        "emphasis on his next word, @S@`HE be dead?'");
    addTopicInterjection("how can he be dead",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "stinks too", 1);

    addTopic("the enemy is upon us", "\n@D@Donald jumps up as he hears "
        "rustling branches to the west, @S@`Damn it! This mystery can wait. "
        "The enemy is upon us!'");

    addTopic("let's get these bastards", "@D@Donald snarls, @S@`Enough of "
        "this! Let's get these bastards!' @D@Donald rushes off to the west.");
    addTopicInterjection("let's get these bastards",
        "/lib/tutorial/characters/alberich/alberich.c",
        "donald is enthusiatic", 1);

    addTopic("take him out", "@D@Donald nods and perhaps a bit too "
        "loudly says, @S@`Aye, take 'im down but leave him able to talk. The "
        "rest of you, with me.' @D@Donald prepares to attack.");
    addTopicInterjection("take him out",
        "/lib/tutorial/characters/alberich/alberich.c",
        "wait you ninny", 1);

    addTopic("ignore and attack", "@D@Donald seems to not notice "
        "Alberich. At the top of his lungs, he bellows, @S@`Charge!' @D@He "
        "lunges out of the cover and rushes the enemy.");
    addTopicInterjection("ignore and attack",
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "I guess I'll just kill this guy", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void BrendanOeldhen()
{
    addTopic("not communicative", "\n@D@Donald lumbers over and glowers at "
        "the man. @S@`He's obviously not feeling communicative enough. "
        "Perhaps he doubts our resolve?' @D@Donald pulls out his sword and "
        "thrusts it into the meaty part of the man's thigh. With a twist of "
        "his blade, he snarls, @S@`Are your memories becoming clearer now?'");

    addTopicInterjection("not communicative",
        "/lib/tutorial/characters/brendan/brendan.c",
        "besotted fool", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("you heard the man", "\n@D@Donald nods and looks at Halgaladh, "
        "@S@`Well you heard the man! Get yer arse moving!' @D@He nods "
        "at ##InitiatorName## and adds, @S@`Move out! Alberich, you're on "
        "point.'");

    Haldor();
    LetsGetTheseBastards();
    BrendanOeldhen();
}
