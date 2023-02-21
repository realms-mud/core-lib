//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void QuestionThisOne()
{
    addTopic("shall we question this one?", 
        "@D@Halgaladh stands over the black-robed figures "
        "body, sword extended down toward its throat. @S@`Please, tell me "
        "that I don't have to soil my sword's blade again.' @D@He looks over "
        "to ##InitiatorName## and says, @S@`Here is another one to question!'");

    addTopicInterjection("shall we question this one?",
        "/tutorial/characters/donald/donald.c",
        "stay your sword, boy", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void WakeDonaldUp()
{
    addTopic("wake up sir", "@D@Halgaladh stares at Donald's inert form, torn "
        "between anger and the need to move on before the enemy renews their "
        "attack. He walks over to Donald and shakes him. @S@`Sir?'");
    addTopicInterjection("wake up sir",
        "/tutorial/characters/donald/donald.c",
        "donald regains consciousness", 1);

    addTopic("think before you leap", "@D@Halgaladh grabs hold of Donald's "
        "shoulder, firmly restraining him from getting up. @S@`Sir! You're a "
        "bit muddled and not thinking straight. We need a plan first!' @D@He "
        "turns to Galadhel and states, @S@`Based on what I heard just now, "
        "you have every right to be angry, but keep your anger focused on "
        "our foes! You and Donald can discuss this later.'");
    addTopicInterjection("think before you leap",
        "/tutorial/characters/alberich/alberich.c",
        "good. a blissful interlude", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void WalkingCorpsesStink()
{
    addTopic("stinks too", "@S@`He's been dead quite "
        "some time by the smell of him.' @D@notes "
        "Halgaladh as he investigates the corpse.");

    addResponse("stinks too", "@I@Examine corpse@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::examine## the corpse closely and "
        "##ResponseInfinitive::say##, @S@`Yet I would bet Halgaladh's meal "
        "tonight that this was the killer. All of the signs point to it - "
        "the bow and arrows, the trail we've followed...'");
    addResponseEffect("stinks too", "@I@Examine corpse@E@",
        (["experience":(["guild":"background", "amount" : 25])]));

    addResponse("stinks too", "It does stink...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::wrinkle## ##InitiatorPossessive## nose and "
        "##ResponseInfinitive::say##, @S@`Yet I would bet Halgaladh's meal "
        "tonight that this was the killer. All of the signs point to it - "
        "the bow and arrows, the trail we've followed...");

    addTopic("stinks part two", "");
    addResponseTopic("stinks too", "@I@Examine corpse@E@", "stinks part two");
    addResponseTopic("stinks too", "It does stink...", "stinks part two");
    addTopicInterjection("stinks part two",
        "/tutorial/characters/galadhel/galadhel.c",
        "What are we missing", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void GrantHisRelease()
{
    addTopic("grant him his release", "@S@`Nay, sir. @D@responds Halgaladh "
        "resolutely. @S@`I have no wish to counter your command nor to be "
        "contrary, but I will not violate the tenets of our order on your "
        "whim. To kill in battle is honorable; to kill a prisoner in our "
        "control... you must conduct your own murder. Our task should be to "
        "investigate the temple and bring this one back to our commanders. "
        "You know this.'");

    addTopicInterjection("grant him his release",
        "/tutorial/characters/donald/donald.c",
        "grant him his release part 2", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("aye but how", "@S@`Aye, but how?' @D@asks "
        "Halgaladh as he steps up next to Galadhel.");
    addTopicInterjection("aye but how",
        "/tutorial/characters/galadhel/galadhel.c",
        "I do not know", 1);

    addTopic("no more mushroom farmers", "@D@As Halgaladh sees Galadhel train "
        "her bow on her target, he snickers and adds, @S@`Galadhel, what "
        "you're 'aiming' to do doesn't look like a bad plan of action. At "
        "least we won't have to worry about him siring more mushroom "
        "farmers.");

    WalkingCorpsesStink();
    WakeDonaldUp();
    QuestionThisOne();
    GrantHisRelease();
}
