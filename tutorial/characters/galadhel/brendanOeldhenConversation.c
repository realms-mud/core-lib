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
}
