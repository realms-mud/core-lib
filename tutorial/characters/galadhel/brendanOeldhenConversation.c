//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void FindingHaldor()
{
    addTopic("haldor is dead", "@D@Galadhel crouches down beside the corpse. @S@`"
        "Haldor has fallen.' @D@She intently examines an arrow that is "
        "protruding from Haldor's temple.");
    addTopicInterjection("haldor is dead",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "aye but how", 1);

    addTopic("I do not know", "@D@Galadhel grimaces, @S@`Good question. Given "
        "the signs here, that arrow was fired from the west.'");
    addTopicInterjection("I do not know",
        "/lib/tutorial/characters/donald/donald.c",
        "Does it matter", 1);

    addTopic("look over there", "@D@Galadhel points to the west and hisses, "
        "@S@`Look! Over there.'");
    addTopicEvent("look over there", "moveCharactersToOnTheTrailPartOne");

    addTopic("What are we missing", "@D@Galadhel frowns as she looks at the "
        "corpse, @S@`What are we missing?'");
    addTopicEvent("What are we missing", "moveCharactersToOnTheTrailPartFour");

    addTopic("the corpse is human", "@D@Galadhel goes over to the fallen robed "
        "figure and investigates. She looks at Donald and says, @S@`Sir, the "
        "corpse is human. Male. Seems to have a taste for sinister-looking "
        "accessories.'");
    addTopicInterjection("the corpse is human",
        "/lib/tutorial/characters/donald/donald.c",
        "let's get these bastards", 1);

    addTopic("whisper about dead to Donald", "@D@Galadhel crouches beside "
        "Donald and whispers, @S@`Do we still want any alive? Certainly "
        "the dead are worthless. There are the robed ones, however.'");
    addTopicInterjection("whisper about dead to Donald",
        "/lib/tutorial/characters/donald/donald.c",
        "take him out", 1);

    addTopic("I guess I'll just kill this guy", "@D@Galadhel sighs in "
        "frustration, clearly annoyed that Donald chose to give their position "
        "away. She knocks an arrow and looses it, embedding it into the "
        "throat of one of the black-robed figures. As it falls to its death, "
        "one of the walking corpses falls to the ground as though it were "
        "a marionette whoses strings had been cut.");
    addTopicInterjection("I guess I'll just kill this guy",
        "/lib/tutorial/characters/alberich/alberich.c",
        "daft bastard", 1);
}

/////////////////////////////////////////////////////////////////////////////
private void YouKnowMe()
{
    addTopic("you know me?", "@D@Galadhel tilts her head, curious now and "
        "uses the tip of the arrow in her hand to ease aside the fabric "
        "of the hood of his robe. Her features register recognition after "
        "a moment and she says softly, @S@`Brendan Oeldhen? What brings you "
        "to this end? How did you come to par...'");

    addTopicInterjection("you know me?",
        "/lib/tutorial/characters/brendan/brendan.c",
        "yes, I know you", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("brendan - need a decorator", "@D@Galadhel chuckles, @S@`Home? You are "
        "in serious need of a decorator, my friend. Even so, I shall not hold "
        "your bad taste against you. Yet. We have followed our prey here, ones "
        "who killed our comrades in our encampment then set their corpses in "
        "motion to try and add us to whatever fell plan is in motion. So, rather "
        "than labelling one another and whining self-defense, how about we have "
        "a conversation.'");

    addTopic("threaten brendan", "@D@Galadhel nocks an arrow and draws back her "
        "bow as she interjects, @S@`Given your handiness with corpses, you also "
        "seem to share the same talent as the one who attacked our camp.'");
    addTopicInterjection("threaten brendan",
        "/lib/tutorial/characters/brendan/brendan.c",
        "slow down, Sparky", 1);

    FindingHaldor();
    YouKnowMe();
}
