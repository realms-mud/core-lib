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
private void WeWasteTime()
{
    addTopic("we waste time on this bastard", "\n@D@Donald tears his sword "
        "from the black-robed figure's leg and shoves the blade through "
        "his throat. Donald gives the now severed head of the man a swift "
        "kick into the bushes, separating it from it's body by many feet "
        "@S@`We waste time! Did anything he said mean anything to you? "
        "Does it shine any light on why they attacked our camp?");

    addTopicEvent("we waste time on this bastard", "killPoorBrendan");

    addTopicInterjection("we waste time on this bastard",
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "did it mean anything to me?", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void WakeUp()
{
    addTopic("you hit me", "\n@D@Donald looks very groggy as he tries to "
        "sit up. He loudly states, @S@`Just so we're clear: we're not taking any "
        "more of these forked-tongued bastards alive. I don't care if they "
        "once were Phaedra or not, they obviously mean us harm and are the "
        "ones who attacked our camp.'");
    addResponse("you hit me", "What next?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`What now, "
        "sir?'");
    addResponse("you hit me", "But it was valuable...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`I disagree, "
        "sir. What he said was important. What he might have said, maybe "
        "moreso. You ended that possibility.'");

    addTopic("donald regains consciousness", "\n@D@Donald looks very groggy "
        "as he tries to sit up. Halgaladh offers his support, but Donald "
        "brushes it aside. @S@`Just so we're clear: we're not taking any "
        "more of these forked-tongued bastards alive. I don't care if they "
        "once were Phaedra or not, they obviously mean us harm and are the "
        "ones who attacked our camp.'"); 
    addResponse("donald regains consciousness", "What next?", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`What now, "
        "sir?'");
    addResponse("donald regains consciousness", "But it was valuable...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`I disagree, "
        "sir. What he said was important. What he might have said, maybe "
        "moreso. You ended that possibility.'");

    addTopic("donald regains consciousness part two", "@D@Donald ignores "
        "##InitiatorName## and instead turns to Galadhel and angrily "
        "growls, @S@`If you have personal issues with that, remember that "
        "you swore an oath. Our duty is to defend the empire, not indulge "
        "in personal pursuits! @D@He unexpectedly turns jovial and, after "
        "letting out a laugh, adds, @S@`Now let's show the enemy what a "
        "real warrior can do!'");
    addResponseTopic("donald regains consciousness", "What next?", 
        "donald regains consciousness part two");
    addResponseTopic("donald regains consciousness", "But it was valuable...",
        "donald regains consciousness part two");
    addResponseTopic("you hit me", "What next?",
        "donald regains consciousness part two");
    addResponseTopic("you hit me", "But it was valuable...",
        "donald regains consciousness part two");

    addTopicInterjection("donald regains consciousness part two",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "think before you leap", 1);
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
    WeWasteTime();
    WakeUp();
}
