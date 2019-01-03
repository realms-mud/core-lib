//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

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
    addTopicEvent("brendan - need a decorator", "bad host");

    addTopic("threaten brendan", "@D@Galadhel nocks an arrow and draws back her "
        "bow as she interjects, @S@`Given your handiness with corpses, you also "
        "seem to share the same talent as the one who attacked our camp.'");
    addTopicEvent("threaten brendan", "I'm a farmer");
}
